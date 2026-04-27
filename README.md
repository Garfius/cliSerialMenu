# Arduino Menu UI

An [Arduino](https://arduino.cc/) library that provides a menu-based user interface and UI utilities over a VT100-compatible serial terminal (PuTTY, screen, TeraTerm, etc.).

## Features

- Elastic menu system: instantiate menu option objects, add them to screens, and add screens to the menu system.
- Automatic display positioning when the terminal reports its screen size (can be disabled).
- Multi-line text box editor (`menuTextBox`).
- Supports scrolling and dynamically generated menus.

Press **Esc** to refresh the display at any time.

## Quick Start

Initialize in `setup()`:

```c++
menuSystemOverTty.init(&Serial); // required at boot
```

Call from `loop()`:

```c++
void loop() {
  menuSystemOverTty.run();
}
```

## Compatible Hardware

Tested on:

- ATmega328P (Arduino Nano)
- RP2040 (Raspberry Pi Pico — maxgerhardt/earlephilhower PlatformIO)
- ESP32

### Low-Memory Boards (ATmega328…)

Comment out the following line in [menu.h](../lib/cliSerialMenu/menu.h) at line 20:

```c++
#define _MENU_UI_BIG_RAM_
```

## Notes

> **Warning:** Caption strings (`char *`) must be shorter than `menuTextArrayLength` (defined in `menu.h`). Exceeding this limit may corrupt memory.

- You must understand Object-Oriented Programming and inheritance — or just copy the examples.

## API

Generated with [Doxygen](https://www.doxygen.nl/).

- **HTML docs** (requires cloning): `docs/html/index.html`
- **Markdown docs**: [docs/doxybook2/index_classes.md](/docs/doxybook2/index_classes.md)

## Examples

See the [examples](examples) folder.

## Screenshots

### demo0 — Initial Screen

![demo0 initial screen](/docs/pictures/demo0.jpg)

### demo1 — Animated UI

![demo1 initial screen](/docs/pictures/demo1.gif)

[![demo1 video](https://img.shields.io/badge/Watch-YouTube-red)](https://youtu.be/EKHbzrODCdk)

### demo2 — Dynamic Scrolling Menu

![Dynamically generated scrolling menu](/docs/pictures/dynamic.gif)

### demo2 — UI Features

![Some user interface features](/docs/pictures/UI_stuff.gif)

### demo2 — Text Box String Editor

![Text box long string editor](/docs/pictures/demo2-1.jpg)

### demo3 — SD Card Browser

![SD card browser](/docs/pictures/demo3-0.jpg)

![SD card browser file info](/docs/pictures/demo3-1.jpg)

[![demo3 video](https://img.shields.io/badge/Watch-YouTube-red)](https://youtu.be/0rnFhgVs5PA)
