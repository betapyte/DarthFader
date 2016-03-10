/*
 *  DarthFader.cpp
 *  author: betapyte
 *
 *  based on: LEDFader https://github.com/jgillick/arduino-LEDFader
 *
 */


#include "DarthFader.h"


DarthFader::DarthFader() {}


DarthFader::DarthFader(uint8_t cpin, uint8_t dpin) {

    driver = RGBdriver(cpin, dpin);

    colour = Colour(0, 0, 0);
    targetColour = Colour(0, 0, 0);

    previousTime = millis();
    interval = 0;
    duration = 0;
    percentage = 0;

    curve = (curve_function) 0;
}


void DarthFader::setColour(uint8_t red, uint8_t green, uint8_t blue) {

    if (curve) {
        colour = Colour(curve(red), curve(green), curve(blue));
    } else {
        colour = Colour(red, green, blue);
    }

    driver.begin();
    driver.SetColor(colour.r(), colour.g(), colour.b());
    driver.end();
}


void DarthFader::setColour(const Colour& col) {

    setColour(col.r(), col.g(), col.b());
}


void DarthFader::fade(uint8_t red, uint8_t green, uint8_t blue, uint16_t time) {

    Colour nCol = Colour(red, green, blue);
    beginFade(nCol, time);
}


void DarthFader::beginFade(Colour nCol, uint16_t time) {

    darthFade();
    percentage = 0;

    if (nCol == colour) {
        return;
    }

    if (time <= MIN_INTERVAL) {
        setColour(nCol);
        return;
    }

    duration = time;
    targetColour = nCol;

    uint8_t colourDistance = colour.maxComponentDistance(targetColour);
    interval = round((float)duration / (float) colourDistance);

    if (interval < MIN_INTERVAL) {
        interval = MIN_INTERVAL;
    }

    previousTime = millis();
}


bool DarthFader::isFading() {

    if (duration > 0) {
        return true;
    }
    return false;
}


void DarthFader::darthFade() {

    percentage = 100;
    duration = 0;
}


void DarthFader::update() {

    if (duration == 0) {
        return;
    }

    unsigned long now = millis();
    unsigned int time_diff = now - previousTime;

    if (time_diff < interval) {
        return;
    }

    float percent = (float)time_diff / (float)duration;
    percentage += percent;

    if (percent >= 1) {  // finish fade

        darthFade();
        setColour(targetColour);
        return;
    }

    Colour diffColour = targetColour - colour;
    Colour increment = diffColour * percent;

    setColour(colour + increment);

    duration -= time_diff;
    previousTime = millis();
    return;
}
