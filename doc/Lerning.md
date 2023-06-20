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