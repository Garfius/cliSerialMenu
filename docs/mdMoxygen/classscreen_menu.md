<a id="classscreen_menu"></a>
# Class screenMenu

![][C++]
![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 113)



Screen base class, use addMenuOption to add menuoptions, to be added at menu class, inherit for fancy things like scroll and stuff

## Members

* [addMenuOption](classscreen_menu.md#classscreen_menu_1ac39be07ee1b987443b807e40fc3f80a6)
* [autoRefresh](classscreen_menu.md#classscreen_menu_1ac4679002f46acaf7c5d9918d644540bc)
* [displayMenuOptionsPnt](classscreen_menu.md#classscreen_menu_1ae66ba02dca8eb4450f78b61dba011918)
* [enter](classscreen_menu.md#classscreen_menu_1a516342b40ecb00fe618ae85ade36bd99)
* [hasMoreAbove](classscreen_menu.md#classscreen_menu_1a8dfb32ebda360ae7ec3b7de7c27674a0)
* [hasMoreBelow](classscreen_menu.md#classscreen_menu_1ae2bc759f356a28a9afb2554b2361ca3c)
* [lastSelectedMenuOptionIndex](classscreen_menu.md#classscreen_menu_1a4dd2d3b32bc10b41d99f0041a499f23d)
* [leave](classscreen_menu.md#classscreen_menu_1a85f14fa158d882fc68e8fde5af7b4531)
* [offsetFromTop](classscreen_menu.md#classscreen_menu_1a4d202ebf35e7fa6d5b521deb092f8b53)
* [pushDn](classscreen_menu.md#classscreen_menu_1a090833c1841adba180a32295cc3c3bf4)
* [pushLt](classscreen_menu.md#classscreen_menu_1a577b4ea511ada011a04aaf44e1b69dfb)
* [pushRt](classscreen_menu.md#classscreen_menu_1a5a0d3d3a4e8585d75a19722b1eb2d83f)
* [pushUp](classscreen_menu.md#classscreen_menu_1a45db5e941689e19841fba5f1f2020eaa)
* [refreshMenu](classscreen_menu.md#classscreen_menu_1a0bb1ab6bef4ceef8b01c2b43d2c699a9)
* [run](classscreen_menu.md#classscreen_menu_1aab8c0b36a2a26de729e2d68a884fa488)
* [screenMenu](classscreen_menu.md#classscreen_menu_1a967fbd675991759e15daa700d22edca9)
* [setHasMores](classscreen_menu.md#classscreen_menu_1a68483f4aceab27d379937a8a9455a955)
* [titol](classscreen_menu.md#classscreen_menu_1ae914170aff6a06caf5e099969a3df8b0)
* [totalMenuOptions](classscreen_menu.md#classscreen_menu_1a138bc5500e93900823d015025069547a)
* [whereICame](classscreen_menu.md#classscreen_menu_1a5775cc8907fd684baa18d4df8ab4a22f)

## Public attributes

<a id="classscreen_menu_1a5775cc8907fd684baa18d4df8ab4a22f"></a>
### Variable whereICame

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 116)


```cpp
int screenMenu::whereICame
```




for screen swapping, where i came from



**Type**: int

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"screenMenu::whereICame"}]}`
-->

<a id="classscreen_menu_1ac4679002f46acaf7c5d9918d644540bc"></a>
### Variable autoRefresh

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 117)


```cpp
bool screenMenu::autoRefresh = false
```




tells menu wants periodical refresh



**Type**: bool

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"screenMenu::autoRefresh"}]}`
-->

<a id="classscreen_menu_1a8dfb32ebda360ae7ec3b7de7c27674a0"></a>
### Variable hasMoreAbove

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 118)


```cpp
bool screenMenu::hasMoreAbove = false
```




tells menu wants Up!(msgOptionsUp) to be shown



**Type**: bool

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"screenMenu::hasMoreAbove"}]}`
-->

<a id="classscreen_menu_1ae2bc759f356a28a9afb2554b2361ca3c"></a>
### Variable hasMoreBelow

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 119)


```cpp
bool screenMenu::hasMoreBelow = false
```




tells menu wants Dn!(msgOptionsDn) to be shown



**Type**: bool

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"screenMenu::hasMoreBelow"}]}`
-->

<a id="classscreen_menu_1a138bc5500e93900823d015025069547a"></a>
### Variable totalMenuOptions

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 120)


```cpp
unsigned int screenMenu::totalMenuOptions
```




running time total inserted options/options



**Type**: unsigned int

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"screenMenu::totalMenuOptions"}]}`
-->

<a id="classscreen_menu_1a4d202ebf35e7fa6d5b521deb092f8b53"></a>
### Variable offsetFromTop

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 121)


```cpp
unsigned int screenMenu::offsetFromTop =0
```




to slide down tru menuoptions 'no dinamic-generated scroll', not used on inheritance



**Type**: unsigned int

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"screenMenu::offsetFromTop"}]}`
-->

<a id="classscreen_menu_1a4dd2d3b32bc10b41d99f0041a499f23d"></a>
### Variable lastSelectedMenuOptionIndex

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 122)


```cpp
unsigned int screenMenu::lastSelectedMenuOptionIndex = 0
```








**Type**: unsigned int

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"screenMenu::lastSelectedMenuOptionIndex"}]}`
-->

<a id="classscreen_menu_1ae914170aff6a06caf5e099969a3df8b0"></a>
### Variable titol

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 123)


```cpp
char screenMenu::titol[menuTextArrayLength][menuTextArrayLength]
```




menu caption



**Type**: char

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"screenMenu::titol"}]}`
-->

<a id="classscreen_menu_1ae66ba02dca8eb4450f78b61dba011918"></a>
### Variable displayMenuOptionsPnt

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 124)


```cpp
menuOption* screenMenu::displayMenuOptionsPnt[menuOptionsMax][menuOptionsMax]
```




pointers to menu option/option objects shown , and run by menu



**Type**: [menuOption](classmenu_option.md#classmenu_option) *

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"screenMenu::displayMenuOptionsPnt"}]}`
-->

## Public functions

<a id="classscreen_menu_1a967fbd675991759e15daa700d22edca9"></a>
### Function screenMenu

![][public]


```cpp
screenMenu::screenMenu(const char *text)
```




constructor, sets text, needs menu



**Parameters**:

* const char * **text**

**Return type**: 

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"screenMenu::screenMenu"}]}`
-->

<a id="classscreen_menu_1a68483f4aceab27d379937a8a9455a955"></a>
### Function setHasMores

![][public]


```cpp
void screenMenu::setHasMores()
```




set hasMoreAbove and hasMoreBelow, to be overwriten on self generated children



**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"screenMenu::setHasMores"}]}`
-->

<a id="classscreen_menu_1a45db5e941689e19841fba5f1f2020eaa"></a>
### Function pushUp

![][public]


```cpp
bool screenMenu::pushUp()
```




menu showing us tells to push Up



**Return type**: bool

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"screenMenu::pushUp"}]}`
-->

<a id="classscreen_menu_1a090833c1841adba180a32295cc3c3bf4"></a>
### Function pushDn

![][public]


```cpp
bool screenMenu::pushDn()
```




menu showing us tells to push Dn



**Return type**: bool

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"screenMenu::pushDn"}]}`
-->

<a id="classscreen_menu_1a5a0d3d3a4e8585d75a19722b1eb2d83f"></a>
### Function pushRt

![][public]


```cpp
bool screenMenu::pushRt(unsigned int index)
```




menu showing us tells to push right



**Parameters**:

* unsigned int **index**

**Return type**: bool

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"screenMenu::pushRt"}]}`
-->

<a id="classscreen_menu_1a577b4ea511ada011a04aaf44e1b69dfb"></a>
### Function pushLt

![][public]


```cpp
bool screenMenu::pushLt(unsigned int index)
```




menu showing us tells to push left



**Parameters**:

* unsigned int **index**

**Return type**: bool

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"screenMenu::pushLt"}]}`
-->

<a id="classscreen_menu_1ac39be07ee1b987443b807e40fc3f80a6"></a>
### Function addMenuOption

![][public]


```cpp
bool screenMenu::addMenuOption(menuOption *menuoption)
```








**Parameters**:

* [menuOption](classmenu_option.md#classmenu_option) * **menuoption**

**Return type**: bool

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"screenMenu::addMenuOption"}]}`
-->

<a id="classscreen_menu_1a0bb1ab6bef4ceef8b01c2b43d2c699a9"></a>
### Function refreshMenu

![][public]


```cpp
bool screenMenu::refreshMenu()
```




called when menu changes and periodically if autoRefresh = true



**Return type**: bool

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"screenMenu::refreshMenu"}]}`
-->

<a id="classscreen_menu_1aab8c0b36a2a26de729e2d68a884fa488"></a>
### Function run

![][public]


```cpp
void screenMenu::run(unsigned int index)
```




calls [run()](classscreen_menu.md#classscreen_menu_1aab8c0b36a2a26de729e2d68a884fa488) on the index menuoption



**Parameters**:

* unsigned int **index**

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"screenMenu::run"}]}`
-->

<a id="classscreen_menu_1a85f14fa158d882fc68e8fde5af7b4531"></a>
### Function leave

![][public]


```cpp
void screenMenu::leave()
```




called when leaving screen



**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"screenMenu::leave"}]}`
-->

<a id="classscreen_menu_1a516342b40ecb00fe618ae85ade36bd99"></a>
### Function enter

![][public]


```cpp
void screenMenu::enter()
```




called when entering screen



**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"screenMenu::enter"}]}`
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