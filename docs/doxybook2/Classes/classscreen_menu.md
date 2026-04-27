---
title: screenMenu

---

# screenMenu



 [More...](#detailed-description)


`#include <menu.h>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[screenMenu](Classes/classscreen_menu.md#function-screenmenu)**(const char * text) |
| virtual void | **[setHasMores](Classes/classscreen_menu.md#function-sethasmores)**() |
| virtual bool | **[pushUp](Classes/classscreen_menu.md#function-pushup)**() |
| virtual bool | **[pushDn](Classes/classscreen_menu.md#function-pushdn)**() |
| virtual bool | **[pushRt](Classes/classscreen_menu.md#function-pushrt)**(unsigned int index) |
| virtual bool | **[pushLt](Classes/classscreen_menu.md#function-pushlt)**(unsigned int index) |
| virtual bool | **[addMenuOption](Classes/classscreen_menu.md#function-addmenuoption)**([menuOption](Classes/classmenu_option.md) * menuoption) |
| virtual bool | **[refreshMenu](Classes/classscreen_menu.md#function-refreshmenu)**() |
| virtual void | **[run](Classes/classscreen_menu.md#function-run)**(unsigned int index) |
| virtual void | **[leave](Classes/classscreen_menu.md#function-leave)**() |
| virtual void | **[enter](Classes/classscreen_menu.md#function-enter)**() |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| int | **[whereICame](Classes/classscreen_menu.md#variable-whereicame)**  |
| bool | **[autoRefresh](Classes/classscreen_menu.md#variable-autorefresh)**  |
| bool | **[hasMoreAbove](Classes/classscreen_menu.md#variable-hasmoreabove)**  |
| bool | **[hasMoreBelow](Classes/classscreen_menu.md#variable-hasmorebelow)**  |
| unsigned int | **[totalMenuOptions](Classes/classscreen_menu.md#variable-totalmenuoptions)**  |
| unsigned int | **[offsetFromTop](Classes/classscreen_menu.md#variable-offsetfromtop)**  |
| unsigned int | **[lastSelectedMenuOptionIndex](Classes/classscreen_menu.md#variable-lastselectedmenuoptionindex)**  |
| char[menuTextArrayLength] | **[titol](Classes/classscreen_menu.md#variable-titol)**  |
| [menuOption](Classes/classmenu_option.md) *[menuOptionsMax] | **[displayMenuOptionsPnt](Classes/classscreen_menu.md#variable-displaymenuoptionspnt)**  |

## Detailed Description

```cpp
class screenMenu;
```


Screen base class, use addMenuOption to add menuoptions, to be added at menu class, inherit for fancy things like scroll and stuff 

## Public Functions Documentation

### function screenMenu

```cpp
screenMenu(
    const char * text
)
```


constructor, sets text, needs menu 


### function setHasMores

```cpp
virtual void setHasMores()
```


set hasMoreAbove and hasMoreBelow, to be overwriten on self generated children 


### function pushUp

```cpp
virtual bool pushUp()
```


menu showing us tells to push Up 


### function pushDn

```cpp
virtual bool pushDn()
```


menu showing us tells to push Dn 


### function pushRt

```cpp
virtual bool pushRt(
    unsigned int index
)
```


menu showing us tells to push right 


### function pushLt

```cpp
virtual bool pushLt(
    unsigned int index
)
```


menu showing us tells to push left 


### function addMenuOption

```cpp
virtual bool addMenuOption(
    menuOption * menuoption
)
```


adds a [menuOption](Classes/classmenu_option.md) pointer to this screen; returns false if menuOptionsMax is reached 


### function refreshMenu

```cpp
virtual bool refreshMenu()
```


called when menu changes and periodically if autoRefresh = true 


### function run

```cpp
virtual void run(
    unsigned int index
)
```


calls [run()](Classes/classscreen_menu.md#function-run) on the index menuoption 


### function leave

```cpp
virtual void leave()
```


called when leaving screen 


### function enter

```cpp
virtual void enter()
```


called when entering screen 


## Public Attributes Documentation

### variable whereICame

```cpp
int whereICame;
```


for screen swapping, where i came from 


### variable autoRefresh

```cpp
bool autoRefresh = false;
```


tells menu wants periodical refresh 


### variable hasMoreAbove

```cpp
bool hasMoreAbove = false;
```


tells menu wants Up!(msgOptionsUp) to be shown 


### variable hasMoreBelow

```cpp
bool hasMoreBelow = false;
```


tells menu wants Dn!(msgOptionsDn) to be shown 


### variable totalMenuOptions

```cpp
unsigned int totalMenuOptions;
```


running time total inserted options/options 


### variable offsetFromTop

```cpp
unsigned int offsetFromTop =0;
```


to slide down tru menuoptions 'no dinamic-generated scroll', not used on inheritance 


### variable lastSelectedMenuOptionIndex

```cpp
unsigned int lastSelectedMenuOptionIndex = 0;
```


remembers the highlighted option index when returning to this screen 


### variable titol

```cpp
char[menuTextArrayLength] titol;
```


menu caption 


### variable displayMenuOptionsPnt

```cpp
menuOption *[menuOptionsMax] displayMenuOptionsPnt;
```


pointers to menu option/option objects shown , and run by menu 


-------------------------------

Updated on 2026-04-27 at 16:36:45 +0200