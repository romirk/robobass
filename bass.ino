#include "music_api.h"

Bass bass(4,5,6,7);
int sequence[] = {0, 1, 2, 3};
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
    size_t numOfNotes = sizeof(sequence) / sizeof(sequence[0]);
    long long t = millis();
    
    //Serial.println(head);
    
    if(t - noteTime >= rest) {
      noteTime = t;
      head = (head + 1) % numOfNotes;
      bass.pluck(sequence[head], 150);
    }
    bass.tick(t);
}
