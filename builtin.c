#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "builtin.h"
#include "parseline.h"

int built_in_cd(char **args){

    if(chdir(args[1]) != 0){
        perror("error changing dir");
        exit(EXIT_FAILURE);
    }
    free(args);
    return 1;
}

