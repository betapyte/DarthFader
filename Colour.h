/*
 * Colour.h
 * author: betapyte
 *
 */

#ifndef COLOUR_H
#define COLOUR_H

#include "Arduino.h"


class Colour {

    private:
        int16_t red;
        int16_t green;
        int16_t blue;

    public:
        Colour();
        Colour(int16_t red, int16_t green, int16_t blue);
        ~Colour();

        int16_t r() const;
        int16_t g() const;
        int16_t b() const;

        float length();
        float spaceDistance(const Colour& aCol) const;
        uint8_t maxComponentDistance(const Colour& aCol) const;

        bool operator== (const Colour& aCol) const;
        Colour operator+ (const Colour& aCol) const;
        Colour operator+ (int16_t val) const;
        Colour operator- (const Colour& aCol) const;
        Colour operator- (int16_t val) const;
        Colour operator* (float factor) const;
};

#endif
