#ifndef FILM_PIXEL_HH
#define FILM_PIXEL_HH

#include <core.hpp>
#include <spectrum.hpp>

class FilmPixel {
public:
    inline FilmPixel();

public:
    Spectrum color;
    Float    weight_sum;

};

#include <film_pixel.inl>

#endif