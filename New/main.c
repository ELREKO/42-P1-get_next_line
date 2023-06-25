# include "get_next_line.h"

int ft_strcmp(char *str1, char *str2)
{
    //unsigned int ui_count; 

    if (ft_strlen(str1) != ft_strlen(str2))
        return (0);
    //ui_count = 0;
    while (*str1 != '\0')
    {
        if (*str1++ != *str2++)
            return (0);
        //ui_count++;
    }
    return (1);    
}

int main(void) 
{
    int fd;
    char *str_read;
  
    fd = open("Test.txt", O_RDONLY);
    if (fd < 0) {
        perror("r1");
        exit(1);
    }

    //char *str1 = "Test";
    // char *str2 = " ";
    // printf("%d\n", ft_strcmp("", str2));
    str_read = get_next_line(fd);
    printf("%s", str_read);
 





    // str_read = get_next_line(fd);
    // printf("%s", str_read);
    // str_read = get_next_line(fd);
    // printf("%s", str_read);
    // str_read = get_next_line(fd);
    // printf("%s", str_read);
    // str_read = get_next_line(fd);
    // printf("%s", str_read);
    // str_read = get_next_line(fd);
    // printf("%s", str_read);
    


    // Close the file

    int result = close(fd);
    if (result < 0) {
        perror("Error closing file");
        exit(1);
    }
    return (0);
}
