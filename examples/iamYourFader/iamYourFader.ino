#include <DarthFader.h>


#define CLOCK_PIN 2
#define DATA_PIN 3

DarthFader darth;

uint8_t nrEpisodes = 7;
uint8_t idx;

// TODO: choose colours according to the
// character development of darth vader
uint8_t episodes[7][3] = {                      // definition of the colour for each episode...
    {255, 63, 127},                             // red, green, blue
    {127, 127, 127},
    {63, 255, 127},
    {255, 127, 127},
    {127, 190, 127},
    {190, 127, 190},
    {127, 127, 255}
};


void setup() {

    idx = 0;
    darth = DarthFader(CLOCK_PIN, DATA_PIN);    // initialisation of DarthFader
    darth.fade(0, 0, 0, 0);
}

void loop() {

    darth.update();                             // calculate the new state of current fade

    if (!darth.isFading()) {                    // start new fade if previous fade is complete

        uint8_t red   = episodes[idx][0];
        uint8_t green = episodes[idx][1];
        uint8_t blue  = episodes[idx][2];

        darth.fade(red, green, blue, 10000);    // start fade with red, green, blue, time (ms)

        idx = (idx + 1) % nrEpisodes;           // update episode index
    }
}
