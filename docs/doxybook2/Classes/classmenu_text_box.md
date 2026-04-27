---
title: menuTextBox
summary: Multiline text box editor extension of menu. 

---

# menuTextBox



Multiline text box editor extension of menu.  [More...](#detailed-description)


`#include <menu.h>`

Inherits from [menu](Classes/classmenu.md), [terminalParser](Classes/classterminal_parser.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[menuTextBox](Classes/classmenu_text_box.md#function-menutextbox)**() |
| | **[~menuTextBox](Classes/classmenu_text_box.md#function-~menutextbox)**() |
| void | **[msgTxtInputMultiline](Classes/classmenu_text_box.md#function-msgtxtinputmultiline)**([textBoxConfig](Classes/structtext_box_config.md) * myConfig)<br>Multi-line text input editor. If cancelled, exits with editing still active.  |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| const char *[] | **[exitCodeDescription](Classes/classmenu_text_box.md#variable-exitcodedescription)**  |
| uint8_t | **[lastTextBoxExitCode](Classes/classmenu_text_box.md#variable-lasttextboxexitcode)**  |
| [textBoxStatus](Files/menu_8h.md#enum-textboxstatus) | **[_textBoxStatus](Classes/classmenu_text_box.md#variable--textboxstatus)**  |

## Additional inherited members

**Public Functions inherited from [menu](Classes/classmenu.md)**

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

**Protected Functions inherited from [menu](Classes/classmenu.md)**

|                | Name           |
| -------------- | -------------- |
| void | **[show](Classes/classmenu.md#function-show)**(unsigned int index) |
| virtual void | **[cPR](Classes/classmenu.md#function-cpr)**(unsigned int argc, int * argv) override |

**Public Attributes inherited from [menu](Classes/classmenu.md)**

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

**Protected Attributes inherited from [menu](Classes/classmenu.md)**

|                | Name           |
| -------------- | -------------- |
| char[3] | **[frameChars](Classes/classmenu.md#variable-framechars)**  |
| unsigned int | **[selectedMenuOption](Classes/classmenu.md#variable-selectedmenuoption)**  |
| unsigned long | **[nextRefresh](Classes/classmenu.md#variable-nextrefresh)**  |
| bool | **[runningOption](Classes/classmenu.md#variable-runningoption)**  |
| unsigned int | **[contentOriginRow](Classes/classmenu.md#variable-contentoriginrow)**  |
| unsigned int | **[contentOriginCol](Classes/classmenu.md#variable-contentorigincol)**  |
| char | **[lastInputChar](Classes/classmenu.md#variable-lastinputchar)**  |

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
| virtual void | **[init](Classes/classterminal_parser.md#function-init)**(Stream * pantalla) |
| | **[terminalParser](Classes/classterminal_parser.md#function-terminalparser)**() |
| bool | **[doGuess](Classes/classterminal_parser.md#function-doguess)**(char caracter) |
| virtual void | **[tab](Classes/classterminal_parser.md#function-tab)**() |
| virtual void | **[beep](Classes/classterminal_parser.md#function-beep)**() |
| virtual void | **[insert](Classes/classterminal_parser.md#function-insert)**(bool setDisplayInsert =false) |
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
| virtual void | **[cPR](Classes/classterminal_parser.md#function-cpr)**(unsigned int argc, int * argv) |

**Public Attributes inherited from [terminalParser](Classes/classterminal_parser.md)**

|                | Name           |
| -------------- | -------------- |
| bool | **[insertStatus](Classes/classterminal_parser.md#variable-insertstatus)**  |
| Stream * | **[userTty](Classes/classterminal_parser.md#variable-usertty)**  |


## Detailed Description

```cpp
class menuTextBox;
```

Multiline text box editor extension of menu. 

Adds an in-place full-screen text editor to the menu system. Activated via [msgTxtInputMultiline()](Classes/classmenu_text_box.md#function-msgtxtinputmultiline). Only available when _MENU_UI_BIG_RAM_ is defined. 

## Public Functions Documentation

### function menuTextBox

```cpp
menuTextBox()
```


### function ~menuTextBox

```cpp
~menuTextBox()
```


### function msgTxtInputMultiline

```cpp
void msgTxtInputMultiline(
    textBoxConfig * myConfig
)
```

Multi-line text input editor. If cancelled, exits with editing still active. 

**Parameters**: 

  * **myConfig** pointer to [textBoxConfig](Classes/structtext_box_config.md) struct containing prompt, result buffer, length limits and allowed characters 


## Public Attributes Documentation

### variable exitCodeDescription

```cpp
static const char *[] exitCodeDescription                                             = {
    "exit by enter",
    "exit by esc",
    "software aborted",
    "not null terminated",
    "text line width too short",
    "text too short",
    "corrupt string",
    "text too long",
    "area 2 tall 4 screen, wide it",
    "area 2 wide 4 screen, tall it"
};
```


human-readable descriptions indexed by exit code value 


### variable lastTextBoxExitCode

```cpp
uint8_t lastTextBoxExitCode =0;
```


exit code of the last [msgTxtInputMultiline()](Classes/classmenu_text_box.md#function-msgtxtinputmultiline) call 


### variable _textBoxStatus

```cpp
textBoxStatus _textBoxStatus = textBoxStatus::noExit;
```


current or last editor session status 


-------------------------------

Updated on 2026-04-27 at 16:36:45 +0200