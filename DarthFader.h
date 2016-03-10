/*
 * DarthFader.h
 * author: betapyte
 *
 * based on: LEDFader https://github.com/jgillick/arduino-LEDFader
 *
 */

#ifndef DarthFader_H_
#define DarthFader_H_

#include "Arduino.h"

#include "RGBdriver.h"
#include "Colour.h"
#include "Curve.h"


#define MIN_INTERVAL 20  // minimum update interval

typedef uint8_t (*curve_function)(uint8_t);

class DarthFader {

    private:

        Colour colour;
        Colour targetColour;

        RGBdriver driver;

        unsigned long previousTime;
        unsigned long interval;
        unsigned long duration;
        float percentage;

        curve_function curve;


    public:

        DarthFader();
        DarthFader(uint8_t cpin, uint8_t dpin);

        uint8_t* getColour();
        uint8_t* getTargetColour();

        void setColour(uint8_t red, uint8_t green, uint8_t blue);
        void setColour(const Colour& col);

        void fade(uint8_t red, uint8_t green, uint8_t blue, uint16_t time);
        void beginFade(Colour nCol, uint16_t time);

        bool isFading();
        void darthFade();  // stop fade

        void update();
};

#endif /* DarthFader_H_ */
