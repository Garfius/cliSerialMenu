# terminalParser.h {#_terminal_parser_8h_source}

terminalParser.h

Go to the documentation of this file.

    1 
    12 
    13 #ifndef __terminalParser__
    14 #define __terminalParser__
    15 #include <Arduino.h>
    16 #define terminalParser_bufferSize 10
    17 #define inverteixColorsTerminal "\e[7m"
    18 #define colorsTerminalReset "\e[m"
    22 enum CONTROL_CARACTERS
    23 {
    24     BEEP = 0x07,
    25     BACKSPACE = 0x08,
    26     HT = 0x09,
    27     LF = 0x0A,
    28     CR = 0x0D,
    29     SO = 0x0E,
    30     SI = 0x0F,
    31     CAN = 0x18,
    32     ESC = 0x1B,
    33     DEL = 0x7F,
    34     CSI = 0x9B
    35 };
    39 enum ESCAPE_SEQUENCES
    40 {
    41     RIS = 'c',
    42     IND = 'D',
    43     NEL = 'E',
    44     HTS = 'H',
    45     RI = 'M',
    46     DECID = 'Z',
    47     DECSC = '7',
    48     DECRC = '8',
    49     ES_CSI = '[',
    50     DECPNM = '>',
    51     DECPAM = '=',
    52     OSC = ']', // COMANDA s.o.
    53     selecting_character_set = '%', //<-- ignora 1 de més
    54     DECALN = '#', //<-- ignora 1 de més
    55     STARTG0 = '(', //<-- ignora 1 de més
    56     STARTG1 = ')', //<-- ignora 1 de més
    57 };
    61 enum CSI_SEQUENCES
    62 {
    63     ICH = '@', //Insert the indicated # of blank characters.
    64     
    65     CUU = 'A', //Move cursor up the indicated # of rows.
    66     CUD = 'B', //Move cursor down the indicated # of rows.
    67     CUF = 'C', //Move cursor right the indicated # of columns.
    68     CUB = 'D', //Move cursor left the indicated # of columns.
    69 
    70     CNL = 'E', //Move cursor down the indicated # of rows, to column 1
    71     CPL = 'F', //Move cursor up the indicated # of rows, to column                     1.
    72     CHA = 'G', // Move cursor to indicated column in current row.
    73     CUP = 'H', //Move cursor to the indicated row, column (origin at 1,1).
    74     ED = 'J', //  ESC [ 1 J: erase from start to cursor.ESC [ 2 J: erase whole display.ESC [ 3 J: erase whole display including scroll- && [J clears the part of the screen from the cursor to the end of the screen.
    75     EL = 'K', //ESC [ 1 K: erase from start of line to cursor. ESC [ 2 K: erase whole line.
    76     IL = 'L',//Insert the indicated # of blank lines, 
    77     DL = 'M', //Delete  the indicated # of blank lines
    78     DCH = 'P', // Delete the indicated # of characters on current                     line
    79     ECH = 'X', // Erase the indicated # of characters on current                     line
    80     HPR = 'a', //Move cursor right the indicated # of columns, horizontal position relative
    81     DA = 'c', //Answer ESC [ ? 6 c: "I am a VT102"
    82     VPA = 'd', //Move cursor to the indicated row, current column.
    83     VPR = 'e', // Move cursor down the indicated # of rows. vertical position relative
    84     HVP = 'f', // Move cursor to the indicated row, column.
    85     TBC = 'g', //Without parameter: clear tab stop at current                     position.ESC [ 3 g: delete all tab stops.
    86     SM = 'h', //Set Mode (see below).
    87     /*the Reset Mode sequences are obtained by replacing the final 'h' by 'l'.*/
    88     RM = 'l', //Reset Mode, 
    89     SGR = 'm', //Set attributes
    90     DSR = 'n', // Status report 
    91     CPR = 'R', // Status report 
    92     DECLL = 'q', //Set keyboard LEDs.                     ESC [ 0 q: clear all LEDs                     ESC [ 1 q: set Scroll Lock LED                     ESC [ 2 q: set Num Lock LED                     ESC [ 3 q: set Caps Lock LED
    93     DECSTBM = 'r', //Set scrolling region; parameters are top and bottom                     row.
    94     Save_cursor_location = 's',
    95     Restore_cursor_location = 'u',
    96     HPA = '`', // Move cursor to indicated column in current row.
    97     LINUX_PRIVATE_CONTROL = ']', //Linux Console Private CSI Sequences
    98     PRIVATE_CONTROL_SEQUENCE = '?' //Linux Console Private CSI Sequences
    99 };
    103 class terminalParser  {
    104     private:
    105         void _printa(char caracter);
    106         bool _inControlCaracters(char caracter);
    107         bool _inEscapeSequences(char caracter);
    108         bool _inCsiSequences(char caracter);
    109         unsigned int i;
    110         void _parsejaUnNumero(bool surt = true);
    111         void _afegeixCaracterNumero(char caracter);// funcions internes
    112         void _enterCSI();
    113         void _surt();
    114         static const unsigned char CSI_SEQUENCE_LIST[];
    115         static const unsigned char CONTROL_CARACTER_LIST[];
    116         static const unsigned char ESCAPE_SEQUENCE_LIST[];
    117         unsigned int indexllistaNumeros;
    118         unsigned int indexCaractersNumeros;
    119         unsigned int indexBuffer;
    120         bool controlSequence;
    121         bool esc;
    122         bool privateControlSequence;
    123         char _buffer[terminalParser_bufferSize];// per poder fer forwarding i anàlisi bugs
    124         char caractersNumeros[4];
    125         int llistaNumeros[4];
    126         int ignore;
    127     public:
    128         bool insertStatus;
    129         //----------------do console display operations----
    130         virtual void doClearScreen();
    131         virtual void doMoveCursor(int line,int column);
    132         virtual void doCUU(unsigned int amount=1);
    133         virtual void doCUD(unsigned int amount=1);
    134         virtual void doCUF(unsigned int amount=1);
    135         virtual void doCUB(unsigned int amount=1);
    136         virtual void doEL(bool wholeLine = true);
    137         virtual void doHideCursor(bool hide = true);
    138         //----------------string manipulation operations----
    139         void invertColors(char* entrada,unsigned int allargadaMax);
    140         void invertColors(String *cadena);
    141         //--------------public control--------
    142         virtual void init(Stream *pantalla);
    143         //virtual void askDisplaySize();/**< cursor position report*/
    144 
    145         Stream *userTty;
    146 
    147         terminalParser();
    148         bool doGuess(char caracter);
    149 //-----------------------------------crides internes a heretar--------------------------------
    150         virtual void tab();
    151         virtual void lf();
    152         virtual void cr();
    153         virtual void backSpace();
    154         virtual void beep();
    155         
    156         virtual void del();
    157         virtual void insert(bool setDisplayInsert=false);
    158         virtual void start();
    159         virtual void end();
    160         virtual void avPg();
    161         virtual void rePg();
    162         //to-do pg up pg dn
    163         virtual void cHA(unsigned int argc,int *argv); 
    164         virtual void cUU(unsigned int argc,int *argv);
    165         virtual void cUD(unsigned int argc,int *argv);
    166         virtual void cUF(unsigned int argc,int *argv);
    167         virtual void cUB(unsigned int argc,int *argv);
    168         virtual void eL(unsigned int argc,int *argv);
    169         virtual void sGR(unsigned int argc,int *argv);
    170         virtual void dSR(unsigned int argc,int *argv);
    171         virtual void rM(unsigned int argc,int *argv);
    172         virtual void sM(unsigned int argc,int *argv);
    173         virtual void dA(unsigned int argc,int *argv);
    174         virtual void cUP(unsigned int argc,int *argv);
    175         virtual void eD(unsigned int argc,int *argv);
    176         virtual void vPA(unsigned int argc,int *argv);
    177         virtual void dCH(unsigned int argc,int *argv);
    178         virtual void cPR(unsigned int argc,int *argv);
    179 };
    180 
    181 #endif
