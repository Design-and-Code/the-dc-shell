#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "shell_utils.h"
#include "utils.h"

#define SIZE 1024
#define STD_IN 0
#define STD_OUT 1
#define ARGS_MAX 20


int main(int argc, char **argv)
{
  // Working of a shell
  // A shell has 3 main functions :
  // 1. Start the shell by loading any configs if any.
  // 2. Execute the commands
  // 3. Clean up by freeing memory.

  //get the user name
  char* user = getenv("USER");
  char line[SIZE];
  char* cmd_with_args[ARGS_MAX];

  printf("\033c");
  printf("Hello %s ;) \n",user);
  for(;;)
  {
    int i = 0;
    bzero(cmd_with_args,sizeof(cmd_with_args));
    print_status_line(user,SIZE);
    write(STD_OUT,"> ",2);  
    read_user_input(line, STD_IN, SIZE);
    parse_input_string(line,cmd_with_args,ARGS_MAX);
    int cmd_status = parse_built_in_cmd(cmd_with_args);
    if(cmd_status == 0)
    {
        execute_command(cmd_with_args);
    }
  }
  return 0;
}
