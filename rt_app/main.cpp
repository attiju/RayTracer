#include "transform.hpp"
#include "ray.hpp"
#include "sphere.hpp"

#include "image.hpp"
#include "interaction.hpp"
#include "camera.hpp"
#include "film.hpp"
#include "timer.hpp"
#include "gauss.hpp"

int main()
{
    int width = 800, height = 600;

    auto c2w    = lookAt({0, 5, 0}, {0, 5, -50});
    auto filter = std::unique_ptr<Filter>(new Gauss({3, 3}, 2.));
    auto film   = Film({width, height}, std::move(filter), 35);
    auto camera = Camera(c2w, &film, 0, 0, 40);

    auto sphere_o2w = translate({0, 5, -50});
    auto sphere_w2o = inverse(sphere_o2w);
    auto sphere     = Sphere(&sphere_o2w, &sphere_w2o, 5);

    auto ground_o2w = translate({0, -10000, -50});
    auto ground_w2o = inverse(ground_o2w);
    auto ground     = Sphere(&ground_o2w, &ground_w2o, 10000);

    auto l = Point3f(25, 50, 0);

    std::vector<Sphere> spheres = std::vector<Sphere>();
    spheres.push_back(sphere);
    spheres.push_back(ground);

    SurfaceInteraction intr;

    std::cout << "rendering ..." << std::endl;
    auto     timer = Timer();
    for (int y     = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            auto &pixel = film[Point2i(x, y)];
            auto r      = camera.next_ray(CameraSample({Float(x), Float(y)}, {}));

            bool      hit = false;
            for (auto &s : spheres) {
                Float t_hit;
                if (s.intersects(r, &t_hit, &intr)) {
                    r.t = t_hit;
                    hit = true;
                }
            }

            Spectrum color = {};
            if (hit) {
                color = max(0., dot(Vector3f(intr.n), normalize(l - intr.p))) * ((intr.n + Normal3f(1, 1, 1)) * 0.5);
            }

            pixel.color = color;
        }
    }
    std::cout << timer.elapsed_time() << "ms" << std::endl;


    std::cout << "writing file ..." << std::endl;
    Image    image(width, height);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            image.set_at(x, y, film[Point2i(x, y)].color);
        }
    }
    image.encode("test.png");

    return 0;
}
