---
title: menu

---

# menu



 [More...](#detailed-description)


`#include <menu.h>`

Inherits from [terminalParser](Classes/classterminal_parser.md)

Inherited by [menuTextBox](Classes/classmenu_text_box.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| void | **[queryTerminalSize](Classes/classmenu.md#function-queryterminalsize)**(bool wait4Response =true) |
| | **[menu](Classes/classmenu.md#function-menu)**() |
| virtual void | **[init](Classes/classmenu.md#function-init)**(Stream * userSerialTerminal) override |
| void | **[addscreen](Classes/classmenu.md#function-addscreen)**([screenMenu](Classes/classscreen_menu.md) * pantalla) |
| void | **[run](Classes/classmenu.md#function-run)**()<br>Parses the userTty, check user interaction or display query.  |
| bool | **[msgTxtInput](Classes/classmenu.md#function-msgtxtinput)**(const char * prompt, char * result, unsigned int maxLength, unsigned int minLength =0) |
| void | **[msgSmallWait](Classes/classmenu.md#function-msgsmallwait)**(const char * prompt) |
| void | **[msgPause](Classes/classmenu.md#function-msgpause)**(const char * prompt) |
| bool | **[msgYes](Classes/classmenu.md#function-msgyes)**(const char * prompt) |
| void | **[msgPause](Classes/classmenu.md#function-msgpause)**() |
| void | **[printLnCentered](Classes/classmenu.md#function-printlncentered)**(const char * text) |
| void | **[printLnCentered](Classes/classmenu.md#function-printlncentered)**(const String & text) |
| void | **[printLnCentered](Classes/classmenu.md#function-printlncentered)**() |
| void | **[printLnCentered](Classes/classmenu.md#function-printlncentered)**(char c) |
| void | **[printLnCentered](Classes/classmenu.md#function-printlncentered)**(unsigned char b, int base =DEC) |
| void | **[printLnCentered](Classes/classmenu.md#function-printlncentered)**(int num, int base =DEC) |
| void | **[printLnCentered](Classes/classmenu.md#function-printlncentered)**(unsigned int num, int base =DEC) |
| void | **[printLnCentered](Classes/classmenu.md#function-printlncentered)**(long num, int base =DEC) |
| void | **[printLnCentered](Classes/classmenu.md#function-printlncentered)**(unsigned long num, int base =DEC) |
| void | **[printLnCentered](Classes/classmenu.md#function-printlncentered)**(long long num, int base =DEC) |
| void | **[printLnCentered](Classes/classmenu.md#function-printlncentered)**(unsigned long long num, int base =DEC) |
| void | **[printLnCentered](Classes/classmenu.md#function-printlncentered)**(double num, int digits =2) |
| void | **[drawProgressBar](Classes/classmenu.md#function-drawprogressbar)**(uint32_t value, uint32_t total, char * progressBar) |
| unsigned int | **[printDotLeaders](Classes/classmenu.md#function-printdotleaders)**(const char * left, const char * right, int margin =-1, int minDots =-1) |
| void | **[setPrettyDotLeadersMargin](Classes/classmenu.md#function-setprettydotleadersmargin)**(int bothTextsLength) |
| void | **[setscreen](Classes/classmenu.md#function-setscreen)**(int targetScreenMenu, bool setWhereICame =true)<br>Gracefully switch menu screen.  |
| void | **[refresh](Classes/classmenu.md#function-refresh)**() |
| void | **[doBack](Classes/classmenu.md#function-doback)**() |
| void | **[show](Classes/classmenu.md#function-show)**() |

## Protected Functions

|                | Name           |
| -------------- | -------------- |
| void | **[show](Classes/classmenu.md#function-show)**(unsigned int index) |
| virtual void | **[cUU](Classes/classmenu.md#function-cuu)**(unsigned int argc, int * argv) override |
| virtual void | **[cUD](Classes/classmenu.md#function-cud)**(unsigned int argc, int * argv) override |
| virtual void | **[cUF](Classes/classmenu.md#function-cuf)**(unsigned int argc, int * argv) override |
| virtual void | **[cUB](Classes/classmenu.md#function-cub)**(unsigned int argc, int * argv) override |
| virtual void | **[cPR](Classes/classmenu.md#function-cpr)**(unsigned int argc, int * argv) override |
| virtual void | **[cr](Classes/classmenu.md#function-cr)**() override |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| unsigned long | **[nextEscBack](Classes/classmenu.md#variable-nextescback)**  |
| uint8_t | **[_topPadding](Classes/classmenu.md#variable--toppadding)**  |
| bool | **[askTerminalSize](Classes/classmenu.md#variable-askterminalsize)**  |
| bool | **[verticallyCenter](Classes/classmenu.md#variable-verticallycenter)**  |
| bool | **[horizontallyCenter](Classes/classmenu.md#variable-horizontallycenter)**  |
| unsigned int[2] | **[terminalRowsCols](Classes/classmenu.md#variable-terminalrowscols)**  |
| uint8_t | **[terminalSizeQueries](Classes/classmenu.md#variable-terminalsizequeries)**  |
| int | **[activeScreenMenu](Classes/classmenu.md#variable-activescreenmenu)**  |
| int | **[totalScreenMenus](Classes/classmenu.md#variable-totalscreenmenus)**  |
| unsigned int | **[screenMenuOptions](Classes/classmenu.md#variable-screenmenuoptions)**  |
| [screenMenu](Classes/classscreen_menu.md) *[screenMenuMax] | **[pantalles](Classes/classmenu.md#variable-pantalles)**  |
| uint8_t | **[dotLeadersMargin](Classes/classmenu.md#variable-dotleadersmargin)**  |
| uint8_t | **[dotLeadersMinDots](Classes/classmenu.md#variable-dotleadersmindots)**  |
| char | **[dotLeadersChar](Classes/classmenu.md#variable-dotleaderschar)**  |
| unsigned int | **[dotLeadersDefaultWidth](Classes/classmenu.md#variable-dotleadersdefaultwidth)**  |

## Protected Attributes

|                | Name           |
| -------------- | -------------- |
| char[3] | **[frameChars](Classes/classmenu.md#variable-framechars)**  |
| unsigned int | **[selectedMenuOption](Classes/classmenu.md#variable-selectedmenuoption)**  |
| unsigned long | **[nextRefresh](Classes/classmenu.md#variable-nextrefresh)**  |
| bool | **[runningOption](Classes/classmenu.md#variable-runningoption)**  |
| unsigned int | **[contentOriginRow](Classes/classmenu.md#variable-contentoriginrow)**  |
| unsigned int | **[contentOriginCol](Classes/classmenu.md#variable-contentorigincol)**  |
| char | **[lastInputChar](Classes/classmenu.md#variable-lastinputchar)**  |

## Additional inherited members

**Public Functions inherited from [terminalParser](Classes/classterminal_parser.md)**

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
| | **[terminalParser](Classes/classterminal_parser.md#function-terminalparser)**() |
| bool | **[doGuess](Classes/classterminal_parser.md#function-doguess)**(char caracter) |
| virtual void | **[tab](Classes/classterminal_parser.md#function-tab)**() |
| virtual void | **[lf](Classes/classterminal_parser.md#function-lf)**() |
| virtual void | **[backSpace](Classes/classterminal_parser.md#function-backspace)**() |
| virtual void | **[beep](Classes/classterminal_parser.md#function-beep)**() |
| virtual void | **[del](Classes/classterminal_parser.md#function-del)**() |
| virtual void | **[insert](Classes/classterminal_parser.md#function-insert)**(bool setDisplayInsert =false) |
| virtual void | **[start](Classes/classterminal_parser.md#function-start)**() |
| virtual void | **[end](Classes/classterminal_parser.md#function-end)**() |
| virtual void | **[avPg](Classes/classterminal_parser.md#function-avpg)**() |
| virtual void | **[rePg](Classes/classterminal_parser.md#function-repg)**() |
| virtual void | **[cHA](Classes/classterminal_parser.md#function-cha)**(unsigned int argc, int * argv) |
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

**Public Attributes inherited from [terminalParser](Classes/classterminal_parser.md)**

|                | Name           |
| -------------- | -------------- |
| bool | **[insertStatus](Classes/classterminal_parser.md#variable-insertstatus)**  |
| Stream * | **[userTty](Classes/classterminal_parser.md#variable-usertty)**  |


## Detailed Description

```cpp
class menu;
```


The menu main container

contains the [screenMenu](Classes/classscreen_menu.md) display screens, add it via addscreen works on a Stream which shows a console VT100/ANSI terminal style inherits [terminalParser](Classes/classterminal_parser.md) to parse keystrokes 

## Public Functions Documentation

### function queryTerminalSize

```cpp
void queryTerminalSize(
    bool wait4Response =true
)
```


sends cursor-position probe to discover terminal dimensions; waits for CPR response when wait4Response is true 


### function menu

```cpp
menu()
```


constructor has no code 


### function init

```cpp
virtual void init(
    Stream * userSerialTerminal
) override
```


**Reimplements**: [terminalParser::init](Classes/classterminal_parser.md#function-init)


kickstart stuff and shows menu, do it at the end os setup(), after addscreen 


### function addscreen

```cpp
void addscreen(
    screenMenu * pantalla
)
```


**Parameters**: 

  * **pantalla** pointer to menu screen 


adds a screen, change it using [changeScreenMenuOption](Classes/classchange_screen_menu_option.md) or setscreen do it after [screenMenu.addMenuOption](Classes/classscreen_menu.md#function-addmenuoption)

Add available menu screen to the array


### function run

```cpp
void run()
```

Parses the userTty, check user interaction or display query. 

to be called at loop()... AOAP As Often As Possible, not to abuse reception buffer 


### function msgTxtInput

```cpp
bool msgTxtInput(
    const char * prompt,
    char * result,
    unsigned int maxLength,
    unsigned int minLength =0
)
```


**Parameters**: 

  * **result** might not be empty, resulting text will be there 
  * **prompt** the top text prompt 
  * **maxLength** 0 for default=(textLineWidth-1) 
  * **minLength** 0 for default=1 


single line text edit, allows (a-Z) && (A-Z) && (0-9)

simple single line text prompt, allows (a-Z) && (A-Z) && (0-9) 


### function msgSmallWait

```cpp
void msgSmallWait(
    const char * prompt
)
```


shows ¿alert? temporary color-inverted text for cliMsgWait milliseconds 


### function msgPause

```cpp
void msgPause(
    const char * prompt
)
```


shows a text and waits any keypress to continue

prints inverted the prompt color and the pressAnyKeyToContinue text when key is pressed, re-writes the text normal colors, and erases the pressAnyKeyToContinue text leaves cursor at column 1 


### function msgYes

```cpp
bool msgYes(
    const char * prompt
)
```


asks yes/no to given text, return true if (y || Y) is press 


### function msgPause

```cpp
void msgPause()
```


shows default text and waits any keypress to continue 


### function printLnCentered

```cpp
void printLnCentered(
    const char * text
)
```


prints text followed by newline, horizontally centred when horizontallyCenter is set 


### function printLnCentered

```cpp
void printLnCentered(
    const String & text
)
```


This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts. 


### function printLnCentered

```cpp
void printLnCentered()
```


prints an empty line 


### function printLnCentered

```cpp
void printLnCentered(
    char c
)
```


This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts. 


### function printLnCentered

```cpp
void printLnCentered(
    unsigned char b,
    int base =DEC
)
```


This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts. 


### function printLnCentered

```cpp
void printLnCentered(
    int num,
    int base =DEC
)
```


This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts. 


### function printLnCentered

```cpp
void printLnCentered(
    unsigned int num,
    int base =DEC
)
```


This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts. 


### function printLnCentered

```cpp
void printLnCentered(
    long num,
    int base =DEC
)
```


This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts. 


### function printLnCentered

```cpp
void printLnCentered(
    unsigned long num,
    int base =DEC
)
```


This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts. 


### function printLnCentered

```cpp
void printLnCentered(
    long long num,
    int base =DEC
)
```


This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts. 


### function printLnCentered

```cpp
void printLnCentered(
    unsigned long long num,
    int base =DEC
)
```


This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts. 


### function printLnCentered

```cpp
void printLnCentered(
    double num,
    int digits =2
)
```


This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts. 


### function drawProgressBar

```cpp
void drawProgressBar(
    uint32_t value,
    uint32_t total,
    char * progressBar
)
```


Draws a progress bar to passed char * pointer, minimum char * size 39 


### function printDotLeaders

```cpp
unsigned int printDotLeaders(
    const char * left,
    const char * right,
    int margin =-1,
    int minDots =-1
)
```


prints a dot-leader line with left and right text, returns number of lines printed 


### function setPrettyDotLeadersMargin

```cpp
void setPrettyDotLeadersMargin(
    int bothTextsLength
)
```


Sets dotLeadersMargin based on terminal width for aesthetics 


### function setscreen

```cpp
void setscreen(
    int targetScreenMenu,
    bool setWhereICame =true
)
```

Gracefully switch menu screen. 

**Parameters**: 

  * **pantallaDesti** index of the target screen 
  * **setWhereICame** if true, records current screen as the origin so [doBack()](Classes/classmenu.md#function-doback) can return to it 


change the showing screen

If coming from a run, no need to call [show()](Classes/classmenu.md#function-show). 


### function refresh

```cpp
void refresh()
```


to force screen refresh 


### function doBack

```cpp
void doBack()
```


sets the display to the previous one 


### function show

```cpp
void show()
```


**Parameters**: 

  * **resetCursor** move cursor to starting point 


draws menu on screen

Show menu on screen, using userTty object member


## Protected Functions Documentation

### function show

```cpp
void show(
    unsigned int index
)
```


redraws selected menuoption text

refreshes the line 


### function cUU

```cpp
virtual void cUU(
    unsigned int argc,
    int * argv
) override
```


**Reimplements**: [terminalParser::cUU](Classes/classterminal_parser.md#function-cuu)


**Reimplemented by**: [menuTextBox::cUU](Classes/classmenu_text_box.md#function-cuu)


inherited from [terminalParser](Classes/classterminal_parser.md). cursor Up handler

Cursor Up, inherited from [terminalParser](Classes/classterminal_parser.md) pantalles[activeScreenMenu]->offsetFromTop 


### function cUD

```cpp
virtual void cUD(
    unsigned int argc,
    int * argv
) override
```


**Reimplements**: [terminalParser::cUD](Classes/classterminal_parser.md#function-cud)


**Reimplemented by**: [menuTextBox::cUD](Classes/classmenu_text_box.md#function-cud)


inherited from [terminalParser](Classes/classterminal_parser.md). cursor Down handler

Cursor Down, inherited from [terminalParser](Classes/classterminal_parser.md) dragons be here 


### function cUF

```cpp
virtual void cUF(
    unsigned int argc,
    int * argv
) override
```


**Reimplements**: [terminalParser::cUF](Classes/classterminal_parser.md#function-cuf)


**Reimplemented by**: [menuTextBox::cUF](Classes/classmenu_text_box.md#function-cuf)


inherited from [terminalParser](Classes/classterminal_parser.md). cursor forward right handler 


### function cUB

```cpp
virtual void cUB(
    unsigned int argc,
    int * argv
) override
```


**Reimplements**: [terminalParser::cUB](Classes/classterminal_parser.md#function-cub)


**Reimplemented by**: [menuTextBox::cUB](Classes/classmenu_text_box.md#function-cub)


inherited from [terminalParser](Classes/classterminal_parser.md). cursor backward left handler 


### function cPR

```cpp
virtual void cPR(
    unsigned int argc,
    int * argv
) override
```


**Reimplements**: [terminalParser::cPR](Classes/classterminal_parser.md#function-cpr)


inherited from [terminalParser](Classes/classterminal_parser.md). cursor position report 


### function cr

```cpp
virtual void cr() override
```


**Reimplements**: [terminalParser::cr](Classes/classterminal_parser.md#function-cr)


**Reimplemented by**: [menuTextBox::cr](Classes/classmenu_text_box.md#function-cr)


inherited from [terminalParser](Classes/classterminal_parser.md). enter 


## Public Attributes Documentation

### variable nextEscBack

```cpp
unsigned long nextEscBack = 0;
```


move screen back using esc control 


### variable _topPadding

```cpp
uint8_t _topPadding = 1;
```


number of rows reserved at the top when not vertically centering 


### variable askTerminalSize

```cpp
bool askTerminalSize = true;
```


ask terminal size before menu show (client might respond after being shown) 


### variable verticallyCenter

```cpp
bool verticallyCenter = false;
```


WARNING: operations clears screen! 


### variable horizontallyCenter

```cpp
bool horizontallyCenter = true;
```


user operations are shown centered on screen 


### variable terminalRowsCols

```cpp
unsigned int[2] terminalRowsCols = {0, 0};
```


reported terminal size: [0]=rows, [1]=columns; 0 means not yet initialised 


### variable terminalSizeQueries

```cpp
uint8_t terminalSizeQueries = 0;
```


number of times terminal size has been queried 


### variable activeScreenMenu

```cpp
int activeScreenMenu = -1;
```


the actual displayed menu 


### variable totalScreenMenus

```cpp
int totalScreenMenus = 0;
```


total amount of displayable/showAble display menus 


### variable screenMenuOptions

```cpp
unsigned int screenMenuOptions = displayMenuOptionsDefault;
```


menuoptions to be displayed 


### variable pantalles

```cpp
screenMenu *[screenMenuMax] pantalles;
```


pointers to display menus 


### variable dotLeadersMargin

```cpp
uint8_t dotLeadersMargin = 2;
```


left and right blank padding columns surrounding the dot-leader row 


### variable dotLeadersMinDots

```cpp
uint8_t dotLeadersMinDots = 2;
```


minimum number of dot characters always printed between left and right text 


### variable dotLeadersChar

```cpp
char dotLeadersChar = '.';
```


character used to fill the dot-leader gap 


### variable dotLeadersDefaultWidth

```cpp
unsigned int dotLeadersDefaultWidth = menuTextArrayLength;
```


fallback line width used when terminal width is unknown 


## Protected Attributes Documentation

### variable frameChars

```cpp
static char[3] frameChars = {'-','|','+'};
```


border characters: [0]=horizontal, [1]=vertical, [2]=corner 


### variable selectedMenuOption

```cpp
unsigned int selectedMenuOption;
```


the actual selected menu index option on display 


### variable nextRefresh

```cpp
unsigned long nextRefresh = 0;
```


screen refresh control 


### variable runningOption

```cpp
bool runningOption = false;
```


esta excutant una opcio 


### variable contentOriginRow

```cpp
unsigned int contentOriginRow = 1;
```


top row where the menu content starts 


### variable contentOriginCol

```cpp
unsigned int contentOriginCol = 1;
```


left column where the menu content starts 


### variable lastInputChar

```cpp
char lastInputChar;
```


temporal character 


-------------------------------

Updated on 2026-04-27 at 16:36:45 +0200