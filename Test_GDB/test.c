#include <stdio.h>

int *px = NULL;

void foo(){
    printf("foo\n");
    //*px = 7;
}


int main(void)
{
    char *name = "rené";
    char *name2 = "Elisa";



    foo();
    printf("my name is: %s\n", name);

    name = name2;
    return (0);
}