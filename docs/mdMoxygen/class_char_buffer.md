<a id="class_char_buffer"></a>
# Class CharBuffer

![][C++]
![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.cpp` (line 893)





## Members

* [addChar](class_char_buffer.md#class_char_buffer_1a085eb3caf663cb601c764b81ce498fb8)
* [consumeChar](class_char_buffer.md#class_char_buffer_1a3b01d158f6173f772d85cccc69d54811)
* [head](class_char_buffer.md#class_char_buffer_1a970e44e04c34c4934031bf7f30561083)
* [myCharBuffer](class_char_buffer.md#class_char_buffer_1aa784d507cae5165632995b58ac5db2ff)
* [tail](class_char_buffer.md#class_char_buffer_1ac6b0d13dcfe605207e3bec22bebb27dc)

## Private static attributes

<a id="class_char_buffer_1aa784d507cae5165632995b58ac5db2ff"></a>
### Variable myCharBuffer

![][private]
![][static]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.cpp` (line 895)


```cpp
volatile char CharBuffer::myCharBuffer[INPUT_BUFFER_SIZE]
```








**Type**: volatile char

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"CharBuffer::myCharBuffer"}]}`
-->

## Public attributes

<a id="class_char_buffer_1a970e44e04c34c4934031bf7f30561083"></a>
### Variable head

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.cpp` (line 898)


```cpp
volatile int CharBuffer::head = 0
```








**Type**: volatile int

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"CharBuffer::head"}]}`
-->

<a id="class_char_buffer_1ac6b0d13dcfe605207e3bec22bebb27dc"></a>
### Variable tail

![][public]

**Definition**: `C:/Users/garf/Documents/PlatformIO/Projects/ArduinoMenuSystem/lib/cliSerialMenu/menu.cpp` (line 899)


```cpp
volatile int CharBuffer::tail = 0
```








**Type**: volatile int

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"CharBuffer::tail"}]}`
-->

## Public functions

<a id="class_char_buffer_1a085eb3caf663cb601c764b81ce498fb8"></a>
### Function addChar

![][public]


```cpp
void CharBuffer::addChar(char c)
```








**Parameters**:

* char **c**

**Return type**: void

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"CharBuffer::addChar"}]}`
-->

<a id="class_char_buffer_1a3b01d158f6173f772d85cccc69d54811"></a>
### Function consumeChar

![][public]


```cpp
char CharBuffer::consumeChar()
```








**Return type**: char

<!--
**TODO**:

* `qualifiedname {"type":"element","name":"qualifiedname","attributes":{},"children":[{"type":"text","text":"CharBuffer::consumeChar"}]}`
-->

[public]: https://img.shields.io/badge/-public-brightgreen (public)
[C++]: https://img.shields.io/badge/language-C%2B%2B-blue (C++)
[private]: https://img.shields.io/badge/-private-red (private)
[static]: https://img.shields.io/badge/-static-lightgrey (static)