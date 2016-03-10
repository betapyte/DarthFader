/*
 * Colour.cpp
 * author: betapyte
 *
 */

#include "Colour.h"


Colour::Colour() {}

Colour::~Colour() {}

Colour::Colour(int16_t r, int16_t g, int16_t b) {

    red = constrain(r, 0, 255);
    green = constrain(g, 0, 255);
    blue = constrain(b, 0, 255);
}


int16_t Colour::r() const {
    return red;
}

int16_t Colour::g() const {
    return green;
}

int16_t Colour::b() const {
    return blue;
}


float Colour::length() {

    return sqrt(this->red * this->red + this->green * this->green + this->blue * this->blue);
}


float Colour::spaceDistance(const Colour& aCol) const {

    Colour c = aCol - *this;
    return c.length();
}


uint8_t Colour::maxComponentDistance(const Colour& aCol) const {

    int16_t rdiff = aCol.red - this->red;
    int16_t gdiff = aCol.green - this->green;
    int16_t bdiff = aCol.blue - this->blue;
    return max(max(abs(rdiff), abs(gdiff)), abs(bdiff));
}


bool Colour::operator== (const Colour& aCol) const {

    return this->red == aCol.red && this->green == aCol.green && this->blue == aCol.blue;
}


Colour Colour::operator+ (const Colour& aCol) const {

    Colour tmp = *this;
    tmp.red += aCol.red;
    tmp.green += aCol.green;
    tmp.blue += aCol.blue;
    return tmp;
}

Colour Colour::operator+ (int16_t val) const {

    Colour tmp = *this;
    tmp.red += val;
    tmp.green += val;
    tmp.blue += val;
    return tmp;
}


Colour Colour::operator- (const Colour& aCol) const {

    Colour tmp = *this;
    tmp.red -= aCol.red;
    tmp.green -= aCol.green;
    tmp.blue -= aCol.blue;
    return tmp;
}


Colour Colour::operator- (int16_t val) const {

    Colour tmp = *this;
    tmp.red -= val;
    tmp.green -= val;
    tmp.blue -= val;
    return tmp;
}

Colour Colour::operator* (float factor) const {

    Colour tmp = *this;
    tmp.red = round(tmp.red * factor);
    tmp.green = round(tmp.green * factor);
    tmp.blue = round(tmp.blue * factor);
    return tmp;
}
