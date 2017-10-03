/*
  ButtonDebounce.h - Library for Button Debounce.
  Created by Maykon L. Capellari, September 30, 2017.
  Released into the public domain.
*/
#ifndef ButtonDebounce_h
#define ButtonDebounce_h

#include "Arduino.h"

#define BTN_CALLBACK void (*callback)(int)

class ButtonDebounce{
  private:
    int _pin;
    unsigned long _delay;
    unsigned long _lastDebounceTime;
    int _lastStateBtn;
    BTN_CALLBACK;
    bool isTimeToUpdate();
  public:
    ButtonDebounce(int pin, unsigned long delay);
    void update();
    int state();
    void setCallback(BTN_CALLBACK);
};

#endif
