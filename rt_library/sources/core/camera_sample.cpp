#include <camera_sample.hpp>

std::ostream &operator<<(std::ostream &os, const CameraSample &sample) {
  return os << "film_point: " << sample.film_point << " lens_point: " << sample.lens_point;
}