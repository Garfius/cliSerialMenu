#include <Arduino.h>
#include <menu.h>
#define inputPin 20
#define serialPortUsed Serial// Choose your Serial port
char allowedChars[86] = 
    "0123456789" 
    "abcdefghij" 
    "klmnopqrst" 
    "uvwxyzABCD"
    "EFGHIJKLMN" 
    "OPQRSTUVWX" 
    "YZ.-:+=^!/" 
    "*?&<>()\\;," 
    " @%$#";
class resizer : public menuOption{
  public:
    resizer() :menuOption("Change menu length"){}
    void run(){
      char myText[15];
      String tmpStr = (String)menuSystemOverTty.screenMenuOptions;
      strcpy(myText,tmpStr.c_str());
      menuSystemOverTty.msgSmallWait("Here comes a msgTxtInput");
      if(menuSystemOverTty.msgTxtInput("Change Screen Menu Options:",myText,3,1)){
        tmpStr = (String)myText;
        unsigned int tmpInt = (unsigned int)tmpStr.toInt();
        if((tmpInt <= menuOptionsMax) && (tmpInt > 0)){
          tmpStr = (String)"New value="+(String)tmpInt;
          strcpy(myText,tmpStr.c_str());
          menuSystemOverTty.msgSmallWait(myText);
          if(menuSystemOverTty.msgYes("U sure?")){
            menuSystemOverTty.screenMenuOptions = tmpInt;
            menuSystemOverTty.setscreen(0,false);
          }
          return;
        }
      }
      menuSystemOverTty.msgSmallWait("Wrong value");
    }
};
class configurer : public menuOption{
    void printDescription(){
      String menuConfigDescription = (String)"verticallyCenter:"+(String)menuSystemOverTtyP->verticallyCenter+(String)" horizontallyCenter:"+(String)menuSystemOverTtyP->horizontallyCenter+(String)" textLineWidth:"+(String)menuSystemOverTtyP->textLineWidth+(String)" Columns:"+(String)menuSystemOverTtyP->terminalRowsCols[1]+(String)" Rows:"+(String)menuSystemOverTtyP->terminalRowsCols[0]+(String)" askTerminalSize:"+(String)menuSystemOverTtyP->askTerminalSize+" Menu padding: "+(String)menuSystemOverTtyP->_topPadding;
      menuSystemOverTtyP->msgPause(menuConfigDescription.c_str());
    }
  public:
    configurer() :menuOption("Change menu beheaviour"){}
    void run(){
      printDescription();
      if(menuSystemOverTtyP->msgYes("clear terminal size?")){
        menuSystemOverTtyP->terminalRowsCols[0] = 0;
        menuSystemOverTtyP->terminalRowsCols[1] = 0;
        menuSystemOverTtyP->terminalSizeQueries = 0;
        return;
      }
      menuSystemOverTtyP->askTerminalSize = menuSystemOverTtyP->msgYes("keep asking for terminal size?");
      menuSystemOverTtyP->verticallyCenter = menuSystemOverTtyP->msgYes("Center verticaly?");
      menuSystemOverTtyP->horizontallyCenter = menuSystemOverTtyP->msgYes("Center horizontally?");
      char myText[15];
      String tmpStr = (String)menuSystemOverTty._topPadding;
      strcpy(myText,tmpStr.c_str());
      menuSystemOverTtyP->msgSmallWait("this is single line text input msgTxtInput");
      if(menuSystemOverTty.msgTxtInput("Set menu top padding:",myText,3,1)){
        tmpStr = (String)myText;
        unsigned int tmpInt = (unsigned int)tmpStr.toInt();
        if((tmpInt <= menuOptionsMax) && (tmpInt > 0)){
          tmpStr = (String)"New value="+(String)tmpInt;
          strcpy(myText,tmpStr.c_str());
          menuSystemOverTty.msgSmallWait(myText);
          menuSystemOverTty._topPadding = tmpInt;
        }else{
          menuSystemOverTty.msgSmallWait("error");
        }
      }else{
        menuSystemOverTty.msgSmallWait("Wrong value");
      }
      printDescription();
    }
};
class rangeShow : public menuOptionRangeValue{
  public:
        rangeShow():menuOptionRangeValue("Select text input line width",minTextBoxWidth,80,defaultTextBoxWidth,2){}
        void run(){
            String tmpStr = "Value set to:"+(String)state;
            if(menuSystemOverTtyP->msgYes(tmpStr.c_str())){  
              menuSystemOverTtyP->textLineWidth = state;
              menuSystemOverTtyP->msgSmallWait("ok");
            }
            menuSystemOverTtyP->msgPause();
        }
        //bool refresh(){} not used, not need to do anything when refreshing
};
class scrollMenuOption: public menuOption{
  unsigned int _myIndex;
  public:
    scrollMenuOption(){};
    scrollMenuOption(const char* text,unsigned int myIndex):menuOption(text){
      _myIndex = myIndex;
    }
  void run(){
    menuSystemOverTty.userTty->print("You just ran index:");
    menuSystemOverTty.printLnCentered(_myIndex);
    menuSystemOverTty.msgPause();
  }
};
static const char * myScrollingMenuCaption = "A dyn-generated scrolling menu";
class myScrollingMenu :public  screenMenu{
  protected:
    static const unsigned int maxValue = 16;
    unsigned int downValue =0;
    scrollMenuOption menuOptions[menuOptionsMax];// use displayMenuOptionsDefault to cheap memory on static size menu
  public: 
    myScrollingMenu():screenMenu(myScrollingMenuCaption){
    }
    bool refreshMenu() override{
      // chack wether display 
      if(totalMenuOptions!= menuSystemOverTty.screenMenuOptions)totalMenuOptions = menuSystemOverTty.screenMenuOptions;

      String tmpStr = (String)myScrollingMenuCaption;
      if(downValue > 0){
        tmpStr += (String)msgOptionsUp;
      }
      if((downValue+menuSystemOverTty.screenMenuOptions) <= maxValue){
        tmpStr += (String)msgOptionsDn;
      }

      strcpy(titol,tmpStr.c_str());
      for (unsigned int i = 0; i < totalMenuOptions; i++)
      {
          tmpStr = "This is menuItem "+(String)(downValue+i);// using arduino string manipulation is da best
          menuOptions[i] = scrollMenuOption(tmpStr.c_str(),(downValue+i));
          menuOptions[i].autoRefresh = false;
          displayMenuOptionsPnt[i] = &menuOptions[i]; // flipada, admet punters de sobrecàrregues ? SI!
      }
      //return screenMenu::refreshMenu();
      return false;
    }
    void leave() override{
      //downValue =0;
      strcpy(titol,myScrollingMenuCaption);
    }
    bool pushUp() override{
      if(downValue > 0){
        downValue--;
        refreshMenu();
        return true;
      }
      return false;
    }
    bool pushDn() override{
      if((downValue+menuSystemOverTty.screenMenuOptions) <= maxValue){
        downValue++;
        refreshMenu();
        return true;
      }
      return false;
    }
};
class textBoxDemoMenuOption : public textBoxMenuOption{
  static const int textBoxDemoArraySize = 340;
  public:
        textBoxDemoMenuOption():textBoxMenuOption("Multiline text Box input demo"){}
        bool checkBackgroundEvents() override{
            return digitalRead(inputPin) == HIGH;
        }
        bool performUserInteraction() override{
            menuSystemOverTtyP->msgPause("physical button pushed");
            return digitalRead(inputPin) == HIGH;
        }
        void run(){
          textBoxMenuOption::run();// <-- IMPORTANT !!
            char result[textBoxDemoArraySize];
            strcpy(result,"And so that no one else may be blamed if errors are found in this work, I, Johanot Martorell, knight, alone wish to bear the responsibility...");
            menuSystemOverTty.msgTxtInputMultiline(result,textBoxDemoArraySize-1,1,allowedChars);
            if(menuSystemOverTty._textBoxStatus == textBoxStatus::enterPressed){
                menuSystemOverTty.userTty->print("You wrote and enter:");
                menuSystemOverTty.printLnCentered(result);
            }else if(menuSystemOverTty._textBoxStatus == textBoxStatus::escPressed){
              menuSystemOverTty.userTty->print("Esc pressed:");
              menuSystemOverTty.printLnCentered(result);
            }else if(menuSystemOverTty._textBoxStatus == textBoxStatus::softwareAborted){
              menuSystemOverTty.userTty->print("Software aborted:");
              menuSystemOverTty.printLnCentered(result);
            }else if(menuSystemOverTty._textBoxStatus == textBoxStatus::activeEditor){
              menuSystemOverTty.userTty->print("----SHIT1---:");
              menuSystemOverTty.printLnCentered(result);
            }else if(menuSystemOverTty._textBoxStatus == textBoxStatus::noExit){
              menuSystemOverTty.userTty->print("----SHIT2---:");
              menuSystemOverTty.printLnCentered(result);
            }else if(menuSystemOverTty._textBoxStatus == textBoxStatus::error){
              menuSystemOverTty.userTty->print("Error");
              menuSystemOverTty.printLnCentered(result);
            }else{
                menuSystemOverTty.userTty->print("----SHIT3---:");
                menuSystemOverTty.printLnCentered(result);
            }
            String tmpStr = "Exit code:"+(String)menuSystemOverTty.lastTextBoxExitCode;
            menuSystemOverTty.setPrettyDotLeadersMargin(20);
            menuSystemOverTty.printDotLeaders(tmpStr.c_str(),menuTextBox::exitCodeDescription[menuSystemOverTty.lastTextBoxExitCode]);
            menuSystemOverTty.msgPause();
        }
};
//--------Screen menus instances
screenMenu myOptionSelector = screenMenu("Arduino Menu System demo1");
myScrollingMenu scrolling = myScrollingMenu();
//--------menu options instances
rangeShow firstMenuItem = rangeShow();
changeScreenMenuOption thirdMenuOption = changeScreenMenuOption(&scrolling);// cast is needed bc inheritance
resizer fifthMenuOptyion = resizer();
configurer sixtMenuOptyion = configurer();
textBoxDemoMenuOption notepat = textBoxDemoMenuOption();
void setup() {
  //hardware init
  serialPortUsed.begin(9600);
  while (!serialPortUsed) {;}
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  pinMode(inputPin, INPUT);
  
  //build menu structure
  menuSystemOverTty.addscreen(&myOptionSelector);
  menuSystemOverTty.addscreen(&scrolling);
  myOptionSelector.addMenuOption(&firstMenuItem);// the order goes here
  myOptionSelector.addMenuOption(&thirdMenuOption);
  myOptionSelector.addMenuOption(&fifthMenuOptyion);
  myOptionSelector.addMenuOption(&sixtMenuOptyion);
  myOptionSelector.addMenuOption(&notepat);

  //menu init
  menuSystemOverTty.init(&serialPortUsed);// requiered at boot 
}

void loop() {
  menuSystemOverTty.run();
}
