#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "shell_utils.h"

void print_status_line(char *user_name,int size)
{
  char cwd[size];
  getcwd(cwd,sizeof(cwd));
  if(cwd == NULL)
  {
    perror("Failed to collect directory info");
    exit(1);
  }
  printf("[%s] - %s \n",user_name,cwd);
}

void read_user_input(char* buf, int input, int size)
{
  read(input,buf,size);
}
