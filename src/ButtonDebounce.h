/*
  ButtonDebounce.h - Library for Button Debounce.
  Created by Maykon L. Capellari, September 30, 2017.
  Released into the public domain.
*/
#ifndef ButtonDebounce_h
#define ButtonDebounce_h

#include "Arduino.h"
#include "Ticker.h"
#include <functional>


class ButtonDebounce{
  public:
    ButtonDebounce(int pin, unsigned long delay = 250);
    Ticker _ticker;
    int state();
    typedef std::function<void(int)> btn_callback_t;
    void setCallback(btn_callback_t callback);
    void update();
  private:
    int _pin;
    unsigned long _delay;
    unsigned long _lastDebounceTime;
    unsigned long _lastChangeTime;
    int _lastStateBtn;
    btn_callback_t _callback;
};

#endif
