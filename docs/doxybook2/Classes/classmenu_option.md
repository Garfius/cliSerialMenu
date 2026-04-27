---
title: menuOption

---

# menuOption



 [More...](#detailed-description)


`#include <menu.h>`

Inherited by [changeScreenMenuOption](Classes/classchange_screen_menu_option.md), [menuOptionOnOff](Classes/classmenu_option_on_off.md), [menuOptionRangeValue](Classes/classmenu_option_range_value.md), [textBoxMenuOption](Classes/classtext_box_menu_option.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[menuOption](Classes/classmenu_option.md#function-menuoption)**() |
| | **[menuOption](Classes/classmenu_option.md#function-menuoption)**(const char * text) |
| virtual void | **[run](Classes/classmenu_option.md#function-run)**() |
| virtual bool | **[refresh](Classes/classmenu_option.md#function-refresh)**() |
| virtual bool | **[pushRt](Classes/classmenu_option.md#function-pushrt)**() |
| virtual bool | **[pushLt](Classes/classmenu_option.md#function-pushlt)**() |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| char[menuTextArrayLength] | **[text](Classes/classmenu_option.md#variable-text)**  |
| bool | **[autoRefresh](Classes/classmenu_option.md#variable-autorefresh)**  |

## Detailed Description

```cpp
class menuOption;
```


Simplest [menuOption](Classes/classmenu_option.md) base class, is to be inherited, put your custom code at [run()](Classes/classmenu_option.md#function-run)

## Public Functions Documentation

### function menuOption

```cpp
menuOption()
```


for compiler puposes, better not to use it 


### function menuOption

```cpp
menuOption(
    const char * text
)
```


constructor, sets the caption text 


### function run

```cpp
virtual void run()
```


**Reimplemented by**: [changeScreenMenuOption::run](Classes/classchange_screen_menu_option.md#function-run), [textBoxMenuOption::run](Classes/classtext_box_menu_option.md#function-run)


inherit to do your thing 


### function refresh

```cpp
virtual bool refresh()
```


**Reimplemented by**: [changeScreenMenuOption::refresh](Classes/classchange_screen_menu_option.md#function-refresh), [menuOptionOnOff::refresh](Classes/classmenu_option_on_off.md#function-refresh), [menuOptionRangeValue::refresh](Classes/classmenu_option_range_value.md#function-refresh)


called when autoRefresh is set here and [screenMenu](Classes/classscreen_menu.md)


### function pushRt

```cpp
virtual bool pushRt()
```


**Reimplemented by**: [menuOptionOnOff::pushRt](Classes/classmenu_option_on_off.md#function-pushrt), [menuOptionRangeValue::pushRt](Classes/classmenu_option_range_value.md#function-pushrt)


called then right arrow is pressed 


### function pushLt

```cpp
virtual bool pushLt()
```


**Reimplemented by**: [menuOptionOnOff::pushLt](Classes/classmenu_option_on_off.md#function-pushlt), [menuOptionRangeValue::pushLt](Classes/classmenu_option_range_value.md#function-pushlt)


called then left left is pressed 


## Public Attributes Documentation

### variable text

```cpp
char[menuTextArrayLength] text;
```


Caption 


### variable autoRefresh

```cpp
bool autoRefresh = true;
```


wants [refresh()](Classes/classmenu_option.md#function-refresh) to be called 


-------------------------------

Updated on 2026-04-27 at 16:36:45 +0200