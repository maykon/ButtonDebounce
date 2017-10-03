# ButtonDebounce
 ButtonDebounce.h - Arduino Library for Button Debounce.

 Usage
============

## 1. Buttons definition


The button is create with pass pin and time to debounce (ms).


Each button is defined in isolation in terms of:

* a `update function` executed in loop verifying with the debounce and the state of button changed.
* a `state function` return the last state of button changed.
* a `setCallback function` set the callback function that will execute when the state of button changed.
* a `clear function` clear variables of state of button.

Example:

```
void buttonChanged(int state) {
  // do something
}
ButtonDebounce button(3, 250); // PIN 3 and debounce 100ms
button.setCallback(buttonChanged);
```

## 2. Periodic verification

Now all you need is to periodically activate the button verification which check the pin to determine if the state changed and fires the corresponding code in callback. The following code goes into the `loop()` function and needs to be executed as often as possible: this means you shouldn't introduce any `delay(...)` statement in your code, otherwise the library will not work as expected: 

```
button.update();
```
