#include <Arduino.h>
#include <menu.h>
#define serialPortUsed Serial// Choose your Serial port
// Create object, which inherits menuOption, so it can be used by the menuSystem
class simpleMenuOption : public menuOption{
  public:
        simpleMenuOption():menuOption("Example option"){}
        void run() override{// this overRiden function is called when enter pressed
          menuSystemOverTty.userTty->print("Hello world!");
          menuSystemOverTty.msgPause();
        }
};
// Create menuOptionOnOff object, which inherits menuOption, so it can be used by the menuSystem
class onboardLedShow : public menuOptionOnOff{
  public:
        onboardLedShow():menuOptionOnOff("Board LED"){
            pinMode(LED_BUILTIN, OUTPUT);
            digitalWrite(LED_BUILTIN, LOW);
        }
        void run() override{
          menuSystemOverTty.userTty->print("The led is ");
          if(state){
            menuSystemOverTty.printLnCentered("ON");// screen centering when display size was reported
          }else{
            menuSystemOverTty.printLnCentered("OFF");
          }
          menuSystemOverTty.msgPause();
        }
        bool refresh() override{// at menuOptionOnOff this is called when switched via arrow keys (left<-->right)
          if(menuOptionOnOff::refresh()){// calls parent constructor, IMPORTANT for display UI pruposes, returns true if state changed
            if(state){
              digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
            }else{
              digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
            }
            return true;// so display text is refreshed
          }
          return false;
        }
};
//--------Screen menus instances
screenMenu myOptionSelector = screenMenu("Arduino Menu System demo1");
//--------menu options instances
onboardLedShow secondMenuItem = onboardLedShow();
simpleMenuOption firstMenuItem = simpleMenuOption();
void setup() {
  //hardware init
  serialPortUsed.begin(9600);
  while (!serialPortUsed) {;}

  //build menu structure
  menuSystemOverTty.addscreen(&myOptionSelector);
  myOptionSelector.addMenuOption(&firstMenuItem);
  myOptionSelector.addMenuOption(&secondMenuItem);

  //menu init
  menuSystemOverTty.init(&serialPortUsed);// requiered at boot to set it up all stuff
}
void loop() {
  menuSystemOverTty.run();// keep it running
}
