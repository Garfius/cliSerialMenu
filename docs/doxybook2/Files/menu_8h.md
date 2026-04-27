---
title: cliSerialMenu/menu.h
summary: here are the menuSystemOverTty object and it's friends. 

---

# cliSerialMenu/menu.h

here are the menuSystemOverTty object and it's friends.  [More...](#detailed-description)

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[menuOption](Classes/classmenu_option.md)**  |
| class | **[menuOptionOnOff](Classes/classmenu_option_on_off.md)**  |
| class | **[menuOptionRangeValue](Classes/classmenu_option_range_value.md)**  |
| class | **[changeScreenMenuOption](Classes/classchange_screen_menu_option.md)**  |
| class | **[screenMenu](Classes/classscreen_menu.md)**  |
| class | **[menu](Classes/classmenu.md)**  |
| class | **[textBoxMenuOption](Classes/classtext_box_menu_option.md)** <br>Base class for menu options that own a multiline text box editor.  |
| struct | **[textBoxConfig](Classes/structtext_box_config.md)** <br>Configuration structure passed to [menuTextBox::msgTxtInputMultiline()](Classes/classmenu_text_box.md#function-msgtxtinputmultiline).  |
| class | **[menuTextBox](Classes/classmenu_text_box.md)** <br>Multiline text box editor extension of menu.  |

## Types

|                | Name           |
| -------------- | -------------- |
| enum| **[textBoxStatus](Files/menu_8h.md#enum-textboxstatus)** { noExit, activeEditor, softwareAborted, escPressed, enterPressed, error}<br>Status codes for the multiline text box editor session.  |

## Attributes

|                | Name           |
| -------------- | -------------- |
| const char * | **[msgOptionsUp](Files/menu_8h.md#variable-msgoptionsup)**  |
| const char * | **[msgOptionsDn](Files/menu_8h.md#variable-msgoptionsdn)**  |
| const char * | **[insertText](Files/menu_8h.md#variable-inserttext)**  |
| [menuTextBox](Classes/classmenu_text_box.md) | **[menuSystemOverTty](Files/menu_8h.md#variable-menusystemovertty)**  |
| [menuTextBox](Classes/classmenu_text_box.md) * | **[menuSystemOverTtyP](Files/menu_8h.md#variable-menusystemoverttyp)**  |

## Defines

|                | Name           |
| -------------- | -------------- |
|  | **[terminalSizeMaxQueries](Files/menu_8h.md#define-terminalsizemaxqueries)**  |
|  | **[_MENU_UI_BIG_RAM_](Files/menu_8h.md#define--menu-ui-big-ram-)**  |
|  | **[screenMenuMax](Files/menu_8h.md#define-screenmenumax)**  |
|  | **[menuTextArrayLength](Files/menu_8h.md#define-menutextarraylength)**  |
|  | **[menuOptionsMax](Files/menu_8h.md#define-menuoptionsmax)**  |
|  | **[displayMenuOptionsDefault](Files/menu_8h.md#define-displaymenuoptionsdefault)**  |
|  | **[minTextBoxWidth](Files/menu_8h.md#define-mintextboxwidth)**  |
|  | **[escBackMillisecondsDelay](Files/menu_8h.md#define-escbackmillisecondsdelay)**  |
|  | **[defaultTextBoxWidth](Files/menu_8h.md#define-defaulttextboxwidth)**  |
|  | **[menuTextLength](Files/menu_8h.md#define-menutextlength)**  |
|  | **[queryterminalSizeTimeout](Files/menu_8h.md#define-queryterminalsizetimeout)**  |
|  | **[userInputLag](Files/menu_8h.md#define-userinputlag)**  |
|  | **[INPUT_BUFFER_SIZE](Files/menu_8h.md#define-input-buffer-size)**  |

## Detailed Description

here are the menuSystemOverTty object and it's friends. 

**Author**: Gerard Forcada Bigas

**Date**: 17/10/24 

This library makes intensive use of object-oriented programming. All the object definitions of menuSystemOverTty base objects to be inherited as customizations. Here are the menuSystemOverTty manager oject, and the base objects which to inherit to create custom menus,

## Types Documentation

### enum textBoxStatus

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| noExit | |   |
| activeEditor | |   |
| softwareAborted | |   |
| escPressed | |   |
| enterPressed | |   |
| error | |   |



Status codes for the multiline text box editor session. 



## Attributes Documentation

### variable msgOptionsUp

```cpp
static const char * msgOptionsUp = " Up!";
```


### variable msgOptionsDn

```cpp
static const char * msgOptionsDn = " Dn!";
```


### variable insertText

```cpp
static const char * insertText = " INSERT";
```


### variable menuSystemOverTty

```cpp
menuTextBox menuSystemOverTty;
```


global menu system instance (with text box support) 


### variable menuSystemOverTtyP

```cpp
menuTextBox * menuSystemOverTtyP;
```


pointer to the global menu system instance 



## Macros Documentation

### define terminalSizeMaxQueries

```cpp
#define terminalSizeMaxQueries 4
```


maximum number of times the terminal size will be queried before giving up 


### define _MENU_UI_BIG_RAM_

```cpp
#define _MENU_UI_BIG_RAM_ 
```


enables larger RAM features: bigger buffers, more screens, and the multiline text box editor 


### define screenMenuMax

```cpp
#define screenMenuMax 10
```


maximum number of [screenMenu](Classes/classscreen_menu.md) instances (displays) 


### define menuTextArrayLength

```cpp
#define menuTextArrayLength 80
```


maximum caption/text buffer length including null terminator 


### define menuOptionsMax

```cpp
#define menuOptionsMax 15
```


maximum number of menu options per [screenMenu](Classes/classscreen_menu.md) instance 


### define displayMenuOptionsDefault

```cpp
#define displayMenuOptionsDefault 9
```


default number of menu options shown on screen; must be less than screenMenuMax 


### define minTextBoxWidth

```cpp
#define minTextBoxWidth 4
```


minimum allowed text box editor width in characters 


### define escBackMillisecondsDelay

```cpp
#define escBackMillisecondsDelay 450
```


milliseconds to wait after ESC before treating it as a back-navigation key 


### define defaultTextBoxWidth

```cpp
#define defaultTextBoxWidth 20
```


default single-line text input box width in characters 


### define menuTextLength

```cpp
#define menuTextLength (menuTextArrayLength-1)
```


maximum usable caption length (excludes null terminator) 


### define queryterminalSizeTimeout

```cpp
#define queryterminalSizeTimeout 250UL
```


milliseconds to wait for terminal size report 


### define userInputLag

```cpp
#define userInputLag 50
```


milliseconds debounce delay after a user key press in the text box editor 


### define INPUT_BUFFER_SIZE

```cpp
#define INPUT_BUFFER_SIZE 320
```


size in bytes of the circular character buffer used by the text box editor 


## Source code

```cpp

#ifndef __menu__
#define __menu__
#include "terminalParser.h"
#include <Arduino.h>
#define terminalSizeMaxQueries 4 
//---------------------RESOURCES USAGE HERE
//---------------------Uncomment the following line for microcontrollers bigger than Atmega328P line RP2040 or ESP32
#define _MENU_UI_BIG_RAM_ 

//---------------------RESOURCES USAGE HERE
#ifdef _MENU_UI_BIG_RAM_
  #define screenMenuMax 10 
  #define menuTextArrayLength 80 
  #define menuOptionsMax 15 
  #define displayMenuOptionsDefault 9 
  #define minTextBoxWidth 4 
  #else
  #define screenMenuMax 4 
  #define menuTextArrayLength 40 
  #define menuOptionsMax 7 
  #define displayMenuOptionsDefault 4 
  #endif
  
  
#define escBackMillisecondsDelay 450 
#define defaultTextBoxWidth 20 
#define menuTextLength (menuTextArrayLength-1) 

#define queryterminalSizeTimeout 250UL 

static const char * msgOptionsUp = " Up!";
static const char * msgOptionsDn = " Dn!";
static const char * insertText = " INSERT";

class menuTextBox;
class screenMenu;
class menu;

class menuOption{
  public:
    menuOption();
    menuOption(const char* text);
    char text[menuTextArrayLength];
    virtual void run();
    virtual bool refresh();
    virtual bool pushRt();
    virtual bool pushLt();
    bool autoRefresh = true;
};
class menuOptionOnOff :public menuOption{
  public:
    bool state; 
    bool statePrinted; 
    menuOptionOnOff();
    menuOptionOnOff(const char* text,bool initValue=false);
    virtual bool refresh() override;
    virtual bool pushRt() override;
    virtual bool pushLt() override;
};
class menuOptionRangeValue :public menuOption{
  public:
    int state; 
    int statePrinted; 
    int _maxValue; 
    int _minValue; 
    int _step; 
    menuOptionRangeValue();
    menuOptionRangeValue(const char* text, int minVal, int maxVal, int initValue, int step=1);
    virtual bool refresh() override;
    virtual bool pushRt() override;
    virtual bool pushLt() override;
};
class changeScreenMenuOption : public menuOption{
    public:
        screenMenu* _menuDesti; 
        changeScreenMenuOption(screenMenu* menuDesti);
        void run() override;
        bool refresh() override;
};
class screenMenu{
  protected:
  public: 
    int whereICame; 
    bool autoRefresh = false;
    bool hasMoreAbove = false;
    bool hasMoreBelow = false;
    unsigned int totalMenuOptions;
    unsigned int offsetFromTop =0;
    unsigned int lastSelectedMenuOptionIndex = 0; 
    char titol[menuTextArrayLength];
    menuOption *displayMenuOptionsPnt[menuOptionsMax];
    screenMenu(const char* text);
    virtual void setHasMores();
    virtual bool pushUp();
    virtual bool pushDn();
    virtual bool pushRt(unsigned int index);
    virtual bool pushLt(unsigned int index);
    virtual bool addMenuOption(menuOption* menuoption); 
    virtual bool refreshMenu();
    virtual void run(unsigned int index);
    virtual void leave();
    virtual void enter();
};
class menu : public terminalParser{
  protected:
    static constexpr char frameChars[3] = {'-','|','+'};
    unsigned int selectedMenuOption;
    unsigned long nextRefresh = 0;
    bool runningOption = false;
    unsigned int contentOriginRow = 1;
    unsigned int contentOriginCol = 1;
    void show(unsigned int index);
    virtual void cUU(unsigned int argc,int *argv) override;
    virtual void cUD(unsigned int argc,int *argv) override;
    virtual void cUF(unsigned int argc,int *argv) override;
    virtual void cUB(unsigned int argc,int *argv) override;
    virtual void cPR(unsigned int argc,int *argv) override;
    virtual void cr() override;
    char lastInputChar;
  public:
    void queryTerminalSize(bool wait4Response=true); 
    unsigned long nextEscBack = 0;
    uint8_t _topPadding = 1; 
    bool askTerminalSize = true;
    bool verticallyCenter = false;
    bool horizontallyCenter = true;
    unsigned int terminalRowsCols[2] = {0, 0}; 
    uint8_t terminalSizeQueries = 0;
    int activeScreenMenu = -1;
    int totalScreenMenus = 0;
    unsigned int screenMenuOptions = displayMenuOptionsDefault;
    screenMenu *pantalles[screenMenuMax];
    //------set up and initialization
    menu();
    virtual void init(Stream *userSerialTerminal) override;
    void addscreen(screenMenu* pantalla);
    //---------loop code
    void run();
    //----------user interaction functions
    bool msgTxtInput(const char* prompt,char* result, unsigned int maxLength, unsigned int minLength=0);
    void msgSmallWait(const char* prompt);
    void msgPause(const char* prompt);
    bool msgYes(const char* prompt);
    void msgPause();
    //----------style print operations
    void printLnCentered(const char* text); 
    void printLnCentered(const String &text); 
    void printLnCentered(); 
    void printLnCentered(char c); 
    void printLnCentered(unsigned char b, int base = DEC); 
    void printLnCentered(int num, int base = DEC); 
    void printLnCentered(unsigned int num, int base = DEC); 
    void printLnCentered(long num, int base = DEC); 
    void printLnCentered(unsigned long num, int base = DEC); 
    void printLnCentered(long long num, int base = DEC); 
    void printLnCentered(unsigned long long num, int base = DEC); 
    void printLnCentered(double num, int digits = 2); 
    void drawProgressBar(uint32_t value, uint32_t total, char* progressBar);
    
    uint8_t dotLeadersMargin = 2; 
    uint8_t dotLeadersMinDots = 2; 
    char dotLeadersChar = '.'; 
    unsigned int dotLeadersDefaultWidth = menuTextArrayLength; 
    unsigned int printDotLeaders(const char* left, const char* right, int margin = -1, int minDots = -1); 
    void setPrettyDotLeadersMargin(int bothTextsLength);
    //---------not so used, rarely for public use
    void setscreen(int targetScreenMenu, bool setWhereICame = true);
    void refresh();
    void doBack();
    void show();
};

#ifdef _MENU_UI_BIG_RAM_
#define userInputLag 50 
#define INPUT_BUFFER_SIZE 320 
enum textBoxStatus {
  noExit,
  activeEditor,
  softwareAborted,
  escPressed,
  enterPressed,
  error
};
class textBoxMenuOption:public menuOption{
protected:
public:
    textBoxMenuOption(); 
    textBoxMenuOption( const char* text); 
    virtual void run() override;
    virtual bool checkBackgroundEvents();
    virtual bool performUserInteraction();
};
struct textBoxConfig{
  const char* prompt = nullptr; 
  char* result = nullptr; 
  unsigned int maxLength=0; 
  unsigned int minLength=0; 
  const char * allowedChars = nullptr; 
  textBoxMenuOption* _textBoxCallBack = nullptr; 
  uint16_t textLineWidth = defaultTextBoxWidth;
};
class menuTextBox:public  menu{
  private:
    bool lastInsertStatus;
    unsigned int cursorBufferIndex = 0;
    unsigned long lastUserInputTime = 0;
    void drawTextPreCursor();
    void drawTextPostCursor(unsigned int fromLineToEnd);
    void redrawLine(unsigned int line);
    void cleanupEditor();
    void removeCharAtIndex(unsigned int index);
    void manageCaretAndSpace(bool erase = false);
    unsigned int getCursorRowIndex();
    unsigned int getTotalLinesCapacity();
    unsigned int getWrittenLinesCount();
    unsigned int getCursorColIndex();
    unsigned int getCaptionLinesCount();
    unsigned int drawnFrameHeight;
    void redrawFrame();
    void drawFrame(bool erase = false);
    void statusBar();
    void eraseStatusBar();
    //---------- redirigeixen a terminalParser
    void cUB(unsigned int argc,int *argv) override;
    void cUF(unsigned int argc,int *argv) override;
    void cUU(unsigned int argc,int *argv) override;
    void cUD(unsigned int argc,int *argv) override;
    void del() override;
    void lf() override;
    void backSpace() override;
    void start() override;// to-do posar a menu::
    void end() override;// to-do posar a menu::
    void cr() override;
    textBoxConfig * runningConfig;
  public:
    static const char* exitCodeDescription[]; 
    uint8_t lastTextBoxExitCode =0; 
    textBoxStatus _textBoxStatus = textBoxStatus::noExit; 
    menuTextBox();
    ~menuTextBox(); // ensur e cleanup of dynamic buffer
    void msgTxtInputMultiline(textBoxConfig * myConfig);
};
extern menuTextBox menuSystemOverTty; 
extern menuTextBox * menuSystemOverTtyP; 

#else
extern menu menuSystemOverTty; 
extern menu * menuSystemOverTtyP; 
#endif

#endif
```


-------------------------------

Updated on 2026-04-27 at 16:36:45 +0200
