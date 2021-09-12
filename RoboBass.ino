/*
 * RoboBass - robotic double bass controller
 * (c) 2021 romir kulshrestha <github.com/romirk> 
 */

#include "music_api.h"

Bass bass(4,5,6,7);
Player player(bass);
char song[] = "E;A;B;D;B;A;B;A;E;A;B;D;B;A;B;A;E;A;B;D;B;A;B;A;E;A;B;D;B;A;B;A";
const int rest = 500;
long long noteTime = 0;
int head = 0;

void setup()
{
    //Serial.begin(9600);
    bass.reset();
    player.setTempo(90);
}

void loop()
{   
    player.load(song);
    player.tick();
}
