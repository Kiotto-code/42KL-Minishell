#include <stdio.h>
#include <stdlib.h>
#include <term.h>
# include <termios.h>
# include <curses.h>

int main() {
    char* up_string = tgetstr("up", NULL);
    char* cr_string = tgetstr("cr", NULL);

    if (up_string != NULL && cr_string != NULL) {
        printf("UP string: %s\n", up_string);
        printf("CR string: %s\n", cr_string);
        // Use the UP string to move the cursor up one line
        // Then use the CR string to move the cursor to the beginning of that line
        printf("%s%sHello, World!\n", up_string, cr_string);
    }
    return 0;
}