/**
* @file menu.cpp
* @brief Code for menu.h
* 
* Might want to change some preprocessor directives to customize beheaviour
*
* @author Gerard Forcada Bigas
*
* @date 20/12/22
*/
#include "menu.h"

//CONFIG HERE
#define menuOptionDelimiter ':'
#define escBackMillisecondsDelay 450 // wait until esc is known as 'wants to go back'
#define cliMsgWait 1250 // push message timeout
#define menuRefreshInterval 250 // self-explanatory

static const char * polsaPerContinuar = "Press any key to continue";

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
    if(totalScreenMenus < 1)return;// comentar?
    setscreen(0);
    queryTerminalSize();
    unsigned int start = millis();
    while(terminalRowsCols[0] == 0){// esperar a que respongui
        if((millis()-start) > queryterminalSizeTimeout)break;
        run();
        delay(10);
    }
    show();
}
/**
 * refresca la linia
*/
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
/**
Show menu on screen, using userTty object member

@param resetCursor move cursor to starting point
*/
void menu::show(bool resetCursor){
    if(totalScreenMenus == 0)return;// safe

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

    if(terminalRowsCols[0] > 0 && terminalRowsCols[0] > contentHeight){
        unsigned int topPadding = (terminalRowsCols[0] - contentHeight) / 2;
        contentOriginRow = 1 + topPadding;
    }else{
        contentOriginRow = 1;
    }

    if(terminalRowsCols[1] > 0 && terminalRowsCols[1] > contentWidth){
        unsigned int leftPadding = (terminalRowsCols[1] - contentWidth) / 2;
        contentOriginCol = 1 + leftPadding;
    }else{
        contentOriginCol = 1;
    }

    // Calculate header position: center it relative to options if narrower, otherwise align left
    unsigned int headerStartCol = contentOriginCol;
    if(terminalRowsCols[1] > 0 && headerLen > contentWidth){
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
        userTty->print(active->displayMenuOptionsPnt[idx]->text);
    }

    if(resetCursor){
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
/**
Cursor Up, inherited from terminalParser pantalles[activeScreenMenu]->offsetFromTop
*/
void menu::cUU(unsigned int argc,int *argv){// keyUp
    if(runningOption)return;
    if(selectedMenuOption < 1){
        if(this->pantalles[activeScreenMenu]->pushUp())show(false);
        return;
    }
    selectedMenuOption--;
    doMoveCursor(contentOriginRow + 1 + selectedMenuOption,contentOriginCol);
    terminalParser::cUU(argc,argv);
}
/**
Cursor Down, inherited from terminalParser
dragons be here
*/
void menu::cUD(unsigned int argc,int *argv){// keyDn
    if(runningOption)return;
    if((this->pantalles[activeScreenMenu]->totalMenuOptions > screenMenuOptions) && ((selectedMenuOption+1)) >= screenMenuOptions){
        if(this->pantalles[activeScreenMenu]->pushDn())show(false);// scroll
        return;
    }else if((selectedMenuOption+1) >= pantalles[activeScreenMenu]->totalMenuOptions){
        if(this->pantalles[activeScreenMenu]->pushDn())show(false);// scroll
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
    terminalRowsCols[0] = (unsigned int)argv[0];
    terminalRowsCols[1] = (unsigned int)argv[1];
    terminalParser::cPR(argc,argv);
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
    //terminalParser::cr();
}
/**
Add available menu screen to the array

@param pantalla pointer to menu screen
*/
void menu::addscreen(screenMenu* pantalla){
    if(totalScreenMenus == screenMenuMax)return;
    pantalles[totalScreenMenus] = pantalla;
    totalScreenMenus+=1;
}
/**
Gracefully switch menu screen
si ve des de un run no cal qua faci show();
@param pantallaDesti where to go
*/
void menu::setscreen(int pantallaDesti,bool setWhereICame){
    if(setWhereICame)pantalles[pantallaDesti]->whereICame = activeScreenMenu;
    activeScreenMenu = pantallaDesti;
    pantalles[activeScreenMenu]->offsetFromTop=0;
    pantalles[activeScreenMenu]->refreshMenu();
    pantalles[activeScreenMenu]->setHasMores();
}
void menu::refresh(){
    if(pantalles[activeScreenMenu]->autoRefresh){
        if(pantalles[activeScreenMenu]->refreshMenu()){
            show(false);
        }
    }
}
/**
 * @brief Parses the userTty, check user interaction or display query
 * 
 */
void menu::run(){
    if(userTty->available() != 0){
        charTmp = userTty->read();
        this->doGuess(charTmp);
        if(charTmp == '\e'){nextEscBack = (millis()+escBackMillisecondsDelay);}
    }else{
        if(charTmp == '\e'){
            if(millis() > nextEscBack){
                charTmp = '\0';
                doGuess(charTmp);
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
    pantalles[activeScreenMenu]->bye();
    if(pantalles[activeScreenMenu]->whereICame >= 0){
        this->setscreen(pantalles[activeScreenMenu]->whereICame,false);
    }
}
void menu::msgSmallWait(const char* text){
        userTty->write(inverteixColorsTerminal);
        userTty->write(text);
        userTty->write(colorsTerminalReset);
        userTty->flush();
        delay(cliMsgWait);
        doEL();
        userTty->write('\r');
        userTty->println(text);
}
bool menu::msgYes(const char* text){
    userTty->write(inverteixColorsTerminal);
    userTty->write(text);
    userTty->write(" y/n");
    userTty->write(colorsTerminalReset);
    userTty->flush();
    while(userTty->available() ==0){}
    char keyPressed = userTty->read();
    while (userTty->available())userTty->read();// buida buffer
    userTty->write('\r');
    doEL();
    userTty->write(text);
    userTty->write(" y/n");
    userTty->write('=');
    userTty->println(keyPressed);
    return (keyPressed == 'y') || (keyPressed == 'Y');
}
void menu::msgPause(const char* prompt){
    userTty->write(inverteixColorsTerminal);
    if(prompt != nullptr)userTty->println(prompt);
    userTty->write(polsaPerContinuar);
    userTty->write(colorsTerminalReset);
    userTty->flush();
    while(userTty->available() ==0){}
    while (userTty->available())userTty->read();// buida buffer
    userTty->write('\r');
    if(prompt != nullptr){
        doCUU();
        userTty->println(prompt);
    }
    doEL();
    //userTty->println(polsaPerContinuar);
}
void menu::msgPause(){
    msgPause(nullptr);
}
/**
 * @param result might not be empty, resulting text will be there
*/
bool menu::msgTxtInputSimple(const char* prompt,char* result, unsigned int maxLength, unsigned int minLength){
    String tmpStr = String(result);
    charTmp = '\0';
    
    userTty->println(prompt);
    userTty->print(result);
    while (true) {
        if((userTty->available() > 0 )) {
            charTmp = userTty->read();
            if(charTmp == '\e'){nextEscBack = (millis()+escBackMillisecondsDelay);}
            if (charTmp == '\r') {
                break;
            }else if (((charTmp == '\b') ||(charTmp == '\177') || (tmpStr.length() > maxLength)) && (tmpStr.length() > 0)) {
                userTty->print("\b \b");
                tmpStr.remove(tmpStr.length()-1);
            }else{
                if(charTmp && (tmpStr.length() < maxLength)){
                    if((charTmp > 64 && charTmp < 91) || (charTmp > 96 && charTmp < 123) || (charTmp > 47 && charTmp < 58) || (charTmp == 32)){
                        userTty->write(charTmp);
                        tmpStr.concat(charTmp);
                    }
                }
            }
        }else{
            if(charTmp == '\e'){
                if(millis() > nextEscBack){
                    break;
                }
            }
        }
    }
    userTty->write("\r\n");

    if(charTmp == '\e'){
        charTmp = '\0';
        return false;
    }else if(strlen(tmpStr.c_str()) < minLength){
        tmpStr = String(minLength)+" cars min";
        this->msgSmallWait(tmpStr.c_str());
        return false;
    }else if(tmpStr.indexOf('\e') >= 0){
        this->msgSmallWait("corrupt txt");
        return false;
    }

    strcpy(result, tmpStr.c_str());
    return true;
}
/**
 * 
 */
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
void screenMenu::bye(){}
void screenMenu::run(unsigned int index){
    displayMenuOptionsPnt[index+offsetFromTop]->run();// en herencies mantenir a 0
}
menuOptionOnOff::menuOptionOnOff(){}
/**
 * @brief menuOptionOnOff constructor
 *
 * might set initial values
 *
 * @param[in]  text  string char * used as caoption
 * @param[in]  initValue  optional initial value
 */
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
            menuSystemOverTtyP->setscreen(i);// si ve des de un run no cal qua faci show();
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
void menu::queryTerminalSize(){
    this->userTty->print("\e[200;200H");
    this->userTty->print("\e[6n");
}

menu menuSystemOverTty;
menu * menuSystemOverTtyP = &menuSystemOverTty;
