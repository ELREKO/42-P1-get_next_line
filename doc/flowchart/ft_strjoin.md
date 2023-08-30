# ft_substr

## Description
conecting to strings together 

## Declaration
```char  *ft_strjoin(char *str1, char *str2)```
## Links

[back](get_next_line.md)
[main function](get_next_line.md)
[README](../../README.md)

### used subfunctions

```mermaid
flowchart TD
	A{!str1} -- yes --> B("str(0) = 0 ")
	A -- no --> C
	B --> C("malloc -- str_ret()")
	C --> D("wihle -- cpy str1 --> str_ret")
	D --> E("wihle -- cpy str2 --> str_ret")
	E --> F("FREE (str1)")
	F --> G("return str_ret")
```
