# Lerning 

## 230619
- static variable 
--> explain on a Example 
```c
#include <stdio.h>

void Func() {
  static int x = 0;
  // |x| is initialized only once across five calls of |Func| and the variable
  // will get incremented five times after these calls. The final value of |x|
  // will be 5.
  x++;
  printf("%d\n", x);  // outputs the value of |x|
}

int main() {
  Func();  // prints 1
  Func();  // prints 2
  Func();  // prints 3
  Func();  // prints 4
  Func();  // prints 5

  return 0;
}
```

## 230620
- if u read() a buffersize - after u read again he read forward at the last position! 
- 2h dealing to resize a storeage for the string; 
  - Realising that u must copy the readend string char by char using strcpy() and strcat()
  - !! 

  ```c
          size_t str_store_length = (str_store != NULL) ? strlen(str_store) : 0;
        temp = (char *)malloc((BUFFER_SIZE + str_store_length + 1) * sizeof(char));
        if (!temp) {
            free(str_c);
            return NULL;
        }

        if (str_store) {
            strcpy(temp, str_store);
            strcat(temp, str_c);
            free(str_store);
        } else {
            strcpy(temp, str_c);
        }
  ```

  - For writting my own 'strcpy' i get the error 
    - segmentation fault (core dumped)
    - forgott the count to init and end with '\0'
  ```c
  ui_count = 0;
  dest[ui_count] = '\0';
  ```

  - if dealing with (void *) in a function 
    --> cast them into a special data typ 
    - for example 
  ```c
  void ft_bzero(void *str)
  {
    unsigned char *mem;
    mem = (unsigned char *)str;
    ...
  }
  ```

  ## 230627
- Ich hatte gestern das Problem das mein Code auf dem Laptop ausfuerbar war aber nicht auf dem Schulrechner!
Auf dem Schulrechner kam immer "Core Dumped" 
Heute hatte ich das "get_next_line" neu angefangen und es hatte sich gelohnt ich habe verstanden warum das Problem auftauchte! 

--> Das Problem lag darin das ich die Variable zum Beschreiben der Funktion uebergeben hatte und dies darin versuchte zu lesen und zu beschreiben dies schien mein Rechner zu machen. 
> **Das Problem --> so nicht machen**
```
int ft_check_Newline(char **str_check)//, char **str_store)
{
    int i_count;
    char *mem; 
    if ((mem = ft_calloc_char(ft_strlen(*str_check))) == NULL)
        return (-1);
    i_count = 0;
    while (str_check[i_count] != '\0')
    {
        i_count++;
    }
    free(mem);
    return (1);
}
```

> **Kein Core Dumped mit "interne Variable" in der Funktion hier mit mem!**
```
int ft_check_Newline(char **str_check)//, char **str_store)
{
    int i_count;
    char *mem; 
    if ((mem = ft_calloc_char(ft_strlen(*str_check))) == NULL)
        return (-1);
    i_count = 0;
    while (mem[i_count] != '\0')
    {
        i_count++;
    }
    free(mem);
    return (1);
}
```

## 230628 
- get next line really short 
[LINK](https://github.com/pasqualerossi/42-School-Exam-Rank-03)
- 