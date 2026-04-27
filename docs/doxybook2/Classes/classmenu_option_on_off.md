---
title: menuOptionOnOff

---

# menuOptionOnOff



 [More...](#detailed-description)


`#include <menu.h>`

Inherits from [menuOption](Classes/classmenu_option.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[menuOptionOnOff](Classes/classmenu_option_on_off.md#function-menuoptiononoff)**() |
| | **[menuOptionOnOff](Classes/classmenu_option_on_off.md#function-menuoptiononoff)**(const char * text, bool initValue =false)<br>[menuOptionOnOff](Classes/classmenu_option_on_off.md) constructor  |
| virtual bool | **[refresh](Classes/classmenu_option_on_off.md#function-refresh)**() override |
| virtual bool | **[pushRt](Classes/classmenu_option_on_off.md#function-pushrt)**() override |
| virtual bool | **[pushLt](Classes/classmenu_option_on_off.md#function-pushlt)**() override |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| bool | **[state](Classes/classmenu_option_on_off.md#variable-state)**  |
| bool | **[statePrinted](Classes/classmenu_option_on_off.md#variable-stateprinted)**  |

## Additional inherited members

**Public Functions inherited from [menuOption](Classes/classmenu_option.md)**

|                | Name           |
| -------------- | -------------- |
| | **[menuOption](Classes/classmenu_option.md#function-menuoption)**() |
| | **[menuOption](Classes/classmenu_option.md#function-menuoption)**(const char * text) |
| virtual void | **[run](Classes/classmenu_option.md#function-run)**() |

**Public Attributes inherited from [menuOption](Classes/classmenu_option.md)**

|                | Name           |
| -------------- | -------------- |
| char[menuTextArrayLength] | **[text](Classes/classmenu_option.md#variable-text)**  |
| bool | **[autoRefresh](Classes/classmenu_option.md#variable-autorefresh)**  |


## Detailed Description

```cpp
class menuOptionOnOff;
```


Switch [menuOptionOnOff](Classes/classmenu_option_on_off.md) base class is to be inherited, put your custom code at [run()](Classes/classmenu_option.md#function-run), read state at state Uses ':'([menu.cpp](Files/menu_8cpp.md#file-menu.cpp) menuOptionDelimiter) as separator 

## Public Functions Documentation

### function menuOptionOnOff

```cpp
menuOptionOnOff()
```


for compiler puposes, better not to use it 


### function menuOptionOnOff

```cpp
menuOptionOnOff(
    const char * text,
    bool initValue =false
)
```

[menuOptionOnOff](Classes/classmenu_option_on_off.md) constructor 

**Parameters**: 

  * **[text](Classes/classmenu_option.md#variable-text)** string char * used as caoption 
  * **initValue** optional initial value 


constructor, sets the caption text, do not use ':', might set init value

might set initial values


### function refresh

```cpp
virtual bool refresh() override
```


**Reimplements**: [menuOption::refresh](Classes/classmenu_option.md#function-refresh)


inherit to do your thing 


### function pushRt

```cpp
virtual bool pushRt() override
```


**Reimplements**: [menuOption::pushRt](Classes/classmenu_option.md#function-pushrt)


switches state, if inherit, call base [menuOptionOnOff::pushRt()](Classes/classmenu_option_on_off.md#function-pushrt)


### function pushLt

```cpp
virtual bool pushLt() override
```


**Reimplements**: [menuOption::pushLt](Classes/classmenu_option.md#function-pushlt)


switches state, if inherit, call base [menuOptionOnOff::pushLt()](Classes/classmenu_option_on_off.md#function-pushlt)


## Public Attributes Documentation

### variable state

```cpp
bool state;
```


current on/off state 


### variable statePrinted

```cpp
bool statePrinted;
```


last state that was rendered to the terminal 


-------------------------------

Updated on 2026-04-27 at 16:36:45 +0200