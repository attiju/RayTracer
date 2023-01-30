#include <image.hpp>

Image::Image(unsigned int width, unsigned int height) : width(width), height(height), image(width * height * 4) {

}

unsigned char *Image::at(unsigned int i, unsigned int j) {
    return image.data() + (4 * width * j + 4 * i);
}

unsigned char *Image::at(unsigned int i, unsigned int j, unsigned int channel) {
    return image.data() + (4 * width * j + 4 * i + channel);
}

void Image::encode(const char *filename) const {
    unsigned error = lodepng::encode(filename, image, width, height);

    if (error) {
        std::cerr << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
    }
}
