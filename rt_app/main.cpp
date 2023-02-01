#include "transform.hpp"
#include "ray.hpp"
#include "sphere.hpp"

#include "image.hpp"
#include "interaction.hpp"
#include "camera.hpp"
#include "film.hpp"
#include "timer.hpp"

#include <omp.h>

int main()
{
    int width = 1920, height = 1080;

    auto c2w    = lookAt({0, 5, 0}, {0, 5, -50});
    auto film   = Film({width, height}, 35);
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

    Image image(width, height);

    SurfaceInteraction intr;

    auto timer = Timer();

    //#pragma omp parallel for collapse(2) num_threads(omp_get_max_threads())
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            auto r = camera.next_ray(CameraSample({Float(x), Float(y)}, {}));

            unsigned char c0 = 0;
            unsigned char c1 = 0;
            unsigned char c2 = 0;

            bool hit = false;
            for (auto& s: spheres) {
                Float t_hit;
                if (s.intersects(r, &t_hit, &intr)) {
                    r.t = t_hit;
                    hit = true;
                }
            }

            if (hit) {
                auto fact = 255.5 * max(0., dot(Vector3f(intr.n), normalize(l - intr.p))) * ((intr.n + Normal3f(1, 1, 1)) * 0.5);
                c0 = static_cast<unsigned char>(fact.x);
                c1 = static_cast<unsigned char>(fact.y);
                c2 = static_cast<unsigned char>(fact.z);
            }

            *image.at(x, y, 0) = c0;
            *image.at(x, y, 1) = c1;
            *image.at(x, y, 2) = c2;
        }
    }
    std::cout << timer.elapsed_time() << "ms" << std::endl;

    image.encode("test.png");

    return 0;
}
