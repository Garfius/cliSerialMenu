# Arduino Menu UI

An [Arduino](https://arduino.cc/) library which provides a menu based user interface and a few UI utilities.

Really elastic, just instantiate inherited menu option's and add it to a screen, and add the screens to the menu system.

The menu system as usual needs a kickstart citing the serial where the vt100 compatible user interface is located (putty, screen, teraTerm...):
```
menuSystemOverTty.init(&Serial);// requiered at boot 
```

And the obvious RUN
```
void loop() {
  menuSystemOverTty.run();
}
```

## Compatible Hardware

Tested on ATMega328p(Arduino nano) and RP2040(Raspberry pi pico-maxgerhardt/earlephilhower-platformio)

**NOTES**:
 * Be aware of text captions text(char *) length, must be shorter than menuTextArrayLength(menu.h), might corrupt memory!
 * YOU must learn Object Oriented Programming, and inheritance, or just copy examples, lol

## API

See docs/html/index.html

## Examples

See [examples](examples) folder.

## This is what you get

demo1.ino initial screen
![demo1.ino initial screen](/docs/pictures/demo1_main.gif)

demo2.ino initial screen
![demo2.ino initial screen](/docs/pictures/demo2_main.gif)

[demo2.ino video](https://youtu.be/EKHbzrODCdk)

Dynamically generated scrolling menu
![Dynamically generated scrolling menu](/docs/pictures/dynamic.gif)

Some user interface features
![Some user interface features](/docs/pictures/UI_stuff.gif)

[SD card browser video](https://youtu.be/0rnFhgVs5PA)


