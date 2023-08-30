# ft_substr

## Description
Cutting a given String from a start postition to  End possion 

## Declaration
```char *ft_substr(char *s, unsigned int start, size_t len)```
## Links

[back](get_next_line.md)
[main function](get_next_line.md)
[README](../../README.md)

### used subfunctions

```mermaid
flowchart TD
	A(set counter = 0)--> B{start > len of storage}
	B -- yes --> C(return '\0')
	B -- no --> D{"(storage - start)< endpoint"}
	D -- yes --> E("Len = (storage - start) - len")
	E --> F("Creat str_ret(len)")
	F --> G(Copy char by char from storage to str_ret -- using while)
	G --> H(return str_ret)
```

