#include "terminalParser.h"
/*#include <stdlib.h>
#include <stdio.h>*/
#ifdef finta_linux
    #include <cctype>
    #include <iostream>
    #include <string.h>
#endif
/**
* @file terminalParser.cpp
* @brief Inheritable byte-by-byte string parser state machine.
* Comportament putty:
* Cursor mou cursor
* cr <-- torna el carrier a inici
* Si escrius l'últim caràcter de la pantalla, el cursor es queda allà, saltará al seguent input
* 
* @author Gerard Forcada Bigas
*
* @date 20/12/22
*/

/*
Coses falten per parsejar
insert = 1B5B327E
ctrl dret = 1B4F43 ctrl esq = 1B4F44
insert = 1B5B327E
https://vt100.net/mirror/mds-199909/cd3/term/vt510rmb.pdf
https://wiki.bash-hackers.org/scripting/terminalcodes
https://man7.org/linux/man-pages/man4/console_codes.4.html
https://tldp.org/HOWTO/Bash-Prompt-HOWTO/x361.html
https://invisible-island.net/xterm/xterm.faq.html#ctlseqs_ms
*/
const unsigned char terminalParser::CONTROL_CARACTER_LIST[]{
    BEEP,		//  0x07
    BACKSPACE,//  0x08
    HT,		//  0x09
    LF,		//  0x0A
    CR,		//  0x0D
    SO,		//  0x0E shift in
    SI,		//  0x0F shift out
    CAN,	//  0x18
    ESC,	//  0x1B
    DEL,	//  0x7F
    CSI,	//  0x9B
};
const unsigned char terminalParser::ESCAPE_SEQUENCE_LIST[]{
    RIS,	  	//  'c'
    IND,	  	//  'D'
    NEL,	  	//  'E'
    HTS,	  	//  'H'
    RI,	    	//  'M'
    DECID,		//  'Z'
    DECSC,		//  '7'
    DECRC,		//  '8'
    ES_CSI,		//  '['
    DECPNM,		//  '>'
    DECPAM,		//  '='  
    OSC,      // ']'  -  COMANDA s.o.
    selecting_character_set,// '%'  - <-- ignora 1 de més
    DECALN,		// '#'  - <-- ignora 1 de més
    STARTG0,	// '('  - <-- ignora 1 de més
    STARTG1   // ')'  - <-- ignora 1 de més
};

const unsigned char terminalParser::CSI_SEQUENCE_LIST[]={
    ICH,		// '@'  - Insert the indicated # of blank characters.
    CUU,		// 'A'  - Move cursor up the indicated # of rows.
    CUD,		// 'B'  - Move cursor down the indicated # of rows.
    CUF,		// 'C'  - Move cursor right the indicated # of columns.
    CUB,		// 'D'  - Move cursor left the indicated # of columns.
    CNL,		// 'E'  - Move cursor down the indicated # of rows, to column 1
    CPL,		// 'F'  - Move cursor up the indicated # of rows, to column                     1.
    CHA,		// 'G'  -  Move cursor to indicated column in current row.
    CUP,		// 'H'  - Move cursor to the indicated row, column (origin at                     1,1).
    ED, 		// 'J'  -   ESC [ 1 J: erase from start to cursor.                     ESC [ 2 J: erase whole display.                     ESC [ 3 J: erase whole display including scroll-
    EL, 		// 'K'  - ESC [ 1 K: erase from start of line to cursor.                     ESC [ 2 K: erase whole line.
    IL, 		// 'L' - Insert the indicated # of blank lines, 
    DL, 		// 'M'  - Delete  the indicated # of blank lines
    DCH,		// 'P'  -  Delete the indicated # of characters on current                     line
    ECH,		// 'X'  -  Erase the indicated # of characters on current                     line
    HPR,		// 'a'  - Move cursor right the indicated # of columns
    DA,	  	// 'c'  - Answer ESC [ ? 6 c: "I am a VT102"
    VPA,		// 'd'  - Move cursor to the indicated row, current column.
    VPR,		// 'e'  -  Move cursor down the indicated # of rows.
    HVP,		// 'f'  -  Move cursor to the indicated row, column.
    TBC,		// 'g'  - Without parameter: clear tab stop at current                     position.ESC [ 3 g: delete all tab stops.
    SM,	  	// 'h'  - Set Mode (see below).
    /*the Reset Mode sequences are obtained by replacing the final 'h' by 'l'.*/
    RM,	  	// 'l'  - Reset Mode, 
    SGR,		// 'm'  - Set attributes
    DSR,		// 'n'  -  Status report 
    DECLL,	// 'q'  - Set keyboard LEDs.                     ESC [ 0 q: clear all LEDs                     ESC [ 1 q: set Scroll Lock LED                     ESC [ 2 q: set Num Lock LED                     ESC [ 3 q: set Caps Lock LED
    DECSTBM,// 'r'  - Set scrolling region; parameters are top and bottom                     row.
    Save_cursor_location,//  's'
    Restore_cursor_location,//  'u'
    HPA,		// '`'  -  Move cursor to indicated column in current row.
    LINUX_PRIVATE_CONTROL,// ']'  - Linux Console Private CSI Sequences
    PRIVATE_CONTROL_SEQUENCE,// '?'  - Linux Console Private CSI Sequences
};

//void terminalParser::dECSTBM(unsigned int argc,int *argv){}
void terminalParser::cUU(unsigned int argc,int *argv){}
void terminalParser::cUD(unsigned int argc,int *argv){}
void terminalParser::cUB(unsigned int argc,int *argv){}
void terminalParser::cUF(unsigned int argc,int *argv){}
void terminalParser::sGR(unsigned int argc,int *argv){}
void terminalParser::dSR(unsigned int argc,int *argv){}
//void terminalParser::cPR(unsigned int argc,int *argv){}
void terminalParser::rM(unsigned int argc,int *argv){}
void terminalParser::sM(unsigned int argc,int *argv){}
void terminalParser::dA(unsigned int argc,int *argv){}
void terminalParser::cUP(unsigned int argc,int *argv){}
void terminalParser::eD(unsigned int argc,int *argv){}
void terminalParser::vPA(unsigned int argc,int *argv){}
void terminalParser::cHA(unsigned int argc,int *argv){}
void terminalParser::eL(unsigned int argc,int *argv){}
void terminalParser::dCH(unsigned int argc,int *argv){}
//void terminalParser::cPR(unsigned int argc,int *argv){}
void terminalParser::backSpace(){}
//void terminalParser::_esc(){}
void terminalParser::tab(){}
void terminalParser::lf(){}
void terminalParser::beep(){}
void terminalParser::cr(){}
void terminalParser::del(){}
void terminalParser::insert(bool setDisplayInsert){
    insertStatus = !insertStatus;
   if(setDisplayInsert){
        if(insertStatus){
            userTty->print("\e[4h");
        }else{
            userTty->print("\e[4l");
        }
   }
}
void terminalParser::start(){}
void terminalParser::end(){}
void terminalParser::avPg(){}
void terminalParser::rePg(){}

//terminalParser::terminalParser(adafruitTerminalDisplay* pantallaExt){
terminalParser::terminalParser(){
    //this->pantalla = pantallaExt;
    controlSequence = esc = privateControlSequence = false;
    indexCaractersNumeros = indexllistaNumeros = ignore = indexBuffer= 0;
    caractersNumeros[0] = '\0';
    
}
void terminalParser::_enterCSI()
{
    controlSequence = true;
    esc = privateControlSequence = false;
    indexCaractersNumeros = indexllistaNumeros = 0;
    caractersNumeros[0] = '\0';
}
void terminalParser::_parsejaUnNumero(bool surt){
    if (isdigit(_buffer[indexBuffer-1]))// _parsejaUnNumero <-- si CAL!
    {
        _afegeixCaracterNumero('\0');
        llistaNumeros[indexllistaNumeros] = atoi(caractersNumeros);
        indexllistaNumeros++;
        indexCaractersNumeros = 0;
    }
    if(surt)this->_surt();
}
void terminalParser::_surt(){// surt de CSI 
    indexCaractersNumeros = 0;
    _buffer[indexBuffer+1] = '\0';
    indexBuffer = 0;
    controlSequence = false;
    esc = false;    
} 
void terminalParser::_afegeixCaracterNumero(char caracter){ // add to number parsing buffer
    caractersNumeros[indexCaractersNumeros] = caracter;
    if(indexCaractersNumeros < sizeof(caractersNumeros)){
        indexCaractersNumeros ++;
    }
}
bool terminalParser::_inControlCaracters(char caracter){
    for(i = 0; i < sizeof(CONTROL_CARACTER_LIST); i++){
        if(CONTROL_CARACTER_LIST[i] == caracter){
            return true;
        }
    }
    return false;
}
bool terminalParser::_inEscapeSequences(char caracter){
    for(i = 0; i < sizeof(ESCAPE_SEQUENCE_LIST); i++){
        if(ESCAPE_SEQUENCE_LIST[i] == caracter){
            return true;
        }
    }
    return false;
}
bool terminalParser::_inCsiSequences(char caracter){// no es fa servir, pot ser numero o ;
    for(i = 0; i < sizeof(CSI_SEQUENCE_LIST); i++){
        if(CSI_SEQUENCE_LIST[i] == caracter){
            return true;
        }
    }
    return false;
}

bool terminalParser::doGuess(char caracter){// do the thing, and guess(return) if shall be screened
    if (ignore > 0)
    {
        esc = false;
        ignore--;
        return false;
    }
    
    if (!controlSequence && !esc && (this->_inControlCaracters(caracter)))
    {
        _buffer[0] = caracter;
        if (caracter == CSI)// equivalent a (esc)[, salta 2 de cop ;)
        {
            _enterCSI();
        }
        else if (caracter == ESC)
        {
            esc = true;
        }else if (caracter == BEEP)
        {
            beep();
        }
        else if (caracter == BACKSPACE)
        {
            backSpace();
        }
        else if (caracter == HT)
        {
            this->tab();
        }
        else if (caracter == LF)
        {
            this->lf();
        }
        else if (caracter == CR)
        {//
            this->cr();
        }
        else if (caracter == CAN)
        { // ABORT SEQUENCE
            controlSequence = false;
        }
        else if (caracter == DEL)
        {
            this->del();
        }else if((caracter == SI)||(caracter == SO)){

        }
        else
        {// els no contemplats
            esc = false;
            return true;
        }
        return false;
    }else if (esc && (this->_inEscapeSequences(caracter)))
    {
        indexBuffer ++;
        _buffer[indexBuffer] = caracter;
        if (caracter == ES_CSI)
        {
            _enterCSI();
        }
        else if (caracter == selecting_character_set)
        {
            ignore = 1;
        }
        else if (caracter == STARTG0)
        {
            ignore = 1;
        }
        else if (caracter == STARTG1)
        {
            ignore = 1;
        }
        else if (caracter == DECALN)
        {
            ignore = 1;
        }
        else if (caracter == OSC)
        {
            /*no hi ha sistema operatiu, no es parseja, coses de clipboard, notificacions, window title https://blog.vucica.net/2017/07/what-are-osc-terminal-control-sequences-escape-codes.html
                */
            esc = false;
        }
        else
        {// els no contemplats?¿
            
            _surt();
            return true;
        }
        return false;
    }
    else if (controlSequence)
    {
        //to-do posar amunt, avall dreta i esquerra A B C D
        // anar parsejant caracters, assignant valors fins encaixar algun CSI
        indexBuffer ++;
        _buffer[indexBuffer] = caracter;
        if (caracter == CUU)// Move cursor to indicated column in current row.
        {
            _parsejaUnNumero();
            this->cUU(indexllistaNumeros,llistaNumeros);// vist amb 1 num
        }
        else if (caracter == CUD)// Move cursor to indicated column in current row.
        {
            _parsejaUnNumero();
            this->cUD(indexllistaNumeros,llistaNumeros);// vist amb 1 num
        }
        else if (caracter == CUF)// Move cursor to indicated column in current row.
        {
            _parsejaUnNumero();
            this->cUF(indexllistaNumeros,llistaNumeros);// vist amb 1 num
        }
        else if (caracter == CUB)// Move cursor to indicated column in current row.
        {
            _parsejaUnNumero();
            this->cUB(indexllistaNumeros,llistaNumeros);// vist amb 1 num
        }
        else 


        if (caracter == CHA)// Move cursor to indicated column in current row.
        {
            _parsejaUnNumero();
            this->cHA(indexllistaNumeros,llistaNumeros);// vist amb 1 num
        }
        /*else if (caracter == DECSTBM)//Set scrolling region; parameters are top and bottom row.
        {
            _parsejaUnNumero();
            this->dECSTBM(indexllistaNumeros,llistaNumeros);// vist amb 1 num// to-do executa funcio, vist en 2 num
        }*/
        else if (caracter == SGR)//Set SELECT_GRAPHIC_RENDITION           '0' = RESET.           '10' = DEFAULT_FONT.           '7' = INVERSE.
        {// fer color invers
            _parsejaUnNumero();
            this->sGR(indexllistaNumeros,llistaNumeros);// vist amb 1 num// to-do executa funcio, vist en 2 num// to-do executa funcio, vist amb 2 num, vist sense numeros, vist amb 3 numeros
        }
        else if (caracter == DSR)
        {// fer color invers
            _parsejaUnNumero();
            this->dSR(indexllistaNumeros,llistaNumeros);
        }
        /*else if (caracter == CPR)
        {// fer color invers
            _parsejaUnNumero();
            this->cPR(indexllistaNumeros,llistaNumeros);
        }*/
        else if (caracter == RM)
        {
            _parsejaUnNumero();
            if (privateControlSequence){
                this->rM(indexllistaNumeros,llistaNumeros);// vist amb 1 num// to-do executa funcio, vist en 2 num// to-do executa funcio, vist amb 2 num, vist sense numeros, vist amb 3 numeros
            }
        }
        else if (caracter == SM)
        {
            _parsejaUnNumero();
            if (privateControlSequence){
                this->sM(indexllistaNumeros,llistaNumeros);// to-do executa funcio? no, és de capa 2
            }
        }
        else if (caracter == DA)
        {
            _parsejaUnNumero();
            this->dA(indexllistaNumeros,llistaNumeros);// to-do executa funcio? no, és de capa 2
            // to-do executa funcio? no, és de capa 2
        }
        else if (caracter == CUP)
        {
            _parsejaUnNumero();
            this->cUP(indexllistaNumeros,llistaNumeros);// to-do executa funcio? no, és de capa 2
            // to-do executar funcio, vist amb 2 num
        }
        else if (caracter == ED)
        {
            _parsejaUnNumero();
            this->eD(indexllistaNumeros,llistaNumeros);// to-do executa funcio? no, és de capa 
        }else if (caracter == EL)
        {
            _parsejaUnNumero();
            this->eL(indexllistaNumeros,llistaNumeros);// to-do executa funcio? no, és de capa 
        }
        else if (caracter == DCH)
        {
            _parsejaUnNumero();
            this->dCH(indexllistaNumeros,llistaNumeros);// to-do executa funcio? no, és de capa 
        }/*else if (caracter == CPR)
        {
            _parsejaUnNumero();
            this->cPR(indexllistaNumeros,llistaNumeros);// to-do executa funcio? no, és de capa 
        }*/
        
        else if (caracter == VPA)
        {
            _parsejaUnNumero();
            this->vPA(indexllistaNumeros,llistaNumeros);// to-do executa funcio? no, és de capa 
            // to do executar funció, vist amb 1 num
        }
        else if (caracter == '~')// posar del aqui? caracter == '~' 
        {
            _parsejaUnNumero();
            if((indexllistaNumeros == 1)&&(llistaNumeros[0]==1))this->start();
            else if((indexllistaNumeros == 1)&&(llistaNumeros[0]==2))this->insert();
            else if((indexllistaNumeros == 1)&&(llistaNumeros[0]==3))this->del();
            else if((indexllistaNumeros == 1)&&(llistaNumeros[0]==4))this->end();
            else if((indexllistaNumeros == 1)&&(llistaNumeros[0]==5))this->rePg();
            else if((indexllistaNumeros == 1)&&(llistaNumeros[0]==6))this->avPg();
            // to do executar funció, vist amb 1 num
        }
        else if (caracter == PRIVATE_CONTROL_SEQUENCE) // entra a capa 2
        {
            privateControlSequence = true;
        }
        else if (caracter == 0x3b)// ; <-- punt i coma
        {// toca parsejar numero
            _parsejaUnNumero(false);
        }
        
        else if (!isdigit(caracter))// arduino caps linux no caps
        
        { // si no és numero i no es contemplat surt
            _surt();
            return true;
        }
        else if (isdigit(caracter))
        {
            _afegeixCaracterNumero(caracter);
        }
        else
        {// els no contemplats?
            /*
            // for debug pruposes
            _buffer[0] = ' ';
            Serial.println(_buffer);
            */
            _surt();
            return true;
        }
        return false;
    }else{
        esc=false;
         /*if (esc && (caracter == ESC)){
            esc=false;
            _esc();
         }*/
    }
    return true;
}
void terminalParser::invertColors(String *cadena){// canviar a printInverted, gasta menys ram to-do
    *cadena = inverteixColorsTerminal+(*cadena)+colorsTerminalReset;
}
void terminalParser::invertColors(char* entrada,unsigned int allargadaMax){
    String caption = inverteixColorsTerminal+String(entrada);
    unsigned int y = caption.length();
    if (y > (allargadaMax-(sizeof(colorsTerminalReset)+1)))// diferenciar quantitat i index.
    {
        y = allargadaMax - (sizeof(colorsTerminalReset)+1);// el +1 es pot treure
    }
    caption =  caption.substring(0,y);// substring necessita quantitat chars
    caption.concat(colorsTerminalReset);
    strcpy(entrada, caption.c_str());
}
/**
 * Cursor position report
void terminalParser::askDisplaySize(){//DSR
   userTty->write("\e[6n");
}
*/
/**
Cursor Position, inherited from terminalParser
*/
void terminalParser::doMoveCursor(int line,int column){// Cursor Position, this array starts at 1
    sprintf(_buffer,"\e[%d;%dH",line,column);
    userTty->write(_buffer);
}
void terminalParser::init(Stream *pantalla){
    userTty = pantalla;
    insertStatus = false;// al reves
    insert();
}
/**
Clear screen
*/
void terminalParser::doClearScreen(){
    userTty->write("\e[2J");
}
void terminalParser::doCUU(unsigned int amount){
    if(amount ==0)return;
    if(amount > 1){
        userTty->print("\e["+String(amount)+"A");
    }else{
        userTty->print("\e[A");
    }
}
void terminalParser::doCUD(unsigned int amount){
    if(amount ==0)return;
    if(amount > 1){
        userTty->print("\e["+String(amount)+"B");
    }else{
        userTty->print("\e[B");
    }
}
void terminalParser::doCUF(unsigned int amount){
    if(amount ==0)return;
    if(amount > 1){
        userTty->print("\e["+String(amount)+"C");
    }else{
        userTty->print("\e[C");
    }
}
void terminalParser::doCUB(unsigned int amount){
    if(amount ==0)return;
    if(amount > 1){
        userTty->print("\e["+String(amount)+"D");
    }else{
        userTty->print("\e[D");
    }
}
/**
 * ESC [ 1 K: erase from start of line to cursor. ESC [ 2 K: erase whole line.
*/
void terminalParser::doEL(bool totaLinia){
    userTty->print("\e[");
    if(totaLinia){
        userTty->write("2");
    }else{
        userTty->write("1");
    }
    userTty->write("K");
}
void terminalParser::doHideCursor(bool hide){
    userTty->print("\e[?25");
    if(hide){
        userTty->write("l");
    }else{
        userTty->write("h");
    }
}
