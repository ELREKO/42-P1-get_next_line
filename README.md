# get_next_line
Is 1 from the Project from the first circel of 42 Cours

## My Points
- About the function [read](/doc/read().md)
- git to a short [version](https://github.com/pasqualerossi/42-School-Exam-Rank-03) for the exam-Rank03
- [Lerning](/doc/Lerning.md)
- [flow Chart](/doc/flowchart/get_next_line.md)
- Prepering [defence](/doc/defence.md)

## Description
Write a function that returns a line read from a
file descriptor.

## Declaration
`char *get_next_line(int fd);`

## Parmeters
fd: The file descriptor to read from

## Allowd External functs.
read, malloc, free

## Return Value
- Read line: correct behavior
- NULL: there is nothing else to read, or an error occurred

## Trun in files
- get_next_line.c,
- get_next_line_utils.c,
- get_next_line.h

## Special
- Make sure that your function works as expected both when reading a file and when reading from the standard input.
- Please note that the returned line should include the terminating \n character, except if the end of file was reached and does not end with a \n character.
- Because you will have to read files in get_next_line(), add this option to your compiler call: -D BUFFER_SIZE=n It will define the buffer size for read(). The buffer size value will be modified by your peer-evaluators and the Moulinette in order to test your code.
- We must be able to compile this project with and without the D BUFFER_SIZE flag in addition to the usual flags. You can choose the default value of your choice.
- You will compile your code as follows (a buffer size of 42 is used as an example): cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 `<files>.c`
- We also consider that get_next_line() has an undefined behavior when reading a binary file. However, you can implement a logical way to handle this behavior if you want to.

## Forbidden
• You are not allowed to use your libft in this project.
• lseek() is forbidden.
• Global variables are forbidden.
  
--> [subject](/PDF/subject_get_next_line.pdf)
