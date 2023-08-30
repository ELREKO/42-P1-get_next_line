#include "get_next_line.h"

int main(void) 
{
    int fd;
    char *str_read;

    fd = open("Test.txt", O_RDONLY);
    if (fd < 0) {
        perror("r1");
        exit(1);
    }

    int i = 0;

    if (!(str_read = get_next_line(42)))
        printf("%s \n", str_read);
    while (str_read)
    {
        printf("Line: %d -->",i);
        printf("%s", str_read);
        i++;
        str_read = get_next_line(fd);
    }
    free(str_read);
    int result = close(fd);
    if (result < 0) {
        perror("Error closing file");
        exit(1);
    }


// //--------------------------------- Test Stdin 

//     printf("Enter a line of text for testing:\n");

//     // Setzen Sie die Standardeingabe auf stdin (Tastatureingabe)
//     freopen(NULL, "r", stdin);

//     // (0) ist fuer die Standardeinage 
//     char *line = get_next_line(0);
//     if (line != NULL) {
//         printf("\nLine read from input:\n%s\n", line);
//     } else {
//         printf("No input was provided.\n");
//     }
//     free(line);

//     return (0);
}
