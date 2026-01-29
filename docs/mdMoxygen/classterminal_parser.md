<a id="classterminal_parser"></a>
# Class terminalParser

![][C++]
![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/terminalParser.h` (line 103)



Base class which processes a stream, calling Ansi escape codes named function

**Inherited by**:

* [menu](classmenu.md#classmenu)

## Members

* [\_afegeixCaracterNumero](classterminal_parser.md#classterminal_parser_1ac354276b8bd84b2d223dcd9348eb1a7e)
* [\_buffer](classterminal_parser.md#classterminal_parser_1a1a363e940635645fbd4da7393bac394c)
* [\_enterCSI](classterminal_parser.md#classterminal_parser_1a3884693a1a1b77e4d3832e97db14463d)
* [\_inControlCaracters](classterminal_parser.md#classterminal_parser_1a8566d8346528b24af5367d6e4441417b)
* [\_inCsiSequences](classterminal_parser.md#classterminal_parser_1af3a036a72772358a4fdf1588ba26d8ef)
* [\_inEscapeSequences](classterminal_parser.md#classterminal_parser_1ae809b3a8fa2f31bf7a5278d4b6ad63cd)
* [\_parsejaUnNumero](classterminal_parser.md#classterminal_parser_1a56e87c626945f5b0b2fc07e5eaa99ff6)
* [\_printa](classterminal_parser.md#classterminal_parser_1ae21e279b30bc1d7455600c698bb156fe)
* [\_surt](classterminal_parser.md#classterminal_parser_1a3c8000baca5e6e65a05ccf2962fae0a6)
* [avPg](classterminal_parser.md#classterminal_parser_1a9f5eafd4aa4534edd3cd6f5fd44ef0e9)
* [backSpace](classterminal_parser.md#classterminal_parser_1adf7da1243c221ab45dc408f0616283f7)
* [beep](classterminal_parser.md#classterminal_parser_1ae66b2b892812a8baf74c04f1f4c0d29a)
* [caractersNumeros](classterminal_parser.md#classterminal_parser_1a0a5374014e05cb8377e52bb5a2b9a854)
* [cHA](classterminal_parser.md#classterminal_parser_1a3c0ecda7f7800f0e03cdcde971c24061)
* [CONTROL\_CARACTER\_LIST](classterminal_parser.md#classterminal_parser_1afe1160537ca023a4206a70db9a2ce4dc)
* [controlSequence](classterminal_parser.md#classterminal_parser_1aaa25db610f1bddbd5957f7cd084b712c)
* [cPR](classterminal_parser.md#classterminal_parser_1a36149f0ad779ddb577cc7f345f7e3627)
* [cr](classterminal_parser.md#classterminal_parser_1a390917a454d87f81811d7cd3ab57ff45)
* [CSI\_SEQUENCE\_LIST](classterminal_parser.md#classterminal_parser_1aa9e5f397ca6e904f3d4377b88e434fd8)
* [cUB](classterminal_parser.md#classterminal_parser_1a3c8273faf2d0185ee366fd72a4c9d474)
* [cUD](classterminal_parser.md#classterminal_parser_1a6ecb0e3e8d18b6d5dda1ca909e5ad8fd)
* [cUF](classterminal_parser.md#classterminal_parser_1a1fa9d95bf128e7909a1fc3b64d1a1ddf)
* [cUP](classterminal_parser.md#classterminal_parser_1ad789769a2e775aab32d432add0ea46a3)
* [cUU](classterminal_parser.md#classterminal_parser_1ad41e0dc7fd63b7b5f3ebfaa7780eebde)
* [dA](classterminal_parser.md#classterminal_parser_1ad5b372fe68d713d0be661b97b59497f9)
* [dCH](classterminal_parser.md#classterminal_parser_1a91e94bc068388e9ac1631bbbb81a1274)
* [del](classterminal_parser.md#classterminal_parser_1a677c55de31859878fc3aad396da3946b)
* [doClearScreen](classterminal_parser.md#classterminal_parser_1a0a29fe6e7213859c8a02848b71d26756)
* [doCUB](classterminal_parser.md#classterminal_parser_1a1a6beae57840957a5562dde17a20a724)
* [doCUD](classterminal_parser.md#classterminal_parser_1ae93279b1f2936775782c8a57b9536ac6)
* [doCUF](classterminal_parser.md#classterminal_parser_1ad8656daf1752076a5a1dac3f4d494fd4)
* [doCUU](classterminal_parser.md#classterminal_parser_1a8f57fd40d9de232c7268e9b7ee847fcd)
* [doEL](classterminal_parser.md#classterminal_parser_1a36ccc931b80ea01156fb211b948175a9)
* [doGuess](classterminal_parser.md#classterminal_parser_1a23fc5e4c509e9b478917501a681abaa2)
* [doHideCursor](classterminal_parser.md#classterminal_parser_1a75a5ceb44572f74422dfd266315fa817)
* [doMoveCursor](classterminal_parser.md#classterminal_parser_1a923c3123f8919bed1f3cb2fa2476910b)
* [dSR](classterminal_parser.md#classterminal_parser_1a4c338824f4aed97156bad3c61dec3180)
* [eD](classterminal_parser.md#classterminal_parser_1ada1592d74dfd5e72606123fa80f45cec)
* [eL](classterminal_parser.md#classterminal_parser_1af64f0dbe1b22ba5589c204d7c43644aa)
* [end](classterminal_parser.md#classterminal_parser_1a50c61e2fcbcb381851e2a591871c3b62)
* [esc](classterminal_parser.md#classterminal_parser_1a4c124633901375029eeee3518886cb7c)
* [ESCAPE\_SEQUENCE\_LIST](classterminal_parser.md#classterminal_parser_1a4a6be3e2acf184f3cdce9e69d5b58d1d)
* [i](classterminal_parser.md#classterminal_parser_1a19db7cfed6b4fa51b47acd9aaede9e45)
* [ignore](classterminal_parser.md#classterminal_parser_1adb4017c0e62ddacb64ae499dda2578b5)
* [indexBuffer](classterminal_parser.md#classterminal_parser_1a0253ca0a9a5e004b4cf24c41eeeca6a5)
* [indexCaractersNumeros](classterminal_parser.md#classterminal_parser_1a7e1f2d6fa86bc395ed52004fd0e5647a)
* [indexllistaNumeros](classterminal_parser.md#classterminal_parser_1a215a2100e4ef56fd83b18f6a44a965d6)
* [init](classterminal_parser.md#classterminal_parser_1ac46360c23d60fa4ddef2882b2afc184f)
* [insert](classterminal_parser.md#classterminal_parser_1a9c16bae04c258effb22b03de3b614ac8)
* [insertStatus](classterminal_parser.md#classterminal_parser_1aba8671a3a57249e204ccff21dfe1760a)
* [invertColors](classterminal_parser.md#classterminal_parser_1a1aadbea2a1ca57bb17df0f606c4e3d38)
* [invertColors](classterminal_parser.md#classterminal_parser_1ab349d035ca25bcb7ebe908e3c672be9f)
* [lf](classterminal_parser.md#classterminal_parser_1ab097be496a1cb6fd62634b166834f25f)
* [llistaNumeros](classterminal_parser.md#classterminal_parser_1a66aba7b1498438a82e6a92e9c57e92f9)
* [privateControlSequence](classterminal_parser.md#classterminal_parser_1ad5b5204e10582dd9b640eb15afe28f40)
* [rePg](classterminal_parser.md#classterminal_parser_1aa45d521a6cab097e88e8233eca680979)
* [rM](classterminal_parser.md#classterminal_parser_1a8dd7048a799c0ff650f9a5ded8d69875)
* [sGR](classterminal_parser.md#classterminal_parser_1a397862cda3885c4d4799f2bec30571f7)
* [sM](classterminal_parser.md#classterminal_parser_1a5a06355cba46c2659407e877605a302a)
* [start](classterminal_parser.md#classterminal_parser_1acd91770bf9c95bd86f9d13e3336b1e00)
* [tab](classterminal_parser.md#classterminal_parser_1a06965ffbf30e9cb90388cf5be46a3f18)
* [terminalParser](classterminal_parser.md#classterminal_parser_1a17d579d4c35d3d4894d712cc0ca2b609)
* [userTty](classterminal_parser.md#classterminal_parser_1a2a6130e1a9850a90aebcd6a72c297f6a)
* [vPA](classterminal_parser.md#classterminal_parser_1a296d184e9c57722f2ed0e4c1ec2f51ee)

## Private attributes

<a id="classterminal_parser_1a19db7cfed6b4fa51b47acd9aaede9e45"></a>
### Variable i

![][private]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/terminalParser.h` (line 109)


```cpp
unsigned int terminalParser::i
```








**Type**: unsigned int

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::i"}]}`
-->

<a id="classterminal_parser_1a215a2100e4ef56fd83b18f6a44a965d6"></a>
### Variable indexllistaNumeros

![][private]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/terminalParser.h` (line 117)


```cpp
unsigned int terminalParser::indexllistaNumeros
```




used for argc



**Type**: unsigned int

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::indexllistaNumeros"}]}`
-->

<a id="classterminal_parser_1a7e1f2d6fa86bc395ed52004fd0e5647a"></a>
### Variable indexCaractersNumeros

![][private]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/terminalParser.h` (line 118)


```cpp
unsigned int terminalParser::indexCaractersNumeros
```




char array index for parsing numbers



**Type**: unsigned int

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::indexCaractersNumeros"}]}`
-->

<a id="classterminal_parser_1a0253ca0a9a5e004b4cf24c41eeeca6a5"></a>
### Variable indexBuffer

![][private]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/terminalParser.h` (line 119)


```cpp
unsigned int terminalParser::indexBuffer
```




buffer char array index



**Type**: unsigned int

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::indexBuffer"}]}`
-->

<a id="classterminal_parser_1aaa25db610f1bddbd5957f7cd084b712c"></a>
### Variable controlSequence

![][private]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/terminalParser.h` (line 120)


```cpp
bool terminalParser::controlSequence
```




internal state



**Type**: bool

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::controlSequence"}]}`
-->

<a id="classterminal_parser_1a4c124633901375029eeee3518886cb7c"></a>
### Variable esc

![][private]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/terminalParser.h` (line 121)


```cpp
bool terminalParser::esc
```




internal state, esc pressed



**Type**: bool

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::esc"}]}`
-->

<a id="classterminal_parser_1ad5b5204e10582dd9b640eb15afe28f40"></a>
### Variable privateControlSequence

![][private]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/terminalParser.h` (line 122)


```cpp
bool terminalParser::privateControlSequence
```




internal state



**Type**: bool

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::privateControlSequence"}]}`
-->

<a id="classterminal_parser_1a1a363e940635645fbd4da7393bac394c"></a>
### Variable \_buffer

![][private]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/terminalParser.h` (line 123)


```cpp
char terminalParser::_buffer[terminalParser_bufferSize][terminalParser_bufferSize]
```








**Type**: char

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::_buffer"}]}`
-->

<a id="classterminal_parser_1a0a5374014e05cb8377e52bb5a2b9a854"></a>
### Variable caractersNumeros

![][private]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/terminalParser.h` (line 124)


```cpp
char terminalParser::caractersNumeros[4][4]
```




buffer to parse number sequences



**Type**: char

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::caractersNumeros"}]}`
-->

<a id="classterminal_parser_1a66aba7b1498438a82e6a92e9c57e92f9"></a>
### Variable llistaNumeros

![][private]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/terminalParser.h` (line 125)


```cpp
int terminalParser::llistaNumeros[4][4]
```




used for argv



**Type**: int

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::llistaNumeros"}]}`
-->

<a id="classterminal_parser_1adb4017c0e62ddacb64ae499dda2578b5"></a>
### Variable ignore

![][private]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/terminalParser.h` (line 126)


```cpp
int terminalParser::ignore
```




amount of characters to ignore



**Type**: int

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::ignore"}]}`
-->

## Private static attributes

<a id="classterminal_parser_1aa9e5f397ca6e904f3d4377b88e434fd8"></a>
### Variable CSI\_SEQUENCE\_LIST

![][private]
![][static]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/terminalParser.h` (line 114)


```cpp
const unsigned char terminalParser::CSI_SEQUENCE_LIST[]
```




internal list for iteration



**Type**: const unsigned char

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::CSI_SEQUENCE_LIST"}]}`
-->

<a id="classterminal_parser_1afe1160537ca023a4206a70db9a2ce4dc"></a>
### Variable CONTROL\_CARACTER\_LIST

![][private]
![][static]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/terminalParser.h` (line 115)


```cpp
const unsigned char terminalParser::CONTROL_CARACTER_LIST[] {
    BEEP,       
    BACKSPACE,
    HT,     
    LF,     
    CR,     
    SO,     
    SI,     
    CAN,    
    ESC,    
    DEL,    
    CSI,    
}
```




internal list for iteration



**Type**: const unsigned char

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::CONTROL_CARACTER_LIST"}]}`
-->

<a id="classterminal_parser_1a4a6be3e2acf184f3cdce9e69d5b58d1d"></a>
### Variable ESCAPE\_SEQUENCE\_LIST

![][private]
![][static]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/terminalParser.h` (line 116)


```cpp
const unsigned char terminalParser::ESCAPE_SEQUENCE_LIST[] {
    RIS,        
    IND,        
    NEL,        
    HTS,        
    RI,         
    DECID,      
    DECSC,      
    DECRC,      
    ES_CSI,     
    DECPNM,     
    DECPAM,     
    OSC,      
    selecting_character_set,
    DECALN,     
    STARTG0,    
    STARTG1   
}
```




internal list for iteration



**Type**: const unsigned char

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::ESCAPE_SEQUENCE_LIST"}]}`
-->

## Public attributes

<a id="classterminal_parser_1aba8671a3a57249e204ccff21dfe1760a"></a>
### Variable insertStatus

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/terminalParser.h` (line 128)


```cpp
bool terminalParser::insertStatus
```








**Type**: bool

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::insertStatus"}]}`
-->

<a id="classterminal_parser_1a2a6130e1a9850a90aebcd6a72c297f6a"></a>
### Variable userTty

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/terminalParser.h` (line 145)


```cpp
Stream* terminalParser::userTty
```




ha d'anar a [terminalParser](classterminal_parser.md#classterminal_parser) per fer les funcions cap a pantalla, millores.



**Type**: Stream *

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::userTty"}]}`
-->

## Private functions

<a id="classterminal_parser_1ae21e279b30bc1d7455600c698bb156fe"></a>
### Function \_printa

![][private]


```cpp
void terminalParser::_printa(char caracter)
```








**Parameters**:

* char **caracter**

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::_printa"}]}`
-->

<a id="classterminal_parser_1a8566d8346528b24af5367d6e4441417b"></a>
### Function \_inControlCaracters

![][private]


```cpp
bool terminalParser::_inControlCaracters(char caracter)
```








**Parameters**:

* char **caracter**

**Return type**: bool

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::_inControlCaracters"}]}`
-->

<a id="classterminal_parser_1ae809b3a8fa2f31bf7a5278d4b6ad63cd"></a>
### Function \_inEscapeSequences

![][private]


```cpp
bool terminalParser::_inEscapeSequences(char caracter)
```








**Parameters**:

* char **caracter**

**Return type**: bool

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::_inEscapeSequences"}]}`
-->

<a id="classterminal_parser_1af3a036a72772358a4fdf1588ba26d8ef"></a>
### Function \_inCsiSequences

![][private]


```cpp
bool terminalParser::_inCsiSequences(char caracter)
```








**Parameters**:

* char **caracter**

**Return type**: bool

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::_inCsiSequences"}]}`
-->

<a id="classterminal_parser_1a56e87c626945f5b0b2fc07e5eaa99ff6"></a>
### Function \_parsejaUnNumero

![][private]


```cpp
void terminalParser::_parsejaUnNumero(bool surt=true)
```








**Parameters**:

* bool **surt** = true 

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::_parsejaUnNumero"}]}`
-->

<a id="classterminal_parser_1ac354276b8bd84b2d223dcd9348eb1a7e"></a>
### Function \_afegeixCaracterNumero

![][private]


```cpp
void terminalParser::_afegeixCaracterNumero(char caracter)
```








**Parameters**:

* char **caracter**

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::_afegeixCaracterNumero"}]}`
-->

<a id="classterminal_parser_1a3884693a1a1b77e4d3832e97db14463d"></a>
### Function \_enterCSI

![][private]


```cpp
void terminalParser::_enterCSI()
```








**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::_enterCSI"}]}`
-->

<a id="classterminal_parser_1a3c8000baca5e6e65a05ccf2962fae0a6"></a>
### Function \_surt

![][private]


```cpp
void terminalParser::_surt()
```








**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::_surt"}]}`
-->

## Public functions

<a id="classterminal_parser_1a0a29fe6e7213859c8a02848b71d26756"></a>
### Function doClearScreen

![][public]


```cpp
void terminalParser::doClearScreen()
```




clear stream console





Clear screen



**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::doClearScreen"}]}`
-->

<a id="classterminal_parser_1a923c3123f8919bed1f3cb2fa2476910b"></a>
### Function doMoveCursor

![][public]


```cpp
void terminalParser::doMoveCursor(int line, int column)
```




sends the move cursor command to stream console





Cursor position report void terminalParser::askDisplaySize(){//DSR userTty->write("\e[6n"); } Cursor Position, inherited from [terminalParser](classterminal_parser.md#classterminal_parser)



**Parameters**:

* int **line**
* int **column**

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::doMoveCursor"}]}`
-->

<a id="classterminal_parser_1a8f57fd40d9de232c7268e9b7ee847fcd"></a>
### Function doCUU

![][public]


```cpp
void terminalParser::doCUU(unsigned int amount=1)
```




moves the cursor up amount positions



**Parameters**:

* unsigned int **amount** = 1 

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::doCUU"}]}`
-->

<a id="classterminal_parser_1ae93279b1f2936775782c8a57b9536ac6"></a>
### Function doCUD

![][public]


```cpp
void terminalParser::doCUD(unsigned int amount=1)
```




moves the cursor down amount positions



**Parameters**:

* unsigned int **amount** = 1 

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::doCUD"}]}`
-->

<a id="classterminal_parser_1ad8656daf1752076a5a1dac3f4d494fd4"></a>
### Function doCUF

![][public]


```cpp
void terminalParser::doCUF(unsigned int amount=1)
```




moves the cursor forward amount positions



**Parameters**:

* unsigned int **amount** = 1 

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::doCUF"}]}`
-->

<a id="classterminal_parser_1a1a6beae57840957a5562dde17a20a724"></a>
### Function doCUB

![][public]


```cpp
void terminalParser::doCUB(unsigned int amount=1)
```




moves the cursor back amount positions



**Parameters**:

* unsigned int **amount** = 1 

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::doCUB"}]}`
-->

<a id="classterminal_parser_1a36ccc931b80ea01156fb211b948175a9"></a>
### Function doEL

![][public]


```cpp
void terminalParser::doEL(bool wholeLine=true)
```




erase line, true for whole line, false from start to cursor





ESC [ 1 K: erase from start of line to cursor. ESC [ 2 K: erase whole line.



**Parameters**:

* totaLiniabool **wholeLine** = true 

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::doEL"}]}`
-->

<a id="classterminal_parser_1a75a5ceb44572f74422dfd266315fa817"></a>
### Function doHideCursor

![][public]


```cpp
void terminalParser::doHideCursor(bool hide=true)
```




hodes or unhides cursor



**Parameters**:

* bool **hide** = true 

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::doHideCursor"}]}`
-->

<a id="classterminal_parser_1a1aadbea2a1ca57bb17df0f606c4e3d38"></a>
### Function invertColors

![][public]


```cpp
void terminalParser::invertColors(char *entrada, unsigned int allargadaMax)
```




wraps the string in invert color escape codes



**Parameters**:

* char * **entrada**
* unsigned int **allargadaMax**

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::invertColors"}]}`
-->

<a id="classterminal_parser_1ab349d035ca25bcb7ebe908e3c672be9f"></a>
### Function invertColors

![][public]


```cpp
void terminalParser::invertColors(String *cadena)
```




wraps the string in invert color escape codes



**Parameters**:

* String * **cadena**

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::invertColors"}]}`
-->

<a id="classterminal_parser_1ac46360c23d60fa4ddef2882b2afc184f"></a>
### Function init

![][public]


```cpp
void terminalParser::init(Stream *pantalla)
```




needs the serial port where to be found a console VT100/ANSI terminal style Aka. Putty/teraTerm/...



**Parameters**:

* Stream * **pantalla**

**Return type**: void

**Reimplemented by**:

* [init](classmenu.md#classmenu_1aeef76dfa13483e5ad3834befee1a9b1e)

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::init"}]}`
-->

<a id="classterminal_parser_1a17d579d4c35d3d4894d712cc0ca2b609"></a>
### Function terminalParser

![][public]


```cpp
terminalParser::terminalParser()
```








**Return type**: 

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::terminalParser"}]}`
-->

<a id="classterminal_parser_1a23fc5e4c509e9b478917501a681abaa2"></a>
### Function doGuess

![][public]


```cpp
bool terminalParser::doGuess(char caracter)
```




Parses a character, triggers any function which might correspond regarding previous parsed characters, and returns true if belongs to screen



**Parameters**:

* char **caracter**

**Return type**: bool

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::doGuess"}]}`
-->

<a id="classterminal_parser_1a06965ffbf30e9cb90388cf5be46a3f18"></a>
### Function tab

![][public]


```cpp
void terminalParser::tab()
```




tabulador



**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::tab"}]}`
-->

<a id="classterminal_parser_1ab097be496a1cb6fd62634b166834f25f"></a>
### Function lf

![][public]


```cpp
void terminalParser::lf()
```




line forward



**Return type**: void

**Reimplemented by**:

* [lf](classmenu_text_box.md#classmenu_text_box_1ae58b7cfdc7e9373840a833fa2fea0b7a)

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::lf"}]}`
-->

<a id="classterminal_parser_1a390917a454d87f81811d7cd3ab57ff45"></a>
### Function cr

![][public]


```cpp
void terminalParser::cr()
```




catrriage return



**Return type**: void

**Reimplemented by**:

* [cr](classmenu.md#classmenu_1a4968eb3ed8cf9275b4b3d589d5856006)
* [cr](classmenu_text_box.md#classmenu_text_box_1ac5e1d895814060a4db265131de800d80)

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::cr"}]}`
-->

<a id="classterminal_parser_1adf7da1243c221ab45dc408f0616283f7"></a>
### Function backSpace

![][public]


```cpp
void terminalParser::backSpace()
```




backspace pressed



**Return type**: void

**Reimplemented by**:

* [backSpace](classmenu_text_box.md#classmenu_text_box_1ad38a34978da944a50784de6e8b34b6f0)

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::backSpace"}]}`
-->

<a id="classterminal_parser_1ae66b2b892812a8baf74c04f1f4c0d29a"></a>
### Function beep

![][public]


```cpp
void terminalParser::beep()
```




beep received



**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::beep"}]}`
-->

<a id="classterminal_parser_1a677c55de31859878fc3aad396da3946b"></a>
### Function del

![][public]


```cpp
void terminalParser::del()
```




delete pressed



**Return type**: void

**Reimplemented by**:

* [del](classmenu_text_box.md#classmenu_text_box_1aea56c53974dd22f3cb80701b9366ab79)

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::del"}]}`
-->

<a id="classterminal_parser_1a9c16bae04c258effb22b03de3b614ac8"></a>
### Function insert

![][public]


```cpp
void terminalParser::insert(bool setDisplayInsert=false)
```








**Parameters**:

* bool **setDisplayInsert** = false 

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::insert"}]}`
-->

<a id="classterminal_parser_1acd91770bf9c95bd86f9d13e3336b1e00"></a>
### Function start

![][public]


```cpp
void terminalParser::start()
```




delete pressed



**Return type**: void

**Reimplemented by**:

* [start](classmenu_text_box.md#classmenu_text_box_1ac036f7795d2a2b2381e8316b36dacca5)

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::start"}]}`
-->

<a id="classterminal_parser_1a50c61e2fcbcb381851e2a591871c3b62"></a>
### Function end

![][public]


```cpp
void terminalParser::end()
```




delete pressed



**Return type**: void

**Reimplemented by**:

* [end](classmenu_text_box.md#classmenu_text_box_1a2dde934b069219015301436f0471d0bb)

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::end"}]}`
-->

<a id="classterminal_parser_1a9f5eafd4aa4534edd3cd6f5fd44ef0e9"></a>
### Function avPg

![][public]


```cpp
void terminalParser::avPg()
```




delete pressed



**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::avPg"}]}`
-->

<a id="classterminal_parser_1aa45d521a6cab097e88e8233eca680979"></a>
### Function rePg

![][public]


```cpp
void terminalParser::rePg()
```




delete pressed



**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::rePg"}]}`
-->

<a id="classterminal_parser_1a3c0ecda7f7800f0e03cdcde971c24061"></a>
### Function cHA

![][public]


```cpp
void terminalParser::cHA(unsigned int argc, int *argv)
```




CHA escape command 

**See also**: [cUP](classterminal_parser.md#classterminal_parser_1ad789769a2e775aab32d432add0ea46a3)



**Parameters**:

* unsigned int **argc**
* int * **argv**

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::cHA"}]}`
-->

<a id="classterminal_parser_1ad41e0dc7fd63b7b5f3ebfaa7780eebde"></a>
### Function cUU

![][public]


```cpp
void terminalParser::cUU(unsigned int argc, int *argv)
```




key up



**Parameters**:

* unsigned int **argc**
* int * **argv**

**Return type**: void

**Reimplemented by**:

* [cUU](classmenu.md#classmenu_1a3020c14d21289ad8d28c0a0c24ae8468)
* [cUU](classmenu_text_box.md#classmenu_text_box_1a61470e9f599a83a7d7019a52e0f5fe71)

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::cUU"}]}`
-->

<a id="classterminal_parser_1a6ecb0e3e8d18b6d5dda1ca909e5ad8fd"></a>
### Function cUD

![][public]


```cpp
void terminalParser::cUD(unsigned int argc, int *argv)
```




key down



**Parameters**:

* unsigned int **argc**
* int * **argv**

**Return type**: void

**Reimplemented by**:

* [cUD](classmenu.md#classmenu_1a9b1466f2342a2c2a4d578cad8676aa3b)
* [cUD](classmenu_text_box.md#classmenu_text_box_1a3d64129d73fda43c613f88ab94ea3a5a)

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::cUD"}]}`
-->

<a id="classterminal_parser_1a1fa9d95bf128e7909a1fc3b64d1a1ddf"></a>
### Function cUF

![][public]


```cpp
void terminalParser::cUF(unsigned int argc, int *argv)
```




key forward... right



**Parameters**:

* unsigned int **argc**
* int * **argv**

**Return type**: void

**Reimplemented by**:

* [cUF](classmenu.md#classmenu_1acb15d93473978aeca348655173604c8a)
* [cUF](classmenu_text_box.md#classmenu_text_box_1abd85e42762246e34211ec369aa5e4781)

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::cUF"}]}`
-->

<a id="classterminal_parser_1a3c8273faf2d0185ee366fd72a4c9d474"></a>
### Function cUB

![][public]


```cpp
void terminalParser::cUB(unsigned int argc, int *argv)
```




key backward... left



**Parameters**:

* unsigned int **argc**
* int * **argv**

**Return type**: void

**Reimplemented by**:

* [cUB](classmenu.md#classmenu_1a74f46b834c3f42e4de58a3e68cec857c)
* [cUB](classmenu_text_box.md#classmenu_text_box_1a5ce286a4037555d9555962afe48082ad)

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::cUB"}]}`
-->

<a id="classterminal_parser_1af64f0dbe1b22ba5589c204d7c43644aa"></a>
### Function eL

![][public]


```cpp
void terminalParser::eL(unsigned int argc, int *argv)
```








**Parameters**:

* unsigned int **argc**
* int * **argv**

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::eL"}]}`
-->

<a id="classterminal_parser_1a397862cda3885c4d4799f2bec30571f7"></a>
### Function sGR

![][public]


```cpp
void terminalParser::sGR(unsigned int argc, int *argv)
```




select graphic rendition



**Parameters**:

* unsigned int **argc**
* int * **argv**

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::sGR"}]}`
-->

<a id="classterminal_parser_1a4c338824f4aed97156bad3c61dec3180"></a>
### Function dSR

![][public]


```cpp
void terminalParser::dSR(unsigned int argc, int *argv)
```




select graphic rendition



**Parameters**:

* unsigned int **argc**
* int * **argv**

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::dSR"}]}`
-->

<a id="classterminal_parser_1a8dd7048a799c0ff650f9a5ded8d69875"></a>
### Function rM

![][public]


```cpp
void terminalParser::rM(unsigned int argc, int *argv)
```




escape command



**Parameters**:

* unsigned int **argc**
* int * **argv**

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::rM"}]}`
-->

<a id="classterminal_parser_1a5a06355cba46c2659407e877605a302a"></a>
### Function sM

![][public]


```cpp
void terminalParser::sM(unsigned int argc, int *argv)
```




escape command



**Parameters**:

* unsigned int **argc**
* int * **argv**

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::sM"}]}`
-->

<a id="classterminal_parser_1ad5b372fe68d713d0be661b97b59497f9"></a>
### Function dA

![][public]


```cpp
void terminalParser::dA(unsigned int argc, int *argv)
```




escape command



**Parameters**:

* unsigned int **argc**
* int * **argv**

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::dA"}]}`
-->

<a id="classterminal_parser_1ad789769a2e775aab32d432add0ea46a3"></a>
### Function cUP

![][public]


```cpp
void terminalParser::cUP(unsigned int argc, int *argv)
```




cursor position



**Parameters**:

* unsigned int **argc**
* int * **argv**

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::cUP"}]}`
-->

<a id="classterminal_parser_1ada1592d74dfd5e72606123fa80f45cec"></a>
### Function eD

![][public]


```cpp
void terminalParser::eD(unsigned int argc, int *argv)
```




escape command



**Parameters**:

* unsigned int **argc**
* int * **argv**

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::eD"}]}`
-->

<a id="classterminal_parser_1a296d184e9c57722f2ed0e4c1ec2f51ee"></a>
### Function vPA

![][public]


```cpp
void terminalParser::vPA(unsigned int argc, int *argv)
```




escape command



**Parameters**:

* unsigned int **argc**
* int * **argv**

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::vPA"}]}`
-->

<a id="classterminal_parser_1a91e94bc068388e9ac1631bbbb81a1274"></a>
### Function dCH

![][public]


```cpp
void terminalParser::dCH(unsigned int argc, int *argv)
```




escape command



**Parameters**:

* unsigned int **argc**
* int * **argv**

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::dCH"}]}`
-->

<a id="classterminal_parser_1a36149f0ad779ddb577cc7f345f7e3627"></a>
### Function cPR

![][public]


```cpp
void terminalParser::cPR(unsigned int argc, int *argv)
```




cursor position report



**Parameters**:

* unsigned int **argc**
* int * **argv**

**Return type**: void

**Reimplemented by**:

* [cPR](classmenu.md#classmenu_1ad3cf38c2f89f949f086be41dcb18f0fb)

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"terminalParser::cPR"}]}`
-->

<!--
**TODO**:

* `includes  {"type":"element","name":"includes","attributes":{"local":"no","refid":"terminal_parser_8h"},"children":[{"type":"text","text":"terminalParser.h"}]}`
-->

[public]: https://img.shields.io/badge/-public-brightgreen (public)
[C++]: https://img.shields.io/badge/language-C%2B%2B-blue (C++)
[private]: https://img.shields.io/badge/-private-red (private)
[static]: https://img.shields.io/badge/-static-lightgrey (static)
[protected]: https://img.shields.io/badge/-protected-yellow (protected)