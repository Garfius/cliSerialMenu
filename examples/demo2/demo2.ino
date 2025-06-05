#include <menu.h>
#include <Servo.h>
/**
 * To be used with vt100 compatible terminal consoles like Putty, screen(linux) or TeraTerm(Windows) DO NOT USE Arduino IDE serialPortUsed MONITOR. 
 * 
 * Here 4 menu options are shown, the first automaticaly changes when the motion detection pin state changes
 * You might move the servos connected at the setvo 1 pin and servo 2 pin using right and left arrows at the menu option
 * The last option is to show user interface capabilities like text prompt, alert messaging...
 * Use the arrows to navigate
 * 
 * Arduino Menu System demo2
 * -Idle                          <---- Shows automatic refresh capability
 * -Move servo 1:90               <---- Move a servo
 * -Move servo 2:90               <---- Move a servo
 * -Show menu UI capabilities     <---- Use UI stuff

*/
//------------------------------------CONFIGURATION START------------------------------------
#define serialPortUsed Serial// Choose your Serial port
#define baudRateUsed 9600// Choose your baud rate speed

#define motionDetectPin 2 // Choose your PIR pin
#define servo1Pin 10 // Choose Servo 1 pin
#define servo2Pin 11 // Choose Servo 2 pin
//------------------------------------CONFIGURATION END------------------------------------
Servo myServo1;
Servo myServo2;
bool motionDetectStatus = false;

static const char * dummyMessage = "Do something here";
static const char * noMotion = "Idle";
static const char * motion = "Motion detected";
class testUiStuff : public menuOption{
  public:
    testUiStuff() :menuOption("Show menu UI capabilities"){}
    void run(){
      char myText[menuTextArrayLength];
      String tmpStr = "Previous text";
      strcpy(myText,tmpStr.c_str());
      if(menuSystemOverTty.msgYes("(this is a msgYes)Do you really want to see my UI capabilities?")){
        menuSystemOverTty.msgSmallWait("(this is a smallWait)Here we go!");
        if(menuSystemOverTty.msgTxtInputSimple("(this is a msgTxtInputSimple)Enter a text:",myText,(menuTextArrayLength-1),1)){  
          menuSystemOverTty.userTty->println("(this will be a msgPause with text)You just wrote:");
          menuSystemOverTty.msgPause(myText);
        }else{
          menuSystemOverTty.msgPause("aborted");
        }
        menuSystemOverTty.userTty->println("(this will be a msgPause no text)And so this is it, bye");
        menuSystemOverTty.msgPause();
      }
    }
};
class testOption1 : public menuOption{
  protected:
    bool lastState;
  public:
        testOption1():menuOption(noMotion){
          lastState = motionDetectStatus;
        }
        void run(){
          menuSystemOverTty.msgSmallWait(dummyMessage);
          menuSystemOverTty.msgPause();
        }
        bool refresh(){
          if(lastState != motionDetectStatus){
            lastState = motionDetectStatus;
            if(motionDetectStatus){
              strcpy(text, motion);
            }else{
              strcpy(text, noMotion);
            }
            return true;
          }
          return false;
        }
};

class testOption3 : public menuOptionRangeValue{
  protected:
    
  public:
        testOption3():menuOptionRangeValue("Move servo 1",0,180,90,7){}
        void run(){
          menuSystemOverTty.msgPause(dummyMessage);
        }
        bool refresh(){
          if(menuOptionRangeValue::refresh()){// have the value changed?
            myServo1.write(state);
            return true;
          }
          return false;
        }
};
class testOption4 : public menuOptionRangeValue{
  protected:
  public:
        testOption4():menuOptionRangeValue("Move servo 2",0,180,90,7){}
        void run(){
          menuSystemOverTty.msgPause(dummyMessage);
          
        }
        bool refresh(){
          if(menuOptionRangeValue::refresh()){// have the value changed?
            myServo2.write(state);
            return true;
          }
          return false;
        }
};

testOption1 firstMenuItem = testOption1();
testOption3 ThirdMenuItem = testOption3();
testOption4 fourthMenuItem = testOption4();
testUiStuff secondMenuItem = testUiStuff();
screenMenu utilitats = screenMenu("Arduino Menu System demo2");

void motionDetectStateChange(){
  motionDetectStatus = digitalRead(motionDetectPin);
}
void setup() {
  serialPortUsed.begin(baudRateUsed);
  while (!serialPortUsed) {;}
  myServo1.attach(servo1Pin);
  myServo2.attach(servo2Pin);
  pinMode(motionDetectPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(motionDetectPin), motionDetectStateChange, CHANGE);
  
  menuSystemOverTty.addscreen(&utilitats);
  utilitats.addMenuOption(&firstMenuItem);// the order goes here
  utilitats.addMenuOption(&ThirdMenuItem);
  utilitats.addMenuOption(&fourthMenuItem);
  utilitats.addMenuOption(&secondMenuItem);
  utilitats.autoRefresh = true;
  
  menuSystemOverTty.init(&serialPortUsed);// requiered at boot
}

void loop() {
  menuSystemOverTty.run();
}

