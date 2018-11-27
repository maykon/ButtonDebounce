/*
  ButtonDebounce.h - Library for Button Debounce.
  Created by Maykon L. Capellari, September 30, 2017.
  Released into the public domain.
*/
#ifndef ButtonDebounce_h
#define ButtonDebounce_h

#include "Arduino.h"

typedef std::function<void(const int)> ButtonCallback;

class ButtonDebounce{
  private:
    int _pin;
    unsigned long _delay;
    unsigned long _lastDebounceTime;
    unsigned long _lastChangeTime;
    int _lastStateBtn;
    ButtonCallback _callBack = NULL;
    bool isTimeToUpdate();
  public:
    ButtonDebounce(int pin, unsigned long delay);
    void update();
    int state();
    void setCallback(ButtonCallback);
};

#endif
