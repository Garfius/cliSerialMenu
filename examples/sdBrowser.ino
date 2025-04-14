#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include <time.h>
#include <menu.h>

//--------Uncomment _MENU_UI_BIG_RAM_ from menu.h:19 for proper displaying, tested on rp2040
#define sdCsPin 17// Choose your SD CS pin

static const char * sdError = "SD err";

class sdBrowserDisplay : public screenMenu{
        File root;
        String currentFolder = "";
    protected:
        unsigned int downValue =0;
        bool notEneded = false;
        char fileName[menuOptionsMax][menuTextArrayLength];/**< Caption */
    public:
        menuOption menuOptions[menuOptionsMax];
        sdBrowserDisplay();
        virtual bool refreshMenu();
        virtual void run(unsigned int index);
        virtual bool pushDn();
        virtual bool pushUp();
        virtual void bye();
};
sdBrowserDisplay::sdBrowserDisplay() : screenMenu("No OS SD browse")
{}
void sdBrowserDisplay::run(unsigned int index){
    
    String tmpStr = String(fileName[index+offsetFromTop]);
    
    if (!SD.begin(sdCsPin))
    {
        menuSystemOverTtyP->msgSmallWait(sdError);
        return;
    }
    File entry;
    time_t tmpTime;
    tmpStr = currentFolder+"/"+tmpStr;
    entry = SD.open(tmpStr.c_str(), FILE_READ);
    if (entry){
        if(entry.isDirectory()){
            currentFolder = tmpStr;
            menuSystemOverTtyP->userTty->print("Folder change to:");
            menuSystemOverTtyP->userTty->println(currentFolder.c_str());
            downValue = offsetFromTop = 0;
            this->refreshMenu();
        }else{
            menuSystemOverTtyP->userTty->print("Name:");
            menuSystemOverTtyP->userTty->println(entry.name());
            menuSystemOverTtyP->userTty->print("fullName:");
            menuSystemOverTtyP->userTty->println(entry.fullName());
            tmpTime = entry.getCreationTime();
            menuSystemOverTtyP->userTty->print("CreationTime:");
            menuSystemOverTtyP->userTty->print(ctime(&tmpTime));
            tmpTime = entry.getLastWrite();
            menuSystemOverTtyP->userTty->print("\rLastWrite:");
            menuSystemOverTtyP->userTty->print(ctime(&tmpTime));
            menuSystemOverTtyP->userTty->print("\rsize:");
            menuSystemOverTtyP->userTty->println(entry.size());
            entry.close();
        }
    }else{
        menuSystemOverTtyP->userTty->println("file not found");
    }
    SD.end(false);
    menuSystemOverTtyP->msgPause();
    
}
bool sdBrowserDisplay::pushDn()
{
    if(notEneded){
        downValue++;
        refreshMenu();
        return true;
    }
    return false;
}
bool sdBrowserDisplay::pushUp()
{
    if(downValue > 0){
        downValue--;
        refreshMenu();
        return true;
    }
    return false;
}
void sdBrowserDisplay::bye(){
    if(currentFolder.length() == 0){
        menuSystemOverTtyP->doClearScreen();
        menuSystemOverTtyP->doMoveCursor(1,1);
        if (!SD.begin(sdCsPin))
        {
            menuSystemOverTtyP->msgSmallWait(sdError);
            return;
        }
        menuSystemOverTtyP->userTty->print("FatType:");
        menuSystemOverTtyP->userTty->println(SD.fatType());
        menuSystemOverTtyP->userTty->print("blockSize:");
        menuSystemOverTtyP->userTty->println(SD.blockSize());
        menuSystemOverTtyP->userTty->print("blocksPerCluster:");
        menuSystemOverTtyP->userTty->println(SD.blocksPerCluster());
        menuSystemOverTtyP->userTty->print("clusterSize:");
        menuSystemOverTtyP->userTty->println(SD.clusterSize());
        menuSystemOverTtyP->userTty->print("Size:");
        menuSystemOverTtyP->userTty->println(SD.size());
        menuSystemOverTtyP->userTty->print("Size64:");
        menuSystemOverTtyP->userTty->println(SD.size64());
        menuSystemOverTtyP->userTty->print("totalBlocks:");
        menuSystemOverTtyP->userTty->println(SD.totalBlocks());
        menuSystemOverTtyP->userTty->print("totalClusters:");
        menuSystemOverTtyP->userTty->println(SD.totalClusters());
        menuSystemOverTtyP->userTty->print("type:");
        menuSystemOverTtyP->userTty->println(SD.type());
        SD.end(false);
        menuSystemOverTtyP->msgPause();
    }else{
        currentFolder = currentFolder.substring(0,currentFolder.lastIndexOf('/'));
        downValue =0;
    }
    this->refreshMenu();
}
bool sdBrowserDisplay::refreshMenu()//, bool canviaTitol
{
    if (!SD.begin(sdCsPin))
    {
        menuSystemOverTtyP->msgSmallWait(sdError);
        return false;
    }
    root = SD.open(currentFolder.c_str());
    
    const char *suffixes[] = {"B", "KB", "MB"};
    const unsigned int num_suffixes = sizeof(suffixes) / sizeof(suffixes[0]);
    
    if(downValue > 0){offsetFromTop = 1;}else{offsetFromTop = 0;}
    totalMenuOptions =0;
    File entry;
    String tmpStr;
    size_t sizeTmp;
    unsigned int tmpInt = 0;
    while(true){
        if(tmpInt >= downValue)break;
        tmpInt++;
        entry = root.openNextFile();
        if (!entry)
        {
            break;
        }
    }

    while(true){
        entry = root.openNextFile();
        if (!entry)
        {
            break;
        }
        tmpStr = (String)entry.name();
        strcpy(fileName[totalMenuOptions+offsetFromTop],entry.name());
        menuOptions[totalMenuOptions+offsetFromTop] = menuOption();
        menuOptions[totalMenuOptions+offsetFromTop].autoRefresh = false;
        displayMenuOptionsPnt[totalMenuOptions+offsetFromTop] = &menuOptions[totalMenuOptions+offsetFromTop];
        if(entry.isDirectory()){
            tmpStr = String("./"+String(entry.name())).substring(0,menuTextLength);
        }else{
            sizeTmp = entry.size();
            tmpInt = 0;
            while (sizeTmp >= 1024.0 && tmpInt < num_suffixes - 1)
            {
                sizeTmp /= 1024.0;
                tmpInt++;
            }
            tmpStr = String(String(entry.name()) + " " + String(sizeTmp) + suffixes[tmpInt]).substring(0,menuTextLength);
        }
        strcpy(menuOptions[totalMenuOptions+offsetFromTop].text, tmpStr.c_str());

        totalMenuOptions++;
        if(totalMenuOptions >= menuSystemOverTtyP->screenMenuOptions){
            break;
        }
    }
    
    notEneded = false;
    if (entry)// has acabat en ple
    {
        while(true){
            entry = root.openNextFile();
            if(entry){// n'hi havia un de més
                notEneded = true;// posar dn al caption
                totalMenuOptions+=(offsetFromTop+1);
            }else{
                break;
            }
        }
    }

    SD.end(false);
    if (totalMenuOptions == 0)
    {
        menuSystemOverTtyP->msgSmallWait("No files found");
    }
    return false;
}

//--------Screen menus instances
sdBrowserDisplay navegador = sdBrowserDisplay();


void setup() {
  //hardware init
  SPI.begin();
  Serial.begin(115200);
  while (!Serial) {;}
  
  //build menu structure
  menuSystemOverTty.addscreen(&navegador);
  //menu init
  menuSystemOverTty.init(&Serial);// requiered at boot 
}

void loop() {
  menuSystemOverTty.run();
}
