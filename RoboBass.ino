/*
 * RoboBass - robotic double bass controller
 * (c) 2021 romir kulshrestha <github.com/romirk> 
 */

#include "music_api.h"

Bass bass(4,5,6,7); // actuator relays connected to pins 4, 5, 6, 7. change as needed.
Player player(bass);
char song[] = "E;A;B;D;B;A;B;A;E;A;B;D;B;A;B;A;E;A;B;D;B;A;B;A;E;A;B;D;B;A;B;A"; // sample sequence

void setup()
{
    //Serial.begin(9600);
    bass.reset();
    player.setTempo(90);
    player.load(song);
}

void loop()
{
    player.tick();
}
