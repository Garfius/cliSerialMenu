#include <Arduino.h>
#include <menu.h>
#include <Servo.h>
#define motionDetectPin 2// PIR sensor
#define servo1Pin 10
#define servo2Pin 11
#define serialPortUsed Serial// Choose your Serial port
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
        if(menuSystemOverTty.msgTxtInput("(this is a msgTxtInputSimple)Enter a text:",myText,(menuTextArrayLength-1),1)){  
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
  Serial.begin(9600);
  while (!Serial) {;}
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
  
  menuSystemOverTty.init(&Serial);// requiered at boot
}

void loop() {
  menuSystemOverTty.run();
}

