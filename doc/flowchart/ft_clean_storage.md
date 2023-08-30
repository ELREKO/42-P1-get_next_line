# ft_clean_storage

## Description
Giving a new string after \n cutting the storage and free the old storage! 

## Declaration
```char *ft_clean_storage(char *storage)```
## Links

[back](get_next_line.md)
[main function](get_next_line.md)
[README](../../README.md)

### used subfunctions

```mermaid
	flowchart TD
	A("usr ft_chrinstr for find \n position -- ptr")
	A --> B{!ptr}
	B -- yes --> C("return (ft_free(storage))")
	B -- no --> D("Calculate len for new_storage")
	D --> E(Fill new_storage from old storage with ft_substr)
	E --> F(return new_storage)
```