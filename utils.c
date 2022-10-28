#include <string.h>
#include "utils.h"


void parse_input_string(char* line, char** cmd, int max_args)
{
    int i;
    for (i = 0; i < max_args; i++) {
        cmd[i] = strsep(&line, " "); 
        if (cmd[i] == NULL)
            break;
        if (strlen(cmd[i]) == 0)
            i--;
    }
}
