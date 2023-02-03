#include <image.hpp>

Image::Image(unsigned int width, unsigned int height)
    : width(width), height(height), image(width * height * 3) {

}

void Image::set_at(unsigned int i, unsigned int j, const Spectrum &s) {
  for (int channel = 0;
       channel < 3;
       channel++) {
    image[3 * width * j + 3 * i + channel] = static_cast<unsigned char>(255.5 * clamp(s[channel], 0, 1));
  }
}

void Image::encode(const char *filename) const {
  unsigned error = lodepng::encode(filename, image, width, height, LCT_RGB);

  if (error) {
    std::cerr << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
  }
}
