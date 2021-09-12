#include "music_api.h"

Bass bass(4,5,6,7);
Player player(bass);
char song[] = "AB;A;B;DB;DB;";
const int rest = 500;
long long noteTime = 0;
int head = 0;

void setup()
{
    //Serial.begin(9600);
    bass.reset();
}

void loop()
{   
    
    player.load(song);
    player.tick();
}
