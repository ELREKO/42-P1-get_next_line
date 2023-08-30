# ft_readbuf

## Description
- read the file in parts of the **BUFFERSIZE** and Checking for /n
- **!! thats Different to mean !!**
## Declaration

```char  *ft_readbuf(int fd, char *storage)```

## Links
- [back](get_next_line.md)
- [main function](get_next_line.md)
- [README](../../README.md)

### used subfunctions
- [ft_chrinstr](ft_chrinstr.md)
- [ft_strjoin](ft_strjoin.md)

---

```mermaid
flowchart TD
	A(set rid = 1)-->B(creat a Buffer)
	B --> C{rid > 0 && no /n in Buffer}
	C -- yes --> D(use read function -- fill buffer && feedback rid)
	D --> E{rid > 0}
	C -- no --> H(free Buffer)
	H --> I{rid == -1}
	I -- yes --> J(return freed storge)
	I -- no --> K(return storage)
	E -- yes --> F(End Buffer '\0')
	F --> G(use ft_strjoin -- storage)
	G -->C
	E -- no --> C
```
