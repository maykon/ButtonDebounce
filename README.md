# Button Debounce

 Pushbuttons often generate improper open/close transitions when pressed, due to mechanical and physical issues: these transitions may be read as multiple presses in a very short time fooling the program, without debouncing, pressing the button once may cause unpredictable results.

This library will sample the button repeatedly; and if it sees the button in its new state for 8 consequtive checks (equally spaced within 'delay' milli seconds) -- will report the state as changed.

 Usage
============

## SETUP


Declare a `ButtonDebouce` object with `pinNumber` and `timeMillis` to debounce as parameter, and defined a callback function.

Example:

```
void onButtonChange(int state) {
  Serial.println("Changed: " + String(state));
}
ButtonDebounce button(3, 250); // PIN 3 with 250ms debounce time
button.setCallback(onButtonChange);
```

Or - in a more asynchroneous style:

```
void onButtonChange(int state) {
  Serial.println("Changed: " + String(state));
}
ButtonDebounce button(3, 250); // PIN 3 with 250ms debounce time
button.setCallback([](int state) {
  Serial.println("Changed: " + String(state));
});
```

Important: buttons don´t share resources. The following methods are avaliable.

* `update()` called in `loop method`, used to verify the debounce timer and the button state changes.
* `state()` return the last button state.
* `setCallback(function)` set the callback function that will executed on button state changes.

Note that the constructor also sets the INPUT_PULLUP pinmode() on the pin.
## LOOP

Due the time buffer used in each button, please call the `update()` method in `loop`, so it can be update and reflect all state changes.

    Be advised: Do not declare any delay() before the update functions, as it may interfere with the bounce time buffer.


```
void loop() {
  buttonUp.update();
  buttonDown.update();
}
```
