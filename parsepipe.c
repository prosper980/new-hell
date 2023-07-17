#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "parsepipe.h"
#include "parseline.h"
#include "execpipe.h"

#define MAX_ARG_SIZE 1024


int parse_pipe(char *pipe){

    char first_command[MAX_ARG_SIZE];
    char second_command[MAX_ARG_SIZE];

    int n = 0;
    while(pipe[n] != '|'){
        first_command[n] = pipe[n];
        n += 1;
    }


    int p = 0;
    n += 1;
    while(pipe[n] != '\0'){
        second_command[p] = pipe[n];
        p += 1;
        n += 1;
    }



    //printf("first: %s second: %s", first_command, second_command);

    char **f_parsed_command = parse_line(first_command);

    char **s_parsed_command = parse_line(second_command);

    exec_pipe(f_parsed_command, s_parsed_command);

    free(pipe);
    free(f_parsed_command);
    free(s_parsed_command);   

    return 1;
    
}