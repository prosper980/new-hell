#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "readinput.h"
#include "parseline.h"
#include "execline.h"
#include "builtin.h"
#include "parsepipe.h"
#include "multipipe.h"


void read_input(void){

    while(1){

        char *line = NULL;
        size_t len = 0;

        printf("new-shell> ");
        
        if(getline(&line, &len, stdin) == -1){
            perror("Error reading input");
            exit(EXIT_FAILURE);
        }

        int n = 0;
        int pipe_counter = 0;
        while(line[n] != '\0'){
            if(line[n] == '|'){
                pipe_counter += 1;
            }
            n += 1;
        }

    

        if(pipe_counter > 0){
            if(pipe_counter > 1){
        
                //longer pipes
                multi_pipe(line, pipe_counter);
            }else{
                parse_pipe(line);
            }

        }else{
            char **data = parse_line(line);

            char cd[] = {"cd"};
            if(strcmp(data[0], cd) == 0){
                built_in_cd(data);
            }else{
                exec_line(data);
            }    

        }

        

          

    }
    
}
