//I'm creating a simple shell in c
//*******************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX_INPUT_SIZE 1024
int main(){
char input[MAX_INPUT_SIZE];
/*while (1)
{
    print_prompt();
    read_input();
    parse_input();
    execute_command();
}*/   //this is the logical workflow for the shell


while(1){

    //to print the prompt that shell gives to the user
    printf("⚔️  shell> ");


    //to read the input from the user
    if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
        printf("\n");
        break; // Exit on EOF (Ctrl+D)

    }
    //since we used the fgets in the previous step to read input, a trailing newline character is left that will be removed using strcspn
    input[strcspn(input, "\n")] = '\0';

    // exit the shell if the user types "exit"
    if (strcmp(input, "exit") == 0) {
        break; 
    }


    //in the beginning i will make the shell simply be able to echo user inputs...
    printf("You entered: %s\n", input);
}

printf("Exiting shell. Goodbye!\n");



return 0;

}