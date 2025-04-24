#include <Arduino.h>
#include <menu.h>
/**
 * 
 * To be used with vt100 compatible terminal consoles like Putty, screen(linux) or TeraTerm(Windows) DO NOT USE Arduino IDE SERIAL MONITOR. 
 * 
 * Here you can use 4 menu options at the main screen menu, plus a second screen menu which is dynamically generated.
 * Use the arrows to navigate
 * 
 * Arduino Menu System demo1
 * -Select value:50                   <---- Slider menuOption demo
 * -Board LED:OFF                     <---- Switch menuOption demo
 * -A dyn-generated scrolling menu    <---- Jump to secondary screen menu which is dynamically generated
 * -Change menu length                <---- You might set the amount of displayed menu options
 *
*/
//------------------------------------CONFIGURATION START------------------------------------
#define serialPortUsed Serial// Choose your Serial port
#define baudRateUsed 9600// Choose your baud rate speed
//------------------------------------CONFIGURATION END------------------------------------
class resizer : public menuOption{
  public:
    resizer() :menuOption("Change menu length"){}
    void run(){
      char myText[15];
      String tmpStr = (String)menuSystemOverTty.screenMenuOptions;
      strcpy(myText,tmpStr.c_str());
      if(menuSystemOverTty.msgTxtInputSimple("Change Screen Menu Options:",myText,3,1)){
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
class rangeShow : public menuOptionRangeValue{
  public:
        rangeShow():menuOptionRangeValue("Select value",0,100,50){}
        void run(){
            menuSystemOverTty.userTty->print("Here do something with");
            menuSystemOverTty.userTty->println(state);
            menuSystemOverTty.msgPause();
        }
        //bool refresh(){} not used, not need to do anything when refreshing
};
class onboardLedShow : public menuOptionOnOff{
  public:
        onboardLedShow():menuOptionOnOff("Board LED"){}
        void run(){
          menuSystemOverTty.userTty->print("The led is ");
          if(state){
            menuSystemOverTty.userTty->println("ON");
          }else{
            menuSystemOverTty.userTty->println("OFF");
          }
          menuSystemOverTty.msgPause();
        }
        bool refresh(){
          if(menuOptionOnOff::refresh()){
            if(state){
              digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
            }else{
              digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
            }
            return true;
          }
          return false;
        }
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
    menuSystemOverTty.userTty->println(_myIndex);
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
    bool refreshMenu(){
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
    void bye(){
      downValue =0;
      strcpy(titol,myScrollingMenuCaption);
    }
    bool pushUp(){// to-do
      if(downValue > 0){
        downValue--;
        refreshMenu();
        return true;
      }
      return false;
    }
    bool pushDn(){
      if((downValue+menuSystemOverTty.screenMenuOptions) <= maxValue){
        downValue++;
        refreshMenu();
        return true;
      }
      return false;
    }
};
//--------Screen menus instances
screenMenu utilitats = screenMenu("Arduino Menu System demo1");
myScrollingMenu scrolling = myScrollingMenu();
//--------menu options instances
rangeShow firstMenuItem = rangeShow();
onboardLedShow secondMenuItem = onboardLedShow();
changeScreenMenuOption thirdMenuOption = changeScreenMenuOption(&scrolling);// cast is needed bc inheritance
resizer fifthMenuOptyion = resizer();
void setup() {
  //hardware init
  serialPortUsed.begin(baudRateUsed);
  while (!serialPortUsed) {;}
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW); 
  
  //build menu structure
  menuSystemOverTty.addscreen(&utilitats);
  menuSystemOverTty.addscreen(&scrolling);
  utilitats.addMenuOption(&firstMenuItem);// the order goes here
  utilitats.addMenuOption(&secondMenuItem);
  utilitats.addMenuOption(&thirdMenuOption);
  utilitats.addMenuOption(&fifthMenuOptyion);

  //menu init
  menuSystemOverTty.init(&serialPortUsed);// requiered at boot 
}

void loop() {
  menuSystemOverTty.run();
}
