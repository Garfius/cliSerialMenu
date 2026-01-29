# menu.h {#_menu_8h_source}

menu.h

Go to the documentation of this file.

    1 
    13 #ifndef __menu__
    14 #define __menu__
    15 #include "terminalParser.h"
    16 #include <Arduino.h>
    17 #define terminalSizeMaxQueries 4
    18 //---------------------RESOURCES USAGE HERE
    19 //---------------------Uncomment the following line for microcontrollers bigger than Atmega328P line RP2040 or ESP32
    20 #define _MENU_UI_BIG_RAM_
    21 
    22 //---------------------RESOURCES USAGE HERE
    23 #ifdef _MENU_UI_BIG_RAM_
    24   #define screenMenuMax 6// maximum screenMenu instances, displays
    25   #define menuTextArrayLength 80 // Max caption length 
    26   #define menuOptionsMax 12 // maximum menu options allowed in memory for each screenMenu instance
    27   #define displayMenuOptionsDefault 8 // the amount of menu options on the screen, always lower than screenMenuMax
    28   #define minTextBoxWidth 4
    29   #else
    30   #define screenMenuMax 4// maximum screenMenu instances, displays of menuitems
    31   #define menuTextArrayLength 40 // Max caption length 
    32   #define menuOptionsMax 7 // maximum menu options allowed in memory for each screenMenu instance
    33   #define displayMenuOptionsDefault 4 // the amount of menu options on the screen, always lower than screenMenuMax
    34   #endif
    35   
    36   
    37 #define escBackMillisecondsDelay 450 // wait until esc is known as 'wants to go back'
    38 #define defaultTextBoxWidth 20
    39 #define menuTextLength (menuTextArrayLength-1)
    40 
    41 #define queryterminalSizeTimeout 250UL 
    42 
    43 static const char * msgOptionsUp = " Up!";
    44 static const char * msgOptionsDn = " Dn!";
    45 static const char * insertText = " INSERT";
    46 
    47 class menuTextBox;
    48 class screenMenu;
    49 class menu;
    50 
    51 enum textBoxStatus {
    52   noExit,
    53   activeEditor,
    54   softwareAborted,
    55   escPressed,
    56   enterPressed,
    57   error
    58 }; 
    59 
    63 class menuOption{
    64   public:
    65     menuOption();
    66     menuOption(const char* text);
    67     char text[menuTextArrayLength];
    68     virtual void run();
    69     virtual bool refresh();
    70     virtual bool pushRt();
    71     virtual bool pushLt();
    72     bool autoRefresh = true;
    73 };
    78 class menuOptionOnOff :public menuOption{
    79   public:
    80     bool state,statePrinted;
    81     menuOptionOnOff();
    82     menuOptionOnOff(const char* text,bool initValue=false);
    83     virtual bool refresh() override;
    84     virtual bool pushRt() override;
    85     virtual bool pushLt() override;
    86 };
    91 class menuOptionRangeValue :public menuOption{
    92   public:
    93     int state,statePrinted,_maxValue,_minValue,_step;
    94     menuOptionRangeValue();
    95     menuOptionRangeValue(const char* text, int minVal, int maxVal, int initValue, int step=1);
    96     virtual bool refresh() override;
    97     virtual bool pushRt() override;
    98     virtual bool pushLt() override;
    99 };
    103 class changeScreenMenuOption : public menuOption{
    104     public:
    105         screenMenu* _menuDesti;
    106         changeScreenMenuOption(screenMenu* menuDesti);
    107         void run() override;
    108         bool refresh() override;
    109 };
    113 class screenMenu{
    114   protected:
    115   public: 
    116     int whereICame; 
    117     bool autoRefresh = false;
    118     bool hasMoreAbove = false;
    119     bool hasMoreBelow = false;
    120     unsigned int totalMenuOptions;
    121     unsigned int offsetFromTop =0;
    122     unsigned int lastSelectedMenuOptionIndex = 0;
    123     char titol[menuTextArrayLength];
    124     menuOption *displayMenuOptionsPnt[menuOptionsMax];
    125     screenMenu(const char* text);
    126     virtual void setHasMores();
    127     virtual bool pushUp();
    128     virtual bool pushDn();
    129     virtual bool pushRt(unsigned int index);
    130     virtual bool pushLt(unsigned int index);
    131     virtual bool addMenuOption(menuOption* menuoption);
    132     virtual bool refreshMenu();
    133     virtual void run(unsigned int index);
    134     virtual void leave();
    135     virtual void enter();
    136 };
    144 class menu : public terminalParser{
    145   protected:
    146     static constexpr char frameChars[3] = {'-','|','+'};//horizontal, vertical, corner
    147     unsigned int selectedMenuOption;
    148     unsigned long nextRefresh = 0;
    149     bool runningOption = false;
    150     unsigned int contentOriginRow = 1;
    151     unsigned int contentOriginCol = 1;
    152     void show(unsigned int index);
    153     virtual void cUU(unsigned int argc,int *argv) override;
    154     virtual void cUD(unsigned int argc,int *argv) override;
    155     virtual void cUF(unsigned int argc,int *argv) override;
    156     virtual void cUB(unsigned int argc,int *argv) override;
    157     virtual void cPR(unsigned int argc,int *argv) override;
    158     virtual void cr() override;
    159     void queryTerminalSize(bool wait4Response=true);
    160     char lastInputChar;
    161     unsigned long nextEscBack = 0;
    162   public:
    163     uint8_t _topPadding = 1;
    164     bool askTerminalSize = true;
    165     bool verticallyCenter = false;
    166     bool horizontallyCenter = true;
    167     unsigned int terminalRowsCols[2] = {0, 0};
    168     uint8_t terminalSizeQueries = 0;
    169     int activeScreenMenu = -1;
    170     int totalScreenMenus = 0;
    171     unsigned int screenMenuOptions = displayMenuOptionsDefault;
    172     screenMenu *pantalles[screenMenuMax];
    173     //------set up and initialization
    174     menu();
    175     virtual void init(Stream *userSerialTerminal) override;
    176     void addscreen(screenMenu* pantalla);
    177     //---------loop code
    178     void run();
    179     //----------user interaction functions
    180     bool msgTxtInput(const char* prompt,char* result, unsigned int maxLength, unsigned int minLength=0);
    181     void msgSmallWait(const char* prompt);
    182     void msgPause(const char* prompt);
    183     bool msgYes(const char* prompt);
    184     void msgPause();
    185     //----------style print operations
    186     void setPrettyDotLeadersMargin(int bothTextsLength);
    187     void printLnCentered(const char* text);
    188     void printLnCentered(const String &text);
    189     void printLnCentered();
    190     void printLnCentered(char c);
    191     void printLnCentered(unsigned char b, int base = DEC);
    192     void printLnCentered(int num, int base = DEC);
    193     void printLnCentered(unsigned int num, int base = DEC);
    194     void printLnCentered(long num, int base = DEC);
    195     void printLnCentered(unsigned long num, int base = DEC);
    196     void printLnCentered(long long num, int base = DEC);
    197     void printLnCentered(unsigned long long num, int base = DEC);
    198     void printLnCentered(double num, int digits = 2);
    199     
    200     uint8_t dotLeadersMargin = 2;
    201     uint8_t dotLeadersMinDots = 2;
    202     char dotLeadersChar = '.';
    203     unsigned int dotLeadersDefaultWidth = menuTextArrayLength;
    204     unsigned int printDotLeaders(const char* left, const char* right, int margin = -1, int minDots = -1);
    205     //---------not so used, rarely for public use
    206     void setscreen(int targetScreenMenu, bool setWhereICame = true);
    207     void refresh();
    208     void doBack();
    209     void show();
    210 };
    211 
    212 #ifdef _MENU_UI_BIG_RAM_
    213 #define userInputLag 50
    214 #define INPUT_BUFFER_SIZE 320
    215 
    216 class textBoxMenuOption:public menuOption{
    217 protected:
    218 public:
    219     String caption;
    220     textBoxMenuOption();
    221     textBoxMenuOption( const char* text);
    222     virtual void run() override;
    223     virtual bool checkBackgroundEvents();
    224     virtual bool performUserInteraction();
    225 };
    226 
    227 class menuTextBox:public  menu{
    228   private:
    229     bool lastInsertStatus;
    230     char* _result = nullptr; // ownership: class allocates/frees
    231     unsigned int _maxStrLen = 0;
    232     unsigned int cursorBufferIndex = 0;
    233     unsigned long lastUserInputTime = 0;
    234     void drawTextPreCursor();
    235     void drawTextPostCursor(unsigned int fromLineToEnd);
    236     void redrawLine(unsigned int line);
    237     void cleanupEditor();
    238     void removeCharAtIndex(unsigned int index);
    239     void manageCaretAndSpace(bool erase = false);
    240     unsigned int getCursorRowIndex();
    241     unsigned int getTotalLinesCapacity();
    242     unsigned int getWrittenLinesCount();
    243     unsigned int getCursorColIndex();
    244     unsigned int getCaptionLinesCount();
    245     unsigned int drawnFrameHeight;
    246     void redrawFrame();
    247     void drawFrame(bool erase = false);
    248     void statusBar();
    249     void eraseStatusBar();
    250     //---------- redirigeixen a terminalParser
    251     void cUB(unsigned int argc,int *argv) override;
    252     void cUF(unsigned int argc,int *argv) override;
    253     void cUU(unsigned int argc,int *argv) override;
    254     void cUD(unsigned int argc,int *argv) override;
    255     void del() override;
    256     void lf() override;
    257     void backSpace() override;
    258     void start() override;// to-do posar a menu::
    259     void end() override;// to-do posar a menu::
    260     void cr() override;
    261   public:
    262     static const char* exitCodeDescription[];
    263     uint16_t textLineWidth = defaultTextBoxWidth;
    264     uint8_t lastTextBoxExitCode =0;
    265     menuTextBox();
    266     ~menuTextBox(); // ensur e cleanup of dynamic buffer
    267     textBoxStatus _textBoxStatus = textBoxStatus::noExit;
    268     textBoxMenuOption* _textBoxCallBack = nullptr;
    269     void msgTxtInputMultiline(char* result, unsigned int maxLength, unsigned int minLength=0,const char * allowedChars = nullptr);
    270 };
    271 extern menuTextBox menuSystemOverTty;
    272 extern menuTextBox * menuSystemOverTtyP;
    273 
    274 #else
    275 extern menu menuSystemOverTty;
    276 extern menu * menuSystemOverTtyP;
    277 #endif
    278 
    279 #endif
