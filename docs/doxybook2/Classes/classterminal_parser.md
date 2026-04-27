---
title: terminalParser

---

# terminalParser



 [More...](#detailed-description)


`#include <terminalParser.h>`

Inherited by [menu](Classes/classmenu.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| virtual void | **[doClearScreen](Classes/classterminal_parser.md#function-doclearscreen)**() |
| virtual void | **[doMoveCursor](Classes/classterminal_parser.md#function-domovecursor)**(int line, int column) |
| virtual void | **[doCUU](Classes/classterminal_parser.md#function-docuu)**(unsigned int amount =1) |
| virtual void | **[doCUD](Classes/classterminal_parser.md#function-docud)**(unsigned int amount =1) |
| virtual void | **[doCUF](Classes/classterminal_parser.md#function-docuf)**(unsigned int amount =1) |
| virtual void | **[doCUB](Classes/classterminal_parser.md#function-docub)**(unsigned int amount =1) |
| virtual void | **[doEL](Classes/classterminal_parser.md#function-doel)**(int operation =2) |
| virtual void | **[doHideCursor](Classes/classterminal_parser.md#function-dohidecursor)**(bool hide =true) |
| void | **[invertColors](Classes/classterminal_parser.md#function-invertcolors)**(char * entrada, unsigned int allargadaMax) |
| void | **[invertColors](Classes/classterminal_parser.md#function-invertcolors)**(String * cadena) |
| virtual void | **[init](Classes/classterminal_parser.md#function-init)**(Stream * pantalla) |
| | **[terminalParser](Classes/classterminal_parser.md#function-terminalparser)**() |
| bool | **[doGuess](Classes/classterminal_parser.md#function-doguess)**(char caracter) |
| virtual void | **[tab](Classes/classterminal_parser.md#function-tab)**() |
| virtual void | **[lf](Classes/classterminal_parser.md#function-lf)**() |
| virtual void | **[cr](Classes/classterminal_parser.md#function-cr)**() |
| virtual void | **[backSpace](Classes/classterminal_parser.md#function-backspace)**() |
| virtual void | **[beep](Classes/classterminal_parser.md#function-beep)**() |
| virtual void | **[del](Classes/classterminal_parser.md#function-del)**() |
| virtual void | **[insert](Classes/classterminal_parser.md#function-insert)**(bool setDisplayInsert =false) |
| virtual void | **[start](Classes/classterminal_parser.md#function-start)**() |
| virtual void | **[end](Classes/classterminal_parser.md#function-end)**() |
| virtual void | **[avPg](Classes/classterminal_parser.md#function-avpg)**() |
| virtual void | **[rePg](Classes/classterminal_parser.md#function-repg)**() |
| virtual void | **[cHA](Classes/classterminal_parser.md#function-cha)**(unsigned int argc, int * argv) |
| virtual void | **[cUU](Classes/classterminal_parser.md#function-cuu)**(unsigned int argc, int * argv) |
| virtual void | **[cUD](Classes/classterminal_parser.md#function-cud)**(unsigned int argc, int * argv) |
| virtual void | **[cUF](Classes/classterminal_parser.md#function-cuf)**(unsigned int argc, int * argv) |
| virtual void | **[cUB](Classes/classterminal_parser.md#function-cub)**(unsigned int argc, int * argv) |
| virtual void | **[eL](Classes/classterminal_parser.md#function-el)**(unsigned int argc, int * argv) |
| virtual void | **[sGR](Classes/classterminal_parser.md#function-sgr)**(unsigned int argc, int * argv) |
| virtual void | **[dSR](Classes/classterminal_parser.md#function-dsr)**(unsigned int argc, int * argv) |
| virtual void | **[rM](Classes/classterminal_parser.md#function-rm)**(unsigned int argc, int * argv) |
| virtual void | **[sM](Classes/classterminal_parser.md#function-sm)**(unsigned int argc, int * argv) |
| virtual void | **[dA](Classes/classterminal_parser.md#function-da)**(unsigned int argc, int * argv) |
| virtual void | **[cUP](Classes/classterminal_parser.md#function-cup)**(unsigned int argc, int * argv) |
| virtual void | **[eD](Classes/classterminal_parser.md#function-ed)**(unsigned int argc, int * argv) |
| virtual void | **[vPA](Classes/classterminal_parser.md#function-vpa)**(unsigned int argc, int * argv) |
| virtual void | **[dCH](Classes/classterminal_parser.md#function-dch)**(unsigned int argc, int * argv) |
| virtual void | **[cPR](Classes/classterminal_parser.md#function-cpr)**(unsigned int argc, int * argv) |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| bool | **[insertStatus](Classes/classterminal_parser.md#variable-insertstatus)**  |
| Stream * | **[userTty](Classes/classterminal_parser.md#variable-usertty)**  |

## Detailed Description

```cpp
class terminalParser;
```


Base class which processes a stream, calling Ansi escape codes named function 

## Public Functions Documentation

### function doClearScreen

```cpp
virtual void doClearScreen()
```


clear stream console

Clear screen 


### function doMoveCursor

```cpp
virtual void doMoveCursor(
    int line,
    int column
)
```


sends the move cursor command to stream console

Cursor position report void terminalParser::askDisplaySize(){//DSR userTty->write("\e[6n"); } Cursor Position, inherited from [terminalParser](Classes/classterminal_parser.md)


### function doCUU

```cpp
virtual void doCUU(
    unsigned int amount =1
)
```


moves the cursor up amount positions 


### function doCUD

```cpp
virtual void doCUD(
    unsigned int amount =1
)
```


moves the cursor down amount positions 


### function doCUF

```cpp
virtual void doCUF(
    unsigned int amount =1
)
```


moves the cursor forward amount positions 


### function doCUB

```cpp
virtual void doCUB(
    unsigned int amount =1
)
```


moves the cursor back amount positions 


### function doEL

```cpp
virtual void doEL(
    int operation =2
)
```


erase line: 0=cursor to end, 1=start to cursor, 2=whole line

ESC [ 0 K: erase from cursor to end of line. ESC [ 1 K: erase from start of line to cursor. ESC [ 2 K: erase whole line. 


### function doHideCursor

```cpp
virtual void doHideCursor(
    bool hide =true
)
```


hodes or unhides cursor 


### function invertColors

```cpp
void invertColors(
    char * entrada,
    unsigned int allargadaMax
)
```


wraps the string in invert color escape codes 


### function invertColors

```cpp
void invertColors(
    String * cadena
)
```


wraps the string in invert color escape codes 


### function init

```cpp
virtual void init(
    Stream * pantalla
)
```


**Reimplemented by**: [menu::init](Classes/classmenu.md#function-init)


needs the serial port where to be found a console VT100/ANSI terminal style Aka. Putty/teraTerm/... 


### function terminalParser

```cpp
terminalParser()
```


### function doGuess

```cpp
bool doGuess(
    char caracter
)
```


Parses a character, triggers any function which might correspond regarding previous parsed characters, and returns true if belongs to screen 


### function tab

```cpp
virtual void tab()
```


tabulador 


### function lf

```cpp
virtual void lf()
```


**Reimplemented by**: [menuTextBox::lf](Classes/classmenu_text_box.md#function-lf)


line forward 


### function cr

```cpp
virtual void cr()
```


**Reimplemented by**: [menu::cr](Classes/classmenu.md#function-cr), [menuTextBox::cr](Classes/classmenu_text_box.md#function-cr)


catrriage return 


### function backSpace

```cpp
virtual void backSpace()
```


**Reimplemented by**: [menuTextBox::backSpace](Classes/classmenu_text_box.md#function-backspace)


backspace pressed 


### function beep

```cpp
virtual void beep()
```


beep received 


### function del

```cpp
virtual void del()
```


**Reimplemented by**: [menuTextBox::del](Classes/classmenu_text_box.md#function-del)


delete pressed 


### function insert

```cpp
virtual void insert(
    bool setDisplayInsert =false
)
```


insert key pressed; setDisplayInsert true also updates the insert-mode indicator on screen 


### function start

```cpp
virtual void start()
```


**Reimplemented by**: [menuTextBox::start](Classes/classmenu_text_box.md#function-start)


delete pressed 


### function end

```cpp
virtual void end()
```


**Reimplemented by**: [menuTextBox::end](Classes/classmenu_text_box.md#function-end)


delete pressed 


### function avPg

```cpp
virtual void avPg()
```


delete pressed 


### function rePg

```cpp
virtual void rePg()
```


delete pressed 


### function cHA

```cpp
virtual void cHA(
    unsigned int argc,
    int * argv
)
```


**See**: [cUP](Classes/classterminal_parser.md#function-cup)

CHA escape command 


### function cUU

```cpp
virtual void cUU(
    unsigned int argc,
    int * argv
)
```


**Reimplemented by**: [menu::cUU](Classes/classmenu.md#function-cuu), [menuTextBox::cUU](Classes/classmenu_text_box.md#function-cuu)


key up 


### function cUD

```cpp
virtual void cUD(
    unsigned int argc,
    int * argv
)
```


**Reimplemented by**: [menu::cUD](Classes/classmenu.md#function-cud), [menuTextBox::cUD](Classes/classmenu_text_box.md#function-cud)


key down 


### function cUF

```cpp
virtual void cUF(
    unsigned int argc,
    int * argv
)
```


**Reimplemented by**: [menu::cUF](Classes/classmenu.md#function-cuf), [menuTextBox::cUF](Classes/classmenu_text_box.md#function-cuf)


key forward... right 


### function cUB

```cpp
virtual void cUB(
    unsigned int argc,
    int * argv
)
```


**Reimplemented by**: [menu::cUB](Classes/classmenu.md#function-cub), [menuTextBox::cUB](Classes/classmenu_text_box.md#function-cub)


key backward... left 


### function eL

```cpp
virtual void eL(
    unsigned int argc,
    int * argv
)
```


EL erase-line escape command handler 


### function sGR

```cpp
virtual void sGR(
    unsigned int argc,
    int * argv
)
```


select graphic rendition 


### function dSR

```cpp
virtual void dSR(
    unsigned int argc,
    int * argv
)
```


select graphic rendition 


### function rM

```cpp
virtual void rM(
    unsigned int argc,
    int * argv
)
```


escape command 


### function sM

```cpp
virtual void sM(
    unsigned int argc,
    int * argv
)
```


escape command 


### function dA

```cpp
virtual void dA(
    unsigned int argc,
    int * argv
)
```


escape command 


### function cUP

```cpp
virtual void cUP(
    unsigned int argc,
    int * argv
)
```


cursor position 


### function eD

```cpp
virtual void eD(
    unsigned int argc,
    int * argv
)
```


escape command 


### function vPA

```cpp
virtual void vPA(
    unsigned int argc,
    int * argv
)
```


escape command 


### function dCH

```cpp
virtual void dCH(
    unsigned int argc,
    int * argv
)
```


escape command 


### function cPR

```cpp
virtual void cPR(
    unsigned int argc,
    int * argv
)
```


**Reimplemented by**: [menu::cPR](Classes/classmenu.md#function-cpr)


cursor position report 


## Public Attributes Documentation

### variable insertStatus

```cpp
bool insertStatus;
```


true when the terminal is in insert mode (as opposed to overwrite mode) 


### variable userTty

```cpp
Stream * userTty;
```


ha d'anar a [terminalParser](Classes/classterminal_parser.md) per fer les funcions cap a pantalla, millores. 


-------------------------------

Updated on 2026-04-27 at 16:36:45 +0200