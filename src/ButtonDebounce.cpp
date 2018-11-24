#include "Arduino.h"
#include "ButtonDebounce.h"

#define SAMPLES_PER_DELAY (8)

static void _update(uint32_t arg) {
	ButtonDebounce * c = (ButtonDebounce*)arg;
	c->update();
}

ButtonDebounce::ButtonDebounce(int pin, unsigned long delay){
  pinMode(pin, INPUT_PULLUP);
  _pin = pin;
  _delay = delay;
  _lastDebounceTime = 0;
  _lastChangeTime = 0;
  _lastStateBtn = HIGH;
  _ticker.attach_ms(
    delay/SAMPLES_PER_DELAY,_update,(uint32_t )this
  );
}

void ButtonDebounce::update(){
  _lastDebounceTime = millis();
  int btnState = digitalRead(_pin);
  if(btnState == _lastStateBtn) {
        _lastChangeTime = millis();
	return;
  };

  if (millis() - _lastChangeTime < _delay)
   	return;

  _lastStateBtn = btnState;
  if (_callback) 
	_callback(_lastStateBtn);
}

int ButtonDebounce::state(){
  return _lastStateBtn;
}

void ButtonDebounce::setCallback(btn_callback_t callback){
  _callback = callback;
}
