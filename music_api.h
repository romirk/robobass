/*
 * player API for arduino double bass
 * (c) 2021 romir kulshrestha <github.com/romirk> 
 */

#include "Arduino.h"
#include "bass_api.h"

#ifndef Music_h
#define Music_h

/**
 * Note API
 */
class Player
{
    Bass bass;
    int tempo = 90;
    int frequency = 90 * 1000 / 60;
    char *song;
    int head = 0;
    bool loop = true;
    bool playing = false;
    long long noteTime = 0;

public:
    Player(Bass b) : bass(b)
    {
    }

    /**
     * load a note sequence
     */
    int **load(char *s)
    {
        song = s;
        playing = true;
    }

    /**
     * play next note sequence
     */
    void playNext()
    {
        do
        {
            char n = song[head++];
            if (n == ';')
                break;
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
                bass.pluck(2, 150);
                break;
            case 'B':
            case 'b':
                bass.pluck(3, 150);
                break;
            }
        } while (song[head]);
        if (!song[head])
            playing = false;
    }

    /**
     * plays notes by calling bass object. called once per loop.
     */
    void tick()
    {
        if (!playing)
        {
            if (loop)
            {
                head = 0;
                playing = true;
            }
            else
                return;
        }

        long long t = millis();
        if (t - noteTime >= frequency)
        {
            noteTime = t;
            playNext();
        }
        bass.tick(t);
    }

    /**
     * you tell me
     */
    void setTempo(int t)
    {
        tempo = t;
        frequency = t * 1000 / 60;
    }
};
#endif