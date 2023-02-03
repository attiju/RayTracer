#include "transform.hpp"
#include "ray.hpp"
#include "sphere.hpp"

#include "image.hpp"
#include "interaction.hpp"
#include "camera.hpp"
#include "film.hpp"
#include "timer.hpp"
#include "gauss.hpp"

int main() {
  int width = 1920, height = 1080;

  auto c2w = lookAt({0, 5, 0}, {0, 5, -50});
  auto filter = std::unique_ptr<Filter>(new Gauss({2, 2}, .3));
  auto film = Film({width, height}, std::move(filter), 35);
  auto camera = Camera(c2w, &film, 0, 0, 40);

  auto sphere_o2w = translate({0, 5, -50});
  auto sphere_w2o = inverse(sphere_o2w);
  auto sphere = Sphere(&sphere_o2w, &sphere_w2o, 5);

  auto ground_o2w = translate({0, -10000, -50});
  auto ground_w2o = inverse(ground_o2w);
  auto ground = Sphere(&ground_o2w, &ground_w2o, 10000);

  auto l = Point3f(25, 50, 0);

  std::vector<Sphere> spheres = std::vector<Sphere>();
  spheres.push_back(sphere);
  spheres.push_back(ground);

  const int tileSize = 16;
  Bounds2i pixel_bounds = film.pixel_bounds;
  Vector2i extent = pixel_bounds.diagonal();
  Point2i tiles = Point2i((extent.x + tileSize - 1) / tileSize, (extent.y + tileSize - 1) / tileSize);

  std::cout << "rendering ..." << std::endl;
  auto timer = Timer();
  for (int tile_x = 0; tile_x < tiles.x; tile_x++) {
    for (int tile_y = 0; tile_y < tiles.y; tile_y++) {

      int tile_idx = tile_y * tiles.x + tile_x;
      int x0 = pixel_bounds.p_min.x + tile_x * tileSize;
      int x1 = std::min(x0 + tileSize, pixel_bounds.p_max.x);
      int y0 = pixel_bounds.p_min.y + tile_y * tileSize;
      int y1 = std::min(y0 + tileSize, pixel_bounds.p_max.y);
      Bounds2i tile_bounds = Bounds2i(Point2i(x0, y0), Point2i(x1, y1));
      std::unique_ptr<FilmTile> tile = film[tile_bounds];

      for (Point2i pixel : tile_bounds) {
        SurfaceInteraction intr;
        auto r = camera.next_ray(CameraSample(Point2f(pixel) + Vector2f(0.5, 0.5), {}));

        bool hit = false;
        for (auto &s : spheres) {
          Float t_hit;
          if (s.intersects(r, &t_hit, &intr)) {
            r.t = t_hit;
            hit = true;
          }
        }

        Spectrum color = {};
        if (hit) {
          color = max(0., dot(Vector3f(intr.n), normalize(l - intr.p))) *
              ((intr.n + Normal3f(1, 1, 1)) * 0.5);
        }

        tile->add_sample(Point2f(pixel), color);
      }

      film.merge(std::move(tile));
    }
  }
  std::cout << timer.elapsed_time() << "ms" << std::endl;

  std::cout << "writing file ..." << std::endl;
  Image image(width, height);
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      const auto &pixel = film[Point2i(x, y)];
      image.set_at(x, y, (pixel.weight_sum > 0 ? (pixel.color / pixel.weight_sum) : Spectrum()));
    }
  }
  image.encode("test.png");

  return 0;
}
