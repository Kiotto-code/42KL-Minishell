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

    char *reset = tgetstr("sgr0", NULL);
  	char* cm_cap = tgetstr("cr", NULL);
	// char* cm_cap = tgetstr("cm", &input);
	// char	*cm_cap = tgetstr("up", &input);
	if (cm_cap == NULL) {
		printf("Cursor motion capability not found.\n");
		return 1;
	}

    tputs(cm_cap, 10, putchar);
    // printf("%sHello, World!%s\n", red, reset);

    return 0;
}



// 	char* cm_cap = tgetstr("cr", &input);
// 	// char* cm_cap = tgetstr("cm", &input);
// 	// char	*cm_cap = tgetstr("up", &input);
// 	if (cm_cap == NULL) {
// 		printf("Cursor motion capability not found.\n");
// 		return 1;
// 	}
// 	// char* cr_cap = tgetstr("al", &input);
//     // if (cr_cap == NULL) {
//     //     printf("Carriage return capability not found.\n");
//     //     return 1;
//     // }

// 	// Set cursor position
// 	// int row = 1;  // Desired row
// 	// int col = 0; // Desired column

// 	// // // Output the sequence
// 	// tputs(tgoto(cm_cap, col, row), 0, putchar);
// 	tputs(cm_cap, 1, putchar);