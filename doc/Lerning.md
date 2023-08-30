# Lerning 

## static Variable 
- Used for safe for a longer Time 
-> Example: 
```C
#include <stdio.h>
void Func() {
static int x = 0;
x++;
printf("%d\n", x); // outputs the value of |x|
}

int main() {
Func(); // prints 1
Func(); // prints 2
Func(); // prints 3
Func(); // prints 4
Func(); // prints 5
return 0;
}
```
- Normal x will set without static to zero. 
## Misstakes
- 2h dealing to resize a storeage for the string;
	- Realising that u must copy the readend string char by char using strcpy() and strcat()
- if u read() a buffersize - after u read again he read forward at the last position!
- if dealing with (void *) in a function
	--> cast them into a special data typ
	- for example
```c
void ft_bzero(void *str)
{
unsigned char *mem;
mem = (unsigned char *)str;
...
}```

### Nach mehren Anlaufen -- Breakpoint
	- After Freeing --> setting the Pointer to NULL ! 

```c
char *ft_free(char **str)
{
free(*str);
*str = NULL;
return (NULL);
}
```
