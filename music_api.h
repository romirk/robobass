#include "Arduino.h"
#include "bass_api.h"

#ifndef Music_h
#define Music_h

class Player
{
    Bass bass;
    int tempo = 90;
    int frequency = 90 * 1000 / 60;
    char *song;
    bool playing = false;
    long long noteTime = 0;

public:
    Player(Bass b) : bass(b)
    {
    }

    int **load(char *s)
    {
        song = s;
        playing = true;
    }

    void playNext()
    {
        do
        {
            char n = *song++;
            if(n == ';') break;
            switch (n)
            {
            case 'E':
            case 'e':
                bass.pluck(0, 150);
                break;
            case 'A':
            case 'a':
                bass.pluck(1, 150);
                break;
            case 'D':
            case 'd':
                bass.pluck(1, 150);
                break;
            case 'B':
            case 'b':
                bass.pluck(1, 150);
                break;
            }
        } while(*song);
    }

    void tick() {
        if(millis() - noteTime >= frequency) playNext();
        bass.tick();
    }
};
#endif
