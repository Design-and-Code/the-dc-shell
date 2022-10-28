#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "shell_utils.h"

#define SIZE 1024
#define STD_IN 0
#define STD_OUT 1

int status = 1;

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
  while(status)
  {
    print_status_line(user,SIZE);
    write(STD_OUT,"> ",2);  
    read_user_input(line, STD_IN, SIZE);
  }
  return 0;
}
