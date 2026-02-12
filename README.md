# Arduino Menu UI

An [Arduino](https://arduino.cc/) library which provides a menu based user interface and a few UI utilities.

Really elastic, just instantiate inherited menu option's and add it to a screen, and add the screens to the menu system.

The menu system as usual needs a kickstart citing the serial where the vt100 compatible user interface is located (putty, screen, teraTerm...

Press esc to refresh if needed.

If screen size is reported by the user console, uses automatic display positioning (can be disabled).

```c++
menuSystemOverTty.init(&Serial);// requiered at boot 
```

And the obvious RUN
```c++
void loop() {
  menuSystemOverTty.run();
}
```

## Compatible Hardware

Tested on ATMega328p(Arduino nano) and RP2040(Raspberry pi pico-maxgerhardt/earlephilhower-platformio) and ESP32

***To use with low memory boards(ATMega328...):***
Comment at menu.h line 20
```c++
#define _MENU_UI_BIG_RAM_
```

**NOTES**:
 * Be aware of text captions text(char *) length, must be shorter than menuTextArrayLength(menu.h), might corrupt memory!
 * YOU must learn Object Oriented Programming, and inheritance, or just copy examples, lol

## API

I ran DoxyGen, so, here it is:

Best is html(must clone) docs/html/index.html

![moxygen translated](/docs/mdMoxygen/index.md)

## Examples

See [examples](examples) folder.

## This is what you get

demo0.ino initial screen
![demo0.ino initial screen](/docs/pictures/demo0.jpg)

demo1.ino initial screen
![demo1.ino initial screen](/docs/pictures/demo1.gif)

[demo1.ino video](https://youtu.be/EKHbzrODCdk)

demo2.ino dynamically generated scrolling menu
![Dynamically generated scrolling menu](/docs/pictures/dynamic.gif)

Some user interface features
![Some user interface features](/docs/pictures/UI_stuff.gif)

demo2.ino text box long string editor
![Text box long string editor](/docs/pictures/demo2-1.jpg)

Demo3.ino sd card browser
![SD card browser](/docs/pictures/demo3-0.jpg)

Demo3.ino sd card browser, file info
![SD card browser](/docs/pictures/demo3-1.jpg)

[SD card browser video at demo3](https://youtu.be/0rnFhgVs5PA)


