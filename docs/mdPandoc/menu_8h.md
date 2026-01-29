# menu.h File Reference {#_menu_8h}

menu.h

here are the menuSystemOverTty object and it\'s friends.

    #include "terminalParser.h"#include <Arduino.h>

## Classes {.unnumbered}

-   class [menuOption](#_classmenu_option)

-   class [menuOptionOnOff](#_classmenu_option_on_off)

-   class [menuOptionRangeValue](#_classmenu_option_range_value)

-   class [changeScreenMenuOption](#_classchange_screen_menu_option)

-   class [screenMenu](#_classscreen_menu)

-   class [menu](#_classmenu)

-   class [textBoxMenuOption](#_classtext_box_menu_option)

-   class [menuTextBox](#_classmenu_text_box)

## Macros {.unnumbered}

-   []{#_menu_8h_1aecf7b06440356b5a9a90ab2520a596db}#define
    **terminalSizeMaxQueries**   4

-   []{#_menu_8h_1ab5c1e7d4bb061144388db2e422abdbf6}#define
    **\_MENU_UI_BIG_RAM\_**

-   []{#_menu_8h_1ad0afcf7c19728a83e8055bf451d2010b}#define
    **screenMenuMax**   6

-   []{#_menu_8h_1ac76587272a788bb7757770f3ced7be23}#define
    **menuTextArrayLength**   80

-   []{#_menu_8h_1a72288823988215a55a00dc40ea61a0b1}#define
    **menuOptionsMax**   12

-   []{#_menu_8h_1a17fa68dadf757bd048564eb1b0a79836}#define
    **displayMenuOptionsDefault**   8

-   []{#_menu_8h_1ac703e8b9cfab10feb6bd75e4c9a66956}#define
    **minTextBoxWidth**   4

-   []{#_menu_8h_1aa539a3070300aef5ea0b1661f0a9961b}#define
    **escBackMillisecondsDelay**   450

-   []{#_menu_8h_1a747a09c3da30256f1b70e735b6a7a0e7}#define
    **defaultTextBoxWidth**   20

-   []{#_menu_8h_1a4a0fbf9bba11658946fe94d48c205c11}#define
    **menuTextLength**   (menuTextArrayLength-1)

-   #define
    [queryterminalSizeTimeout](#_menu_8h_1aa0a17a95ab131571df9a625fd74ffe1c)   250UL

-   []{#_menu_8h_1a440b4791067da0672e4b3b049f3c25bb}#define
    **userInputLag**   50

-   []{#_menu_8h_1aa9b8dcc02cea15aab8e3d0b7860327a7}#define
    **INPUT_BUFFER_SIZE**   320

## Enumerations {.unnumbered}

-   []{#_menu_8h_1ac4a84be0bf2a19771281a6659df073f5}enum
    **textBoxStatus** { **noExit** , **activeEditor** ,
    **softwareAborted** , **escPressed** , **enterPressed** , **error**
    }

## Variables {.unnumbered}

-   []{#_menu_8h_1a58aa1cbda0d0701af5cd55568509cd68}[menuTextBox](#_classmenu_text_box)
    **menuSystemOverTty**

-   []{#_menu_8h_1a2e8e5a0db1e23bfacce9ac4ad19e69e9}[menuTextBox](#_classmenu_text_box)
    \* **menuSystemOverTtyP**

## Detailed Description

here are the menuSystemOverTty object and it\'s friends.

This library makes intensive use of object-oriented programming. All the
object definitions of menuSystemOverTty base objects to be inherited as
customizations. Here are the menuSystemOverTty manager oject, and the
base objects which to inherit to create custom menus,

::: formalpara-title
**Author**
:::

Gerard Forcada Bigas

::: formalpara-title
**Date**
:::

17/10/24

## Macro Definition Documentation

### queryterminalSizeTimeout

queryterminalSizeTimeout

menu.h

menu.h

queryterminalSizeTimeout

`#define queryterminalSizeTimeout 250UL`

milliseconds to wait for terminal size report
