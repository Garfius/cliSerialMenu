---
title: textBoxConfig
summary: Configuration structure passed to menuTextBox::msgTxtInputMultiline(). 

---

# textBoxConfig



Configuration structure passed to [menuTextBox::msgTxtInputMultiline()](Classes/classmenu_text_box.md#function-msgtxtinputmultiline). 


`#include <menu.h>`

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| const char * | **[prompt](Classes/structtext_box_config.md#variable-prompt)**  |
| char * | **[result](Classes/structtext_box_config.md#variable-result)**  |
| unsigned int | **[maxLength](Classes/structtext_box_config.md#variable-maxlength)**  |
| unsigned int | **[minLength](Classes/structtext_box_config.md#variable-minlength)**  |
| const char * | **[allowedChars](Classes/structtext_box_config.md#variable-allowedchars)**  |
| [textBoxMenuOption](Classes/classtext_box_menu_option.md) * | **[_textBoxCallBack](Classes/structtext_box_config.md#variable--textboxcallback)**  |
| uint16_t | **[textLineWidth](Classes/structtext_box_config.md#variable-textlinewidth)**  |

## Public Attributes Documentation

### variable prompt

```cpp
const char * prompt = nullptr;
```


text displayed above the editor frame as the input prompt 


### variable result

```cpp
char * result = nullptr;
```


pointer to the buffer where the edited text is read from and written back to 


### variable maxLength

```cpp
unsigned int maxLength =0;
```


maximum number of characters accepted (0 = use textLineWidth-1) 


### variable minLength

```cpp
unsigned int minLength =0;
```


minimum number of characters required (0 = 1) 


### variable allowedChars

```cpp
const char * allowedChars = nullptr;
```


null-terminated string of permitted characters; nullptr allows all printable characters 


### variable _textBoxCallBack

```cpp
textBoxMenuOption * _textBoxCallBack = nullptr;
```


optional callback object whose checkBackgroundEvents() and performUserInteraction() are polled during editing 


### variable textLineWidth

```cpp
uint16_t textLineWidth = defaultTextBoxWidth;
```


for textBox editor width 


-------------------------------

Updated on 2026-04-27 at 16:36:45 +0200