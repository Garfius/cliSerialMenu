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
#define terminalSizeMaxQueries 4 /**< maximum number of times the terminal size will be queried before giving up */
//---------------------RESOURCES USAGE HERE
//---------------------Uncomment the following line for microcontrollers bigger than Atmega328P line RP2040 or ESP32
#define _MENU_UI_BIG_RAM_ /**< enables larger RAM features: bigger buffers, more screens, and the multiline text box editor */

//---------------------RESOURCES USAGE HERE
#ifdef _MENU_UI_BIG_RAM_
  #define screenMenuMax 10 /**< maximum number of screenMenu instances (displays) */
  #define menuTextArrayLength 80 /**< maximum caption/text buffer length including null terminator */
  #define menuOptionsMax 15 /**< maximum number of menu options per screenMenu instance */
  #define displayMenuOptionsDefault 9 /**< default number of menu options shown on screen; must be less than screenMenuMax */
  #define minTextBoxWidth 4 /**< minimum allowed text box editor width in characters */
  #else
  #define screenMenuMax 4 /**< maximum number of screenMenu instances (displays) */
  #define menuTextArrayLength 40 /**< maximum caption/text buffer length including null terminator */
  #define menuOptionsMax 7 /**< maximum number of menu options per screenMenu instance */
  #define displayMenuOptionsDefault 4 /**< default number of menu options shown on screen; must be less than screenMenuMax */
  #endif
  
  
#define escBackMillisecondsDelay 450 /**< milliseconds to wait after ESC before treating it as a back-navigation key */
#define defaultTextBoxWidth 20 /**< default single-line text input box width in characters */
#define menuTextLength (menuTextArrayLength-1) /**< maximum usable caption length (excludes null terminator) */

#define queryterminalSizeTimeout 250UL /**< milliseconds to wait for terminal size report */

static const char * msgOptionsUp = " Up!";
static const char * msgOptionsDn = " Dn!";
static const char * insertText = " INSERT";

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
    bool state; /**< current on/off state */
    bool statePrinted; /**< last state that was rendered to the terminal */
    menuOptionOnOff();/**< for compiler puposes, better not to use it*/
    menuOptionOnOff(const char* text,bool initValue=false);/**< constructor, sets the caption text, do not use ':', might set init value */
    virtual bool refresh() override;/**< inherit to do your thing */
    virtual bool pushRt() override;/**< switches state, if inherit, call base menuOptionOnOff::pushRt() */
    virtual bool pushLt() override;/**< switches state, if inherit, call base menuOptionOnOff::pushLt() */
};
/**
 * Linear value selector menuOptionRangeValue base class is to be inherited, put your custom code at run(), read state at state
 * Uses ':' as separator
*/
class menuOptionRangeValue :public menuOption{
  public:
    int state; /**< current value */
    int statePrinted; /**< last value that was rendered to the terminal */
    int _maxValue; /**< upper bound of the allowed range */
    int _minValue; /**< lower bound of the allowed range */
    int _step; /**< amount to increment or decrement per arrow key press */
    menuOptionRangeValue();/**< for compiler puposes, better not to use it*/
    menuOptionRangeValue(const char* text, int minVal, int maxVal, int initValue, int step=1);/**< constructor, sets the caption text, do not use ':', maximum, minimum, initial value, might set step */
    virtual bool refresh() override;/**< inherit to do your thing */
    virtual bool pushRt() override;/**< increases state by 1 step(see constructor), if inherit, call base menuOptionRangeValue::pushRt() */
    virtual bool pushLt() override;/**< decreases state by 1 step(see constructor), if inherit, call base menuOptionRangeValue::pushRt() */
};
/**
 * Utility menuoption used to change the displayed screenMenu, no need to customize or 
*/
class changeScreenMenuOption : public menuOption{
    public:
        screenMenu* _menuDesti; /**< pointer to the target screenMenu to navigate to */
        changeScreenMenuOption(screenMenu* menuDesti);/**< constructor needs target screen to jump to */
        void run() override;/**< to be called by menu */
        bool refresh() override;/**< to be called by menu  */
};
/**
 * Screen base class, use addMenuOption to add menuoptions, to be added at menu class, inherit for fancy things like scroll and stuff
*/
class screenMenu{
  protected:
  public: 
    int whereICame; /**< for screen swapping, where i came from */
    bool autoRefresh = false;/**< tells menu wants periodical refresh */
    bool hasMoreAbove = false;/**< tells menu wants Up!(msgOptionsUp) to be shown */
    bool hasMoreBelow = false;/**< tells menu wants Dn!(msgOptionsDn) to be shown */
    unsigned int totalMenuOptions;/**< running time total inserted options/options */
    unsigned int offsetFromTop =0;/**< to slide down tru menuoptions 'no dinamic-generated scroll', not used on inheritance*/
    unsigned int lastSelectedMenuOptionIndex = 0; /**< remembers the highlighted option index when returning to this screen */
    char titol[menuTextArrayLength];/**< menu caption*/
    menuOption *displayMenuOptionsPnt[menuOptionsMax];/**< pointers to menu option/option objects shown , and run by menu*/
    screenMenu(const char* text);/**< constructor, sets text, needs menu*/
    virtual void setHasMores();/**< set hasMoreAbove and hasMoreBelow, to be overwriten on self generated children*/
    virtual bool pushUp();/**< menu showing us tells to push Up*/
    virtual bool pushDn();/**< menu showing us tells to push Dn*/
    virtual bool pushRt(unsigned int index);/**< menu showing us tells to push right */
    virtual bool pushLt(unsigned int index);/**< menu showing us tells to push left */
    virtual bool addMenuOption(menuOption* menuoption); /**< adds a menuOption pointer to this screen; returns false if menuOptionsMax is reached */
    virtual bool refreshMenu();/**< called when menu changes and periodically if autoRefresh = true */
    virtual void run(unsigned int index);/**< calls run() on the index menuoption */
    virtual void leave();/**< called when leaving screen */
    virtual void enter();/**< called when entering screen */
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
    static constexpr char frameChars[3] = {'-','|','+'};/**< border characters: [0]=horizontal, [1]=vertical, [2]=corner */
    unsigned int selectedMenuOption;/**< the actual selected menu index option on display*/
    unsigned long nextRefresh = 0;/**< screen refresh control*/
    bool runningOption = false;/**< esta excutant una opcio */
    unsigned int contentOriginRow = 1;/**< top row where the menu content starts */
    unsigned int contentOriginCol = 1;/**< left column where the menu content starts */
    void show(unsigned int index);/**< redraws selected menuoption text */
    virtual void cUU(unsigned int argc,int *argv) override;/**< inherited from terminalParser. cursor Up handler */
    virtual void cUD(unsigned int argc,int *argv) override;/**< inherited from terminalParser. cursor Down handler */
    virtual void cUF(unsigned int argc,int *argv) override;/**< inherited from terminalParser. cursor forward right handler*/
    virtual void cUB(unsigned int argc,int *argv) override;/**< inherited from terminalParser. cursor backward left handler*/
    virtual void cPR(unsigned int argc,int *argv) override;/**< inherited from terminalParser. cursor position report*/
    virtual void cr() override;/**< inherited from terminalParser. enter */
    char lastInputChar;/**< temporal character*/
  public:
    void queryTerminalSize(bool wait4Response=true); /**< sends cursor-position probe to discover terminal dimensions; waits for CPR response when wait4Response is true */
    unsigned long nextEscBack = 0;/**< move screen back using esc control */
    uint8_t _topPadding = 1; /**< number of rows reserved at the top when not vertically centering */
    bool askTerminalSize = true;/**< ask terminal size before menu show (client might respond after being shown) */
    bool verticallyCenter = false;/**< WARNING: operations clears screen! */
    bool horizontallyCenter = true;/**< user operations are shown centered on screen */
    unsigned int terminalRowsCols[2] = {0, 0}; /**< reported terminal size: [0]=rows, [1]=columns; 0 means not yet initialised */
    uint8_t terminalSizeQueries = 0;/**< number of times terminal size has been queried */
    int activeScreenMenu = -1;/**< the actual displayed menu*/
    int totalScreenMenus = 0;/**< total amount of displayable/showAble display menus*/
    unsigned int screenMenuOptions = displayMenuOptionsDefault;/**< menuoptions to be displayed */
    screenMenu *pantalles[screenMenuMax];/**< pointers to  display menus*/
    //------set up and initialization
    menu();/**< constructor has no code */
    virtual void init(Stream *userSerialTerminal) override;/**< kickstart stuff and shows menu, do it at the end os setup(), after addscreen */
    void addscreen(screenMenu* pantalla);/**< adds a screen, change it using changeScreenMenuOption or setscreen do it after screenMenu.addMenuOption */
    //---------loop code
    void run();/**< to be called at loop()... AOAP As Often As Possible, not to abuse reception buffer */
    //----------user interaction functions
    bool msgTxtInput(const char* prompt,char* result, unsigned int maxLength, unsigned int minLength=0);/**< single line text edit, allows (a-Z) && (A-Z) && (0-9) */
    void msgSmallWait(const char* prompt);/**< shows ¿alert? temporary color-inverted text for cliMsgWait milliseconds */
    void msgPause(const char* prompt);/**< shows a text and waits any keypress to continue */
    bool msgYes(const char* prompt);/**< asks yes/no to given text, return true if (y || Y) is press*/
    void msgPause();/**< shows default text and waits any keypress to continue */
    //----------style print operations
    void printLnCentered(const char* text); /**< prints text followed by newline, horizontally centred when horizontallyCenter is set */
    void printLnCentered(const String &text); /**< @overload */
    void printLnCentered(); /**< prints an empty line */
    void printLnCentered(char c); /**< @overload */
    void printLnCentered(unsigned char b, int base = DEC); /**< @overload */
    void printLnCentered(int num, int base = DEC); /**< @overload */
    void printLnCentered(unsigned int num, int base = DEC); /**< @overload */
    void printLnCentered(long num, int base = DEC); /**< @overload */
    void printLnCentered(unsigned long num, int base = DEC); /**< @overload */
    void printLnCentered(long long num, int base = DEC); /**< @overload */
    void printLnCentered(unsigned long long num, int base = DEC); /**< @overload */
    void printLnCentered(double num, int digits = 2); /**< @overload */
    void drawProgressBar(uint32_t value, uint32_t total, char* progressBar);
    
    uint8_t dotLeadersMargin = 2; /**< left and right blank padding columns surrounding the dot-leader row */
    uint8_t dotLeadersMinDots = 2; /**< minimum number of dot characters always printed between left and right text */
    char dotLeadersChar = '.'; /**< character used to fill the dot-leader gap */
    unsigned int dotLeadersDefaultWidth = menuTextArrayLength; /**< fallback line width used when terminal width is unknown */
    unsigned int printDotLeaders(const char* left, const char* right, int margin = -1, int minDots = -1); /**< prints a dot-leader line with left and right text, returns number of lines printed */
    void setPrettyDotLeadersMargin(int bothTextsLength);/**< Sets dotLeadersMargin based on terminal width for aesthetics */
    //---------not so used, rarely for public use
    void setscreen(int targetScreenMenu, bool setWhereICame = true);/**< change the showing screen*/
    void refresh();/**< to force screen refresh */
    void doBack();/**< sets the display to the previous one*/
    void show();/**< draws menu on screen  */
};

#ifdef _MENU_UI_BIG_RAM_
#define userInputLag 50 /**< milliseconds debounce delay after a user key press in the text box editor */
#define INPUT_BUFFER_SIZE 320 /**< size in bytes of the circular character buffer used by the text box editor */
/**
 * @brief Status codes for the multiline text box editor session.
 */
enum textBoxStatus {
  noExit,
  activeEditor,
  softwareAborted,
  escPressed,
  enterPressed,
  error
};
/**
 * @brief Base class for menu options that own a multiline text box editor.
 *
 * Inherit this class and override run(), checkBackgroundEvents(), and performUserInteraction()
 * to integrate a text box editing session with the menu system.
 */
class textBoxMenuOption:public menuOption{
protected:
public:
    textBoxMenuOption(); /**< for compiler purposes, do not use directly */
    textBoxMenuOption( const char* text); /**< constructor; sets the caption text */
    virtual void run() override;
    virtual bool checkBackgroundEvents();
    virtual bool performUserInteraction();
};
/**
 * @brief Configuration structure passed to menuTextBox::msgTxtInputMultiline().
 */
struct textBoxConfig{
  const char* prompt = nullptr; /**< text displayed above the editor frame as the input prompt */
  char* result = nullptr; /**< pointer to the buffer where the edited text is read from and written back to */
  unsigned int maxLength=0; /**< maximum number of characters accepted (0 = use textLineWidth-1) */
  unsigned int minLength=0; /**< minimum number of characters required (0 = 1) */
  const char * allowedChars = nullptr; /**< null-terminated string of permitted characters; nullptr allows all printable characters */
  textBoxMenuOption* _textBoxCallBack = nullptr; /**< optional callback object whose checkBackgroundEvents() and performUserInteraction() are polled during editing */
  uint16_t textLineWidth = defaultTextBoxWidth;/**< for textBox editor width */
};
/**
 * @brief Multiline text box editor extension of menu.
 *
 * Adds an in-place full-screen text editor to the menu system. Activated via
 * msgTxtInputMultiline(). Only available when _MENU_UI_BIG_RAM_ is defined.
 */
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
    void cUB(unsigned int argc,int *argv) override;/**< inherited from terminalParser. cursor Back */
    void cUF(unsigned int argc,int *argv) override;/**< inherited from terminalParser. cursor forward */
    void cUU(unsigned int argc,int *argv) override;/**< inherited from terminalParser. cursor Up */
    void cUD(unsigned int argc,int *argv) override;/**< inherited from terminalParser. cursor Dn */
    void del() override;/**< inherited from terminalParser. delete */
    void lf() override;/**< inherited from terminalParser. line forward */
    void backSpace() override;
    void start() override;// to-do posar a menu::
    void end() override;// to-do posar a menu::
    void cr() override;/**< inherited from terminalParser. carriage return */
    textBoxConfig * runningConfig;
  public:
    static const char* exitCodeDescription[]; /**< human-readable descriptions indexed by exit code value */
    uint8_t lastTextBoxExitCode =0; /**< exit code of the last msgTxtInputMultiline() call */
    textBoxStatus _textBoxStatus = textBoxStatus::noExit; /**< current or last editor session status */
    menuTextBox();
    ~menuTextBox(); // ensur e cleanup of dynamic buffer
    void msgTxtInputMultiline(textBoxConfig * myConfig);
};
extern menuTextBox menuSystemOverTty; /**< global menu system instance (with text box support) */
extern menuTextBox * menuSystemOverTtyP; /**< pointer to the global menu system instance */

#else
extern menu menuSystemOverTty; /**< global menu system instance */
extern menu * menuSystemOverTtyP; /**< pointer to the global menu system instance */
#endif

#endif