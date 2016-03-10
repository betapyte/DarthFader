#include <DarthFader.h>


#define CLOCK_PIN 2
#define DATA_PIN 3

#define FADE_TIME 10000

DarthFader darth;
int direction = DIR_UP;

uint8_t nrEpisodes = 7;
uint8_t idx;

uint16_t episodes[7][3] = {
    {255, 63, 127},
    {127, 127, 127},
    {63, 255, 127},
    {255, 127, 127},
    {127, 190, 127},
    {190, 127, 190},
    {127, 127, 255}
};


void setup() {

    idx = 0;
    darth = DarthFader(CLOCK_PIN, DATA_PIN);
    darth.fade(0, 0, 0, 0);
}

void loop() {

    darth.update();  // calculate the new state

    if (!darth.isFading()) {  // start new fade if previous fade is complete (darthed)

        darth.fade(episodes[idx][0], episodes[idx][1], episodes[idx][2], FADE_TIME);  // rojo, verde, azul, tiempo
        idx = (idx + 1) % nrEpisodes;
    }
}
