# screenMenu Class Reference {#_classscreen_menu}

screenMenu

`#include <menu.h>`

## Public Member Functions {.unnumbered}

-   [screenMenu](#_classscreen_menu_1a967fbd675991759e15daa700d22edca9)
    (const char \*text)

-   virtual void
    [setHasMores](#_classscreen_menu_1a68483f4aceab27d379937a8a9455a955)
    ()

-   virtual bool
    [pushUp](#_classscreen_menu_1a45db5e941689e19841fba5f1f2020eaa) ()

-   virtual bool
    [pushDn](#_classscreen_menu_1a090833c1841adba180a32295cc3c3bf4) ()

-   virtual bool
    [pushRt](#_classscreen_menu_1a5a0d3d3a4e8585d75a19722b1eb2d83f)
    (unsigned int index)

-   virtual bool
    [pushLt](#_classscreen_menu_1a577b4ea511ada011a04aaf44e1b69dfb)
    (unsigned int index)

-   []{#_classscreen_menu_1ac39be07ee1b987443b807e40fc3f80a6}virtual
    bool **addMenuOption** ([menuOption](#_classmenu_option)
    \*menuoption)

-   virtual bool
    [refreshMenu](#_classscreen_menu_1a0bb1ab6bef4ceef8b01c2b43d2c699a9)
    ()

-   virtual void
    [run](#_classscreen_menu_1aab8c0b36a2a26de729e2d68a884fa488)
    (unsigned int index)

-   virtual void
    [leave](#_classscreen_menu_1a85f14fa158d882fc68e8fde5af7b4531) ()

-   virtual void
    [enter](#_classscreen_menu_1a516342b40ecb00fe618ae85ade36bd99) ()

## Public Attributes {.unnumbered}

-   int
    [whereICame](#_classscreen_menu_1a5775cc8907fd684baa18d4df8ab4a22f)

-   bool
    [autoRefresh](#_classscreen_menu_1ac4679002f46acaf7c5d9918d644540bc)
    = false

-   bool
    [hasMoreAbove](#_classscreen_menu_1a8dfb32ebda360ae7ec3b7de7c27674a0)
    = false

-   bool
    [hasMoreBelow](#_classscreen_menu_1ae2bc759f356a28a9afb2554b2361ca3c)
    = false

-   unsigned int
    [totalMenuOptions](#_classscreen_menu_1a138bc5500e93900823d015025069547a)

-   unsigned int
    [offsetFromTop](#_classscreen_menu_1a4d202ebf35e7fa6d5b521deb092f8b53)
    =0

-   []{#_classscreen_menu_1a4dd2d3b32bc10b41d99f0041a499f23d}unsigned
    int **lastSelectedMenuOptionIndex** = 0

-   char [titol](#_classscreen_menu_1ae914170aff6a06caf5e099969a3df8b0)
    \[menuTextArrayLength\]

-   [menuOption](#_classmenu_option) \*
    [displayMenuOptionsPnt](#_classscreen_menu_1ae66ba02dca8eb4450f78b61dba011918)
    \[menuOptionsMax\]

## Detailed Description

Screen base class, use addMenuOption to add menuoptions, to be added at
menu class, inherit for fancy things like scroll and stuff

## Constructor & Destructor Documentation

### screenMenu()

screenMenu

screenMenu

screenMenu

screenMenu

`screenMenu::screenMenu (const char * text)`

constructor, sets text, needs menu

## Member Function Documentation

### enter()

enter

screenMenu

screenMenu

enter

`void screenMenu::enter ( )[virtual]`

called when entering screen

### leave()

leave

screenMenu

screenMenu

leave

`void screenMenu::leave ( )[virtual]`

called when leaving screen

### pushDn()

pushDn

screenMenu

screenMenu

pushDn

`bool screenMenu::pushDn ( )[virtual]`

menu showing us tells to push Dn

### pushLt()

pushLt

screenMenu

screenMenu

pushLt

`bool screenMenu::pushLt (unsigned int index)[virtual]`

menu showing us tells to push left

### pushRt()

pushRt

screenMenu

screenMenu

pushRt

`bool screenMenu::pushRt (unsigned int index)[virtual]`

menu showing us tells to push right

### pushUp()

pushUp

screenMenu

screenMenu

pushUp

`bool screenMenu::pushUp ( )[virtual]`

menu showing us tells to push Up

### refreshMenu()

refreshMenu

screenMenu

screenMenu

refreshMenu

`bool screenMenu::refreshMenu ( )[virtual]`

called when menu changes and periodically if autoRefresh = true

### run()

run

screenMenu

screenMenu

run

`void screenMenu::run (unsigned int index)[virtual]`

calls [run()](#_classscreen_menu_1aab8c0b36a2a26de729e2d68a884fa488) on
the index menuoption

### setHasMores()

setHasMores

screenMenu

screenMenu

setHasMores

`void screenMenu::setHasMores ( )[virtual]`

set hasMoreAbove and hasMoreBelow, to be overwriten on self generated
children

## Member Data Documentation

### autoRefresh

autoRefresh

screenMenu

screenMenu

autoRefresh

`bool screenMenu::autoRefresh = false`

tells menu wants periodical refresh

### displayMenuOptionsPnt

displayMenuOptionsPnt

screenMenu

screenMenu

displayMenuOptionsPnt

`menuOption* screenMenu::displayMenuOptionsPnt[menuOptionsMax]`

pointers to menu option/option objects shown , and run by menu

### hasMoreAbove

hasMoreAbove

screenMenu

screenMenu

hasMoreAbove

`bool screenMenu::hasMoreAbove = false`

tells menu wants Up!(msgOptionsUp) to be shown

### hasMoreBelow

hasMoreBelow

screenMenu

screenMenu

hasMoreBelow

`bool screenMenu::hasMoreBelow = false`

tells menu wants Dn!(msgOptionsDn) to be shown

### offsetFromTop

offsetFromTop

screenMenu

screenMenu

offsetFromTop

`unsigned int screenMenu::offsetFromTop =0`

to slide down tru menuoptions \'no dinamic-generated scroll\', not used
on inheritance

### titol

titol

screenMenu

screenMenu

titol

`char screenMenu::titol[menuTextArrayLength]`

menu caption

### totalMenuOptions

totalMenuOptions

screenMenu

screenMenu

totalMenuOptions

`unsigned int screenMenu::totalMenuOptions`

running time total inserted options/options

### whereICame

whereICame

screenMenu

screenMenu

whereICame

`int screenMenu::whereICame`

for screen swapping, where i came from

The documentation for this class was generated from the following files:

menu.h

menu.cpp
