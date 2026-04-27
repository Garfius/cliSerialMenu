---
title: menuOptionRangeValue

---

# menuOptionRangeValue



 [More...](#detailed-description)


`#include <menu.h>`

Inherits from [menuOption](Classes/classmenu_option.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[menuOptionRangeValue](Classes/classmenu_option_range_value.md#function-menuoptionrangevalue)**() |
| | **[menuOptionRangeValue](Classes/classmenu_option_range_value.md#function-menuoptionrangevalue)**(const char * text, int minVal, int maxVal, int initValue, int step =1) |
| virtual bool | **[refresh](Classes/classmenu_option_range_value.md#function-refresh)**() override |
| virtual bool | **[pushRt](Classes/classmenu_option_range_value.md#function-pushrt)**() override |
| virtual bool | **[pushLt](Classes/classmenu_option_range_value.md#function-pushlt)**() override |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| int | **[state](Classes/classmenu_option_range_value.md#variable-state)**  |
| int | **[statePrinted](Classes/classmenu_option_range_value.md#variable-stateprinted)**  |
| int | **[_maxValue](Classes/classmenu_option_range_value.md#variable--maxvalue)**  |
| int | **[_minValue](Classes/classmenu_option_range_value.md#variable--minvalue)**  |
| int | **[_step](Classes/classmenu_option_range_value.md#variable--step)**  |

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
class menuOptionRangeValue;
```


Linear value selector [menuOptionRangeValue](Classes/classmenu_option_range_value.md) base class is to be inherited, put your custom code at [run()](Classes/classmenu_option.md#function-run), read state at state Uses ':' as separator 

## Public Functions Documentation

### function menuOptionRangeValue

```cpp
menuOptionRangeValue()
```


for compiler puposes, better not to use it 


### function menuOptionRangeValue

```cpp
menuOptionRangeValue(
    const char * text,
    int minVal,
    int maxVal,
    int initValue,
    int step =1
)
```


constructor, sets the caption text, do not use ':', maximum, minimum, initial value, might set step 


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


increases state by 1 step(see constructor), if inherit, call base [menuOptionRangeValue::pushRt()](Classes/classmenu_option_range_value.md#function-pushrt)


### function pushLt

```cpp
virtual bool pushLt() override
```


**Reimplements**: [menuOption::pushLt](Classes/classmenu_option.md#function-pushlt)


decreases state by 1 step(see constructor), if inherit, call base [menuOptionRangeValue::pushRt()](Classes/classmenu_option_range_value.md#function-pushrt)


## Public Attributes Documentation

### variable state

```cpp
int state;
```


current value 


### variable statePrinted

```cpp
int statePrinted;
```


last value that was rendered to the terminal 


### variable _maxValue

```cpp
int _maxValue;
```


upper bound of the allowed range 


### variable _minValue

```cpp
int _minValue;
```


lower bound of the allowed range 


### variable _step

```cpp
int _step;
```


amount to increment or decrement per arrow key press 


-------------------------------

Updated on 2026-04-27 at 16:36:45 +0200