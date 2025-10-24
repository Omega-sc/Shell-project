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

        // to check the tokenization worked properly, let's print the tokens one by one
        for (int j = 0; args[j] != NULL; j++) {
            printf("arg[%d]: %s\n", j, args[j]);
        }
    }

    printf("Exiting shell. Goodbye!\n");

    return 0;
}     