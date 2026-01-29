<a id="classmenu"></a>
# Class menu

![][C++]
![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 144)



The menu main container





contains the [screenMenu](classscreen_menu.md#classscreen_menu) display screens, add it via addscreen works on a Stream which shows a console VT100/ANSI terminal style inherits [terminalParser](classterminal_parser.md#classterminal_parser) to parse keystrokes

**Inherits from**:

* [terminalParser](classterminal_parser.md#classterminal_parser)

**Inherited by**:

* [menuTextBox](classmenu_text_box.md#classmenu_text_box)

## Members

* [\_topPadding](classmenu.md#classmenu_1a4b456bb558681793323209dba8edab7a)
* [activeScreenMenu](classmenu.md#classmenu_1a85f384d5548453ee9bca984199d1f65b)
* [addscreen](classmenu.md#classmenu_1a70e706129d30d2cab9f2c1ca145b8911)
* [askTerminalSize](classmenu.md#classmenu_1a6ad9b94a26de95af0654c30fbe288023)
* [avPg](classterminal_parser.md#classterminal_parser_1a9f5eafd4aa4534edd3cd6f5fd44ef0e9)
* [backSpace](classterminal_parser.md#classterminal_parser_1adf7da1243c221ab45dc408f0616283f7)
* [beep](classterminal_parser.md#classterminal_parser_1ae66b2b892812a8baf74c04f1f4c0d29a)
* [cHA](classterminal_parser.md#classterminal_parser_1a3c0ecda7f7800f0e03cdcde971c24061)
* [contentOriginCol](classmenu.md#classmenu_1aa5e62c03f5b6d7fa7a476242fa401640)
* [contentOriginRow](classmenu.md#classmenu_1a4cf8c7333e2a4506b6c26a44afffe5d7)
* [cPR](classmenu.md#classmenu_1ad3cf38c2f89f949f086be41dcb18f0fb)
* [cr](classmenu.md#classmenu_1a4968eb3ed8cf9275b4b3d589d5856006)
* [cUB](classmenu.md#classmenu_1a74f46b834c3f42e4de58a3e68cec857c)
* [cUD](classmenu.md#classmenu_1a9b1466f2342a2c2a4d578cad8676aa3b)
* [cUF](classmenu.md#classmenu_1acb15d93473978aeca348655173604c8a)
* [cUP](classterminal_parser.md#classterminal_parser_1ad789769a2e775aab32d432add0ea46a3)
* [cUU](classmenu.md#classmenu_1a3020c14d21289ad8d28c0a0c24ae8468)
* [dA](classterminal_parser.md#classterminal_parser_1ad5b372fe68d713d0be661b97b59497f9)
* [dCH](classterminal_parser.md#classterminal_parser_1a91e94bc068388e9ac1631bbbb81a1274)
* [del](classterminal_parser.md#classterminal_parser_1a677c55de31859878fc3aad396da3946b)
* [doBack](classmenu.md#classmenu_1aefe2d8a405d258c73361b32ccaf79960)
* [doClearScreen](classterminal_parser.md#classterminal_parser_1a0a29fe6e7213859c8a02848b71d26756)
* [doCUB](classterminal_parser.md#classterminal_parser_1a1a6beae57840957a5562dde17a20a724)
* [doCUD](classterminal_parser.md#classterminal_parser_1ae93279b1f2936775782c8a57b9536ac6)
* [doCUF](classterminal_parser.md#classterminal_parser_1ad8656daf1752076a5a1dac3f4d494fd4)
* [doCUU](classterminal_parser.md#classterminal_parser_1a8f57fd40d9de232c7268e9b7ee847fcd)
* [doEL](classterminal_parser.md#classterminal_parser_1a36ccc931b80ea01156fb211b948175a9)
* [doGuess](classterminal_parser.md#classterminal_parser_1a23fc5e4c509e9b478917501a681abaa2)
* [doHideCursor](classterminal_parser.md#classterminal_parser_1a75a5ceb44572f74422dfd266315fa817)
* [doMoveCursor](classterminal_parser.md#classterminal_parser_1a923c3123f8919bed1f3cb2fa2476910b)
* [dotLeadersChar](classmenu.md#classmenu_1a19c53fb1e94b2b85e75724a7e33404f5)
* [dotLeadersDefaultWidth](classmenu.md#classmenu_1a333a504efaae9fd0c04fe7bddec7a55e)
* [dotLeadersMargin](classmenu.md#classmenu_1a20eaa96f046f592523bd6d1c4decca0f)
* [dotLeadersMinDots](classmenu.md#classmenu_1a4127ac960098bcc839ba3fa0c5f62c68)
* [dSR](classterminal_parser.md#classterminal_parser_1a4c338824f4aed97156bad3c61dec3180)
* [eD](classterminal_parser.md#classterminal_parser_1ada1592d74dfd5e72606123fa80f45cec)
* [eL](classterminal_parser.md#classterminal_parser_1af64f0dbe1b22ba5589c204d7c43644aa)
* [end](classterminal_parser.md#classterminal_parser_1a50c61e2fcbcb381851e2a591871c3b62)
* [frameChars](classmenu.md#classmenu_1ac8343844f9b15ecc6e042e861c3df2f3)
* [horizontallyCenter](classmenu.md#classmenu_1a58b8fde6110d6977c20942473d95ab58)
* [init](classmenu.md#classmenu_1aeef76dfa13483e5ad3834befee1a9b1e)
* [insert](classterminal_parser.md#classterminal_parser_1a9c16bae04c258effb22b03de3b614ac8)
* [insertStatus](classterminal_parser.md#classterminal_parser_1aba8671a3a57249e204ccff21dfe1760a)
* [invertColors](classterminal_parser.md#classterminal_parser_1a1aadbea2a1ca57bb17df0f606c4e3d38)
* [invertColors](classterminal_parser.md#classterminal_parser_1ab349d035ca25bcb7ebe908e3c672be9f)
* [lastInputChar](classmenu.md#classmenu_1ad8f94037dda569600452a261962ea75a)
* [lf](classterminal_parser.md#classterminal_parser_1ab097be496a1cb6fd62634b166834f25f)
* [menu](classmenu.md#classmenu_1ad345b60b72c4992525cf064d5642c1d9)
* [msgPause](classmenu.md#classmenu_1aef231381a7322e8822ef9e7ebdbc26a0)
* [msgPause](classmenu.md#classmenu_1aa1d6e3892e78989e60b7d62bb600a4c0)
* [msgSmallWait](classmenu.md#classmenu_1a6d1b2c9042ea98d42859208ad20312ed)
* [msgTxtInput](classmenu.md#classmenu_1a37db65afc7cb697e85eb3e78e2c94367)
* [msgYes](classmenu.md#classmenu_1a9b0ba44cd5add79dd4a521886fe61e03)
* [nextEscBack](classmenu.md#classmenu_1aa75acd07479fe52843238bb4bbdb740d)
* [nextRefresh](classmenu.md#classmenu_1ad5c3afc956e40fceec51f84076d587a5)
* [pantalles](classmenu.md#classmenu_1ad44abe1e9b8eb92c8650fa2555ed1719)
* [printDotLeaders](classmenu.md#classmenu_1acfa0d7be200244f099dbb8cf1f9940f7)
* [printLnCentered](classmenu.md#classmenu_1a4f3c92a51aca228a0145469d74a5a1da)
* [printLnCentered](classmenu.md#classmenu_1a94f47a220a62b987ea9ca68202322ef3)
* [printLnCentered](classmenu.md#classmenu_1a283e7bad957b728731758c594a07326b)
* [printLnCentered](classmenu.md#classmenu_1a5959c1103c849295b1b131f5bf2817a7)
* [printLnCentered](classmenu.md#classmenu_1a875629d3776de73a41b399d4feb47b6c)
* [printLnCentered](classmenu.md#classmenu_1aebc03ecfda04939f6af1b76a7de1bb31)
* [printLnCentered](classmenu.md#classmenu_1a926a33006741fda46c5716afe53e048f)
* [printLnCentered](classmenu.md#classmenu_1a1e7e19229ca0d1dc98b2e29cc2c0356b)
* [printLnCentered](classmenu.md#classmenu_1a50447c7d47ba865ab3b845172961b79f)
* [printLnCentered](classmenu.md#classmenu_1ab0cab18ba3b204f84b53557468f26baf)
* [printLnCentered](classmenu.md#classmenu_1a5dc45a26db63ef26133450ec4d0bf97a)
* [printLnCentered](classmenu.md#classmenu_1aabc96a25f89d1181bf6709d6121e5063)
* [queryTerminalSize](classmenu.md#classmenu_1aaf9f58cf5d2dfb5058f7d1ae8b44166b)
* [refresh](classmenu.md#classmenu_1a4e9b098475d7d5b723eca934105540f0)
* [rePg](classterminal_parser.md#classterminal_parser_1aa45d521a6cab097e88e8233eca680979)
* [rM](classterminal_parser.md#classterminal_parser_1a8dd7048a799c0ff650f9a5ded8d69875)
* [run](classmenu.md#classmenu_1a5c752d626f8bd8e3ff69ec04b18fc1b1)
* [runningOption](classmenu.md#classmenu_1a6bfb8b09beaf20e61fa49b5354814ba0)
* [screenMenuOptions](classmenu.md#classmenu_1a5bdd3be3af51b84e1f48bfaf63a47030)
* [selectedMenuOption](classmenu.md#classmenu_1a86a4b29a9344918183d9bca19fced1fb)
* [setPrettyDotLeadersMargin](classmenu.md#classmenu_1a745a30a0f44073a03e8c9d5bf02892c8)
* [setscreen](classmenu.md#classmenu_1a8d2562e25294e0610bdac5aa78846b43)
* [sGR](classterminal_parser.md#classterminal_parser_1a397862cda3885c4d4799f2bec30571f7)
* [show](classmenu.md#classmenu_1a2446ad69c4c477e504057eb973d970c6)
* [show](classmenu.md#classmenu_1aae1769c812999eba1699adcf91481a06)
* [sM](classterminal_parser.md#classterminal_parser_1a5a06355cba46c2659407e877605a302a)
* [start](classterminal_parser.md#classterminal_parser_1acd91770bf9c95bd86f9d13e3336b1e00)
* [tab](classterminal_parser.md#classterminal_parser_1a06965ffbf30e9cb90388cf5be46a3f18)
* [terminalParser](classterminal_parser.md#classterminal_parser_1a17d579d4c35d3d4894d712cc0ca2b609)
* [terminalRowsCols](classmenu.md#classmenu_1ad827b9529b6d6581088d18aafe614840)
* [terminalSizeQueries](classmenu.md#classmenu_1ae98d8f9d0acf83c7a3da3ef122130775)
* [totalScreenMenus](classmenu.md#classmenu_1ae0b012e3923d083b152f26a806dd1954)
* [userTty](classterminal_parser.md#classterminal_parser_1a2a6130e1a9850a90aebcd6a72c297f6a)
* [verticallyCenter](classmenu.md#classmenu_1a7445256b6a139888c7a40324222f8a1b)
* [vPA](classterminal_parser.md#classterminal_parser_1a296d184e9c57722f2ed0e4c1ec2f51ee)

## Protected static attributes

<a id="classmenu_1ac8343844f9b15ecc6e042e861c3df2f3"></a>
### Variable frameChars

![][protected]
![][static]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 146)


```cpp
char menu::frameChars[3][3] = {'-','|','+'}
```








**Type**: char

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::frameChars"}]}`
-->

## Protected attributes

<a id="classmenu_1a86a4b29a9344918183d9bca19fced1fb"></a>
### Variable selectedMenuOption

![][protected]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 147)


```cpp
unsigned int menu::selectedMenuOption
```




the actual selected menu index option on display



**Type**: unsigned int

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::selectedMenuOption"}]}`
-->

<a id="classmenu_1ad5c3afc956e40fceec51f84076d587a5"></a>
### Variable nextRefresh

![][protected]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 148)


```cpp
unsigned long menu::nextRefresh = 0
```




screen refresh control



**Type**: unsigned long

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::nextRefresh"}]}`
-->

<a id="classmenu_1a6bfb8b09beaf20e61fa49b5354814ba0"></a>
### Variable runningOption

![][protected]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 149)


```cpp
bool menu::runningOption = false
```




esta excutant una opcio



**Type**: bool

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::runningOption"}]}`
-->

<a id="classmenu_1a4cf8c7333e2a4506b6c26a44afffe5d7"></a>
### Variable contentOriginRow

![][protected]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 150)


```cpp
unsigned int menu::contentOriginRow = 1
```




top row where the menu content starts



**Type**: unsigned int

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::contentOriginRow"}]}`
-->

<a id="classmenu_1aa5e62c03f5b6d7fa7a476242fa401640"></a>
### Variable contentOriginCol

![][protected]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 151)


```cpp
unsigned int menu::contentOriginCol = 1
```




left column where the menu content starts



**Type**: unsigned int

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::contentOriginCol"}]}`
-->

<a id="classmenu_1ad8f94037dda569600452a261962ea75a"></a>
### Variable lastInputChar

![][protected]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 160)


```cpp
char menu::lastInputChar
```




temporal character



**Type**: char

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::lastInputChar"}]}`
-->

<a id="classmenu_1aa75acd07479fe52843238bb4bbdb740d"></a>
### Variable nextEscBack

![][protected]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 161)


```cpp
unsigned long menu::nextEscBack = 0
```




move screen back using esc control



**Type**: unsigned long

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::nextEscBack"}]}`
-->

## Public attributes

<a id="classmenu_1a4b456bb558681793323209dba8edab7a"></a>
### Variable \_topPadding

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 163)


```cpp
uint8_t menu::_topPadding = 1
```








**Type**: uint8_t

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::_topPadding"}]}`
-->

<a id="classmenu_1a6ad9b94a26de95af0654c30fbe288023"></a>
### Variable askTerminalSize

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 164)


```cpp
bool menu::askTerminalSize = true
```




ask terminal size before menu show (client might respond after being shown)



**Type**: bool

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::askTerminalSize"}]}`
-->

<a id="classmenu_1a7445256b6a139888c7a40324222f8a1b"></a>
### Variable verticallyCenter

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 165)


```cpp
bool menu::verticallyCenter = false
```




WARNING: operations clears screen!



**Type**: bool

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::verticallyCenter"}]}`
-->

<a id="classmenu_1a58b8fde6110d6977c20942473d95ab58"></a>
### Variable horizontallyCenter

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 166)


```cpp
bool menu::horizontallyCenter = true
```




user operations are shown centered on screen



**Type**: bool

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::horizontallyCenter"}]}`
-->

<a id="classmenu_1ad827b9529b6d6581088d18aafe614840"></a>
### Variable terminalRowsCols

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 167)


```cpp
unsigned int menu::terminalRowsCols[2][2] = {0, 0}
```








**Type**: unsigned int

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::terminalRowsCols"}]}`
-->

<a id="classmenu_1ae98d8f9d0acf83c7a3da3ef122130775"></a>
### Variable terminalSizeQueries

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 168)


```cpp
uint8_t menu::terminalSizeQueries = 0
```




reported size rows and cols, 0 means not initialized number of times terminal size has been queried



**Type**: uint8_t

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::terminalSizeQueries"}]}`
-->

<a id="classmenu_1a85f384d5548453ee9bca984199d1f65b"></a>
### Variable activeScreenMenu

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 169)


```cpp
int menu::activeScreenMenu = -1
```




the actual displayed menu



**Type**: int

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::activeScreenMenu"}]}`
-->

<a id="classmenu_1ae0b012e3923d083b152f26a806dd1954"></a>
### Variable totalScreenMenus

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 170)


```cpp
int menu::totalScreenMenus = 0
```




total amount of displayable/showAble display menus



**Type**: int

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::totalScreenMenus"}]}`
-->

<a id="classmenu_1a5bdd3be3af51b84e1f48bfaf63a47030"></a>
### Variable screenMenuOptions

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 171)


```cpp
unsigned int menu::screenMenuOptions = displayMenuOptionsDefault
```




menuoptions to be displayed



**Type**: unsigned int

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::screenMenuOptions"}]}`
-->

<a id="classmenu_1ad44abe1e9b8eb92c8650fa2555ed1719"></a>
### Variable pantalles

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 172)


```cpp
screenMenu* menu::pantalles[screenMenuMax][screenMenuMax]
```




pointers to display menus



**Type**: [screenMenu](classscreen_menu.md#classscreen_menu) *

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::pantalles"}]}`
-->

<a id="classmenu_1a20eaa96f046f592523bd6d1c4decca0f"></a>
### Variable dotLeadersMargin

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 200)


```cpp
uint8_t menu::dotLeadersMargin = 2
```








**Type**: uint8_t

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::dotLeadersMargin"}]}`
-->

<a id="classmenu_1a4127ac960098bcc839ba3fa0c5f62c68"></a>
### Variable dotLeadersMinDots

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 201)


```cpp
uint8_t menu::dotLeadersMinDots = 2
```








**Type**: uint8_t

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::dotLeadersMinDots"}]}`
-->

<a id="classmenu_1a19c53fb1e94b2b85e75724a7e33404f5"></a>
### Variable dotLeadersChar

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 202)


```cpp
char menu::dotLeadersChar = '.'
```








**Type**: char

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::dotLeadersChar"}]}`
-->

<a id="classmenu_1a333a504efaae9fd0c04fe7bddec7a55e"></a>
### Variable dotLeadersDefaultWidth

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.h` (line 203)


```cpp
unsigned int menu::dotLeadersDefaultWidth = menuTextArrayLength
```








**Type**: unsigned int

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::dotLeadersDefaultWidth"}]}`
-->

## Protected functions

<a id="classmenu_1a2446ad69c4c477e504057eb973d970c6"></a>
### Function show

![][protected]


```cpp
void menu::show(unsigned int index)
```




redraws selected menuoption text





refreshes the line



**Parameters**:

* unsigned int **index**

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::show"}]}`
-->

<a id="classmenu_1a3020c14d21289ad8d28c0a0c24ae8468"></a>
### Function cUU

![][protected]


```cpp
void menu::cUU(unsigned int argc, int *argv) override
```




inherited from [terminalParser](classterminal_parser.md#classterminal_parser). cursor Up handler





Cursor Up, inherited from [terminalParser](classterminal_parser.md#classterminal_parser) pantalles[activeScreenMenu]->offsetFromTop



**Parameters**:

* unsigned int **argc**
* int * **argv**

**Return type**: void

**Reimplements**: [cUU](classterminal_parser.md#classterminal_parser_1ad41e0dc7fd63b7b5f3ebfaa7780eebde)

**Reimplemented by**:

* [cUU](classmenu_text_box.md#classmenu_text_box_1a61470e9f599a83a7d7019a52e0f5fe71)

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::cUU"}]}`
-->

<a id="classmenu_1a9b1466f2342a2c2a4d578cad8676aa3b"></a>
### Function cUD

![][protected]


```cpp
void menu::cUD(unsigned int argc, int *argv) override
```




inherited from [terminalParser](classterminal_parser.md#classterminal_parser). cursor Down handler





Cursor Down, inherited from [terminalParser](classterminal_parser.md#classterminal_parser) dragons be here



**Parameters**:

* unsigned int **argc**
* int * **argv**

**Return type**: void

**Reimplements**: [cUD](classterminal_parser.md#classterminal_parser_1a6ecb0e3e8d18b6d5dda1ca909e5ad8fd)

**Reimplemented by**:

* [cUD](classmenu_text_box.md#classmenu_text_box_1a3d64129d73fda43c613f88ab94ea3a5a)

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::cUD"}]}`
-->

<a id="classmenu_1acb15d93473978aeca348655173604c8a"></a>
### Function cUF

![][protected]


```cpp
void menu::cUF(unsigned int argc, int *argv) override
```




inherited from [terminalParser](classterminal_parser.md#classterminal_parser). cursor forward right handler



**Parameters**:

* unsigned int **argc**
* int * **argv**

**Return type**: void

**Reimplements**: [cUF](classterminal_parser.md#classterminal_parser_1a1fa9d95bf128e7909a1fc3b64d1a1ddf)

**Reimplemented by**:

* [cUF](classmenu_text_box.md#classmenu_text_box_1abd85e42762246e34211ec369aa5e4781)

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::cUF"}]}`
-->

<a id="classmenu_1a74f46b834c3f42e4de58a3e68cec857c"></a>
### Function cUB

![][protected]


```cpp
void menu::cUB(unsigned int argc, int *argv) override
```




inherited from [terminalParser](classterminal_parser.md#classterminal_parser). cursor backward left handler



**Parameters**:

* unsigned int **argc**
* int * **argv**

**Return type**: void

**Reimplements**: [cUB](classterminal_parser.md#classterminal_parser_1a3c8273faf2d0185ee366fd72a4c9d474)

**Reimplemented by**:

* [cUB](classmenu_text_box.md#classmenu_text_box_1a5ce286a4037555d9555962afe48082ad)

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::cUB"}]}`
-->

<a id="classmenu_1ad3cf38c2f89f949f086be41dcb18f0fb"></a>
### Function cPR

![][protected]


```cpp
void menu::cPR(unsigned int argc, int *argv) override
```




inherited from [terminalParser](classterminal_parser.md#classterminal_parser). cursor position report



**Parameters**:

* unsigned int **argc**
* int * **argv**

**Return type**: void

**Reimplements**: [cPR](classterminal_parser.md#classterminal_parser_1a36149f0ad779ddb577cc7f345f7e3627)

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::cPR"}]}`
-->

<a id="classmenu_1a4968eb3ed8cf9275b4b3d589d5856006"></a>
### Function cr

![][protected]


```cpp
void menu::cr() override
```




inherited from [terminalParser](classterminal_parser.md#classterminal_parser). enter



**Return type**: void

**Reimplements**: [cr](classterminal_parser.md#classterminal_parser_1a390917a454d87f81811d7cd3ab57ff45)

**Reimplemented by**:

* [cr](classmenu_text_box.md#classmenu_text_box_1ac5e1d895814060a4db265131de800d80)

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::cr"}]}`
-->

<a id="classmenu_1aaf9f58cf5d2dfb5058f7d1ae8b44166b"></a>
### Function queryTerminalSize

![][protected]


```cpp
void menu::queryTerminalSize(bool wait4Response=true)
```








**Parameters**:

* bool **wait4Response** = true 

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::queryTerminalSize"}]}`
-->

## Public functions

<a id="classmenu_1ad345b60b72c4992525cf064d5642c1d9"></a>
### Function menu

![][public]


```cpp
menu::menu()
```




constructor has no code



**Return type**: 

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::menu"}]}`
-->

<a id="classmenu_1aeef76dfa13483e5ad3834befee1a9b1e"></a>
### Function init

![][public]


```cpp
void menu::init(Stream *userSerialTerminal) override
```




kickstart stuff and shows menu, do it at the end os setup(), after addscreen



**Parameters**:

* Stream * **userSerialTerminal**

**Return type**: void

**Reimplements**: [init](classterminal_parser.md#classterminal_parser_1ac46360c23d60fa4ddef2882b2afc184f)

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::init"}]}`
-->

<a id="classmenu_1a70e706129d30d2cab9f2c1ca145b8911"></a>
### Function addscreen

![][public]


```cpp
void menu::addscreen(screenMenu *pantalla)
```




adds a screen, change it using [changeScreenMenuOption](classchange_screen_menu_option.md#classchange_screen_menu_option) or setscreen do it after screenMenu.addMenuOption





Add available menu screen to the array






**Parameters**:

* **pantalla**: pointer to menu screen



**Parameters**:

* [screenMenu](classscreen_menu.md#classscreen_menu) * **pantalla**

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::addscreen"}]}`
-->

<a id="classmenu_1a5c752d626f8bd8e3ff69ec04b18fc1b1"></a>
### Function run

![][public]


```cpp
void menu::run()
```


Parses the userTty, check user interaction or display query.

to be called at loop()... AOAP As Often As Possible, not to abuse reception buffer



**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::run"}]}`
-->

<a id="classmenu_1a37db65afc7cb697e85eb3e78e2c94367"></a>
### Function msgTxtInput

![][public]


```cpp
bool menu::msgTxtInput(const char *prompt, char *result, unsigned int maxLength, unsigned int minLength=0)
```




single line text edit, allows (a-Z) && (A-Z) && (0-9)





simple single line text prompt, allows (a-Z) && (A-Z) && (0-9) 
**Parameters**:

* **result**: might not be empty, resulting text will be there
* **prompt**: the top text prompt
* **maxLength**: 0 for default=(textLineWidth-1)
* **minLength**: 0 for default=1



**Parameters**:

* const char * **prompt**
* char * **result**
* unsigned int **maxLength**
* unsigned int **minLength** = 0 

**Return type**: bool

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::msgTxtInput"}]}`
-->

<a id="classmenu_1a6d1b2c9042ea98d42859208ad20312ed"></a>
### Function msgSmallWait

![][public]


```cpp
void menu::msgSmallWait(const char *prompt)
```




shows ¿alert? temporary color-inverted text for cliMsgWait milliseconds



**Parameters**:

* const char * **prompt**

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::msgSmallWait"}]}`
-->

<a id="classmenu_1aef231381a7322e8822ef9e7ebdbc26a0"></a>
### Function msgPause

![][public]


```cpp
void menu::msgPause(const char *prompt)
```




shows a text and waits any keypress to continue





prints inverted the prompt color and the pressAnyKeyToContinue text when key is pressed, re-writes the text normal colors, and erases the pressAnyKeyToContinue text leaves cursor at column 1



**Parameters**:

* const char * **prompt**

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::msgPause"}]}`
-->

<a id="classmenu_1a9b0ba44cd5add79dd4a521886fe61e03"></a>
### Function msgYes

![][public]


```cpp
bool menu::msgYes(const char *prompt)
```




asks yes/no to given text, return true if (y || Y) is press



**Parameters**:

* const char * **prompt**

**Return type**: bool

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::msgYes"}]}`
-->

<a id="classmenu_1aa1d6e3892e78989e60b7d62bb600a4c0"></a>
### Function msgPause

![][public]


```cpp
void menu::msgPause()
```




shows default text and waits any keypress to continue



**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::msgPause"}]}`
-->

<a id="classmenu_1a745a30a0f44073a03e8c9d5bf02892c8"></a>
### Function setPrettyDotLeadersMargin

![][public]


```cpp
void menu::setPrettyDotLeadersMargin(int bothTextsLength)
```




Sets dotLeadersMargin based on terminal width for aesthetics



**Parameters**:

* int **bothTextsLength**

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::setPrettyDotLeadersMargin"}]}`
-->

<a id="classmenu_1a4f3c92a51aca228a0145469d74a5a1da"></a>
### Function printLnCentered

![][public]


```cpp
void menu::printLnCentered(const char *text)
```








**Parameters**:

* const char * **text**

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::printLnCentered"}]}`
-->

<a id="classmenu_1a94f47a220a62b987ea9ca68202322ef3"></a>
### Function printLnCentered

![][public]


```cpp
void menu::printLnCentered(const String &text)
```








**Parameters**:

* const String & **text**

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::printLnCentered"}]}`
-->

<a id="classmenu_1a283e7bad957b728731758c594a07326b"></a>
### Function printLnCentered

![][public]


```cpp
void menu::printLnCentered()
```








**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::printLnCentered"}]}`
-->

<a id="classmenu_1a5959c1103c849295b1b131f5bf2817a7"></a>
### Function printLnCentered

![][public]


```cpp
void menu::printLnCentered(char c)
```








**Parameters**:

* char **c**

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::printLnCentered"}]}`
-->

<a id="classmenu_1a875629d3776de73a41b399d4feb47b6c"></a>
### Function printLnCentered

![][public]


```cpp
void menu::printLnCentered(unsigned char b, int base=DEC)
```








**Parameters**:

* unsigned char **b**
* int **base** = DEC 

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::printLnCentered"}]}`
-->

<a id="classmenu_1aebc03ecfda04939f6af1b76a7de1bb31"></a>
### Function printLnCentered

![][public]


```cpp
void menu::printLnCentered(int num, int base=DEC)
```








**Parameters**:

* int **num**
* int **base** = DEC 

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::printLnCentered"}]}`
-->

<a id="classmenu_1a926a33006741fda46c5716afe53e048f"></a>
### Function printLnCentered

![][public]


```cpp
void menu::printLnCentered(unsigned int num, int base=DEC)
```








**Parameters**:

* unsigned int **num**
* int **base** = DEC 

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::printLnCentered"}]}`
-->

<a id="classmenu_1a1e7e19229ca0d1dc98b2e29cc2c0356b"></a>
### Function printLnCentered

![][public]


```cpp
void menu::printLnCentered(long num, int base=DEC)
```








**Parameters**:

* long **num**
* int **base** = DEC 

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::printLnCentered"}]}`
-->

<a id="classmenu_1a50447c7d47ba865ab3b845172961b79f"></a>
### Function printLnCentered

![][public]


```cpp
void menu::printLnCentered(unsigned long num, int base=DEC)
```








**Parameters**:

* unsigned long **num**
* int **base** = DEC 

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::printLnCentered"}]}`
-->

<a id="classmenu_1ab0cab18ba3b204f84b53557468f26baf"></a>
### Function printLnCentered

![][public]


```cpp
void menu::printLnCentered(long long num, int base=DEC)
```








**Parameters**:

* long long **num**
* int **base** = DEC 

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::printLnCentered"}]}`
-->

<a id="classmenu_1a5dc45a26db63ef26133450ec4d0bf97a"></a>
### Function printLnCentered

![][public]


```cpp
void menu::printLnCentered(unsigned long long num, int base=DEC)
```








**Parameters**:

* unsigned long long **num**
* int **base** = DEC 

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::printLnCentered"}]}`
-->

<a id="classmenu_1aabc96a25f89d1181bf6709d6121e5063"></a>
### Function printLnCentered

![][public]


```cpp
void menu::printLnCentered(double num, int digits=2)
```








**Parameters**:

* double **num**
* int **digits** = 2 

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::printLnCentered"}]}`
-->

<a id="classmenu_1acfa0d7be200244f099dbb8cf1f9940f7"></a>
### Function printDotLeaders

![][public]


```cpp
unsigned int menu::printDotLeaders(const char *left, const char *right, int margin=-1, int minDots=-1)
```








**Parameters**:

* const char * **left**
* const char * **right**
* int **margin** = -1 
* int **minDots** = -1 

**Return type**: unsigned int

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::printDotLeaders"}]}`
-->

<a id="classmenu_1a8d2562e25294e0610bdac5aa78846b43"></a>
### Function setscreen

![][public]


```cpp
void menu::setscreen(int targetScreenMenu, bool setWhereICame=true)
```




change the showing screen





Gracefully switch menu screen if coming from a run, no need to call [show()](classmenu.md#classmenu_1aae1769c812999eba1699adcf91481a06); 
**Parameters**:

* **pantallaDesti**: where to go



**Parameters**:

* pantallaDestiint **targetScreenMenu**
* bool **setWhereICame** = true 

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::setscreen"}]}`
-->

<a id="classmenu_1a4e9b098475d7d5b723eca934105540f0"></a>
### Function refresh

![][public]


```cpp
void menu::refresh()
```




to force screen refresh



**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::refresh"}]}`
-->

<a id="classmenu_1aefe2d8a405d258c73361b32ccaf79960"></a>
### Function doBack

![][public]


```cpp
void menu::doBack()
```




sets the display to the previous one



**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::doBack"}]}`
-->

<a id="classmenu_1aae1769c812999eba1699adcf91481a06"></a>
### Function show

![][public]


```cpp
void menu::show()
```




draws menu on screen





Show menu on screen, using userTty object member






**Parameters**:

* **resetCursor**: move cursor to starting point



**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"menu::show"}]}`
-->

<!--
**TODO**:

* `includes  {"type":"element","name":"includes","attributes":{"local":"no","refid":"menu_8h"},"children":[{"type":"text","text":"menu.h"}]}`
-->

[public]: https://img.shields.io/badge/-public-brightgreen (public)
[C++]: https://img.shields.io/badge/language-C%2B%2B-blue (C++)
[private]: https://img.shields.io/badge/-private-red (private)
[static]: https://img.shields.io/badge/-static-lightgrey (static)
[protected]: https://img.shields.io/badge/-protected-yellow (protected)