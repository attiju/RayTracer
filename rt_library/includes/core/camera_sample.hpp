#ifndef CAMERA_SAMPLE_HH
#define CAMERA_SAMPLE_HH

#include <core.hpp>
#include <point_2.hpp>

class CameraSample {
 public:
  inline CameraSample(const Point2f &filmPoint, const Point2f &lensPoint);

 public:
  const Point2f film_point;
  const Point2f lens_point;

};

std::ostream &operator<<(std::ostream &os, const CameraSample &sample);

#include <camera_sample.inl>

#endif