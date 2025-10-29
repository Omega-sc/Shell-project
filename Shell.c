// I'm creating a simple shell in C
// *******************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define CMD_LEN 1024
#define MAX_ARGS 64

int main() {
    char cmd[CMD_LEN];
    char *args[MAX_ARGS];

    /*
    while (1)
    {
        print_prompt();
        read_input();
        parse_input();
        execute_command();
    }   // this is the logical workflow for the shell
    */

    while (1) {
        // to print the prompt that shell gives to the user
        printf("⚔️  shell> ");

        // to read the input from the user
        if (fgets(cmd, CMD_LEN, stdin) == NULL) {
            printf("\n");
            break; 
            // exit on EOF (Ctrl+D)
        }

        // since we used fgets in the previous step to read input, trailing newline character is left that will be removed using strcspn
        cmd[strcspn(cmd, "\n")] = '\0';

        if (strlen(cmd) == 0) {
            continue; 
            // if the user entered an empty line, prompt again
        }

        // exit the shell if the user types "exit"
        if (strcmp(cmd, "exit") == 0) {
            break;
        }

        // now I will begin the operation of parsing the input using tokenization
        char *token = strtok(cmd, " ");
        int i = 0;
        while (token != NULL && i < MAX_ARGS - 1) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;   // ------- this is very important for the execvp to know where the arguments end

        // to check the tokenization worked properly, let's print the tokens.
        // ill make this section a comment now, as we no longer need the user argument to be printed.

        /*for (int j = 0; args[j] != NULL; j++) {
        printf("arg[%d]: %s\n", j, args[j]);
        }*/

    //lets us begin some actual shell stuff now..
    // we will use fork() to create a new process, that is identical to the one already running. lets call the original process the parent, amd the new one is called the child.
    // these to processes are identical, except for the return value of the fork() call.
    // using execvp we make allow the child to be able to run other programs.
    //the parent meanwhile waits for the child to complete using wait(NULL)
    // if the execution of execvp is successful, the child process is replaced by the new program, and doesnt return the. 
    //otherwise we will configure it to print an error message and exit (using perror()))

        //using built in commands to handle stuff like cwd
        
        if (strcasecmp(cmd, "Exit") == 0) {
            break;
        }


        //Now lets add functionality to handle some commonly used built-in commands like 'cd'.


        if(strcmp(args[0], "cd")==0) {
            if (args[1]==NULL){
                fprintf(stderr, "cd: missing argument\n");
            }
            else {
                if (chdir(args[1])!=0){
                    perror("cd failed");
                }
                 else {
                    printf("Changed directory to %s\n", args[1]);
                 }
            }
        continue;
        }

        pid_t pid = fork();
        if (pid<0) {
            perror("fork failed");
        }
        else if (pid==0){
            execvp(args[0], args);
            perror("execvp failed");
            exit(1);
        }
        else {
            wait(NULL);
        }
    }

    printf("Exiting shell. Goodbye!\n");
    return 0;

}     