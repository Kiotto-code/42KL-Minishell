#include <stdio.h>
#include <stdlib.h>
#include <term.h>
# include <termios.h>
# include <curses.h>


int main() {
    char    *termtype = getenv("TERM");

    printf("termtype: %s\n", termtype);
    if (termtype == NULL) {
        printf("TERM environment variable not set.\n");
        return 1;
    }

    int success = tgetent(NULL, termtype);
    if (success != 1) {
        printf("Failed to retrieve terminal capabilities.\n");
        return 1;
    }

    char *setaf = tgetstr("setaf", NULL);
    if (setaf == NULL) {
        printf("setaf capability not found.\n");
        return 1;
    }

    // char *reset = tgetstr("sgr0", NULL);
    char *reset = tgetstr("op", NULL);
    if (reset == NULL) {
        printf("sgr0 capability not found.\n");
        return 1;
    }

    char *red = tgoto(setaf, 1, 0);  // Use the color index 1 for red.

    printf("%sHello, World!%s\n", red, reset);

    return 0;
}
