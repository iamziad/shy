#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    while (1) {
        char cmd[64];
        printf("$ ");
        if (!fgets(cmd, sizeof(cmd), stdin))
            return EXIT_FAILURE;

        size_t new_line = strcspn(cmd, "\n");
        cmd[new_line] = 0;

        if (strncmp(cmd, "exit ", 5) == 0) {
            if (strlen(cmd) == 4)
                exit(0);

            char *arg = cmd + 5;
            char *end_ptr;
            long exit_code = strtol(arg, &end_ptr, 10);

            if (end_ptr != arg && *end_ptr == '\0')
                exit((int)exit_code);
            else
                fprintf(stderr, "exit: %s: invalid integer\n", arg);
        }

        else if (strncmp(cmd, "echo ", 5) == 0) {
            char *arg = cmd + 5;
            printf("%s\n", arg);
        }

        else {
            fprintf(stderr, "%s: command not found\n", cmd);
        }
    }

    return EXIT_SUCCESS;
}
