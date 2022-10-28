#include <string.h>
#include <stdio.h>
#include "utils.h"


void parse_input_string(char* line, char** cmd, int max_args)
{
    int i = 0;
    char *chunk, *string;
    string = strdup(line);
    while( (chunk=strsep(&string," ")) != NULL )
    {
      cmd[i] = chunk;
      i++;
    }
    cmd[i + 1] = NULL;
}
