# changeScreenMenuOption Class Reference {#_classchange_screen_menu_option}

changeScreenMenuOption

`#include <menu.h>`

Inheritance diagram for changeScreenMenuOption:

![image](classchange_screen_menu_option.png){width="50%"}

## Public Member Functions {.unnumbered}

-   [changeScreenMenuOption](#_classchange_screen_menu_option_1a178520a15032de0f8c65d531207430c4)
    ([screenMenu](#_classscreen_menu) \*menuDesti)

-   void
    [run](#_classchange_screen_menu_option_1a83972fdbfcda7b9f6cc9ae8eb9feb580)
    () override

-   bool
    [refresh](#_classchange_screen_menu_option_1ac3f7c0cc125172f8cd3ec286639ba4d4)
    () override

Public Member Functions inherited from

menuOption

-   [menuOption](#_classmenu_option_1a39a33397bfc7e6f57bdf3e2ccf8eb21c)
    ()

-   [menuOption](#_classmenu_option_1af1f55f3fdf6764f94f7d5dd59e149d6a)
    (const char
    \*[text](#_classmenu_option_1afbd3fb2a0fdb65669ec90f3fecf47623))

-   virtual bool
    [pushRt](#_classmenu_option_1aeeb4a10bb097059ec82d128beabd8bf1) ()

-   virtual bool
    [pushLt](#_classmenu_option_1ab500086963932ceb473f1ed45ea7d0b4) ()

## Public Attributes {.unnumbered}

-   []{#_classchange_screen_menu_option_1aed964956ed11f6d935eeabbe3dfed80e}[screenMenu](#_classscreen_menu)
    \* **\_menuDesti**

Public Attributes inherited from

menuOption

-   char [text](#_classmenu_option_1afbd3fb2a0fdb65669ec90f3fecf47623)
    \[menuTextArrayLength\]

-   bool
    [autoRefresh](#_classmenu_option_1a610ed80a3027cac149f9da18ba53a82f)
    = true

## Detailed Description

Utility menuoption used to change the displayed
[screenMenu](#_classscreen_menu), no need to customize or

## Constructor & Destructor Documentation

### changeScreenMenuOption()

changeScreenMenuOption

changeScreenMenuOption

changeScreenMenuOption

changeScreenMenuOption

`changeScreenMenuOption::changeScreenMenuOption (screenMenu * menuDesti)`

constructor needs target screen to jump to

## Member Function Documentation

### refresh()

refresh

changeScreenMenuOption

changeScreenMenuOption

refresh

`bool changeScreenMenuOption::refresh ( )[override], [virtual]`

to be called by menu

Reimplemented from
[menuOption](#_classmenu_option_1acffe6e9fa34a5dc7b77f21d03dd2e446).

### run()

run

changeScreenMenuOption

changeScreenMenuOption

run

`void changeScreenMenuOption::run ( )[override], [virtual]`

to be called by menu

Reimplemented from
[menuOption](#_classmenu_option_1a685680a783d26033f6e8cdb6eeab3a99).

The documentation for this class was generated from the following files:

menu.h

menu.cpp
