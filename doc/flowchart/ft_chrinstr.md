# ft_chrinstr

## Description
checking if charter includet in a string

## Declaration

```char *ft_chrinstr(char *str, int chr)```

## Links

- [back](get_next_line.md)
- [main function](get_next_line.md)
- [README](../../README.md)

### used subfunctions
---


```mermaid
flowchart TD

A{str_i != '\0} -- no --> E(return_0)
A -- yes --> B{str_i == chr}
B -- no -->C(i++)-->A
B -- yes -->D(Rerurn *str_i)
```
