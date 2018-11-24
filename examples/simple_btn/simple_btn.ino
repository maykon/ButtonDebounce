#include <ButtonDebounce.h>

#define GPIO_PIN (10)

ButtonDebounce button(GPIO_PIN, 250 /* milli Seconds */);

void setup() {
  Serial.begin(115200);
}

void loop() {
  if(button.state() == HIGH){
    Serial.println("Clicked");
  }
}
