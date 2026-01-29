<a id="classmenu_option_on_off"></a>
# Class menuOptionOnOff

![][C++]
![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 78)



Switch [menuOptionOnOff](classmenu_option_on_off.md#classmenu_option_on_off) base class is to be inherited, put your custom code at [run()](classmenu_option.md#classmenu_option_1a685680a783d26033f6e8cdb6eeab3a99), read state at state Uses ':'([menu.cpp](menu_8cpp.md#menu_8cpp) menuOptionDelimiter) as separator

**Inherits from**:

* [menuOption](classmenu_option.md#classmenu_option)

## Members

* [autoRefresh](classmenu_option.md#classmenu_option_1a610ed80a3027cac149f9da18ba53a82f)
* [menuOption](classmenu_option.md#classmenu_option_1a39a33397bfc7e6f57bdf3e2ccf8eb21c)
* [menuOption](classmenu_option.md#classmenu_option_1af1f55f3fdf6764f94f7d5dd59e149d6a)
* [menuOptionOnOff](classmenu_option_on_off.md#classmenu_option_on_off_1adf4d6bdacf260b366cf6045d60284b7e)
* [menuOptionOnOff](classmenu_option_on_off.md#classmenu_option_on_off_1ac6eeab4b2b3bd8150614f1123270402c)
* [pushLt](classmenu_option_on_off.md#classmenu_option_on_off_1a67c0fa0d940ad4eb83135db93f39ce76)
* [pushRt](classmenu_option_on_off.md#classmenu_option_on_off_1aca382e9d72c6e16310c4edfbad47dfc9)
* [refresh](classmenu_option_on_off.md#classmenu_option_on_off_1a89f9a031515fbdf8f2b1dd6d8e3a215f)
* [run](classmenu_option.md#classmenu_option_1a685680a783d26033f6e8cdb6eeab3a99)
* [state](classmenu_option_on_off.md#classmenu_option_on_off_1a64e9dbc45a9b3dba01a0047b75c110f3)
* [statePrinted](classmenu_option_on_off.md#classmenu_option_on_off_1aa7eaba9c65a236748ed28083d83b224a)
* [text](classmenu_option.md#classmenu_option_1afbd3fb2a0fdb65669ec90f3fecf47623)

## Public attributes

<a id="classmenu_option_on_off_1a64e9dbc45a9b3dba01a0047b75c110f3"></a>
### Variable state

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 80)


```cpp
bool menuOptionOnOff::state
```








**Type**: bool

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menuOptionOnOff::state"}]}`
-->

<a id="classmenu_option_on_off_1aa7eaba9c65a236748ed28083d83b224a"></a>
### Variable statePrinted

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 80)


```cpp
bool menuOptionOnOff::statePrinted
```








**Type**: bool

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menuOptionOnOff::statePrinted"}]}`
-->

## Public functions

<a id="classmenu_option_on_off_1adf4d6bdacf260b366cf6045d60284b7e"></a>
### Function menuOptionOnOff

![][public]


```cpp
menuOptionOnOff::menuOptionOnOff()
```




for compiler puposes, better not to use it



**Return type**: 

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menuOptionOnOff::menuOptionOnOff"}]}`
-->

<a id="classmenu_option_on_off_1ac6eeab4b2b3bd8150614f1123270402c"></a>
### Function menuOptionOnOff

![][public]


```cpp
menuOptionOnOff::menuOptionOnOff(const char *text, bool initValue=false)
```


[menuOptionOnOff](classmenu_option_on_off.md#classmenu_option_on_off) constructor

constructor, sets the caption text, do not use ':', might set init value





might set initial values






**Parameters**:

* **[text](classmenu_option.md#classmenu_option_1afbd3fb2a0fdb65669ec90f3fecf47623)**: string char * used as caoption
* **initValue**: optional initial value



**Parameters**:

* const char * **text**
* bool **initValue** = false 

**Return type**: 

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menuOptionOnOff::menuOptionOnOff"}]}`
-->

<a id="classmenu_option_on_off_1a89f9a031515fbdf8f2b1dd6d8e3a215f"></a>
### Function refresh

![][public]


```cpp
bool menuOptionOnOff::refresh() override
```




inherit to do your thing



**Return type**: bool

**Reimplements**: [refresh](classmenu_option.md#classmenu_option_1acffe6e9fa34a5dc7b77f21d03dd2e446)

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menuOptionOnOff::refresh"}]}`
-->

<a id="classmenu_option_on_off_1aca382e9d72c6e16310c4edfbad47dfc9"></a>
### Function pushRt

![][public]


```cpp
bool menuOptionOnOff::pushRt() override
```




switches state, if inherit, call base [menuOptionOnOff::pushRt()](classmenu_option_on_off.md#classmenu_option_on_off_1aca382e9d72c6e16310c4edfbad47dfc9)



**Return type**: bool

**Reimplements**: [pushRt](classmenu_option.md#classmenu_option_1aeeb4a10bb097059ec82d128beabd8bf1)

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menuOptionOnOff::pushRt"}]}`
-->

<a id="classmenu_option_on_off_1a67c0fa0d940ad4eb83135db93f39ce76"></a>
### Function pushLt

![][public]


```cpp
bool menuOptionOnOff::pushLt() override
```




switches state, if inherit, call base [menuOptionOnOff::pushLt()](classmenu_option_on_off.md#classmenu_option_on_off_1a67c0fa0d940ad4eb83135db93f39ce76)



**Return type**: bool

**Reimplements**: [pushLt](classmenu_option.md#classmenu_option_1ab500086963932ceb473f1ed45ea7d0b4)

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menuOptionOnOff::pushLt"}]}`
-->

<!--
**TODO**:

* `includes  {"type":"element","name":"includes","attributes":{"local":"no","refid":"menu_8h"},"children":[{"type":"text","text":"menu.h"}]}`
-->

[public]: https://img.shields.io/badge/-public-brightgreen (public)
[C++]: https://img.shields.io/badge/language-C%2B%2B-blue (C++)
[private]: https://img.shields.io/badge/-private-red (private)
[static]: https://img.shields.io/badge/-static-lightgrey (static)