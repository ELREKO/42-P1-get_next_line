# show debuging Case 
objdump ./a.out

# Using GDB
1. Type ```gdb``` 
2. Type ```file ./progammname``` (./programmname is the Progammname for exampel ./a.out)
3. Type ```run```
4. --> For Debugging 
    Type ```start``` -->a breakpoint is creating at the main
5. Type ```list``` --> show the whole Progamm
6. Type ```next``` --> to jump to the next point
6. Type ```n``` for the next step

# Using Text User Interface 
1. Type ```list```
2. Press 'ctrl' + 'x' + 'a' --> Jump to a other view 
3. Type next for Debugging 
4. If Output somesing ogward -- Press 'ctrl' + 'l' --> for deleting

# Printing 
1. Use ```print <Var>``` to print the Pointer of the var 

# Step into a function 
1. If u from Steppoint at the function 
Type 's' to stept into the function you could aso step into the printf function for example
2. Use ```backtrack``` to show infos where u are and from


# Segment fault (Core Dumpe)
if u start it will show u the line with is the Problem with 
or use ```bt```

# Breakpoints 
ou set a basic breakpoint with the following command:

```break [LOCATION]``` or just ```b [LOCATION]``

Where ```LOCATION``` can be a line number, function name, or "*" and an address.

```(gdb) break hello.c:7```

Once your program hits a breakpoint, it waits for instruction. You can navigate or step through the program using ```next```, ```continue```, ```step i```, and other commands. To speed up your typing, you can abbreviate all of these commands; ```n``` for next, ```c``` for continue, ```si``` for step i - you get it.




## Reverce Debugging 
--> Type ```record``` for revers Debugging
reverse-next (rn) - step the program backward, run through subroutine calls
reverse-nexti (rni) - step backward one instruction, but run through called subroutines
reverse-step (rs) - step the program backward until it reaches the beginning of a previous source line
reverse-step (rsi) - step backward one instruction
reverse-continue (rc) - continue the program but run it in reverse
reverse-finish (rf) - execute the program backward until just before the point the memory 

--> (Link for Comands)[https://undo.io/resources/gdb-watchpoint/5-ways-reduce-debugging-hours/]