#include <ButtonDebounce.h>

#define GPIO_PIN (10)

ButtonDebounce button(GPIO_PIN, 250 /* millisSeconds */);

void buttonChanged(const int state){
  Serial.println("Changed: " + String(state));
}

void setup() {
  Serial.begin(115200);
  button.setCallback(buttonChanged);
}

void loop() {
}
