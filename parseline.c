#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "parseline.h"



#define BUF_SIZE 64
#define MAX_ARG_SIZE 1024
#define STR_DELIM " \t\r\n\a"



char **parse_line(char *line){
    
    int pos = 0;

    char **tokens = malloc(BUF_SIZE * sizeof(char *));

    char *token = NULL;

    if(!tokens){
        perror("Error, alloncating memory");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, STR_DELIM);

    while(token != NULL){
        tokens[pos] = token;
        pos += 1;

        if(pos >= BUF_SIZE){
            pos += BUF_SIZE;

            tokens = realloc(tokens, BUF_SIZE * sizeof(char *));

            if(!tokens){
                perror("Error reallocating memory");
                exit(EXIT_FAILURE);
            }

        }

        token = strtok(NULL, STR_DELIM);
    }
    
    tokens[pos] = NULL;


    return tokens; 
}
