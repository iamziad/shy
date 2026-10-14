#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  char *desc;
} Builtin;

Builtin builtins[] = {{"exit", "exit the shell"},
                      {"echo", "display a line of text"},
                      {"type", "locate a command and describe it's type"}};

Builtin *find_builtin(const char *cmd) {
  for (size_t i = 0; i < sizeof(builtins) / sizeof(Builtin); i++) {
    if (strcmp(cmd, builtins[i].name) == 0) {
      return &builtins[i];
    }
  }
  return NULL;
}

void parse_path(const char *path) {
  size_t i = 0;
  while (path[i] != 0) {
    if (path[i] == ':') {
      printf("%s\n", path + i);
    }
    i++;
  }
}

int main(int argc, char *argv[]) {
  const char *path = getenv("PATH");
  parse_path(path);

  while (1) {
    char cmd[64];
    printf("$ ");
    if (!fgets(cmd, sizeof(cmd), stdin))
      return EXIT_FAILURE;

    size_t new_line = strcspn(cmd, "\n");
    cmd[new_line] = 0;

    if (strncmp(cmd, "exit", 4) == 0) {
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

    else if (strncmp(cmd, "echo", 4) == 0) {
      char *arg = cmd + 5;
      printf("%s\n", arg);
    }

    else if (strncmp(cmd, "type", 4) == 0) {
      char *arg = cmd + 5;

      if (find_builtin(arg)) {
        printf("%s is a shell builtin\n", arg);
      } else {
        printf("%s: not found\n", arg);
      }
    }

    else {
      fprintf(stderr, "%s: command not found\n", cmd);
    }
  }

  return EXIT_SUCCESS;
}
