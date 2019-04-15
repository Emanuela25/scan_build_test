#include <string.h>
#include <stdio.h>
#include <stddef.h>

int checkpass(char *password) {
  if (strcmp(password, "pass") == 0) {
    return 1;
  }
}

void func(char *userinput) {
  if (checkpass(userinput)) {
    printf("Success\n");
  }
}

void msc_main() {
    char* input = "test";
    func(input);
    return;
}
