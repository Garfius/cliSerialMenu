# terminalParser Class Reference {#_classterminal_parser}

terminalParser

`#include <terminalParser.h>`

Inheritance diagram for terminalParser:

![image](classterminal_parser.png){width="50%"}

## Public Member Functions {.unnumbered}

-   virtual void
    [doClearScreen](#_classterminal_parser_1a0a29fe6e7213859c8a02848b71d26756)
    ()

-   virtual void
    [doMoveCursor](#_classterminal_parser_1a923c3123f8919bed1f3cb2fa2476910b)
    (int line, int column)

-   virtual void
    [doCUU](#_classterminal_parser_1a8f57fd40d9de232c7268e9b7ee847fcd)
    (unsigned int amount=1)

-   virtual void
    [doCUD](#_classterminal_parser_1ae93279b1f2936775782c8a57b9536ac6)
    (unsigned int amount=1)

-   virtual void
    [doCUF](#_classterminal_parser_1ad8656daf1752076a5a1dac3f4d494fd4)
    (unsigned int amount=1)

-   virtual void
    [doCUB](#_classterminal_parser_1a1a6beae57840957a5562dde17a20a724)
    (unsigned int amount=1)

-   virtual void
    [doEL](#_classterminal_parser_1a36ccc931b80ea01156fb211b948175a9)
    (bool wholeLine=true)

-   virtual void
    [doHideCursor](#_classterminal_parser_1a75a5ceb44572f74422dfd266315fa817)
    (bool hide=true)

-   void
    [invertColors](#_classterminal_parser_1a1aadbea2a1ca57bb17df0f606c4e3d38)
    (char \*entrada, unsigned int allargadaMax)

-   void
    [invertColors](#_classterminal_parser_1ab349d035ca25bcb7ebe908e3c672be9f)
    (String \*cadena)

-   virtual void
    [init](#_classterminal_parser_1ac46360c23d60fa4ddef2882b2afc184f)
    (Stream \*pantalla)

-   bool
    [doGuess](#_classterminal_parser_1a23fc5e4c509e9b478917501a681abaa2)
    (char caracter)

-   virtual void
    [tab](#_classterminal_parser_1a06965ffbf30e9cb90388cf5be46a3f18) ()

-   virtual void
    [lf](#_classterminal_parser_1ab097be496a1cb6fd62634b166834f25f) ()

-   virtual void
    [cr](#_classterminal_parser_1a390917a454d87f81811d7cd3ab57ff45) ()

-   virtual void
    [backSpace](#_classterminal_parser_1adf7da1243c221ab45dc408f0616283f7)
    ()

-   virtual void
    [beep](#_classterminal_parser_1ae66b2b892812a8baf74c04f1f4c0d29a) ()

-   virtual void
    [del](#_classterminal_parser_1a677c55de31859878fc3aad396da3946b) ()

-   []{#_classterminal_parser_1a9c16bae04c258effb22b03de3b614ac8}virtual
    void **insert** (bool setDisplayInsert=false)

-   virtual void
    [start](#_classterminal_parser_1acd91770bf9c95bd86f9d13e3336b1e00)
    ()

-   virtual void
    [end](#_classterminal_parser_1a50c61e2fcbcb381851e2a591871c3b62) ()

-   virtual void
    [avPg](#_classterminal_parser_1a9f5eafd4aa4534edd3cd6f5fd44ef0e9) ()

-   virtual void
    [rePg](#_classterminal_parser_1aa45d521a6cab097e88e8233eca680979) ()

-   virtual void
    [cHA](#_classterminal_parser_1a3c0ecda7f7800f0e03cdcde971c24061)
    (unsigned int argc, int \*argv)

-   virtual void
    [cUU](#_classterminal_parser_1ad41e0dc7fd63b7b5f3ebfaa7780eebde)
    (unsigned int argc, int \*argv)

-   virtual void
    [cUD](#_classterminal_parser_1a6ecb0e3e8d18b6d5dda1ca909e5ad8fd)
    (unsigned int argc, int \*argv)

-   virtual void
    [cUF](#_classterminal_parser_1a1fa9d95bf128e7909a1fc3b64d1a1ddf)
    (unsigned int argc, int \*argv)

-   virtual void
    [cUB](#_classterminal_parser_1a3c8273faf2d0185ee366fd72a4c9d474)
    (unsigned int argc, int \*argv)

-   []{#_classterminal_parser_1af64f0dbe1b22ba5589c204d7c43644aa}virtual
    void **eL** (unsigned int argc, int \*argv)

-   virtual void
    [sGR](#_classterminal_parser_1a397862cda3885c4d4799f2bec30571f7)
    (unsigned int argc, int \*argv)

-   virtual void
    [dSR](#_classterminal_parser_1a4c338824f4aed97156bad3c61dec3180)
    (unsigned int argc, int \*argv)

-   virtual void
    [rM](#_classterminal_parser_1a8dd7048a799c0ff650f9a5ded8d69875)
    (unsigned int argc, int \*argv)

-   virtual void
    [sM](#_classterminal_parser_1a5a06355cba46c2659407e877605a302a)
    (unsigned int argc, int \*argv)

-   virtual void
    [dA](#_classterminal_parser_1ad5b372fe68d713d0be661b97b59497f9)
    (unsigned int argc, int \*argv)

-   virtual void
    [cUP](#_classterminal_parser_1ad789769a2e775aab32d432add0ea46a3)
    (unsigned int argc, int \*argv)

-   virtual void
    [eD](#_classterminal_parser_1ada1592d74dfd5e72606123fa80f45cec)
    (unsigned int argc, int \*argv)

-   virtual void
    [vPA](#_classterminal_parser_1a296d184e9c57722f2ed0e4c1ec2f51ee)
    (unsigned int argc, int \*argv)

-   virtual void
    [dCH](#_classterminal_parser_1a91e94bc068388e9ac1631bbbb81a1274)
    (unsigned int argc, int \*argv)

-   virtual void
    [cPR](#_classterminal_parser_1a36149f0ad779ddb577cc7f345f7e3627)
    (unsigned int argc, int \*argv)

## Public Attributes {.unnumbered}

-   []{#_classterminal_parser_1aba8671a3a57249e204ccff21dfe1760a}bool
    **insertStatus**

-   Stream \*
    [userTty](#_classterminal_parser_1a2a6130e1a9850a90aebcd6a72c297f6a)

## Detailed Description

Base class which processes a stream, calling Ansi escape codes named
function

## Member Function Documentation

### avPg()

avPg

terminalParser

terminalParser

avPg

`void terminalParser::avPg ( )[virtual]`

delete pressed

### backSpace()

backSpace

terminalParser

terminalParser

backSpace

`void terminalParser::backSpace ( )[virtual]`

backspace pressed

### beep()

beep

terminalParser

terminalParser

beep

`void terminalParser::beep ( )[virtual]`

beep received

### cHA()

cHA

terminalParser

terminalParser

cHA

`void terminalParser::cHA (unsigned int argc, int * argv)[virtual]`

CHA escape command

::: formalpara-title
**See also**
:::

[cUP](#_classterminal_parser_1ad789769a2e775aab32d432add0ea46a3)

### cPR()

cPR

terminalParser

terminalParser

cPR

`void terminalParser::cPR (unsigned int argc, int * argv)[virtual]`

cursor position report

Reimplemented in [menu](#_classmenu_1ad3cf38c2f89f949f086be41dcb18f0fb).

### cr()

cr

terminalParser

terminalParser

cr

`void terminalParser::cr ( )[virtual]`

catrriage return

Reimplemented in [menu](#_classmenu_1a4968eb3ed8cf9275b4b3d589d5856006).

### cUB()

cUB

terminalParser

terminalParser

cUB

`void terminalParser::cUB (unsigned int argc, int * argv)[virtual]`

key backward\... left

Reimplemented in [menu](#_classmenu_1a74f46b834c3f42e4de58a3e68cec857c).

### cUD()

cUD

terminalParser

terminalParser

cUD

`void terminalParser::cUD (unsigned int argc, int * argv)[virtual]`

key down

Reimplemented in [menu](#_classmenu_1a9b1466f2342a2c2a4d578cad8676aa3b).

### cUF()

cUF

terminalParser

terminalParser

cUF

`void terminalParser::cUF (unsigned int argc, int * argv)[virtual]`

key forward\... right

Reimplemented in [menu](#_classmenu_1acb15d93473978aeca348655173604c8a).

### cUP()

cUP

terminalParser

terminalParser

cUP

`void terminalParser::cUP (unsigned int argc, int * argv)[virtual]`

cursor position

### cUU()

cUU

terminalParser

terminalParser

cUU

`void terminalParser::cUU (unsigned int argc, int * argv)[virtual]`

key up

Reimplemented in [menu](#_classmenu_1a3020c14d21289ad8d28c0a0c24ae8468).

### dA()

dA

terminalParser

terminalParser

dA

`void terminalParser::dA (unsigned int argc, int * argv)[virtual]`

escape command

### dCH()

dCH

terminalParser

terminalParser

dCH

`void terminalParser::dCH (unsigned int argc, int * argv)[virtual]`

escape command

### del()

del

terminalParser

terminalParser

del

`void terminalParser::del ( )[virtual]`

delete pressed

### doClearScreen()

doClearScreen

terminalParser

terminalParser

doClearScreen

`void terminalParser::doClearScreen ( )[virtual]`

clear stream console

Clear screen

### doCUB()

doCUB

terminalParser

terminalParser

doCUB

`void terminalParser::doCUB (unsigned int amount = 1 )[virtual]`

moves the cursor back amount positions

### doCUD()

doCUD

terminalParser

terminalParser

doCUD

`void terminalParser::doCUD (unsigned int amount = 1 )[virtual]`

moves the cursor down amount positions

### doCUF()

doCUF

terminalParser

terminalParser

doCUF

`void terminalParser::doCUF (unsigned int amount = 1 )[virtual]`

moves the cursor forward amount positions

### doCUU()

doCUU

terminalParser

terminalParser

doCUU

`void terminalParser::doCUU (unsigned int amount = 1 )[virtual]`

moves the cursor up amount positions

### doEL()

doEL

terminalParser

terminalParser

doEL

`void terminalParser::doEL (bool totaLinia = true )[virtual]`

erase line, true for whole line, false from start to cursor

ESC \[ 1 K: erase from start of line to cursor. ESC \[ 2 K: erase whole
line.

### doGuess()

doGuess

terminalParser

terminalParser

doGuess

`bool terminalParser::doGuess (char caracter)`

Parses a character, triggers any function which might correspond
regarding previous parsed characters, and returns true if belongs to
screen

### doHideCursor()

doHideCursor

terminalParser

terminalParser

doHideCursor

`void terminalParser::doHideCursor (bool hide = true )[virtual]`

hodes or unhides cursor

### doMoveCursor()

doMoveCursor

terminalParser

terminalParser

doMoveCursor

`void terminalParser::doMoveCursor (int line, int column)[virtual]`

sends the move cursor command to stream console

Cursor position report void terminalParser::askDisplaySize(){//DSR
userTty-\>write(\"\\e\[6n\"); } Cursor Position, inherited from
[terminalParser](#_classterminal_parser)

### dSR()

dSR

terminalParser

terminalParser

dSR

`void terminalParser::dSR (unsigned int argc, int * argv)[virtual]`

select graphic rendition

### eD()

eD

terminalParser

terminalParser

eD

`void terminalParser::eD (unsigned int argc, int * argv)[virtual]`

escape command

### end()

end

terminalParser

terminalParser

end

`void terminalParser::end ( )[virtual]`

delete pressed

### init()

init

terminalParser

terminalParser

init

`void terminalParser::init (Stream * pantalla)[virtual]`

needs the serial port where to be found a console VT100/ANSI terminal
style Aka. Putty/teraTerm/\...

Reimplemented in [menu](#_classmenu_1aeef76dfa13483e5ad3834befee1a9b1e).

### invertColors()`[1/2]`

invertColors

terminalParser

terminalParser

invertColors

`void terminalParser::invertColors (char * entrada, unsigned int allargadaMax)`

wraps the string in invert color escape codes

### invertColors()`[2/2]`

invertColors

terminalParser

terminalParser

invertColors

`void terminalParser::invertColors (String * cadena)`

wraps the string in invert color escape codes

### lf()

lf

terminalParser

terminalParser

lf

`void terminalParser::lf ( )[virtual]`

line forward

### rePg()

rePg

terminalParser

terminalParser

rePg

`void terminalParser::rePg ( )[virtual]`

delete pressed

### rM()

rM

terminalParser

terminalParser

rM

`void terminalParser::rM (unsigned int argc, int * argv)[virtual]`

escape command

### sGR()

sGR

terminalParser

terminalParser

sGR

`void terminalParser::sGR (unsigned int argc, int * argv)[virtual]`

select graphic rendition

### sM()

sM

terminalParser

terminalParser

sM

`void terminalParser::sM (unsigned int argc, int * argv)[virtual]`

escape command

### start()

start

terminalParser

terminalParser

start

`void terminalParser::start ( )[virtual]`

delete pressed

### tab()

tab

terminalParser

terminalParser

tab

`void terminalParser::tab ( )[virtual]`

tabulador

### vPA()

vPA

terminalParser

terminalParser

vPA

`void terminalParser::vPA (unsigned int argc, int * argv)[virtual]`

escape command

## Member Data Documentation

### userTty

userTty

terminalParser

terminalParser

userTty

`Stream* terminalParser::userTty`

ha d\'anar a [terminalParser](#_classterminal_parser) per fer les
funcions cap a pantalla, millores.

The documentation for this class was generated from the following files:

terminalParser.h

terminalParser.cpp
