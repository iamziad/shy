#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    while (1) {
        char command[64];
        printf("$ ");
        fgets(command, sizeof(command), stdin);
        size_t new_line = strcspn(command, "\n");
        command[new_line] = 0;

        if (strcmp(command, "exit") == 0) {
            exit(0);
        }

        printf("%s: command not found\n", command);
    }

    return 0;
}
