#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char command[256];
    FILE* fp;
    char buffer[1024];

    printf("Enter command:\n");
    fgets(command, sizeof(command), stdin);
    command[strcspn(command, "\n")] = '\0';

    snprintf(buffer, sizeof(buffer), "zsh -c '%s'", command);

    fp = popen(buffer, "r");
    if (fp == NULL) {
        printf("Failed to execute command.\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    pclose(fp);

    return 0;
}
