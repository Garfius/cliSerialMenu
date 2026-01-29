<a id="classchange_screen_menu_option"></a>
# Class changeScreenMenuOption

![][C++]
![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 103)



Utility menuoption used to change the displayed [screenMenu](classscreen_menu.md#classscreen_menu), no need to customize or

**Inherits from**:

* [menuOption](classmenu_option.md#classmenu_option)

## Members

* [\_menuDesti](classchange_screen_menu_option.md#classchange_screen_menu_option_1aed964956ed11f6d935eeabbe3dfed80e)
* [autoRefresh](classmenu_option.md#classmenu_option_1a610ed80a3027cac149f9da18ba53a82f)
* [changeScreenMenuOption](classchange_screen_menu_option.md#classchange_screen_menu_option_1a178520a15032de0f8c65d531207430c4)
* [menuOption](classmenu_option.md#classmenu_option_1a39a33397bfc7e6f57bdf3e2ccf8eb21c)
* [menuOption](classmenu_option.md#classmenu_option_1af1f55f3fdf6764f94f7d5dd59e149d6a)
* [pushLt](classmenu_option.md#classmenu_option_1ab500086963932ceb473f1ed45ea7d0b4)
* [pushRt](classmenu_option.md#classmenu_option_1aeeb4a10bb097059ec82d128beabd8bf1)
* [refresh](classchange_screen_menu_option.md#classchange_screen_menu_option_1ac3f7c0cc125172f8cd3ec286639ba4d4)
* [run](classchange_screen_menu_option.md#classchange_screen_menu_option_1a83972fdbfcda7b9f6cc9ae8eb9feb580)
* [text](classmenu_option.md#classmenu_option_1afbd3fb2a0fdb65669ec90f3fecf47623)

## Public attributes

<a id="classchange_screen_menu_option_1aed964956ed11f6d935eeabbe3dfed80e"></a>
### Variable \_menuDesti

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 105)


```cpp
screenMenu* changeScreenMenuOption::_menuDesti
```








**Type**: [screenMenu](classscreen_menu.md#classscreen_menu) *

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"changeScreenMenuOption::_menuDesti"}]}`
-->

## Public functions

<a id="classchange_screen_menu_option_1a178520a15032de0f8c65d531207430c4"></a>
### Function changeScreenMenuOption

![][public]


```cpp
changeScreenMenuOption::changeScreenMenuOption(screenMenu *menuDesti)
```




constructor needs target screen to jump to



**Parameters**:

* [screenMenu](classscreen_menu.md#classscreen_menu) * **menuDesti**

**Return type**: 

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"changeScreenMenuOption::changeScreenMenuOption"}]}`
-->

<a id="classchange_screen_menu_option_1a83972fdbfcda7b9f6cc9ae8eb9feb580"></a>
### Function run

![][public]


```cpp
void changeScreenMenuOption::run() override
```




to be called by menu



**Return type**: void

**Reimplements**: [run](classmenu_option.md#classmenu_option_1a685680a783d26033f6e8cdb6eeab3a99)

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"changeScreenMenuOption::run"}]}`
-->

<a id="classchange_screen_menu_option_1ac3f7c0cc125172f8cd3ec286639ba4d4"></a>
### Function refresh

![][public]


```cpp
bool changeScreenMenuOption::refresh() override
```




to be called by menu



**Return type**: bool

**Reimplements**: [refresh](classmenu_option.md#classmenu_option_1acffe6e9fa34a5dc7b77f21d03dd2e446)

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"changeScreenMenuOption::refresh"}]}`
-->

<!--
**TODO**:

* `includes  {"type":"element","name":"includes","attributes":{"local":"no","refid":"menu_8h"},"children":[{"type":"text","text":"menu.h"}]}`
-->

[public]: https://img.shields.io/badge/-public-brightgreen (public)
[C++]: https://img.shields.io/badge/language-C%2B%2B-blue (C++)