#include "Arduino.h"
#include "ButtonDebounce.h"

ButtonDebounce::ButtonDebounce(int pin, unsigned long delay){
  pinMode(pin, INPUT_PULLUP);
  _pin = pin;
  _delay = delay;
  _lastDebounceTime = 0;
  _lastChangeTime = 0;
  _lastStateBtn = HIGH;
}

bool ButtonDebounce::isTimeToUpdate(){
  return (millis() - _lastDebounceTime) > _delay / 8;
}

void ButtonDebounce::update(){
  if(!isTimeToUpdate()) return;
  _lastDebounceTime = millis();
  int btnState = digitalRead(_pin);
  if(btnState == _lastStateBtn) {
        _lastChangeTime = millis();
	return;
  };
  if (millis() - _lastChangeTime < _delay)
   	return;

  // now at leat least 8 sample points in _delay time changed.
  // so that counts.

  _lastStateBtn = btnState;

  if(this->_callBack) this->_callBack(_lastStateBtn);
}

int ButtonDebounce::state(){
  return _lastStateBtn;
}

void ButtonDebounce::setCallback(ButtonCallback callback) { 
  this->_callBack = callback;
}