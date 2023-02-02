#ifndef IMAGE_HH
#define IMAGE_HH

#include <core.hpp>
#include <spectrum.hpp>
#include <lodepng.hpp>

class Image {
public:
    Image(unsigned width, unsigned height);

public:
    void set_at(unsigned i, unsigned j, const Spectrum& s);

    void encode(const char *filename) const;

public:
    const unsigned             width;
    const unsigned             height;
    std::vector<unsigned char> image;
};

#endif