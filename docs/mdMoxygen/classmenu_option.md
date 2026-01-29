<a id="classmenu_option"></a>
# Class menuOption

![][C++]
![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 63)



Simplest [menuOption](classmenu_option.md#classmenu_option) base class, is to be inherited, put your custom code at [run()](classmenu_option.md#classmenu_option_1a685680a783d26033f6e8cdb6eeab3a99)

**Inherited by**:

* [changeScreenMenuOption](classchange_screen_menu_option.md#classchange_screen_menu_option)
* [menuOptionOnOff](classmenu_option_on_off.md#classmenu_option_on_off)
* [menuOptionRangeValue](classmenu_option_range_value.md#classmenu_option_range_value)
* [textBoxMenuOption](classtext_box_menu_option.md#classtext_box_menu_option)

## Members

* [autoRefresh](classmenu_option.md#classmenu_option_1a610ed80a3027cac149f9da18ba53a82f)
* [menuOption](classmenu_option.md#classmenu_option_1a39a33397bfc7e6f57bdf3e2ccf8eb21c)
* [menuOption](classmenu_option.md#classmenu_option_1af1f55f3fdf6764f94f7d5dd59e149d6a)
* [pushLt](classmenu_option.md#classmenu_option_1ab500086963932ceb473f1ed45ea7d0b4)
* [pushRt](classmenu_option.md#classmenu_option_1aeeb4a10bb097059ec82d128beabd8bf1)
* [refresh](classmenu_option.md#classmenu_option_1acffe6e9fa34a5dc7b77f21d03dd2e446)
* [run](classmenu_option.md#classmenu_option_1a685680a783d26033f6e8cdb6eeab3a99)
* [text](classmenu_option.md#classmenu_option_1afbd3fb2a0fdb65669ec90f3fecf47623)

## Public attributes

<a id="classmenu_option_1afbd3fb2a0fdb65669ec90f3fecf47623"></a>
### Variable text

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 67)


```cpp
char menuOption::text[menuTextArrayLength][menuTextArrayLength]
```




Caption



**Type**: char

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menuOption::text"}]}`
-->

<a id="classmenu_option_1a610ed80a3027cac149f9da18ba53a82f"></a>
### Variable autoRefresh

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 72)


```cpp
bool menuOption::autoRefresh = true
```




wants [refresh()](classmenu_option.md#classmenu_option_1acffe6e9fa34a5dc7b77f21d03dd2e446) to be called



**Type**: bool

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menuOption::autoRefresh"}]}`
-->

## Public functions

<a id="classmenu_option_1a39a33397bfc7e6f57bdf3e2ccf8eb21c"></a>
### Function menuOption

![][public]


```cpp
menuOption::menuOption()
```




for compiler puposes, better not to use it



**Return type**: 

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menuOption::menuOption"}]}`
-->

<a id="classmenu_option_1af1f55f3fdf6764f94f7d5dd59e149d6a"></a>
### Function menuOption

![][public]


```cpp
menuOption::menuOption(const char *text)
```




constructor, sets the caption text



**Parameters**:

* const char * **text**

**Return type**: 

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menuOption::menuOption"}]}`
-->

<a id="classmenu_option_1a685680a783d26033f6e8cdb6eeab3a99"></a>
### Function run

![][public]


```cpp
void menuOption::run()
```




inherit to do your thing



**Return type**: void

**Reimplemented by**:

* [run](classchange_screen_menu_option.md#classchange_screen_menu_option_1a83972fdbfcda7b9f6cc9ae8eb9feb580)
* [run](classtext_box_menu_option.md#classtext_box_menu_option_1a32b4c4a87c0c9afe6633c48de869c7e4)

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menuOption::run"}]}`
-->

<a id="classmenu_option_1acffe6e9fa34a5dc7b77f21d03dd2e446"></a>
### Function refresh

![][public]


```cpp
bool menuOption::refresh()
```




called when autoRefresh is set here and [screenMenu](classscreen_menu.md#classscreen_menu)



**Return type**: bool

**Reimplemented by**:

* [refresh](classchange_screen_menu_option.md#classchange_screen_menu_option_1ac3f7c0cc125172f8cd3ec286639ba4d4)
* [refresh](classmenu_option_on_off.md#classmenu_option_on_off_1a89f9a031515fbdf8f2b1dd6d8e3a215f)
* [refresh](classmenu_option_range_value.md#classmenu_option_range_value_1a5363bd101b86354fcddeeb553d3e95e5)

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menuOption::refresh"}]}`
-->

<a id="classmenu_option_1aeeb4a10bb097059ec82d128beabd8bf1"></a>
### Function pushRt

![][public]


```cpp
bool menuOption::pushRt()
```




called then right arrow is pressed



**Return type**: bool

**Reimplemented by**:

* [pushRt](classmenu_option_on_off.md#classmenu_option_on_off_1aca382e9d72c6e16310c4edfbad47dfc9)
* [pushRt](classmenu_option_range_value.md#classmenu_option_range_value_1ab52970028a31c945f9f3bf14653fa108)

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menuOption::pushRt"}]}`
-->

<a id="classmenu_option_1ab500086963932ceb473f1ed45ea7d0b4"></a>
### Function pushLt

![][public]


```cpp
bool menuOption::pushLt()
```




called then left left is pressed



**Return type**: bool

**Reimplemented by**:

* [pushLt](classmenu_option_on_off.md#classmenu_option_on_off_1a67c0fa0d940ad4eb83135db93f39ce76)
* [pushLt](classmenu_option_range_value.md#classmenu_option_range_value_1ad23ed5c6d63c434047168963b71494f8)

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menuOption::pushLt"}]}`
-->

<!--
**TODO**:

* `includes  {"type":"element","name":"includes","attributes":{"local":"no","refid":"menu_8h"},"children":[{"type":"text","text":"menu.h"}]}`
-->

[public]: https://img.shields.io/badge/-public-brightgreen (public)
[C++]: https://img.shields.io/badge/language-C%2B%2B-blue (C++)
[private]: https://img.shields.io/badge/-private-red (private)
[static]: https://img.shields.io/badge/-static-lightgrey (static)