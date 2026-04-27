---
title: CharBuffer
summary: Circular character buffer used as intermediate input buffer for the text box editor. 

---

# CharBuffer



Circular character buffer used as intermediate input buffer for the text box editor.  [More...](#detailed-description)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| void | **[addChar](Classes/class_char_buffer.md#function-addchar)**(char c)<br>Adds a character to the tail of the buffer.  |
| char | **[consumeChar](Classes/class_char_buffer.md#function-consumechar)**()<br>Removes and returns a character from the head of the buffer.  |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| volatile int | **[head](Classes/class_char_buffer.md#variable-head)**  |
| volatile int | **[tail](Classes/class_char_buffer.md#variable-tail)**  |

## Detailed Description

```cpp
class CharBuffer;
```

Circular character buffer used as intermediate input buffer for the text box editor. 

Provides lock-free single-producer/single-consumer FIFO storage up to INPUT_BUFFER_SIZE bytes. 

## Public Functions Documentation

### function addChar

```cpp
inline void addChar(
    char c
)
```

Adds a character to the tail of the buffer. 

**Parameters**: 

  * **c** character to enqueue 


### function consumeChar

```cpp
inline char consumeChar()
```

Removes and returns a character from the head of the buffer. 

**Return**: next character in the buffer 

## Public Attributes Documentation

### variable head

```cpp
volatile int head = 0;
```


read index, points to next character to consume 


### variable tail

```cpp
volatile int tail = 0;
```


write index, points to next free slot 


-------------------------------

Updated on 2026-04-27 at 16:36:45 +0200