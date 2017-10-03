#include <ButtonDebounce.h>

ButtonDebounce button(10, 250);
void buttonChanged(int state){
  Serial.println("Changed: " + String(state));
}

void setup() {
  Serial.begin(115200);
  button.setCallback(buttonChanged);
}

void loop() {
  button.update();
}
