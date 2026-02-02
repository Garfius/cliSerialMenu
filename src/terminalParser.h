/**
* @file terminalParser.h
* @brief object and resources definitions for terminal parser library, Inheritable byte-by-byte string parser state machine.
* 
* This library makes intensive use of object-oriented programming.
* Meant to be inherited to make use of it's features.
* 
* @author Gerard Forcada Bigas
*
* @date 20/12/22
*/

#ifndef __terminalParser__
#define __terminalParser__
#include <Arduino.h>
#define terminalParser_bufferSize 10
#define inverteixColorsTerminal "\e[7m"
#define colorsTerminalReset "\e[m"
/**
 * 1 keystroke keys
*/
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
/**
 * which kind of escape are we going to?
*/
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
/**
 * finalization escape sequence command
*/
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
/**
 * Base class which processes a stream, calling Ansi escape codes named function
*/
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
        static const unsigned char CSI_SEQUENCE_LIST[];/**< internal list for iteration*/
        static const unsigned char CONTROL_CARACTER_LIST[];/**< internal list for iteration*/
        static const unsigned char ESCAPE_SEQUENCE_LIST[];/**< internal list for iteration*/
        unsigned int indexllistaNumeros;/**< used for argc */
        unsigned int indexCaractersNumeros;/**< char array index for parsing numbers*/
        unsigned int indexBuffer;/**< buffer char array index*/
        bool controlSequence;/**< internal state */
        bool esc;/**< internal state, esc pressed*/
        bool privateControlSequence;/**< internal state*/
        char _buffer[terminalParser_bufferSize];// per poder fer forwarding i anàlisi bugs
        char caractersNumeros[4];/**< buffer to parse number sequences*/
        int llistaNumeros[4];/**< used for argv */
        int ignore;/**< amount of characters to ignore*/
    public:
        bool insertStatus;
        //----------------do console display operations----
        virtual void doClearScreen();/**< clear stream console  */
        virtual void doMoveCursor(int line,int column);/**< sends the move cursor command to stream console */
        virtual void doCUU(unsigned int amount=1);/**< moves the cursor up amount positions */
        virtual void doCUD(unsigned int amount=1);/**< moves the cursor down amount positions */
        virtual void doCUF(unsigned int amount=1);/**< moves the cursor forward amount positions */
        virtual void doCUB(unsigned int amount=1);/**< moves the cursor back amount positions */
        virtual void doEL(bool wholeLine = true);/**< erase line, true for whole line, false from start to cursor */
        virtual void doHideCursor(bool hide = true);/**< hodes or unhides cursor */
        //----------------string manipulation operations----
        void invertColors(char* entrada,unsigned int allargadaMax);/**< wraps the string in invert color escape codes */
        void invertColors(String *cadena);/**< wraps the string in invert color escape codes */
        //--------------public control--------
        virtual void init(Stream *pantalla);/**< needs the serial port where to be found a console VT100/ANSI terminal style Aka. Putty/teraTerm/...  */
        //virtual void askDisplaySize();/**< cursor position report*/

        Stream *userTty;/**< ha d'anar a terminalParser per fer les funcions cap a pantalla, millores. */

        terminalParser();
        bool doGuess(char caracter);/**< Parses a character, triggers any function which might correspond regarding previous parsed characters, and returns true if belongs to screen*/
//-----------------------------------crides internes a heretar--------------------------------
        virtual void tab();/**< tabulador*/
        virtual void lf();/**< line forward*/
        virtual void cr();/**< catrriage return*/
        virtual void backSpace();/**< backspace pressed*/
        virtual void beep();/**< beep received*/
        
        virtual void del();/**< delete pressed*/
        virtual void insert(bool setDisplayInsert=false);
        virtual void start();/**< delete pressed*/
        virtual void end();/**< delete pressed*/
        virtual void avPg();/**< delete pressed*/
        virtual void rePg();/**< delete pressed*/
        //to-do pg up pg dn
        virtual void cHA(unsigned int argc,int *argv); /**< CHA escape command @see cUP */
        virtual void cUU(unsigned int argc,int *argv);/**< key up*/
        virtual void cUD(unsigned int argc,int *argv);/**< key down*/
        virtual void cUF(unsigned int argc,int *argv);/**< key forward... right*/
        virtual void cUB(unsigned int argc,int *argv);/**< key backward... left*/
        virtual void eL(unsigned int argc,int *argv);
        virtual void sGR(unsigned int argc,int *argv);/**< select graphic rendition*/
        virtual void dSR(unsigned int argc,int *argv);/**< select graphic rendition*/
        virtual void rM(unsigned int argc,int *argv);/**< escape command*/
        virtual void sM(unsigned int argc,int *argv);/**< escape command*/
        virtual void dA(unsigned int argc,int *argv);/**< escape command*/
        virtual void cUP(unsigned int argc,int *argv);/**< cursor position */
        virtual void eD(unsigned int argc,int *argv);/**< escape command*/
        virtual void vPA(unsigned int argc,int *argv);/**< escape command*/
        virtual void dCH(unsigned int argc,int *argv);/**< escape command*/
        virtual void cPR(unsigned int argc,int *argv);/**< cursor position report*/
};

#endif
