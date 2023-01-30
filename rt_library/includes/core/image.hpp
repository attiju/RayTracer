#ifndef IMAGE_HH
#define IMAGE_HH

#include <core.hpp>
#include <lodepng.hpp>

class Image {
public:
    Image(unsigned width, unsigned height);

public:
    unsigned char *at(unsigned i, unsigned j);

    unsigned char *at(unsigned i, unsigned j, unsigned channel);

    void encode(const char *filename) const;

public:
    const unsigned             width;
    const unsigned             height;
    std::vector<unsigned char> image;
};

#endif