---
title: textBoxMenuOption
summary: Base class for menu options that own a multiline text box editor. 

---

# textBoxMenuOption



Base class for menu options that own a multiline text box editor.  [More...](#detailed-description)


`#include <menu.h>`

Inherits from [menuOption](Classes/classmenu_option.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[textBoxMenuOption](Classes/classtext_box_menu_option.md#function-textboxmenuoption)**() |
| | **[textBoxMenuOption](Classes/classtext_box_menu_option.md#function-textboxmenuoption)**(const char * text) |
| virtual void | **[run](Classes/classtext_box_menu_option.md#function-run)**() override |
| virtual bool | **[checkBackgroundEvents](Classes/classtext_box_menu_option.md#function-checkbackgroundevents)**() |
| virtual bool | **[performUserInteraction](Classes/classtext_box_menu_option.md#function-performuserinteraction)**() |

## Additional inherited members

**Public Functions inherited from [menuOption](Classes/classmenu_option.md)**

|                | Name           |
| -------------- | -------------- |
| | **[menuOption](Classes/classmenu_option.md#function-menuoption)**() |
| | **[menuOption](Classes/classmenu_option.md#function-menuoption)**(const char * text) |
| virtual bool | **[refresh](Classes/classmenu_option.md#function-refresh)**() |
| virtual bool | **[pushRt](Classes/classmenu_option.md#function-pushrt)**() |
| virtual bool | **[pushLt](Classes/classmenu_option.md#function-pushlt)**() |

**Public Attributes inherited from [menuOption](Classes/classmenu_option.md)**

|                | Name           |
| -------------- | -------------- |
| char[menuTextArrayLength] | **[text](Classes/classmenu_option.md#variable-text)**  |
| bool | **[autoRefresh](Classes/classmenu_option.md#variable-autorefresh)**  |


## Detailed Description

```cpp
class textBoxMenuOption;
```

Base class for menu options that own a multiline text box editor. 

Inherit this class and override [run()](Classes/classtext_box_menu_option.md#function-run), [checkBackgroundEvents()](Classes/classtext_box_menu_option.md#function-checkbackgroundevents), and [performUserInteraction()](Classes/classtext_box_menu_option.md#function-performuserinteraction) to integrate a text box editing session with the menu system. 

## Public Functions Documentation

### function textBoxMenuOption

```cpp
textBoxMenuOption()
```


for compiler purposes, do not use directly 


### function textBoxMenuOption

```cpp
textBoxMenuOption(
    const char * text
)
```


constructor; sets the caption text 


### function run

```cpp
virtual void run() override
```


**Reimplements**: [menuOption::run](Classes/classmenu_option.md#function-run)


inherit to do your thing 


### function checkBackgroundEvents

```cpp
virtual bool checkBackgroundEvents()
```


**Return**: wether display is needed 

doEvents, textbox still on display, do not use it 


### function performUserInteraction

```cpp
virtual bool performUserInteraction()
```


**Return**: wether textBox editing shall be cancelled 

textBox still active, but not on display, may perform display user interaction 


-------------------------------

Updated on 2026-04-27 at 16:36:45 +0200