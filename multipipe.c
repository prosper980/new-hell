#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//remove when done testing
#include <stdio.h> 

#include "multipipe.h"

#define ARG 64

int multi_pipe(char *pipe_line, int pipe_counter){



    int n = 0;
    char** commands = malloc(sizeof(pipe_line) * sizeof(char  *));


    int cnt = 0;
    while(pipe_counter+1 > 0){
        char *command = malloc(ARG * sizeof(char *)); 
        int counter = 0; 
        while(pipe_line[n] != '|'){
            command[counter] = pipe_line[n];
            counter += 1;
            n += 1; 
        }

        commands[cnt] = command;
        cnt += 1;
        //have to free command
        //printf("command %s\n", command);
        pipe_counter -= 1;
        n += 2;
    }

    printf("co: %s\n",commands[2]);

    free(commands);


    return 1;
}