#include <string.h>
#include <unistd.h>
#include <stdlib.h>
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


int parse_built_in_cmd(char **cmd)
{
  int no_of_cmd = 2, i, cmd_no = 0;
  char* cmd_list[no_of_cmd];
  cmd_list[0] = "exit";
  cmd_list[1] = "cd";
  for(i=0;i<no_of_cmd;i++)
    {
      if(strcmp(cmd[0],cmd_list[i]) == 0)
      {
        cmd_no = i + 1;
        break;
      }
    }
  switch(cmd_no)
    {
      case 1: 
        printf("Exiting shell...");
        printf("\033c");
        exit(0);
      case 2:
        chdir(cmd[1]);
        return 1;
      default:
        break;
    }
  return 0;
}
