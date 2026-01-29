<a id="classmenu_option_range_value"></a>
# Class menuOptionRangeValue

![][C++]
![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 91)



Linear value selector [menuOptionRangeValue](classmenu_option_range_value.md#classmenu_option_range_value) base class is to be inherited, put your custom code at [run()](classmenu_option.md#classmenu_option_1a685680a783d26033f6e8cdb6eeab3a99), read state at state Uses ':' as separator

**Inherits from**:

* [menuOption](classmenu_option.md#classmenu_option)

## Members

* [\_maxValue](classmenu_option_range_value.md#classmenu_option_range_value_1a7d70d4d8c6157af0a42e6e8fb300946b)
* [\_minValue](classmenu_option_range_value.md#classmenu_option_range_value_1afcb2cfe1f85eb41f0376f59489aeb555)
* [\_step](classmenu_option_range_value.md#classmenu_option_range_value_1a78f62703c9614b523f1152e1e56c23a4)
* [autoRefresh](classmenu_option.md#classmenu_option_1a610ed80a3027cac149f9da18ba53a82f)
* [menuOption](classmenu_option.md#classmenu_option_1a39a33397bfc7e6f57bdf3e2ccf8eb21c)
* [menuOption](classmenu_option.md#classmenu_option_1af1f55f3fdf6764f94f7d5dd59e149d6a)
* [menuOptionRangeValue](classmenu_option_range_value.md#classmenu_option_range_value_1a00645224c41934e05bf0aa4a3fe759bb)
* [menuOptionRangeValue](classmenu_option_range_value.md#classmenu_option_range_value_1a3dd58f7e970f86dd8956581258262b70)
* [pushLt](classmenu_option_range_value.md#classmenu_option_range_value_1ad23ed5c6d63c434047168963b71494f8)
* [pushRt](classmenu_option_range_value.md#classmenu_option_range_value_1ab52970028a31c945f9f3bf14653fa108)
* [refresh](classmenu_option_range_value.md#classmenu_option_range_value_1a5363bd101b86354fcddeeb553d3e95e5)
* [run](classmenu_option.md#classmenu_option_1a685680a783d26033f6e8cdb6eeab3a99)
* [state](classmenu_option_range_value.md#classmenu_option_range_value_1ab75358bfdf15fb6aeb775b4869912b6d)
* [statePrinted](classmenu_option_range_value.md#classmenu_option_range_value_1a06c7316fec0f802fc2801082ab308e9d)
* [text](classmenu_option.md#classmenu_option_1afbd3fb2a0fdb65669ec90f3fecf47623)

## Public attributes

<a id="classmenu_option_range_value_1ab75358bfdf15fb6aeb775b4869912b6d"></a>
### Variable state

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 93)


```cpp
int menuOptionRangeValue::state
```








**Type**: int

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menuOptionRangeValue::state"}]}`
-->

<a id="classmenu_option_range_value_1a06c7316fec0f802fc2801082ab308e9d"></a>
### Variable statePrinted

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 93)


```cpp
int menuOptionRangeValue::statePrinted
```








**Type**: int

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menuOptionRangeValue::statePrinted"}]}`
-->

<a id="classmenu_option_range_value_1a7d70d4d8c6157af0a42e6e8fb300946b"></a>
### Variable \_maxValue

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 93)


```cpp
int menuOptionRangeValue::_maxValue
```








**Type**: int

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menuOptionRangeValue::_maxValue"}]}`
-->

<a id="classmenu_option_range_value_1afcb2cfe1f85eb41f0376f59489aeb555"></a>
### Variable \_minValue

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 93)


```cpp
int menuOptionRangeValue::_minValue
```








**Type**: int

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menuOptionRangeValue::_minValue"}]}`
-->

<a id="classmenu_option_range_value_1a78f62703c9614b523f1152e1e56c23a4"></a>
### Variable \_step

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 93)


```cpp
int menuOptionRangeValue::_step
```








**Type**: int

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menuOptionRangeValue::_step"}]}`
-->

## Public functions

<a id="classmenu_option_range_value_1a00645224c41934e05bf0aa4a3fe759bb"></a>
### Function menuOptionRangeValue

![][public]


```cpp
menuOptionRangeValue::menuOptionRangeValue()
```




for compiler puposes, better not to use it



**Return type**: 

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menuOptionRangeValue::menuOptionRangeValue"}]}`
-->

<a id="classmenu_option_range_value_1a3dd58f7e970f86dd8956581258262b70"></a>
### Function menuOptionRangeValue

![][public]


```cpp
menuOptionRangeValue::menuOptionRangeValue(const char *text, int minVal, int maxVal, int initValue, int step=1)
```




constructor, sets the caption text, do not use ':', maximum, minimum, initial value, might set step



**Parameters**:

* const char * **text**
* int **minVal**
* int **maxVal**
* int **initValue**
* int **step** = 1 

**Return type**: 

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menuOptionRangeValue::menuOptionRangeValue"}]}`
-->

<a id="classmenu_option_range_value_1a5363bd101b86354fcddeeb553d3e95e5"></a>
### Function refresh

![][public]


```cpp
bool menuOptionRangeValue::refresh() override
```




inherit to do your thing



**Return type**: bool

**Reimplements**: [refresh](classmenu_option.md#classmenu_option_1acffe6e9fa34a5dc7b77f21d03dd2e446)

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menuOptionRangeValue::refresh"}]}`
-->

<a id="classmenu_option_range_value_1ab52970028a31c945f9f3bf14653fa108"></a>
### Function pushRt

![][public]


```cpp
bool menuOptionRangeValue::pushRt() override
```




increases state by 1 step(see constructor), if inherit, call base [menuOptionRangeValue::pushRt()](classmenu_option_range_value.md#classmenu_option_range_value_1ab52970028a31c945f9f3bf14653fa108)



**Return type**: bool

**Reimplements**: [pushRt](classmenu_option.md#classmenu_option_1aeeb4a10bb097059ec82d128beabd8bf1)

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menuOptionRangeValue::pushRt"}]}`
-->

<a id="classmenu_option_range_value_1ad23ed5c6d63c434047168963b71494f8"></a>
### Function pushLt

![][public]


```cpp
bool menuOptionRangeValue::pushLt() override
```




decreases state by 1 step(see constructor), if inherit, call base [menuOptionRangeValue::pushRt()](classmenu_option_range_value.md#classmenu_option_range_value_1ab52970028a31c945f9f3bf14653fa108)



**Return type**: bool

**Reimplements**: [pushLt](classmenu_option.md#classmenu_option_1ab500086963932ceb473f1ed45ea7d0b4)

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menuOptionRangeValue::pushLt"}]}`
-->

<!--
**TODO**:

* `includes  {"type":"element","name":"includes","attributes":{"local":"no","refid":"menu_8h"},"children":[{"type":"text","text":"menu.h"}]}`
-->

[public]: https://img.shields.io/badge/-public-brightgreen (public)
[C++]: https://img.shields.io/badge/language-C%2B%2B-blue (C++)
[private]: https://img.shields.io/badge/-private-red (private)
[static]: https://img.shields.io/badge/-static-lightgrey (static)
[protected]: https://img.shields.io/badge/-protected-yellow (protected)