# get next line 
## Description
checking if charter includet in a string, 

## Declaration

```char *ft_chrinstr(char *str, int chr)```

## Links

[back](../../README.md)
[main function](get_next_line.md)
[README](../../README.md)

### used subfunctions
[ft_chrinstr](ft_chrinstr.md)
[ft_readbuf](ft_readbuf.md)
[ft_clean_storage](ft_clean_storage.md)

---
```mermaid
flowchart TD

A{fd < 0} -- yes -->B(return NULL)
A -- no --> C{/n not in storage}
C -- yes --> D(ft_readbuf)
C -- no --> E{!storge}
D --> E
E -- yes --> F(return NULL)
E -- no --> G(line == storage)
G --> H{!line}
H -- yes --> I(return freed storage)
H -- no --> J(clean Storage)
J --> K(return line)
```
