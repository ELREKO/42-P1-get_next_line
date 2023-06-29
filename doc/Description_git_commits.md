# Description git commits 

## first_steps --> 2023.06.19
- created a make file 
- count how many characters are in the function 
**ToDo:** 
- if i use the read during the count founction i does not get a good resualt for reading a gain. --> from the Task i have do include the ```BUFFER_SIZE``` for compiling ```cc .... -D BUFFER_SIZE=42``` and a Default setting 

## setting for BUFFER_SIZE --> 2023.06.19
- Change the header "get_next_line.h" 
- Change the main.c for Test
**ToDo:** 
- [ ] safe the reading line in a static var -- reading during a loop till \new line
- [x] Default value if i use "cc -D BUFFER_SIZE <file>.c"
- [x] clear git repo ft_printf
- [x] look the movie for todo next line


## first output return from get_next_line --> 2023.06.19
- creating some helpers (ft_strlen, ft_strcpy, ft_strcat, ft_bzero)
- Changed the get_next_line() function to a return from a whole file size, 
- thing about whats give read() as return if the file is open
### ToDo
- [ ] seperatet the fedback into a line feedback 
- [ ] Creat a loop function get_next_line at loops 
- [ ] Lern how to use valgrind for memory leaks
- [ ] Lern creating makefile

## seperate the get_next_line function --> 2023.06.24
- The function get_next_line is for Norminette to long 
- --> so it split to seperate function 
### ToDo
- [x] seperatet the fedback into a line feedback 
- [ ] Creat a loop function get_next_line at loops 
- [ ] Lern how to use valgrind for memory leaks
- [ ] Lern creating makefile
- [x] Baue in den Test "Test;--" ein --> nächste Zeile kommt eine '1' Warum ? 


## get_next_line works --> 2023.06.24
- get line give the feedback till '\n' newline char
- ';--' wiht seperate line it works right no extra error with printing a '1'
- Loop durring make forgot the last line 
### ToDo
- [ ] Creat a loop function get_next_line at loops 
- [ ] creat a special Testfile 
- [ ] look what is to to next_line_utiles() --> pdf
- [ ] Lern how to use valgrind for memory leaks
- [ ] Lern creating makefile

## folder New --> 2023.06.25
- test at school Pc doesnt work 
- changed filles in folder "New" 
### ToDo
- [ ] Creat a loop function get_next_line at loops 
- [ ] creat a special Testfile 
- [ ] look what is to to next_line_utiles() --> pdf
- [ ] Lern how to use valgrind for memory leaks
- [ ] Lern creating makefile

## Kill Memory Leaks -- Loop without memory leak --> 2023.06.25
- serch and kill memory leaks 
- Test in a loop was okay
- delete folder "New"
### ToDo 
- [x] doesn't print last line from reading 
- [ ] creat a special Testfile
- [ ] All Return Values if memory leaks

## it works but not testet compled --> 2023.06.25
- I test the function with easy Test files it works 
- Now it print the last line 
### ToDo 
- [ ] Read and Test with Valgrind 
- [ ] Look at francinett special Test 
- [ ] Test with Big Buffer Size 10000000
    - ich habe immer nur mit klienen  Buffer Size getestet jedoch bekomme ich bei einer grosse zurück BS das ganze file zurück
    - Ich muss den static speicher auslesen 

## fixing some mem leaks --> 2023.06.26
- The file dosn't work on the school PC 
--> i save it on git becouse i want to test with my laptop agian 
- on my laptop it wokrs. 

## Fixing more leaks --> 2023.06.26
--> Programm does not work maybe i think to start new. And think about the mem leak at the Exam i have also write down in 3h 
- i have a fuction Repo at as extra folder in my folder 
[source](https://codeberg.org/Vusk/get_next_line)

## Newstart --> 2023.06.27
- i write the function new --> the old Project are in the Folder "Old_Project"
- The new are at the foler --> "new_begin"


## fix mem leeks --> 2023.06.28
Next Step: Stop if file end;  

## fixing newline space --> 2023.06.28
- i had problem with newline and i fixing it 

## last stand --> 2023.06.28
- no bigger changing
ToDo: 
- [ ]Check the file end. 

## Fixing the end of file Problem --> 2023.06.28
- [ ] Cleaning for Norminette 
- [ ] Testting special Case from francinette 
