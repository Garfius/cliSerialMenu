/**
* @file menu.h
* @brief here are the menuSystemOverTty object and it's friends.
*
* This library makes intensive use of object-oriented programming.
* All the object definitions of menuSystemOverTty base objects to be inherited as customizations.
* Here are the menuSystemOverTty manager oject, and the base objects which to inherit to create custom menus,
*
* @author Gerard Forcada Bigas
*
* @date 17/10/24
*/
#ifndef __menu__
#define __menu__
#include "terminalParser.h"
#include <Arduino.h>

//---------------------RESOURCES USAGE HERE
#ifndef screenMenuMax
  #define screenMenuMax 4// maximum screenMenu instances, displays of menuitems
#endif
#ifndef menuTextArrayLength
  #define menuTextArrayLength 40 // Max caption length 
#endif
#ifndef menuOptionsMax
  #define menuOptionsMax 7 // maximum menu options allowed in memory for each screenMenu instance
#endif
#ifndef displayMenuOptionsDefault
  #define displayMenuOptionsDefault 4 // the amount of menu options on the screen, always lower than screenMenuMax
#endif

#define menuTextLength (menuTextArrayLength-1)

static const char * msgOptionsUp = " Up!";
static const char * msgOptionsDn = " Dn!";

class menuTextBox;
class screenMenu;

class menu;
/**
 * Simplest menuOption base class, is to be inherited, put your custom code at run()
*/
class menuOption{
  public:
    menuOption();/**< for compiler puposes, better not to use it*/
    menuOption(const char* text);/**< constructor, sets the caption text */
    char text[menuTextArrayLength];/**< Caption */
    virtual void run();/**< inherit to do your thing */
    virtual bool refresh();/**< called when autoRefresh is set here and screenMenu*/
    virtual bool pushRt();/**< called then right arrow is pressed */
    virtual bool pushLt();/**< called then left left is pressed */
    bool autoRefresh = true;/**< wants refresh() to be called*/
};
/**
 * Switch menuOptionOnOff base class is to be inherited, put your custom code at run(), read state at state
 * Uses ':'(menu.cpp menuOptionDelimiter) as separator
*/
class menuOptionOnOff :public menuOption{
  public:
    bool state,statePrinted;
    menuOptionOnOff();/**< for compiler puposes, better not to use it*/
    menuOptionOnOff(const char* text,bool initValue=false);/**< constructor, sets the caption text, do not use ':', might set init value */
    virtual bool refresh();/**< inherit to do your thing */
    virtual bool pushRt();/**< switches state, if inherit, call base menuOptionOnOff::pushRt() */
    virtual bool pushLt();/**< switches state, if inherit, call base menuOptionOnOff::pushLt() */
};
/**
 * Linear value selector menuOptionRangeValue base class is to be inherited, put your custom code at run(), read state at state
 * Uses ':' as separator
*/
class menuOptionRangeValue :public menuOption{
  public:
    int state,statePrinted,_maxValue,_minValue,_step;
    menuOptionRangeValue();/**< for compiler puposes, better not to use it*/
    menuOptionRangeValue(const char* text, int minVal, int maxVal, int initValue, int step=1);/**< constructor, sets the caption text, do not use ':', maximum, minimum, initial value, might set step */
    virtual bool refresh();/**< inherit to do your thing */
    virtual bool pushRt();/**< increases state by 1 step(see constructor), if inherit, call base menuOptionRangeValue::pushRt() */
    virtual bool pushLt();/**< decreases state by 1 step(see constructor), if inherit, call base menuOptionRangeValue::pushRt() */
};
/**
 * Utility menuoption used to change the displayed screenMenu, no need to customize or 
*/
class changeScreenMenuOption : public menuOption{
    public:
        screenMenu* _menuDesti;
        changeScreenMenuOption(screenMenu* menuDesti);/**< constructor needs target screen to jump to */
        void run();/**< to be called by menu */
        bool refresh();
};
/**
 * Screen base class, use addMenuOption to add menuoptions, to be added at menu class, inherit for fancy things like scroll and stuff
*/
class screenMenu{
  protected:
  public: 
    int whereICame; /**< for screen swapping, where i came from */
    bool autoRefresh = false;/**< tells menu wants periodical refresh */
    unsigned int totalMenuOptions;/**< running time total inserted options/options */
    unsigned int offsetFromTop =0;/**< to slide down tru menuoptions 'no dinamic-generated scroll', not used on inheritance*/
    char titol[menuTextArrayLength];/**< menu caption*/
    menuOption *displayMenuOptionsPnt[menuOptionsMax];/**< pointers to menu option/option objects shown , and run by menu*/
    screenMenu(const char* text);/**< constructor, sets text, needs menu*/
    virtual bool pushUp();/**< menu showing us tells to push Up*/
    virtual bool pushDn();/**< menu showing us tells to push Dn*/
    virtual bool pushRt(unsigned int index);/**< menu showing us tells to push right */
    virtual bool pushLt(unsigned int index);/**< menu showing us tells to push left */
    virtual bool addMenuOption(menuOption* menuoption);
    virtual bool refreshMenu();/**< called when menu changes and periodically if autoRefresh = true */
    virtual void run(unsigned int index);/**< calls run() on the index menuoption */
    virtual void bye();/**< called when leaving screen */
};
/**
 * The menu main container
 * 
 * contains the screenMenu display screens, add it via addscreen
 * works on a Stream which shows a console VT100/ANSI terminal style
 * inherits terminalParser to parse keystrokes
*/
class menu : public terminalParser{
  protected:
    char charTmp;/**< temporal character*/
    unsigned int selectedMenuOption;/**< the actual selected menu index option on display*/
    unsigned long nextEscBack = 0;/**< move screen back using esc control */
    unsigned long nextRefresh = 0;/**< screen refresh control*/
    bool runningOption = false;/**< esta excutant una opcio */
    int activeScreenMenu = -1;/**< the actual displayed menu*/
    void show(unsigned int index);/**< redraws selected menuoption text */
    virtual void cUU(unsigned int argc,int *argv);/**< inherited from terminalParser. cursor Dn handler */
    virtual void cUD(unsigned int argc,int *argv);/**< inherited from terminalParser. cursor Up handler */
    virtual void cUF(unsigned int argc,int *argv);/**< inherited from terminalParser. cursor forward right handler*/
    virtual void cUB(unsigned int argc,int *argv);/**< inherited from terminalParser. cursor backward left  handler*/
    virtual void cr();/**< inherited from terminalParser. enter */
  public:
    int totalScreenMenus = 0;/**< total amount of displayable/showAble display menus*/
    unsigned int screenMenuOptions = displayMenuOptionsDefault;/**< menuoptions to be displayed */
    screenMenu *pantalles[screenMenuMax];/**< pointers to  display menus*/
    //------set up and initialization
    menu();/**< constructor has no code */
    virtual void init(Stream *userSerialTerminal);/**< kickstart stuff and shows menu, do it at the end os setup(), after addscreen */
    void addscreen(screenMenu* pantalla);/**< adds a screen, change it using changeScreenMenuOption or setscreen do it after screenMenu.addMenuOption */
    //---------loop code
    void run();/**< to be called at loop()... AOAP As Often As Possible, not to abuse reception buffer */
    // public user interaction functions
    bool msgTxtInputSimple(const char* prompt,char* result, unsigned int maxLength, unsigned int minLength=0);/**< simple text prompt, allows (a-Z) && (A-Z) && (0-9) */
    void msgSmallWait(const char* text);/**< shows ¿alert? temporary color-inverted text for cliMsgWait milliseconds */
    void msgPause(const char* prompt);/**< shows a text and waits any keypress to continue */
    bool msgYes(const char* text);/**< asks yes/no to given text, return true if (y || Y) is press*/
    void msgPause();/**< shows default text and waits any keypress to continue */
    //---------not so used, rarely for public use
    void setscreen(int targetScreenMenu, bool setWhereICame = true);/**< change the showing screen*/
    void refresh();/**< to force screen refresh */
    void doBack();/**< sets the display to the previous one*/
    void show(bool resetCursor = true);/**< draws menu on screen  */
};

extern menu menuSystemOverTty;
extern menu * menuSystemOverTtyP;
#endif