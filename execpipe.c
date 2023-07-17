#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "execpipe.h"

int exec_pipe(char **first_command, char **second_command){

    __pid_t pid1, pid2;

    
    //fd[0] => reading end
    //fd[1] => writing end
    int fd[2];
    int pip = pipe(fd);

    if(pip == -1){
        perror("piper error");
        exit(EXIT_FAILURE);
    }

    pid1 = fork();
    pid2  = fork();

    if(pid1 == -1){
        perror("forking first child error");
        exit(EXIT_FAILURE);
    }

    if(pid1 == 0){
        //in first child
        
        //close unused ends
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);

        if(execvp(first_command[0], first_command) == -1){
            perror("First pipe command execution error");
            exit(EXIT_FAILURE);
        }

    }

    if(pid2 == -1){
        perror("forking second child error");
        exit(EXIT_FAILURE);
    }
    

    if(pid2 == 0){
        //in second child

        dup2(fd[0], STDIN_FILENO);
        close(fd[1]);
        close(fd[0]);

       if(execvp(second_command[0], second_command) == -1){
            perror("Second pipe command execution error");
            exit(EXIT_FAILURE);
       }
    }


    close(fd[0]);
    close(fd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    return 0;
}

