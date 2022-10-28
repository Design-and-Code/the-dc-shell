#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <strings.h>
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
  bzero(buf,size);
  read(input,buf,size);
  buf[strlen(buf) - 1] = '\0';
}

void execute_command(char** cmd)
{
  pid_t id = fork();
  if(id == -1)
  {
    perror("Cannot create process :((");
    return;
  }
  else if(id == 0)
  {
    if(execvp(cmd[0],cmd) == -1)
    {
      printf("%s",cmd[0]);
      perror("Command execution failed \n");
    }
    exit(0);
  }
  else
  {
    wait(NULL);
    return;
  }
}
