# menu.cpp File Reference {#_menu_8cpp}

menu.cpp

Code for [menu.h](#_menu_8h).

    #include "menu.h"

## Classes {.unnumbered}

-   class [CharBuffer](#_class_char_buffer)

## Macros {.unnumbered}

-   []{#_menu_8cpp_1a8c877b00dc535facfa2f3b35b1b74b7f}#define
    **menuOptionDelimiter**   \':\'

-   []{#_menu_8cpp_1a4b8e37dc95cdf19253602512c729c8dc}#define
    **cliMsgWait**   1250

-   []{#_menu_8cpp_1a5821e981efec035ed35549f99ab2d8d6}#define
    **menuRefreshInterval**   250

## Variables {.unnumbered}

-   []{#_menu_8cpp_1a4675348869a81e85e179f090ba3329df}[CharBuffer](#_class_char_buffer)
    **buffer**

-   []{#_menu_8cpp_1a58aa1cbda0d0701af5cd55568509cd68}[menuTextBox](#_classmenu_text_box)
    **menuSystemOverTty**

-   []{#_menu_8cpp_1a2e8e5a0db1e23bfacce9ac4ad19e69e9}[menuTextBox](#_classmenu_text_box)
    \* **menuSystemOverTtyP** = &menuSystemOverTty

## Detailed Description

Code for [menu.h](#_menu_8h).

Might want to change some preprocessor directives to customize
beheaviour

::: formalpara-title
**Author**
:::

Gerard Forcada Bigas

::: formalpara-title
**Date**
:::

20/12/22
