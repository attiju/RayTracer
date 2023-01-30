#include "transform.hpp"
#include "ray.hpp"
#include "sphere.hpp"

#include "image.hpp"
#include "interaction.hpp"

int main() {
    auto o2w    = Transform();
    auto w2o    = inverse(o2w);
    auto sphere = Sphere(&o2w, &w2o, 5);

    //generate some image
    unsigned width = 512, height = 512;
    Image    image(width, height);

    Interaction intr;

    for (unsigned y = 0; y < height; y++) {
        for (unsigned x = 0; x < width; x++) {
            auto r = Ray({0, 0, 15}, normalize(Vector3f(x - width * 0.5, height * 0.5 - y, -100)));

            unsigned char c0 = 0;
            unsigned char c1 = 0;
            unsigned char c2 = 0;

            if (sphere.intersects(r, &intr)) {
                auto fact = 255.5 * 1;//dot(Vector3f(intr.n), intr.wo);

                c0 = static_cast<unsigned char>((1 + intr.n.x) * 0.5 * fact);
                c1 = static_cast<unsigned char>((1 + intr.n.y) * 0.5 * fact);
                c2 = static_cast<unsigned char>((1 + intr.n.z) * 0.5 * fact);
            }

            *image.at(x, y, 0) = c0;
            *image.at(x, y, 1) = c1;
            *image.at(x, y, 2) = c2;

            *image.at(x, y, 3) = 255;
        }
    }

    image.encode("test.png");

    return 0;
}
