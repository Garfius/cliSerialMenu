<a id="menu_8cpp"></a>
# File menu.cpp

![][C++]

**Location**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.cpp`

Code for [menu.h](menu_8h.md#menu_8h).

Might want to change some preprocessor directives to customize beheaviour






**author**\
Gerard Forcada Bigas


**date**\
20/12/22

## Classes

* [CharBuffer](class_char_buffer.md#class_char_buffer)

## Includes

* [menu.h](menu_8h.md#menu_8h)


```mermaid
graph LR
4["Arduino.h"]

1["menu.cpp"]
click 1 "menu_8cpp.md#menu_8cpp"
1 --> 2

2["menu.h"]
click 2 "menu_8h.md#menu_8h"
2 --> 3
2 --> 4

3["terminalParser.h"]
click 3 "terminal_parser_8h.md#terminal_parser_8h"
3 --> 4

```


## Macros

<a id="menu_8cpp_1a8c877b00dc535facfa2f3b35b1b74b7f"></a>
### Macro menuOptionDelimiter

![][public]


```cpp
#define menuOptionDelimiter ':'
```








<a id="menu_8cpp_1a4b8e37dc95cdf19253602512c729c8dc"></a>
### Macro cliMsgWait

![][public]


```cpp
#define cliMsgWait 1250
```








<a id="menu_8cpp_1a5821e981efec035ed35549f99ab2d8d6"></a>
### Macro menuRefreshInterval

![][public]


```cpp
#define menuRefreshInterval 250
```








## Variables

<a id="menu_8cpp_1a4df13028e814c836b0760b2861e7503d"></a>
### Variable pressAnyKeyToContinue

![][public]
![][static]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.cpp` (line 18)


```cpp
const char* pressAnyKeyToContinue = "Press any key to continue"
```








**Type**: const char *

<a id="menu_8cpp_1a4675348869a81e85e179f090ba3329df"></a>
### Variable buffer

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.cpp` (line 922)


```cpp
CharBuffer buffer
```








**Type**: [CharBuffer](class_char_buffer.md#class_char_buffer)

<a id="menu_8cpp_1a58aa1cbda0d0701af5cd55568509cd68"></a>
### Variable menuSystemOverTty

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.cpp` (line 1643)


```cpp
menuTextBox menuSystemOverTty
```








**Type**: [menuTextBox](classmenu_text_box.md#classmenu_text_box)

<a id="menu_8cpp_1a2e8e5a0db1e23bfacce9ac4ad19e69e9"></a>
### Variable menuSystemOverTtyP

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.cpp` (line 1644)


```cpp
menuTextBox* menuSystemOverTtyP = &menuSystemOverTty
```








**Type**: [menuTextBox](classmenu_text_box.md#classmenu_text_box) *

## Source


```cpp

#include "menu.h"

//CONFIG HERE
#define menuOptionDelimiter ':'
#define cliMsgWait 1250 // push message timeout
#define menuRefreshInterval 250 // self-explanatory

static const char * pressAnyKeyToContinue = "Press any key to continue";

void menuOption::run(){}
bool menuOption::refresh(){return false;}
bool menuOption::pushRt(){ return false;}
bool menuOption::pushLt(){return false;}
menuOption::menuOption(const char* textUser){
    if(strlen(textUser) <= menuTextLength){
        strcpy(text, textUser);
    }else{
        strcpy(text, "*");
    }
}
menuOption::menuOption(){
}
menu::menu(){
}
void menu::init(Stream *userSerialTerminal){
    terminalParser::init(userSerialTerminal);
    if(totalScreenMenus < 1)return;// comment out?
    queryTerminalSize();
    setscreen(0);
    show();
}
void menu::show(unsigned int index){
    screenMenu *active = pantalles[activeScreenMenu];
    unsigned int displayIndex = index + active->offsetFromTop;
    unsigned int targetRow = contentOriginRow + 1 + index;

    doMoveCursor(targetRow, contentOriginCol);
    doEL();
    if(displayIndex < active->totalMenuOptions){
        userTty->write('-');
        userTty->print(active->displayMenuOptionsPnt[displayIndex]->text);
    }
    doMoveCursor(contentOriginRow + 1 + selectedMenuOption, contentOriginCol);
    userTty->flush();
}
void menu::show(){
    if(totalScreenMenus == 0)return;// safe
    queryTerminalSize(askTerminalSize && (terminalRowsCols[0] == 0)&&(terminalSizeQueries < terminalSizeMaxQueries));

    screenMenu *active = pantalles[activeScreenMenu];
    unsigned int visibleOptions = active->totalMenuOptions < screenMenuOptions ? active->totalMenuOptions : screenMenuOptions;
    unsigned int headerLen = strlen(active->titol);

    if(active->hasMoreAbove){
        headerLen += strlen(msgOptionsUp);
    }
    if(active->hasMoreBelow){
        headerLen += strlen(msgOptionsDn);
    }

    unsigned int maxOptionLen = 0;
    for(unsigned int i = 0; i < visibleOptions; ++i){
        unsigned int idx = i + active->offsetFromTop;
        if(idx >= active->totalMenuOptions)break;
        unsigned int optionLen = 1 + strlen(active->displayMenuOptionsPnt[idx]->text);
        if(optionLen > maxOptionLen){
            maxOptionLen = optionLen;
        }
    }

    unsigned int contentWidth = maxOptionLen;
    if(contentWidth == 0){
        contentWidth = 1;
    }

    unsigned int contentHeight = 1 + visibleOptions;

    if(verticallyCenter && (terminalRowsCols[0] > 0) && (terminalRowsCols[0] > contentHeight)){
        unsigned int topPadding = (terminalRowsCols[0] - contentHeight) / 2;
        contentOriginRow = 1;
    }else if((terminalRowsCols[0] > 0) && (terminalRowsCols[0] > (contentHeight+_topPadding))){
        contentOriginRow = 1 + _topPadding;
    }else{
        contentOriginRow = 1;
    }

    if(horizontallyCenter && (terminalRowsCols[1] > 0) && (terminalRowsCols[1] > contentWidth)){
        unsigned int leftPadding = (terminalRowsCols[1] - contentWidth) / 2;
        contentOriginCol = 1 + leftPadding;
    }else{
        contentOriginCol = 1;
    }

    // Calculate header position: center it relative to options if narrower, otherwise align left
    unsigned int headerStartCol = contentOriginCol;
    if(horizontallyCenter &&(terminalRowsCols[1] > 0) && (headerLen > contentWidth)){
        headerStartCol = (terminalRowsCols[1] - headerLen) / 2;
    }

    this->doClearScreen();
    this->doMoveCursor(contentOriginRow, headerStartCol);
    userTty->write(inverteixColorsTerminal);
    userTty->print(active->titol);
    if(active->hasMoreAbove){
        userTty->print(msgOptionsUp);
    }
    if(active->hasMoreBelow){
        userTty->print(msgOptionsDn);
    }
    userTty->write(colorsTerminalReset);

    for(unsigned int i = 0; i < visibleOptions; ++i){
        unsigned int idx = i + active->offsetFromTop;
        if(idx >= active->totalMenuOptions)break;
        this->doMoveCursor(contentOriginRow + 1 + i, contentOriginCol);
        userTty->write('-');
        if((terminalRowsCols[1] > 0) && ((strlen(active->displayMenuOptionsPnt[idx]->text)+contentOriginCol) > terminalRowsCols[1])){
            userTty->write((const uint8_t*)active->displayMenuOptionsPnt[idx]->text, (terminalRowsCols[1]-contentOriginCol)-2);
            userTty->print("..");
        }else{
            userTty->print(active->displayMenuOptionsPnt[idx]->text);
        }
    }

    if((selectedMenuOption >= active->totalMenuOptions) || (selectedMenuOption >=visibleOptions)){
        selectedMenuOption = 0;
    }

    if(visibleOptions > 0){
        if(selectedMenuOption >= visibleOptions){
            selectedMenuOption = visibleOptions - 1;
        }
        doMoveCursor(contentOriginRow + 1 + selectedMenuOption, contentOriginCol);
    }else{
        doMoveCursor(contentOriginRow, contentOriginCol);
    }
    userTty->flush();
}
void menu::cUU(unsigned int argc,int *argv){// keyUp
    if(runningOption)return;
    if(selectedMenuOption < 1){
        if(this->pantalles[activeScreenMenu]->pushUp()){
            show();
        }
        return;
    }
    selectedMenuOption--;
    doMoveCursor(contentOriginRow + 1 + selectedMenuOption,contentOriginCol);
    terminalParser::cUU(argc,argv);
}
void menu::cUD(unsigned int argc,int *argv){// keyDn
    if(runningOption)return;
    if((this->pantalles[activeScreenMenu]->totalMenuOptions > screenMenuOptions) && ((selectedMenuOption+1)) >= screenMenuOptions){
        if(this->pantalles[activeScreenMenu]->pushDn()){
            show();// scroll
        }
        return;
    }else if((selectedMenuOption+1) >= pantalles[activeScreenMenu]->totalMenuOptions){
        if(this->pantalles[activeScreenMenu]->pushDn()){
            show();// scroll
        }
        return;
    }
    selectedMenuOption++;
    doMoveCursor(contentOriginRow + 1 + selectedMenuOption,contentOriginCol);
    terminalParser::cUD(argc,argv);
}
void menu::cUF(unsigned int argc,int *argv){
    if(pantalles[activeScreenMenu]->pushRt(selectedMenuOption)){
        show((unsigned int)selectedMenuOption);// terminalparser::cUF
    }
}
void menu::cUB(unsigned int argc,int *argv){
    if(pantalles[activeScreenMenu]->pushLt(selectedMenuOption)){
        show((unsigned int)selectedMenuOption);// terminalparser::cUF
    }
}
void menu::cPR(unsigned int argc,int *argv){
    if(argc != 2)return;
    bool newSize = ((terminalRowsCols[0] != (unsigned int)argv[0])||(terminalRowsCols[1] != (unsigned int)argv[1]));
    terminalRowsCols[0] = (unsigned int)argv[0];
    terminalRowsCols[1] = (unsigned int)argv[1];
    terminalParser::cPR(argc,argv);
    if((activeScreenMenu > -1) && newSize)menu::show();
}
void menu::cr(){
    doClearScreen();
    doMoveCursor(1,1);
    runningOption = true;
    pantalles[activeScreenMenu]->run(this->selectedMenuOption);
    runningOption = false;
    if(this->pantalles[activeScreenMenu]->totalMenuOptions == 0) {
        msgSmallWait("no options");
        doBack();
    }
    show();
    terminalParser::cr();
}
void menu::addscreen(screenMenu* pantalla){
    if(totalScreenMenus == screenMenuMax)return;
    pantalles[totalScreenMenus] = pantalla;
    totalScreenMenus+=1;
}
void menu::setscreen(int pantallaDesti,bool setWhereICame){
    if(activeScreenMenu > -1)pantalles[activeScreenMenu]->leave();
    if(setWhereICame)pantalles[pantallaDesti]->whereICame = activeScreenMenu;
    pantalles[activeScreenMenu]->lastSelectedMenuOptionIndex = selectedMenuOption;
    activeScreenMenu = pantallaDesti;
    pantalles[activeScreenMenu]->refreshMenu();
    pantalles[activeScreenMenu]->setHasMores();
    pantalles[activeScreenMenu]->enter();
    selectedMenuOption = pantalles[activeScreenMenu]->lastSelectedMenuOptionIndex;
}
void menu::refresh(){
    if(pantalles[activeScreenMenu]->autoRefresh){
        if(pantalles[activeScreenMenu]->refreshMenu()){
            show();
        }
    }
}
void menu::run(){
    if(userTty->available() != 0){
        lastInputChar = userTty->read();
        this->doGuess(lastInputChar);
        if(lastInputChar == '\e'){nextEscBack = (millis()+escBackMillisecondsDelay);}
    }else{
        if(lastInputChar == '\e'){
            if(millis() > nextEscBack){
                lastInputChar = '\0';
                doGuess(lastInputChar);
                doBack();
                show();
            }
        }else{
            if(millis() > nextRefresh){
                this->refresh();
                nextRefresh = menuRefreshInterval + millis();
            }
        }
    }
}
void menu::doBack(){
    if(pantalles[activeScreenMenu]->whereICame >= 0){
        this->setscreen(pantalles[activeScreenMenu]->whereICame,false);
    }
}
void menu::msgSmallWait(const char* prompt){
        unsigned int textLen = strlen(prompt);
        unsigned int startCol = 1;
        
        if(verticallyCenter) {
            doClearScreen();
            doMoveCursor(1,1);
            if(terminalRowsCols[0] > 1) doCUD((terminalRowsCols[0] - 1) / 2);
        }

        if (horizontallyCenter && terminalRowsCols[1] > textLen) {
            startCol = (terminalRowsCols[1] - textLen) / 2;
            if (startCol == 0) startCol = 1;
        }
        if(startCol > 1) doCUF(startCol - 1);
        userTty->write(inverteixColorsTerminal);
        userTty->write(prompt);
        userTty->write(colorsTerminalReset);
        userTty->flush();
        delay(cliMsgWait);
        userTty->write('\r');
        //-------------
        if (terminalRowsCols[1] > 0) {
            if (textLen > terminalRowsCols[1]) {
                unsigned int linesUsed = (textLen + terminalRowsCols[1] - 1) / terminalRowsCols[1];
                doCUU(linesUsed - 1);
            }
        }
        //---------------
        if(startCol > 1) doCUF(startCol - 1);
        userTty->println(prompt);
}
bool menu::msgYes(const char* prompt){
    String _prompt = String(prompt) + " y/n";
    unsigned int textLen = _prompt.length();
    unsigned int startCol = 1;

    if(verticallyCenter) {
        doClearScreen();
        doMoveCursor(1,1);
        if(terminalRowsCols[0] > 1) doCUD((terminalRowsCols[0] - 1) / 2);
    }

    if (horizontallyCenter && terminalRowsCols[1] > textLen) {
        startCol = (terminalRowsCols[1] - textLen) / 2;
        if (startCol == 0) startCol = 1;
    }
    if(startCol > 1) doCUF(startCol - 1);
    userTty->write(inverteixColorsTerminal);
    userTty->print(_prompt);
    userTty->write(colorsTerminalReset);
    userTty->flush();
    while(userTty->available() ==0){}
    char keyPressed = userTty->read();
    delay(10);
    while (userTty->available())userTty->read();// empty buffer
    userTty->write('\r');
    //doEL();
    _prompt += "=";
    _prompt += keyPressed;
    textLen = _prompt.length();
    startCol = 1;
    if (horizontallyCenter && terminalRowsCols[1] > textLen) {
        startCol = (terminalRowsCols[1] - textLen) / 2;
        if (startCol == 0) startCol = 1;
    }
    if(startCol > 1) doCUF(startCol - 1);
    //if the ((initial prompt length printed at line 314) > columns) doCUU((the number of lines used)-1)
    if (terminalRowsCols[1] > 0) {
        unsigned int initialPromptLen = textLen - 2;
        if (initialPromptLen > terminalRowsCols[1]) {
            unsigned int linesUsed = (initialPromptLen + terminalRowsCols[1] - 1) / terminalRowsCols[1];
            doCUU(linesUsed - 1);
        }
    }
    
    userTty->println(_prompt);
    return (keyPressed == 'y') || (keyPressed == 'Y');
}
void menu::msgPause(const char* prompt){
    unsigned int contentHeight = (prompt != nullptr) ? 2 : 1;
    if(verticallyCenter) {
        doClearScreen();
        doMoveCursor(1,1);
        if(terminalRowsCols[0] > contentHeight) doCUD((terminalRowsCols[0] - contentHeight) / 2);
    }
    
    if(horizontallyCenter)userTty->write('\r');
    unsigned int promptLen,promptCol;
    userTty->write(inverteixColorsTerminal);
    if(prompt != nullptr){
        promptLen = strlen(prompt);
        promptCol = 1;
        if (horizontallyCenter && terminalRowsCols[1] > promptLen) {
            promptCol = (terminalRowsCols[1] - promptLen) / 2;
            if (promptCol == 0) promptCol = 1;
        }
        if(promptCol > 1) doCUF(promptCol - 1);
        userTty->println(prompt);
    }
    unsigned int msgLen = strlen(pressAnyKeyToContinue);
    unsigned int msgCol = 1;
    if (horizontallyCenter && terminalRowsCols[1] > msgLen) {
        msgCol = (terminalRowsCols[1] - msgLen) / 2;
        if (msgCol == 0) msgCol = 1;
    }
    if(msgCol > 1) doCUF(msgCol - 1);
    userTty->write(pressAnyKeyToContinue);
    userTty->write(colorsTerminalReset);
    userTty->flush();
    while(userTty->available() ==0){}
    delay(10);
    while (userTty->available())userTty->read();// empty buffer

    //userTty->write('\r');
    //doEL();// to be replaced with cub(length) to start if horizontallyCenter and spaces(no prompt check)
    doCUB(msgLen);
    for(unsigned int i =0;i < msgLen;i++)userTty->write(' ');
    if(prompt != nullptr){
        unsigned int promptLines = 1;
        if (terminalRowsCols[1] > 0 && promptLen > 0) {
            // Calculate the number of lines the prompt text will occupy.
            promptLines = (promptLen + terminalRowsCols[1] - 1) / terminalRowsCols[1];
        }
        doCUU(promptLines);
        userTty->write('\r');// here cursor is at the prompt line
        if(promptCol > 1) doCUF(promptCol - 1);
        userTty->println(prompt);
    }else{
        userTty->write('\r');
    }
}
void menu::msgPause(){
    msgPause(nullptr);
}
void menu::setPrettyDotLeadersMargin(int bothTextsLength){
    unsigned int width = (terminalRowsCols[1] > 0) ? terminalRowsCols[1] : dotLeadersDefaultWidth;

    // Calculate space remaining after text and minimum dots
    int remainingSpace = (int)width - bothTextsLength - (int)dotLeadersMinDots;

    if (remainingSpace < 0) {
        dotLeadersMargin = 0;
        return;
    }

    // Aesthetic target: 1/8th of screen width (approx 12.5%)
    unsigned int aestheticMargin = width / 8;
    unsigned int maxMargin = remainingSpace / 2;

    // Choose the smaller of aesthetic target or maximum possible
    dotLeadersMargin = (aestheticMargin < maxMargin) ? (uint8_t)aestheticMargin : (uint8_t)maxMargin;
}
void menu::printLnCentered(const char* text){
    if(text == nullptr) {
        userTty->println();
        return;
    }
    if(horizontallyCenter)userTty->write('\r');
    unsigned int textLen = strlen(text);
    if (horizontallyCenter && terminalRowsCols[1] > textLen) {
        unsigned int padding = (terminalRowsCols[1] - textLen) / 2;
        if (padding > 0) doCUF(padding);
    }
    userTty->println(text);
}
void menu::printLnCentered(const String &text){
    printLnCentered(text.c_str());
}
void menu::printLnCentered(){
    userTty->println();
}
void menu::printLnCentered(char c){
    char buf[2] = {c, 0};
    printLnCentered(buf);
}
void menu::printLnCentered(unsigned char b, int base){
    printLnCentered(String(b, base));
}
void menu::printLnCentered(int num, int base){
    printLnCentered(String(num, base));
}
void menu::printLnCentered(unsigned int num, int base){
    printLnCentered(String(num, base));
}
void menu::printLnCentered(long num, int base){
    printLnCentered(String(num, base));
}
void menu::printLnCentered(unsigned long num, int base){
    printLnCentered(String(num, base));
}
void menu::printLnCentered(long long num, int base){
    printLnCentered(String((long)num, base));
}
void menu::printLnCentered(unsigned long long num, int base){
    printLnCentered(String((unsigned long)num, base));
}
void menu::printLnCentered(double num, int digits){
    printLnCentered(String(num, digits));
}
unsigned int menu::printDotLeaders(const char* left, const char* right, int margin, int minDots){
    unsigned int _margin = (margin >= 0) ? margin : dotLeadersMargin;
    unsigned int _minDots = (minDots >= 0) ? minDots : dotLeadersMinDots;
    unsigned int _width = (terminalRowsCols[1] > 0) ? terminalRowsCols[1] : dotLeadersDefaultWidth;
    
    if (_width <= (_margin * 2 + _minDots)) return 0;
    
    unsigned int maxContentWidth = _width - (_margin * 2);
    unsigned int lines = 1;
    
    auto printMargin = [&]() {
        for(unsigned int i=0; i<_margin; ++i) userTty->write(' ');
    };

    if(horizontallyCenter) userTty->write('\r');
    printMargin();
    
    unsigned int currentLen = 0;
    unsigned int leftLen = strlen(left);
    
    for (unsigned int i = 0; i < leftLen; ++i) {
        if (currentLen >= maxContentWidth) {
            userTty->println();
            if(horizontallyCenter) userTty->write('\r');
            printMargin();
            currentLen = 0;
            lines++;
        }
        userTty->write(left[i]);
        currentLen++;
    }
    
    unsigned int rightLen = strlen(right);
    
    if (rightLen > 0) {
        if (currentLen + _minDots + 1 > maxContentWidth) {
             userTty->println();
             if(horizontallyCenter) userTty->write('\r');
             printMargin();
             currentLen = 0;
             lines++;
        }
    }
    
    unsigned int dotsCount = _minDots;
    if (rightLen < maxContentWidth) {
        unsigned int spaceForRight = maxContentWidth - rightLen;
        if (spaceForRight > currentLen) {
            unsigned int fill = spaceForRight - currentLen;
            if (fill > _minDots) dotsCount = fill;
        }
    }
    
    for(unsigned int i=0; i<dotsCount; ++i){
        if (currentLen >= maxContentWidth) {
             userTty->println();
             if(horizontallyCenter) userTty->write('\r');
             printMargin();
             currentLen = 0;
             lines++;
        }
        userTty->write(dotLeadersChar);
        currentLen++;
    }
    
    for (unsigned int i = 0; i < rightLen; ++i) {
        if (currentLen >= maxContentWidth) {
            userTty->println();
            if(horizontallyCenter) userTty->write('\r');
            printMargin();
            currentLen = 0;
            lines++;
        }
        userTty->write(right[i]);
        currentLen++;
    }
    
    userTty->println();
    return lines;
}
bool menu::msgTxtInput(const char* prompt,char* result, unsigned int maxLength, unsigned int minLength){
    if(maxLength == 0 )maxLength= defaultTextBoxWidth-1;
    if(minLength == 0 )minLength= 1;

    unsigned int boxWidth = maxLength + 2;
    unsigned int startCol = 1;

    if (horizontallyCenter && terminalRowsCols[1] > boxWidth) {
        startCol = (terminalRowsCols[1] - boxWidth) / 2;
        if (startCol == 0) startCol = 1;
    }

    if (verticallyCenter) {
        doClearScreen();
        doMoveCursor(1,1);
        unsigned int boxHeight = 3;
        unsigned int startRow = 1;
        if (terminalRowsCols[0] > boxHeight) {
            startRow = (terminalRowsCols[0] - boxHeight) / 2;
            if (startRow == 0) startRow = 1;
        }
        if(startRow > 1) doCUD(startRow - 1);

        if (prompt) {
            unsigned int promptLen = strlen(prompt);
            unsigned int promptCol = 1;
            if (horizontallyCenter && terminalRowsCols[1] > promptLen) {
                promptCol = (terminalRowsCols[1] - promptLen) / 2;
                if (promptCol == 0) promptCol = 1;
            }
            if(promptCol > 1) doCUF(promptCol - 1);
            userTty->print(prompt);
            userTty->write('\r');
        }
        userTty->write('\n');
    } else {
        if (prompt) {
            unsigned int promptLen = strlen(prompt);
            unsigned int promptCol = 1;
            if (horizontallyCenter && terminalRowsCols[1] > promptLen) {
                promptCol = (terminalRowsCols[1] - promptLen) / 2;
                if (promptCol == 0) promptCol = 1;
            }
            if(promptCol > 1) doCUF(promptCol - 1);
            userTty->println(prompt);
        } else {
            userTty->println();
        }
    }

    if(startCol > 1) doCUF(startCol - 1);

    userTty->write(frameChars[1]);
    doCUF(maxLength);
    userTty->write(frameChars[1]);

    //doCUD(1);
    userTty->write('\n');
    doCUB(maxLength + 2);
    userTty->write(frameChars[2]);
    for (unsigned int i = 0; i < maxLength; ++i) userTty->write(frameChars[0]);
    userTty->write(frameChars[2]);

    doCUU(1);
    doCUB(maxLength + 1);

    String tmpStr = String(result);
    lastInputChar = '\0';
    userTty->print(tmpStr);

    while (true) {
        if((userTty->available() > 0 )) {
            lastInputChar = userTty->read();
            if(lastInputChar == '\e'){nextEscBack = (millis()+escBackMillisecondsDelay);}
            if (lastInputChar == '\r') {
                break;
            }else if (((lastInputChar == '\b') ||(lastInputChar == '\177')) && (tmpStr.length() > 0)) {
                userTty->print("\b \b");
                tmpStr.remove(tmpStr.length()-1);
            }else{
                if(lastInputChar && (tmpStr.length() < maxLength)){
                    if((lastInputChar > 64 && lastInputChar < 91) || (lastInputChar > 96 && lastInputChar < 123) || (lastInputChar > 47 && lastInputChar < 58) || (lastInputChar == 32)){
                        userTty->write(lastInputChar);
                        tmpStr.concat(lastInputChar);
                    }
                }
            }
        }else{
            if(lastInputChar == '\e'){
                if(millis() > nextEscBack){
                    break;
                }
            }
        }
    }

    doCUD(2);
    userTty->write('\r');

    if(lastInputChar == '\e'){
        lastInputChar = '\0';
        return false;
    }else if(strlen(tmpStr.c_str()) < minLength){
        tmpStr = String(minLength)+" chars min";
        doCUU(3);
        userTty->write('\r');
        doEL(true);
        unsigned int errLen = tmpStr.length();
        unsigned int errCol = 1;
        if (horizontallyCenter && terminalRowsCols[1] > errLen) {
            errCol = (terminalRowsCols[1] - errLen) / 2;
            if(errCol > 1) doCUF(errCol - 1);
        }
        userTty->write(inverteixColorsTerminal);
        userTty->print(tmpStr.c_str());
        userTty->write(colorsTerminalReset);
        userTty->flush();
        delay(cliMsgWait);
        return false;
    }else if(tmpStr.indexOf('\e') >= 0){
        doCUU(3);
        userTty->write('\r');
        doEL(true);
        const char* err = "corrupt txt";
        unsigned int errLen = strlen(err);
        unsigned int errCol = 1;
        if (horizontallyCenter && terminalRowsCols[1] > errLen) {
            errCol = (terminalRowsCols[1] - errLen) / 2;
            if(errCol > 1) doCUF(errCol - 1);
        }
        userTty->write(inverteixColorsTerminal);
        userTty->print(err);
        userTty->write(colorsTerminalReset);
        userTty->flush();
        delay(cliMsgWait);
        return false;
    }

    strcpy(result, tmpStr.c_str());
    return true;
}
bool screenMenu::refreshMenu(){
    bool tmp = false;
    if(totalMenuOptions <= menuSystemOverTtyP->screenMenuOptions){
        for(unsigned int i=0;i < totalMenuOptions;i++){    
            if(displayMenuOptionsPnt[i]->autoRefresh)if(displayMenuOptionsPnt[i]->refresh())tmp = true;
        }
    }else{
        for(unsigned int i=offsetFromTop;i < (menuSystemOverTtyP->screenMenuOptions+offsetFromTop);i++){    
            if(displayMenuOptionsPnt[i]->autoRefresh)if(displayMenuOptionsPnt[i]->refresh())tmp = true;
        }
    }
    
    return tmp;
}
void screenMenu::setHasMores(){
    hasMoreBelow = ((menuSystemOverTtyP->screenMenuOptions+offsetFromTop)< totalMenuOptions);
    hasMoreAbove = (offsetFromTop > 0);
}
bool screenMenu::pushDn(){
    if((menuSystemOverTtyP->screenMenuOptions+offsetFromTop)< totalMenuOptions){
        offsetFromTop++;
        setHasMores();
        return true;
    }
    return false;
}
bool screenMenu::pushUp(){
    if(offsetFromTop > 0){
        offsetFromTop--;
        setHasMores();
        return true;
    }
    return false;
}
bool screenMenu::pushRt(unsigned int index){
    if(displayMenuOptionsPnt[index+offsetFromTop]->pushRt()){
        return displayMenuOptionsPnt[index+offsetFromTop]->refresh();
    }
    return false;
}
bool screenMenu::pushLt(unsigned int index){
    if(displayMenuOptionsPnt[index+offsetFromTop]->pushLt()){
        return displayMenuOptionsPnt[index+offsetFromTop]->refresh();
    }
    return false;
}
screenMenu::screenMenu(const char* text){
    strcpy(titol,text);
    totalMenuOptions = 0;
    whereICame = -1;
}
bool screenMenu::addMenuOption(menuOption* menuOption){
    if(totalMenuOptions == menuOptionsMax)return false;
    displayMenuOptionsPnt[totalMenuOptions] = menuOption;
    totalMenuOptions++;
    return true;
}
void screenMenu::leave(){}
void screenMenu::enter(){}
void screenMenu::run(unsigned int index){
    displayMenuOptionsPnt[index+offsetFromTop]->run();// in inheritance keep at 0
}
menuOptionOnOff::menuOptionOnOff(){}
menuOptionOnOff::menuOptionOnOff(const char* text,bool initValue):menuOption(text),state(initValue),statePrinted(!initValue){}
bool menuOptionOnOff::refresh(){
    if(state== statePrinted)return false;
    String tmp = String(text);
    tmp = tmp.substring(0,tmp.indexOf(menuOptionDelimiter))+menuOptionDelimiter;
    if(state){
        tmp = tmp+"ON";
    }else{
        tmp = tmp+"OFF";
    }
    strcpy(text,tmp.c_str());
    statePrinted = state;
    return true;
}
bool menuOptionOnOff::pushRt(){
    state = !state;
    return true;
}
bool menuOptionOnOff::pushLt(){
    state = !state;
    return true;
}
menuOptionRangeValue::menuOptionRangeValue():menuOption(){
}
menuOptionRangeValue::menuOptionRangeValue(const char* text, int minVal, int maxVal, int initValue,int step):menuOption(text),state(initValue),statePrinted(!initValue),_maxValue(maxVal),_minValue(minVal),_step(step){
    if(initValue > maxVal){
        initValue = maxVal;
    }
    if(initValue < minVal){
        initValue = minVal;
    }
}
bool menuOptionRangeValue::refresh(){
    if(state== statePrinted)return false;
    String tmp = String(text);
    tmp = tmp.substring(0,tmp.indexOf(menuOptionDelimiter))+menuOptionDelimiter;
    tmp = tmp+(String)state;
    strcpy(text,tmp.c_str());
    statePrinted = state;
    return true;
}
bool menuOptionRangeValue::pushRt(){
    if((state+_step) > _maxValue){
        if(state == _maxValue){
            return false;
        }else{
            state = _maxValue;
            return true;
        }
    }
    state+=_step;
    return true;   
}
bool menuOptionRangeValue::pushLt(){
    if((state-_step) < _minValue){
        if(state == _minValue){
            return false;
        }else{
            state = _minValue;
            return true;
        }
    }
    state-=_step;
    return true;
}
changeScreenMenuOption::changeScreenMenuOption(screenMenu* menuDesti){
    this->_menuDesti = menuDesti;
    this->refresh();
}
void changeScreenMenuOption::run(){
    for (int i = 0; i < menuSystemOverTtyP->totalScreenMenus; ++i) {
        if(menuSystemOverTtyP->pantalles[i] == this->_menuDesti){
            menuSystemOverTtyP->setscreen(i);// if coming from a run, no need to call show();
        }
    }
}
bool changeScreenMenuOption::refresh(){
    if(strlen(_menuDesti->titol) < menuTextLength){
        strcpy(menuOption::text,_menuDesti->titol);
    }else{
        strcpy(menuOption::text,"2Long");
    }
    return false;
}
void menu::queryTerminalSize(bool wait4Response){
    this->userTty->print("\e[200;200H");
    this->userTty->print("\e[6n");
    unsigned int start = millis();
    while(terminalRowsCols[0] == 0){// wait for response
        if((millis()-start) > queryterminalSizeTimeout)break;
        if(userTty->available() != 0){
            lastInputChar = userTty->read();
            this->doGuess(lastInputChar);
        }
        delay(10);
    }
    terminalSizeQueries++;
}

#ifdef _MENU_UI_BIG_RAM_
class CharBuffer {
private:
    volatile static char myCharBuffer[INPUT_BUFFER_SIZE];// whole ram must be buffer, lol
public:
    
    volatile int head = 0;
    volatile int tail = 0;

    // Add a character to the buffer
    void addChar(char c) {
        if (((tail + 1) % INPUT_BUFFER_SIZE) == head) { // Buffer is full
          //giveErrorVisibility(false);
        }
        myCharBuffer[tail] = c;
        tail = (tail + 1) % INPUT_BUFFER_SIZE;
    }

    // Consume a character from the buffer
    char consumeChar() {
        if (head == tail) { // Buffer is empty
          //giveErrorVisibility(false);
        }
        char c = myCharBuffer[head];
        head = (head + 1) % INPUT_BUFFER_SIZE;
        return c;
    }
};
// Define static member of CharBuffer class
volatile char CharBuffer::myCharBuffer[INPUT_BUFFER_SIZE];
CharBuffer buffer;

textBoxMenuOption::textBoxMenuOption(){}
textBoxMenuOption::textBoxMenuOption( const char* _text): menuOption(_text), caption(_text){}
void textBoxMenuOption::run(){
    menuOption::run();
    menuSystemOverTtyP->_textBoxCallBack = this;
}
bool textBoxMenuOption::checkBackgroundEvents(){return false;}
bool textBoxMenuOption::performUserInteraction(){return false;}
void menuTextBox::cUB(unsigned int argc,int *argv){
    if(_textBoxStatus!= textBoxStatus::activeEditor){
        menu::cUB(argc,argv);
        return;
    }
    if(getCursorRowIndex()> 0){
        if(getCursorColIndex() == 0){
            doCUU();
            doCUF(textLineWidth-1);
        }else
        {
            doCUB();
        }
        cursorBufferIndex-=1;
    }else{// first line
        if(getCursorColIndex() > 0){
            doCUB();
            cursorBufferIndex-=1;
        }
    }
}
void menuTextBox::cUU(unsigned int argc,int *argv){// keyUp
    if(_textBoxStatus!= textBoxStatus::activeEditor){
        menu::cUU(argc,argv);
        return;
    }
    if(getCursorRowIndex() > 0 ){
        if(cursorBufferIndex >= textLineWidth){ // adjust?
            doCUU();
            cursorBufferIndex-=textLineWidth;
        }
    }
}
void menuTextBox::cUD(unsigned int argc,int *argv){// keyDn
    if(_textBoxStatus!= textBoxStatus::activeEditor){
        menu::cUD(argc,argv);
        return;
    }
    if((getCursorRowIndex() < getTotalLinesCapacity()) && (cursorBufferIndex+textLineWidth < _maxStrLen)){
        if((cursorBufferIndex+textLineWidth)<= strlen(_result)){ // adjust?
            doCUD();
            cursorBufferIndex+=textLineWidth;
        }
    }
}
void menuTextBox::cUF(unsigned int argc,int *argv){
    if(_textBoxStatus!= textBoxStatus::activeEditor){
        menu::cUF(argc,argv);
        return;
    }
    if((cursorBufferIndex < strlen(_result))&&((cursorBufferIndex+1) < _maxStrLen)){ //  with (bicp+1) does not allow cursor to go over \0
        if(getCursorColIndex() >= (textLineWidth-1)){// -1 because one is offset and the other count
            doCUB(textLineWidth-1);
            doCUD();
        }else{
            doCUF();
        }
    cursorBufferIndex+=1;
    }
}
void menuTextBox::cr(){
    if(_textBoxStatus== textBoxStatus::activeEditor){
        _textBoxStatus = textBoxStatus::enterPressed;
    }else{
        menu::cr();
    }
}
void menuTextBox::del(){
    if(_textBoxStatus!= textBoxStatus::activeEditor){
        menu::del();
        return;
    }
    if(cursorBufferIndex < strlen(_result)){//unsigned int aa = strlen(inputBuffer);
        removeCharAtIndex(cursorBufferIndex);
    }
}
void menuTextBox::backSpace(){
    if(_textBoxStatus== textBoxStatus::activeEditor){
        removeCharAtIndex(cursorBufferIndex-1);
        if(getCursorColIndex() > 0){
            doCUB();
        }else if((getCursorColIndex() == 0) && (cursorBufferIndex > 0)){
            doCUU();
            doCUF(textLineWidth-1);
        }
        cursorBufferIndex--;
    }else{
        menu::backSpace();
    }
}
void menuTextBox::lf(){
    if(_textBoxStatus!= textBoxStatus::activeEditor){
        menu::lf();
        return;
    }
    _textBoxStatus = textBoxStatus::enterPressed;
}
void menuTextBox::start(){
    if(_textBoxStatus == textBoxStatus::activeEditor){
        unsigned int _liniesAvall = getCursorColIndex();
        doCUB(_liniesAvall);
        _liniesAvall = getCursorRowIndex();
        doCUU(_liniesAvall);
        cursorBufferIndex = 0;
    }else{
        menu::start();
    }
}
void menuTextBox::end(){
    if(_textBoxStatus!= textBoxStatus::activeEditor){
        menu::end();
        return;
    }else{
        unsigned int _liniesAvall = getWrittenLinesCount();
        _liniesAvall = _liniesAvall-(getCursorRowIndex()+1);
        doCUD(_liniesAvall);
        doCUB(getCursorColIndex());
        cursorBufferIndex = strlen(_result)-1;
        _liniesAvall = getCursorColIndex();
        doCUF(_liniesAvall);
        if((cursorBufferIndex+1) < _maxStrLen){
            this->cUF(0,0);
        }
    }
}
unsigned int menuTextBox::getTotalLinesCapacity(){
    unsigned int aa = this->_maxStrLen/textLineWidth;
    if (this->_maxStrLen > (aa*textLineWidth)){
        return aa+1;
    }
    return aa;
}
void menuTextBox::manageCaretAndSpace(bool borrar){
    if(borrar){
        doCUU(getCursorRowIndex());
        doCUB(getCursorColIndex());
    }
    unsigned int _totalLinies = getTotalLinesCapacity();
    
    for(unsigned int i=0;i < _totalLinies;i++)userTty->write('\n');// ensures screen space
    
    doCUF(textLineWidth);// caret
    if(borrar){
        userTty->write(' ');
    }else{
        userTty->write(frameChars[2]);
    }
    doCUB(textLineWidth+1);
    doCUU(_totalLinies);
    if(borrar){
        doCUD(getCursorRowIndex());// missing doCUF(getCursorColIndex()); ??
        doCUF(getCursorColIndex());
    }    
}
void menuTextBox::cleanupEditor(){
    drawFrame(true);// erases the frame
    manageCaretAndSpace(true);// erases the caret and ensures space
    unsigned int tmp = getCursorRowIndex();
    unsigned int liniesPerSortir = getWrittenLinesCount();// - if the cursor is lower than the last line ...
    if(tmp <liniesPerSortir){// leaves cursor at last line
        liniesPerSortir -= tmp;
        if(liniesPerSortir> 1)doCUD(liniesPerSortir-1);
    }else if((tmp > liniesPerSortir) ||(getCursorColIndex() == 0)){// if cursor in position to start new line
        doCUU();
    }
    
    liniesPerSortir = getWrittenLinesCount();
    for(unsigned int i=0;i < liniesPerSortir;i++){// erases text
        doCUF(textLineWidth-1);
        doEL(false);
        doCUB(textLineWidth-1);
        doCUU();
    }
    
    userTty->write('\n');
}
void menuTextBox::statusBar(){
    const char* caption = (_textBoxCallBack != nullptr) ? _textBoxCallBack->caption.c_str() : "InitError";
    
    // Horizontally center the caption if terminalRowsCols is initialized
    unsigned int captionLen = strlen(caption)+strlen(insertText);
    
    if (horizontallyCenter && terminalRowsCols[1] > 0 && terminalRowsCols[1] > captionLen) {
        doCUF((terminalRowsCols[1] - captionLen) / 2);
    }
    
    userTty->print(inverteixColorsTerminal);
    userTty->print(caption);
    if(insertStatus) userTty->print(insertText);
    userTty->print(colorsTerminalReset);
    userTty->println();
    
    // Horizontally center the cursor for the textBox
    if (horizontallyCenter && terminalRowsCols[1] > 0 && terminalRowsCols[1] > textLineWidth) {
        doCUF((terminalRowsCols[1] - textLineWidth) / 2);
    }
}
void menuTextBox::removeCharAtIndex(unsigned int desde){
    unsigned int totalLiniesAbans = getWrittenLinesCount();
    if(desde > strlen(_result)){
        userTty->print("ERB");
        return;
    }
    int bufferLength = strlen(_result);
    for (int i = desde; i < bufferLength; ++i) {// here it differs from the backSpace of the insert
        _result[i] = _result[i + 1];
        if(_result[i] == '\0')break;
    }
    
    int y;
    if( totalLiniesAbans > getWrittenLinesCount()){// erases line no longer used
        redrawLine(totalLiniesAbans-1);
    }
    // and draws lines downwards
    y = getWrittenLinesCount();
    for(int i=getCursorRowIndex();i < y;i++){
        redrawLine(i);
    }
}
void menuTextBox::drawTextPreCursor(){
    manageCaretAndSpace();
    unsigned int pos=0;
    unsigned int endindex =textLineWidth;
    while(pos < this->cursorBufferIndex){
        if(endindex > cursorBufferIndex) endindex = cursorBufferIndex + 1;
        
        unsigned int len = endindex - pos;
        unsigned int bufLen = strlen(_result);
        unsigned int printLen = len;
        if (pos >= bufLen) printLen = 0;
        else if (pos + printLen > bufLen) printLen = bufLen - pos;
        
        size_t written = 0;
        if (printLen > 0) written = userTty->write((const uint8_t*)(_result + pos), printLen);
        
        size_t restants = textLineWidth - written;
        for(size_t i =0;i<restants;i++){
            userTty->write(' ');
        }
        doCUD();
        doCUB(textLineWidth);
        pos += textLineWidth;
        endindex = pos+this->textLineWidth;
    }
    endindex = getCursorColIndex();
    if(endindex > 0){
        doCUU();
        doCUF(endindex);
    }
}
void menuTextBox::redrawFrame(){
    doCUD(getWrittenLinesCount()-getCursorRowIndex());// moves cursor down
    if(drawnFrameHeight > getWrittenLinesCount()){// shrinks bottom border by 1, here cursor is at bottom border line
        doCUD();
        if (horizontallyCenter && terminalRowsCols[1] > 0 && terminalRowsCols[1] > textLineWidth) {
            doCUB(getCursorColIndex()+1);
            userTty->write(' ');
        }else{
            doCUB(getCursorColIndex());
        }
        doCUF(textLineWidth);
        if(drawnFrameHeight == getTotalLinesCapacity()){
            doCUB();// to avoid erasing caret which is also a corner
        }
        doEL(false);// erases from start to cursor
        doCUU();
        if(drawnFrameHeight == getTotalLinesCapacity()){
            doCUF();// leaves cursor where it belongs
        }
    }else{// expands bottom border by 1, there is 1 character on the new line, cursor at last line writing height
        doCUU();// places cursor just after the first character already written on new line
        if (horizontallyCenter && terminalRowsCols[1] > 0 && terminalRowsCols[1] > textLineWidth) {
            doCUB(getCursorColIndex()+1);
            userTty->write(frameChars[1]);// draws border
            doCUB();
            doCUD();
            userTty->write(frameChars[2]);// draws corner
            doCUU();
        }else{
            doCUB(getCursorColIndex());
        }
        doCUF();// skips the (new) 1 character of the new line
        for(unsigned int i =1;i< textLineWidth;i++)userTty->write(' ');// clears rest of characters on the line
        userTty->write(frameChars[1]);// draws border
        doCUB();
        doCUD();
    }
    // here cursor is at the line of the new bottom bar(frame), right corner
    if (horizontallyCenter && terminalRowsCols[1] > 0 && terminalRowsCols[1] > textLineWidth) {
        doCUB(textLineWidth+1);
        userTty->write(frameChars[2]);// draws left corner
    }else{
        doCUB(textLineWidth);
    }
    for(unsigned int i =0;i< textLineWidth;i++)userTty->write(frameChars[0]);// draws bottom horizontal border
    userTty->write(frameChars[2]);// draws right corner
    // re-positions cursor at new character position
    doCUB(textLineWidth+1);
    doCUU(getWrittenLinesCount());
    doCUD(getCursorRowIndex());
    doCUF(getCursorColIndex());
    drawnFrameHeight = getWrittenLinesCount();
}
void menuTextBox::eraseStatusBar(){
    const char* caption = (_textBoxCallBack != nullptr) ? _textBoxCallBack->caption.c_str() : "InitError";
    unsigned int captionLen = strlen(caption)+strlen(insertText);
    
    unsigned int lines = getCaptionLinesCount();
    for(unsigned int i=0;i < lines;i++){
        doCUU();
        doEL();
    }
    userTty->write('\r');
}
void menuTextBox::redrawLine(unsigned int linia){
    if(linia > getTotalLinesCapacity()){
        return;
    }
    int y;
    // moves cursor to line to draw
    y = linia-getCursorRowIndex();
    if(y > 0){// down
        doCUD(y);
    }else if(y < 0){// up
        y=-y; 
        doCUU(y);
    }
    doCUB(getCursorColIndex());
    if(linia < getWrittenLinesCount()){// print line
        unsigned int startIdx = linia * textLineWidth;
        unsigned int len = 0;
        unsigned int bufLen = strlen(_result);
        if (startIdx < bufLen) {
            len = bufLen - startIdx;
            if (len > textLineWidth) len = textLineWidth;
        }
        
        size_t written = 0;
        if (len > 0) {
            written = userTty->write((const uint8_t*)(_result + startIdx), len);
        }
        size_t restants = textLineWidth - written;
        
        for(size_t i =0;i<restants;i++)userTty->write(' ');
    }else{// erase line
        doCUF(textLineWidth-1);
        doEL(false);
        doCUF();
    }
    // returns cursor to writing position
    y = (int)linia-(int)getCursorRowIndex();
    if(y > 0){// down
        doCUU(y);
    }else if(y < 0){// up
        y=-y;
        doCUD(y);
    }
    doCUB(textLineWidth);
    doCUF(getCursorColIndex());
}
void menuTextBox::drawTextPostCursor(unsigned int desDaquestaFinsAlFinal){
    for(unsigned int i=desDaquestaFinsAlFinal;i < getWrittenLinesCount();i++){
        redrawLine(i);
    }
}
void menuTextBox::msgTxtInputMultiline(char* result, unsigned int maxLength, unsigned int minLength,const char * allowedChars ){    
    lastInputChar = '\0';
    _textBoxStatus = textBoxStatus::activeEditor;
    _maxStrLen = maxLength;
    _result = result;
    cursorBufferIndex = strlen(result);
    insertStatus = true;
    lastInsertStatus = insertStatus;
    result[_maxStrLen] = '\0';
    
    String _caractersPermesosStr;
    bool tmpBool = false;
    unsigned int desDaquestaFinsAlFinal;
    unsigned int bufferLength;
    
    if(cursorBufferIndex> maxLength){
        _textBoxStatus = textBoxStatus::error;
        lastTextBoxExitCode = 3;
        return;
    }else if(cursorBufferIndex == _maxStrLen)cursorBufferIndex--;
    
    if(textLineWidth < minTextBoxWidth){
        _textBoxStatus = textBoxStatus::error;
        lastTextBoxExitCode = 4;
        return;
    }
    if ((terminalRowsCols[1] > 0) && (terminalRowsCols[1] < (textLineWidth+2))) {
        _textBoxStatus = textBoxStatus::error;
        lastTextBoxExitCode = 9;
        return;
    }
    desDaquestaFinsAlFinal = getCaptionLinesCount();// re using variable
    if((terminalRowsCols[0] > 0) &&((desDaquestaFinsAlFinal+1+getTotalLinesCapacity()) > terminalRowsCols[0])){
        _textBoxStatus = textBoxStatus::error;
        lastTextBoxExitCode = 8;
        return;
    }

    if(verticallyCenter && (terminalRowsCols[0] > (2+getTotalLinesCapacity()))) {
        doClearScreen();
        doMoveCursor(1,1);
        unsigned int h = 3 + getTotalLinesCapacity();
        if(terminalRowsCols[0] > h) doCUD((terminalRowsCols[0] - h) / 2);
    }
    // put cursor in position
    
    drawnFrameHeight = 0;
    statusBar();
    drawTextPreCursor();
    drawFrame();
    if(allowedChars != nullptr){
        _caractersPermesosStr = String(allowedChars);
    }
    while (_textBoxStatus == textBoxStatus::activeEditor) {// add: line jump controls, arrows, put a bool of menu object to receiver
        if(_textBoxCallBack != nullptr)tmpBool = _textBoxCallBack->checkBackgroundEvents();
        if(tmpBool||(lastInsertStatus != insertStatus)){
            if(lastInsertStatus != insertStatus)lastInsertStatus = insertStatus;
            cleanupEditor();
            eraseStatusBar();
            if((_textBoxCallBack != nullptr) && tmpBool &&(_textBoxCallBack->performUserInteraction()))
                _textBoxStatus = textBoxStatus::softwareAborted;
            statusBar();
            drawTextPreCursor();
            drawTextPostCursor(getCursorRowIndex());
            drawFrame();// does not leave in place
        }
    
        if(userTty->available() != 0){
            lastUserInputTime = millis();
            buffer.addChar((char)userTty->read());
        }else{
            if((buffer.head != buffer.tail) && (millis() > (lastUserInputTime+userInputLag))) {
                lastInputChar = buffer.consumeChar();
                if(lastInputChar == '\e')nextEscBack = (millis()+escBackMillisecondsDelay);
                if(doGuess(lastInputChar) && ((allowedChars == nullptr) ||(_caractersPermesosStr.indexOf(lastInputChar) > -1))){
                    if(cursorBufferIndex+1 < _maxStrLen){
                        if(insertStatus){
                            bufferLength = strlen(result);
                            desDaquestaFinsAlFinal = getCursorRowIndex();
                            if(bufferLength < _maxStrLen){// shifts string
                                for (int i = bufferLength; i >= (int)cursorBufferIndex; --i) {// damn c++ and the damn cast
                                    result[i+1] = result[i];// if inputBuffer[i+1] == '\0' break;
                                }
                                if(getCursorColIndex() >= (textLineWidth-1)){// if it falls outside
                                    userTty->write(lastInputChar);
                                    if((cursorBufferIndex+1) < _maxStrLen){// falls outside but is not the end
                                        desDaquestaFinsAlFinal++;
                                        doCUB(textLineWidth);
                                        doCUD();
                                    }else{// is the end, go back
                                        doCUB();
                                    }
                                }else{
                                    doCUF();
                                }
                                result[cursorBufferIndex] = lastInputChar;
                                if((cursorBufferIndex+1) < _maxStrLen){
                                    cursorBufferIndex++;
                                }
                                drawTextPostCursor(desDaquestaFinsAlFinal);
                            }
                        }else{
                            if(result[cursorBufferIndex] == '\0'){
                                result[cursorBufferIndex+1]= '\0';
                            }
                            result[cursorBufferIndex] = lastInputChar;
                            userTty->write(lastInputChar);
                            if((cursorBufferIndex+1)< _maxStrLen){
                                if(getCursorColIndex() >= (textLineWidth-1)){
                                    doCUB(textLineWidth);
                                    doCUD();
                                }
                                cursorBufferIndex++;
                            }else{
                                doCUB();
                            }
                        }
                    }else{
                        result[cursorBufferIndex] = lastInputChar;
                        redrawLine(getCursorRowIndex());
                    }
                }else{
                    if(millis() > nextEscBack)userTty->write('\a');// bell
                }
                if(drawnFrameHeight != getWrittenLinesCount())redrawFrame();
            }
            if(lastInputChar == '\e'){
                if(millis() > nextEscBack){// exit
                    doGuess('\0');
                    break;
                }
            }
        }
    }
    
    cleanupEditor();
    eraseStatusBar();
    buffer.tail = buffer.head;
    
    if(_textBoxStatus == textBoxStatus::softwareAborted){
        lastTextBoxExitCode = 2;
        return;
    }
    //---------checks
    _caractersPermesosStr = String(result);// re use of _caractersPermesosStr for final checks
    if(strlen(result) < minLength){
        _caractersPermesosStr = String(minLength)+" caracters minim";
        invertColors(&_caractersPermesosStr);
        this->msgSmallWait(_caractersPermesosStr.c_str());
        _textBoxStatus = textBoxStatus::error;
        lastTextBoxExitCode = 5;
        return;
    }
    if(_caractersPermesosStr.indexOf('\e') >= 0){
        _textBoxStatus = textBoxStatus::error;
        lastTextBoxExitCode = 6;
        return;
    }
    if(_caractersPermesosStr.length() > _maxStrLen){
        _textBoxStatus = textBoxStatus::error;
        lastTextBoxExitCode = 7;
        return;
    }
    //---------checks end
    
    strcpy(result, _caractersPermesosStr.c_str());
    
    if(lastInputChar == '\e'){
        _textBoxStatus = textBoxStatus::escPressed;    
        lastTextBoxExitCode = 1;
    }else{
        _textBoxStatus = textBoxStatus::enterPressed;
        lastTextBoxExitCode = 0;
    }
    return;
}
unsigned int menuTextBox::getCursorColIndex(){
        return cursorBufferIndex%textLineWidth;
}
unsigned int menuTextBox::getCaptionLinesCount(){
    const char* caption = (_textBoxCallBack != nullptr) ? _textBoxCallBack->caption.c_str() : "InitError";
    unsigned int captionLen = strlen(caption)+strlen(insertText);
    
    unsigned int lines = 1;
    if (terminalRowsCols[1] > 0 && captionLen > 0) {
        lines = (captionLen + terminalRowsCols[1] - 1) / terminalRowsCols[1];
    }
    return lines;
}
unsigned int menuTextBox::getWrittenLinesCount(){
    unsigned int aa = strlen(_result);
    aa = aa/textLineWidth;
    if (strlen(_result) > (aa*textLineWidth)){
        return aa+1;
    }
    return aa;
}
unsigned int menuTextBox::getCursorRowIndex(){
    /*unsigned int aa = cursorBufferIndex/textBoxWidth;
    return aa;*/
    return cursorBufferIndex/textLineWidth;
}
void menuTextBox::drawFrame(bool borrar){
    doCUD(getWrittenLinesCount()-getCursorRowIndex());// moves cursor down
    if (horizontallyCenter && terminalRowsCols[1] > 0 && terminalRowsCols[1] > textLineWidth) {
        doCUB(getCursorColIndex()+1);// moves cursor to right
    }else{
        doCUB(getCursorColIndex());// moves cursor to right
    }

    if(borrar){
        if (horizontallyCenter && terminalRowsCols[1] > 0 && terminalRowsCols[1] > textLineWidth) {
            for(unsigned int i =0;i< (2+textLineWidth);i++)userTty->write(' ');
            for(unsigned int i =0;i< getWrittenLinesCount();i++){
                doCUU();
                doCUB();
                userTty->write(' ');
                doCUB(textLineWidth+2);
                userTty->write(' ');
                doCUF(textLineWidth+1);
            }
        }else{
            for(unsigned int i =0;i< (1+textLineWidth);i++)userTty->write(' ');
            for(unsigned int i =0;i< getWrittenLinesCount();i++){
                doCUB();
                doCUU();
                userTty->write(' ');
            }
        }
    }else{
        if (horizontallyCenter && terminalRowsCols[1] > 0 && terminalRowsCols[1] > textLineWidth) {
            userTty->write(frameChars[2]);
            for(unsigned int i =0;i< textLineWidth;i++)userTty->write(frameChars[0]);
            userTty->write(frameChars[2]);
            for(unsigned int i =0;i< getWrittenLinesCount();i++){
                doCUU();
                doCUB();
                userTty->write(frameChars[1]);
                doCUB(textLineWidth+2);
                userTty->write(frameChars[1]);
                doCUF(textLineWidth+1);
            }
        }else{
            for(unsigned int i =0;i< textLineWidth;i++)userTty->write(frameChars[0]);
            userTty->write(frameChars[2]);
            for(unsigned int i =0;i< getWrittenLinesCount();i++){
                doCUB();
                doCUU();
                userTty->write(frameChars[1]);
            }
        }
    }
    doCUB(textLineWidth+1);// cursor in position after top right frame character
    doCUD(getCursorRowIndex());
    doCUF(getCursorColIndex());
    drawnFrameHeight = getWrittenLinesCount();
}
menuTextBox::menuTextBox(): menu(){
}
menuTextBox::~menuTextBox() {
    _textBoxCallBack = nullptr;
    _result = nullptr;
}
const char* menuTextBox::exitCodeDescription[] = {
    "exit by enter",//0
    "exit by esc",
    "software aborted",
    "not null terminated",
    "text line width too short",//4
    "text too short",
    "corrupt string",
    "text too long",
    "area 2 tall 4 screen, wide it",//8
    "area 2 wide 4 screen, tall it"
};
#endif
#ifdef _MENU_UI_BIG_RAM_
menuTextBox menuSystemOverTty;
menuTextBox * menuSystemOverTtyP = &menuSystemOverTty;
#else
menu menuSystemOverTty;
menu * menuSystemOverTtyP = &menuSystemOverTty;
#endif
```


[public]: https://img.shields.io/badge/-public-brightgreen (public)
[C++]: https://img.shields.io/badge/language-C%2B%2B-blue (C++)
[private]: https://img.shields.io/badge/-private-red (private)
[static]: https://img.shields.io/badge/-static-lightgrey (static)
[protected]: https://img.shields.io/badge/-protected-yellow (protected)