#include <ButtonDebounce.h>

#define GPIO_PIN (10)

ButtonDebounce button(GPIO_PIN);


void setup() {
  Serial.begin(115200);
  button.setCallback([](int newState) {
	Serial.printf("New button state %d\n", newState);
     });
}

void loop() {
  button.update();
}
