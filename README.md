
*Mini Shell (Work in Progress)

*************************************************************************************

*A minimal shell written in C — currently at the echo stage.  
*The shell takes user input, processes it, and echoes it back to the screen.  
*Future versions will execute commands using unix system calls (fork(), execvp(), etc)


*Current Status

 Accepts user input  
 Loops continuously until manually exited  
 *Enable input tokenization through strtok(), and parsing of user input..

 Does *not yet* execute system commands  
 No piping, redirection, or background tasks  

*************************************************************************

 *Planned Functionality


| Input parsing, Basic string handling
| Command execution using fork()  and execvp() 
| cd, exit built-ins
| Piping & redirection

**| Input parsing, Basic string handling  ----has been implemented as of 24th October,2025
**| Built-in command handling added. Now commands like whoami, ls, ls -l, and exit are working.


*Requirements

- GCC (or any C compiler)
- linux/WSL environment



-Im making this project only for UNIX like systems and on Windows* only through WSL (windows subsystem for Linux)
-It won’t compile properly in a pure Windows environment (<unistd.h> or <sys/wait.h> not yet used, but planned).

---

*Compilation

**bash
gcc Shell.c -o Shell
