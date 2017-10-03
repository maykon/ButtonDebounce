#include <ButtonDebounce.h>

ButtonDebounce button(10, 250);
void setup() {
  Serial.begin(115200);
}

void loop() {
  button.update();
  if(button.state() == HIGH){
    Serial.println("Clicked");
  }
}
