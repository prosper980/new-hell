#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include "execline.h"


int exec_line(char **args){
  
    __pid_t pid = fork();

    if(pid == 0){
        //in the child process
        if(execvp(args[0], args) ==  - 1){
            perror("Command execution failed");
        }
        exit(EXIT_FAILURE);
    }else if(pid < 0){
            perror("Processing forking error");
    }else{
            waitpid(pid, NULL, 0);
    
    }
        

    free(args);

    return 1;
}
