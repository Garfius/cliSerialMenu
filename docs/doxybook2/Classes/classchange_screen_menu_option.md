---
title: changeScreenMenuOption

---

# changeScreenMenuOption



 [More...](#detailed-description)


`#include <menu.h>`

Inherits from [menuOption](Classes/classmenu_option.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[changeScreenMenuOption](Classes/classchange_screen_menu_option.md#function-changescreenmenuoption)**([screenMenu](Classes/classscreen_menu.md) * menuDesti) |
| virtual void | **[run](Classes/classchange_screen_menu_option.md#function-run)**() override |
| virtual bool | **[refresh](Classes/classchange_screen_menu_option.md#function-refresh)**() override |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| [screenMenu](Classes/classscreen_menu.md) * | **[_menuDesti](Classes/classchange_screen_menu_option.md#variable--menudesti)**  |

## Additional inherited members

**Public Functions inherited from [menuOption](Classes/classmenu_option.md)**

|                | Name           |
| -------------- | -------------- |
| | **[menuOption](Classes/classmenu_option.md#function-menuoption)**() |
| | **[menuOption](Classes/classmenu_option.md#function-menuoption)**(const char * text) |
| virtual bool | **[pushRt](Classes/classmenu_option.md#function-pushrt)**() |
| virtual bool | **[pushLt](Classes/classmenu_option.md#function-pushlt)**() |

**Public Attributes inherited from [menuOption](Classes/classmenu_option.md)**

|                | Name           |
| -------------- | -------------- |
| char[menuTextArrayLength] | **[text](Classes/classmenu_option.md#variable-text)**  |
| bool | **[autoRefresh](Classes/classmenu_option.md#variable-autorefresh)**  |


## Detailed Description

```cpp
class changeScreenMenuOption;
```


Utility menuoption used to change the displayed [screenMenu](Classes/classscreen_menu.md), no need to customize or 

## Public Functions Documentation

### function changeScreenMenuOption

```cpp
changeScreenMenuOption(
    screenMenu * menuDesti
)
```


constructor needs target screen to jump to 


### function run

```cpp
virtual void run() override
```


**Reimplements**: [menuOption::run](Classes/classmenu_option.md#function-run)


to be called by menu 


### function refresh

```cpp
virtual bool refresh() override
```


**Reimplements**: [menuOption::refresh](Classes/classmenu_option.md#function-refresh)


to be called by menu 


## Public Attributes Documentation

### variable _menuDesti

```cpp
screenMenu * _menuDesti;
```


pointer to the target [screenMenu](Classes/classscreen_menu.md) to navigate to 


-------------------------------

Updated on 2026-04-27 at 16:36:45 +0200