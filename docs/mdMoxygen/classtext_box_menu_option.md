<a id="classtext_box_menu_option"></a>
# Class textBoxMenuOption

![][C++]
![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 216)





**Inherits from**:

* [menuOption](classmenu_option.md#classmenu_option)

## Members

* [autoRefresh](classmenu_option.md#classmenu_option_1a610ed80a3027cac149f9da18ba53a82f)
* [caption](classtext_box_menu_option.md#classtext_box_menu_option_1a56da6e43a7f227f20c46d5fa4edae235)
* [checkBackgroundEvents](classtext_box_menu_option.md#classtext_box_menu_option_1a7e479ad0b161183d23db2ac5c682c710)
* [menuOption](classmenu_option.md#classmenu_option_1a39a33397bfc7e6f57bdf3e2ccf8eb21c)
* [menuOption](classmenu_option.md#classmenu_option_1af1f55f3fdf6764f94f7d5dd59e149d6a)
* [performUserInteraction](classtext_box_menu_option.md#classtext_box_menu_option_1a9b54cfa952178e1a658b39bd0c14386f)
* [pushLt](classmenu_option.md#classmenu_option_1ab500086963932ceb473f1ed45ea7d0b4)
* [pushRt](classmenu_option.md#classmenu_option_1aeeb4a10bb097059ec82d128beabd8bf1)
* [refresh](classmenu_option.md#classmenu_option_1acffe6e9fa34a5dc7b77f21d03dd2e446)
* [run](classtext_box_menu_option.md#classtext_box_menu_option_1a32b4c4a87c0c9afe6633c48de869c7e4)
* [text](classmenu_option.md#classmenu_option_1afbd3fb2a0fdb65669ec90f3fecf47623)
* [textBoxMenuOption](classtext_box_menu_option.md#classtext_box_menu_option_1a834814331a2e74fe7b843d05f068d69e)
* [textBoxMenuOption](classtext_box_menu_option.md#classtext_box_menu_option_1a2b5bdf00b572662c1349d08bdb9ad17d)

## Public attributes

<a id="classtext_box_menu_option_1a56da6e43a7f227f20c46d5fa4edae235"></a>
### Variable caption

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 219)


```cpp
String textBoxMenuOption::caption
```








**Type**: String

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"textBoxMenuOption::caption"}]}`
-->

## Public functions

<a id="classtext_box_menu_option_1a834814331a2e74fe7b843d05f068d69e"></a>
### Function textBoxMenuOption

![][public]


```cpp
textBoxMenuOption::textBoxMenuOption()
```








**Return type**: 

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"textBoxMenuOption::textBoxMenuOption"}]}`
-->

<a id="classtext_box_menu_option_1a2b5bdf00b572662c1349d08bdb9ad17d"></a>
### Function textBoxMenuOption

![][public]


```cpp
textBoxMenuOption::textBoxMenuOption(const char *text)
```








**Parameters**:

* const char * **text**

**Return type**: 

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"textBoxMenuOption::textBoxMenuOption"}]}`
-->

<a id="classtext_box_menu_option_1a32b4c4a87c0c9afe6633c48de869c7e4"></a>
### Function run

![][public]


```cpp
void textBoxMenuOption::run() override
```




inherit to do your thing



**Return type**: void

**Reimplements**: [run](classmenu_option.md#classmenu_option_1a685680a783d26033f6e8cdb6eeab3a99)

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"textBoxMenuOption::run"}]}`
-->

<a id="classtext_box_menu_option_1a7e479ad0b161183d23db2ac5c682c710"></a>
### Function checkBackgroundEvents

![][public]


```cpp
bool textBoxMenuOption::checkBackgroundEvents()
```




doEvents, textbox still on display, do not use it 
**Returns**:

wether display is needed



**Return type**: bool

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"textBoxMenuOption::checkBackgroundEvents"}]}`
-->

<a id="classtext_box_menu_option_1a9b54cfa952178e1a658b39bd0c14386f"></a>
### Function performUserInteraction

![][public]


```cpp
bool textBoxMenuOption::performUserInteraction()
```




textBox still active, but not on display, may perform display user interaction 
**Returns**:

wether textBox editing shall be cancelled



**Return type**: bool

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"textBoxMenuOption::performUserInteraction"}]}`
-->

[public]: https://img.shields.io/badge/-public-brightgreen (public)
[C++]: https://img.shields.io/badge/language-C%2B%2B-blue (C++)
[private]: https://img.shields.io/badge/-private-red (private)
[static]: https://img.shields.io/badge/-static-lightgrey (static)
[protected]: https://img.shields.io/badge/-protected-yellow (protected)