# terminalParser.h File Reference {#_terminal_parser_8h}

terminalParser.h

object and resources definitions for terminal parser library,
Inheritable byte-by-byte string parser state machine.

    #include <Arduino.h>

## Classes {.unnumbered}

-   class [terminalParser](#_classterminal_parser)

## Macros {.unnumbered}

-   []{#_terminal_parser_8h_1a1a4e083d4a507b9eb10db3a81a8b4731}#define
    **terminalParser_bufferSize**   10

-   []{#_terminal_parser_8h_1aab3d89da9155d7feca19c408b9b69114}#define
    **inverteixColorsTerminal**   \"\\e\[7m\"

-   []{#_terminal_parser_8h_1aa19473ab24e6cf57100494740d614e6c}#define
    **colorsTerminalReset**   \"\\e\[m\"

## Enumerations {.unnumbered}

-   enum
    [CONTROL_CARACTERS](#_terminal_parser_8h_1a58a5e757f9c902f7fc41cd9965723882)
    { **BEEP** = 0x07 , **BACKSPACE** = 0x08 , **HT** = 0x09 , **LF** =
    0x0A , **CR** = 0x0D , **SO** = 0x0E , **SI** = 0x0F , **CAN** =
    0x18 , **ESC** = 0x1B , **DEL** = 0x7F , **CSI** = 0x9B }

-   enum
    [ESCAPE_SEQUENCES](#_terminal_parser_8h_1aff396320953c99edabf026551521a982)
    { **RIS** = \'c\' , **IND** = \'D\' , **NEL** = \'E\' , **HTS** =
    \'H\' , **RI** = \'M\' , **DECID** = \'Z\' , **DECSC** = \'7\' ,
    **DECRC** = \'8\' , **ES_CSI** = \'\[\' , **DECPNM** = \'\>\' ,
    **DECPAM** = \'=\' , **OSC** = \'\]\' , **selecting_character_set**
    = \'\' , **DECALN** = \'#\' , **STARTG0** = \'(\' , **STARTG1** =
    \')\' }

-   enum
    [CSI_SEQUENCES](#_terminal_parser_8h_1ae48ba699dd4e79c566507a6843ae881b)
    { **ICH** = \'@\' , **CUU** = \'A\' , **CUD** = \'B\' , **CUF** =
    \'C\' , **CUB** = \'D\' , **CNL** = \'E\' , **CPL** = \'F\' ,
    **CHA** = \'G\' , **CUP** = \'H\' , **ED** = \'J\' , **EL** = \'K\'
    , **IL** = \'L\' , **DL** = \'M\' , **DCH** = \'P\' , **ECH** =
    \'X\' , **HPR** = \'a\' , **DA** = \'c\' , **VPA** = \'d\' , **VPR**
    = \'e\' , **HVP** = \'f\' , **TBC** = \'g\' , **SM** = \'h\' ,
    **RM** = \'l\' , **SGR** = \'m\' , **DSR** = \'n\' , **CPR** = \'R\'
    , **DECLL** = \'q\' , **DECSTBM** = \'r\' , **Save_cursor_location**
    = \'s\' , **Restore_cursor_location** = \'u\' , **HPA** = \'\`\' ,
    **LINUX_PRIVATE_CONTROL** = \'\]\' , **PRIVATE_CONTROL_SEQUENCE** =
    \'?\' }

## Detailed Description

object and resources definitions for terminal parser library,
Inheritable byte-by-byte string parser state machine.

This library makes intensive use of object-oriented programming. Meant
to be inherited to make use of it\'s features.

::: formalpara-title
**Author**
:::

Gerard Forcada Bigas

::: formalpara-title
**Date**
:::

20/12/22

## Enumeration Type Documentation

### CONTROL_CARACTERS

CONTROL_CARACTERS

terminalParser.h

terminalParser.h

CONTROL_CARACTERS

`enum CONTROL_CARACTERS`

1 keystroke keys

### CSI_SEQUENCES

CSI_SEQUENCES

terminalParser.h

terminalParser.h

CSI_SEQUENCES

`enum CSI_SEQUENCES`

finalization escape sequence command

### ESCAPE_SEQUENCES

ESCAPE_SEQUENCES

terminalParser.h

terminalParser.h

ESCAPE_SEQUENCES

`enum ESCAPE_SEQUENCES`

which kind of escape are we going to?
