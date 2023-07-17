#include <stdio.h>
#include <stdlib.h>
#include <term.h>
# include <termios.h>
# include <curses.h>


// int main() {
//     char *termtype = getenv("TERM");
//     if (termtype == NULL) {
//         printf("TERM environment variable not set.\n");
//         return 1;
//     }

//     int success = tgetent(NULL, termtype);
//     if (success != 1) {
//         printf("Failed to retrieve terminal capabilities.\n");
//         return 1;
//     }

//     char *setaf = tgetstr("setaf", NULL);
//     if (setaf == NULL) {
//         printf("setaf capability not found.\n");
//         return 1;
//     }

//     char *reset = tgetstr("op", NULL);
//     if (reset == NULL) {
//         printf("op capability not found.\n");
//         return 1;
//     }

//     char *red = tparm(setaf, 1);  // Use the color index 1 for red.

//     printf("%sHello, World!%s\n", red, reset);

//     return 0;
// }


// #include <stdio.h>
// #include <term.h>

// int main() {
//     char *termtype = getenv("TERM");
//     if (termtype == NULL) {
//         printf("TERM environment variable not set.\n");
//         return 1;
//     }

//     int success = tgetent(NULL, termtype);
//     if (success != 1) {
//         printf("Failed to retrieve terminal capabilities.\n");
//         return 1;
//     }

//     char *setaf = tgetstr("setaf", NULL);
//     if (setaf == NULL) {
//         printf("setaf capability not found.\n");
//         return 1;
//     }

//     char *reset = tgetstr("op", NULL);
//     if (reset == NULL) {
//         printf("op capability not found.\n");
//         return 1;
//     }

//     // Output the control sequence to set the text color to red
//     tputs(setaf, 1, putchar);

//     // Print the text in the modified color
//     printf("Hello, World!");

//     // Output the control sequence to reset the text color
//     tputs(reset, 1, putchar);

//     return 0;
// }


#include <stdio.h>
#include <term.h>

int main() {
    char *termtype = getenv("TERM");
    if (termtype == NULL) {
        printf("TERM environment variable not set.\n");
        return 1;
    }

    int success = tgetent(NULL, termtype);
    if (success != 1) {
        printf("Failed to retrieve terminal capabilities.\n");
        return 1;
    }

    char *up = tgetstr("up", NULL);
    if (up == NULL) {
        printf("up capability not found.\n");
        return 1;
    }

    char *cr = tgetstr("cm", NULL);
    if (cr == NULL) {
        printf("cr capability not found.\n");
        return 1;
    }

    // Output the control sequence to move cursor up one line
    tputs(up, 1, putchar);

    // Output the control sequence to move cursor to beginning of the line
    tputs(cr, 1, putchar);

    // Print the text
    printf("Hello, World!\n");

    return 0;
}
