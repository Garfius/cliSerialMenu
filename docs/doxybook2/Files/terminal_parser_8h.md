---
title: cliSerialMenu/terminalParser.h
summary: object and resources definitions for terminal parser library, Inheritable byte-by-byte string parser state machine. 

---

# cliSerialMenu/terminalParser.h

object and resources definitions for terminal parser library, Inheritable byte-by-byte string parser state machine.  [More...](#detailed-description)

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[terminalParser](Classes/classterminal_parser.md)**  |

## Types

|                | Name           |
| -------------- | -------------- |
| enum| **[CONTROL_CARACTERS](Files/terminal_parser_8h.md#enum-control-caracters)** { BEEP = 0x07, BACKSPACE = 0x08, HT = 0x09, LF = 0x0A, CR = 0x0D, SO = 0x0E, SI = 0x0F, CAN = 0x18, ESC = 0x1B, DEL = 0x7F, CSI = 0x9B} |
| enum| **[ESCAPE_SEQUENCES](Files/terminal_parser_8h.md#enum-escape-sequences)** { RIS = 'c', IND = 'D', NEL = 'E', HTS = 'H', RI = 'M', DECID = 'Z', DECSC = '7', DECRC = '8', ES_CSI = '[', DECPNM = '>', DECPAM = '=', OSC = ']', selecting_character_set = '%', DECALN = '#', STARTG0 = '(', STARTG1 = ')'} |
| enum| **[CSI_SEQUENCES](Files/terminal_parser_8h.md#enum-csi-sequences)** { ICH = '@', CUU = 'A', CUD = 'B', CUF = 'C', CUB = 'D', CNL = 'E', CPL = 'F', CHA = 'G', CUP = 'H', ED = 'J', EL = 'K', IL = 'L', DL = 'M', DCH = 'P', ECH = 'X', HPR = 'a', DA = 'c', VPA = 'd', VPR = 'e', HVP = 'f', TBC = 'g', SM = 'h', RM = 'l', SGR = 'm', DSR = 'n', CPR = 'R', DECLL = 'q', DECSTBM = 'r', Save_cursor_location = 's', Restore_cursor_location = 'u', HPA = '`', LINUX_PRIVATE_CONTROL = ']', PRIVATE_CONTROL_SEQUENCE = '?'} |

## Defines

|                | Name           |
| -------------- | -------------- |
|  | **[terminalParser_bufferSize](Files/terminal_parser_8h.md#define-terminalparser-buffersize)**  |
|  | **[inverteixColorsTerminal](Files/terminal_parser_8h.md#define-inverteixcolorsterminal)**  |
|  | **[colorsTerminalReset](Files/terminal_parser_8h.md#define-colorsterminalreset)**  |

## Detailed Description

object and resources definitions for terminal parser library, Inheritable byte-by-byte string parser state machine. 

**Author**: Gerard Forcada Bigas

**Date**: 20/12/22 

This library makes intensive use of object-oriented programming. Meant to be inherited to make use of it's features.

## Types Documentation

### enum CONTROL_CARACTERS

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| BEEP | 0x07|   |
| BACKSPACE | 0x08|   |
| HT | 0x09|   |
| LF | 0x0A|   |
| CR | 0x0D|   |
| SO | 0x0E|   |
| SI | 0x0F|   |
| CAN | 0x18|   |
| ESC | 0x1B|   |
| DEL | 0x7F|   |
| CSI | 0x9B|   |




1 keystroke keys 


### enum ESCAPE_SEQUENCES

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| RIS | 'c'|   |
| IND | 'D'|   |
| NEL | 'E'|   |
| HTS | 'H'|   |
| RI | 'M'|   |
| DECID | 'Z'|   |
| DECSC | '7'|   |
| DECRC | '8'|   |
| ES_CSI | '['|   |
| DECPNM | '>'|   |
| DECPAM | '='|   |
| OSC | ']'|   |
| selecting_character_set | '%'|   |
| DECALN | '#'|   |
| STARTG0 | '('|   |
| STARTG1 | ')'|   |




which kind of escape are we going to? 


### enum CSI_SEQUENCES

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| ICH | '@'|   |
| CUU | 'A'|   |
| CUD | 'B'|   |
| CUF | 'C'|   |
| CUB | 'D'|   |
| CNL | 'E'|   |
| CPL | 'F'|   |
| CHA | 'G'|   |
| CUP | 'H'|   |
| ED | 'J'|   |
| EL | 'K'|   |
| IL | 'L'|   |
| DL | 'M'|   |
| DCH | 'P'|   |
| ECH | 'X'|   |
| HPR | 'a'|   |
| DA | 'c'|   |
| VPA | 'd'|   |
| VPR | 'e'|   |
| HVP | 'f'|   |
| TBC | 'g'|   |
| SM | 'h'|   |
| RM | 'l'|   |
| SGR | 'm'|   |
| DSR | 'n'|   |
| CPR | 'R'|   |
| DECLL | 'q'|   |
| DECSTBM | 'r'|   |
| Save_cursor_location | 's'|   |
| Restore_cursor_location | 'u'|   |
| HPA | '`'|   |
| LINUX_PRIVATE_CONTROL | ']'|   |
| PRIVATE_CONTROL_SEQUENCE | '?'|   |




finalization escape sequence command 





## Macros Documentation

### define terminalParser_bufferSize

```cpp
#define terminalParser_bufferSize 10
```


size of the internal parse-ahead character buffer 


### define inverteixColorsTerminal

```cpp
#define inverteixColorsTerminal "\e[7m"
```


ANSI escape sequence to enable reverse-video (inverted) colours 


### define colorsTerminalReset

```cpp
#define colorsTerminalReset "\e[m"
```


ANSI escape sequence to reset all text attributes 


## Source code

```cpp


#ifndef __terminalParser__
#define __terminalParser__
#include <Arduino.h>
#define terminalParser_bufferSize 10 
#define inverteixColorsTerminal "\e[7m" 
#define colorsTerminalReset "\e[m" 
enum CONTROL_CARACTERS
{
    BEEP = 0x07,
    BACKSPACE = 0x08,
    HT = 0x09,
    LF = 0x0A,
    CR = 0x0D,
    SO = 0x0E,
    SI = 0x0F,
    CAN = 0x18,
    ESC = 0x1B,
    DEL = 0x7F,
    CSI = 0x9B
};
enum ESCAPE_SEQUENCES
{
    RIS = 'c',
    IND = 'D',
    NEL = 'E',
    HTS = 'H',
    RI = 'M',
    DECID = 'Z',
    DECSC = '7',
    DECRC = '8',
    ES_CSI = '[',
    DECPNM = '>',
    DECPAM = '=',
    OSC = ']', // COMANDA s.o.
    selecting_character_set = '%', //<-- ignora 1 de més
    DECALN = '#', //<-- ignora 1 de més
    STARTG0 = '(', //<-- ignora 1 de més
    STARTG1 = ')', //<-- ignora 1 de més
};
enum CSI_SEQUENCES
{
    ICH = '@', //Insert the indicated # of blank characters.
    
    CUU = 'A', //Move cursor up the indicated # of rows.
    CUD = 'B', //Move cursor down the indicated # of rows.
    CUF = 'C', //Move cursor right the indicated # of columns.
    CUB = 'D', //Move cursor left the indicated # of columns.

    CNL = 'E', //Move cursor down the indicated # of rows, to column 1
    CPL = 'F', //Move cursor up the indicated # of rows, to column                     1.
    CHA = 'G', // Move cursor to indicated column in current row.
    CUP = 'H', //Move cursor to the indicated row, column (origin at 1,1).
    ED = 'J', //  ESC [ 1 J: erase from start to cursor.ESC [ 2 J: erase whole display.ESC [ 3 J: erase whole display including scroll- && [J clears the part of the screen from the cursor to the end of the screen.
    EL = 'K', //ESC [ 1 K: erase from start of line to cursor. ESC [ 2 K: erase whole line.
    IL = 'L',//Insert the indicated # of blank lines, 
    DL = 'M', //Delete  the indicated # of blank lines
    DCH = 'P', // Delete the indicated # of characters on current                     line
    ECH = 'X', // Erase the indicated # of characters on current                     line
    HPR = 'a', //Move cursor right the indicated # of columns, horizontal position relative
    DA = 'c', //Answer ESC [ ? 6 c: "I am a VT102"
    VPA = 'd', //Move cursor to the indicated row, current column.
    VPR = 'e', // Move cursor down the indicated # of rows. vertical position relative
    HVP = 'f', // Move cursor to the indicated row, column.
    TBC = 'g', //Without parameter: clear tab stop at current                     position.ESC [ 3 g: delete all tab stops.
    SM = 'h', //Set Mode (see below).
    /*the Reset Mode sequences are obtained by replacing the final 'h' by 'l'.*/
    RM = 'l', //Reset Mode, 
    SGR = 'm', //Set attributes
    DSR = 'n', // Status report 
    CPR = 'R', // Status report 
    DECLL = 'q', //Set keyboard LEDs.                     ESC [ 0 q: clear all LEDs                     ESC [ 1 q: set Scroll Lock LED                     ESC [ 2 q: set Num Lock LED                     ESC [ 3 q: set Caps Lock LED
    DECSTBM = 'r', //Set scrolling region; parameters are top and bottom                     row.
    Save_cursor_location = 's',
    Restore_cursor_location = 'u',
    HPA = '`', // Move cursor to indicated column in current row.
    LINUX_PRIVATE_CONTROL = ']', //Linux Console Private CSI Sequences
    PRIVATE_CONTROL_SEQUENCE = '?' //Linux Console Private CSI Sequences
};
class terminalParser  {
    private:
        void _printa(char caracter);
        bool _inControlCaracters(char caracter);
        bool _inEscapeSequences(char caracter);
        bool _inCsiSequences(char caracter);
        unsigned int i;
        void _parsejaUnNumero(bool surt = true);
        void _afegeixCaracterNumero(char caracter);// funcions internes
        void _enterCSI();
        void _surt();
        static const unsigned char CSI_SEQUENCE_LIST[];
        static const unsigned char CONTROL_CARACTER_LIST[];
        static const unsigned char ESCAPE_SEQUENCE_LIST[];
        unsigned int indexllistaNumeros;
        unsigned int indexCaractersNumeros;
        unsigned int indexBuffer;
        bool controlSequence;
        bool esc;
        bool privateControlSequence;
        char _buffer[terminalParser_bufferSize];// per poder fer forwarding i anàlisi bugs
        char caractersNumeros[4];
        int llistaNumeros[4];
        int ignore;
    public:
        bool insertStatus; 
        //----------------do console display operations----
        virtual void doClearScreen();
        virtual void doMoveCursor(int line,int column);
        virtual void doCUU(unsigned int amount=1);
        virtual void doCUD(unsigned int amount=1);
        virtual void doCUF(unsigned int amount=1);
        virtual void doCUB(unsigned int amount=1);
        virtual void doEL(int operation = 2);
        virtual void doHideCursor(bool hide = true);
        //----------------string manipulation operations----
        void invertColors(char* entrada,unsigned int allargadaMax);
        void invertColors(String *cadena);
        //--------------public control--------
        virtual void init(Stream *pantalla);
        //virtual void askDisplaySize();/**< cursor position report*/

        Stream *userTty;

        terminalParser();
        bool doGuess(char caracter);
//-----------------------------------crides internes a heretar--------------------------------
        virtual void tab();
        virtual void lf();
        virtual void cr();
        virtual void backSpace();
        virtual void beep();
        
        virtual void del();
        virtual void insert(bool setDisplayInsert=false); 
        virtual void start();
        virtual void end();
        virtual void avPg();
        virtual void rePg();
        //to-do pg up pg dn
        virtual void cHA(unsigned int argc,int *argv); 
        virtual void cUU(unsigned int argc,int *argv);
        virtual void cUD(unsigned int argc,int *argv);
        virtual void cUF(unsigned int argc,int *argv);
        virtual void cUB(unsigned int argc,int *argv);
        virtual void eL(unsigned int argc,int *argv); 
        virtual void sGR(unsigned int argc,int *argv);
        virtual void dSR(unsigned int argc,int *argv);
        virtual void rM(unsigned int argc,int *argv);
        virtual void sM(unsigned int argc,int *argv);
        virtual void dA(unsigned int argc,int *argv);
        virtual void cUP(unsigned int argc,int *argv);
        virtual void eD(unsigned int argc,int *argv);
        virtual void vPA(unsigned int argc,int *argv);
        virtual void dCH(unsigned int argc,int *argv);
        virtual void cPR(unsigned int argc,int *argv);
};

#endif
```


-------------------------------

Updated on 2026-04-27 at 16:36:45 +0200
