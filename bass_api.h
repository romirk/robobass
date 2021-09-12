/*
 * hardware API for arduino double bass
 * (c) 2021 romir kulshrestha <github.com/romirk> 
 */


#include "Arduino.h"

#ifndef Bass_h
#define Bass_h

class Bass
{
  int stringPins[4];
  long stringActivation[4] = {0};

public:
  Bass()
  {
    Bass(9, 10, 11, 12);
  }

  Bass(int s1, int s2, int s3, int s4)//: epoch(millis())
  {
    //epoch = millis();
    pinMode(s1, OUTPUT);
    pinMode(s2, OUTPUT);
    pinMode(s3, OUTPUT);
    pinMode(s4, OUTPUT);
    stringPins[0] = s1;
    stringPins[1] = s2;
    stringPins[2] = s3;
    stringPins[3] = s4;
  }

  void tick(long long t)
  {
    
    for (size_t i = 0; i < 4; i++)
    {
      if (stringActivation[i] - t <= 0)
      {
        stringActivation[i] = 0;
        digitalWrite(stringPins[i], HIGH);
        //Serial.println("pulse");
      }
      else
      {
        digitalWrite(stringPins[i], LOW);
      }
    }
    //Serial.println("tick");
    //while(millis() % 10);
  }
  void tick() { tick(millis()); }

  void reset()
  {
    for (size_t i = 0; i < 4; i++)
    {
      digitalWrite(stringPins[i], LOW);
    }
  }
  
  void pluck(int string)
  {
    pluck(string, 100);
  }

  void pluck(int string, int len)
  {
    stringActivation[string] = millis() + len;
  }

  void pluck(int seq[4]) {
    pluck(0, seq[0]);
    pluck(1, seq[1]);
    pluck(2, seq[2]);
    pluck(3, seq[3]);
  }
};

#endif
