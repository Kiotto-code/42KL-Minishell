/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tgetstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:48:04 by yichan            #+#    #+#             */
/*   Updated: 2023/07/04 02:21:50 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

// int cursor_plc(char *input)
// {
//     // char term_buffer[1024];
//     char *term_buffer;
//     // char *termtype = getenv("TERM");

//     term_buffer = malloc(sizeof(char *) * 1024);
//     // Initialize the termcap database
//     if (tgetent(term_buffer, input) < 0) {
//         printf("Failed to initialize termcap.\n");
//         return 1;
//     }

//     // Retrieve the "rmso" capability string (end standout mode)
//     char *end_standout = tgetstr("rmso", &input);
//     if (end_standout == NULL) {
//         printf("Failed to retrieve end standout capability.\n");
//         return 1;
//     }

//     // Use tputs to send the capability string to the terminal
//     if (tputs(end_standout, 1, putchar) == -1) {
//         printf("Failed to end standout mode.\n");
//         return 1;
//     }

//     printf("Standout mode ended successfully!\n");

//     return 0;
// }

// int cursor_plc(char *input)
// {
// 	// Initialize termcap library
// 	// char term_buffer[1024];
// 	char *term_buffer = malloc(sizeof(char) * 1024);
// 	// char* input = getenv("TERM");
	
// 	int success = tgetent(term_buffer, input);
// 	if (success < 0) {
// 		printf("Failed to initialize termcap library.\n");
// 		return 1;
// 	} else if (success == 0) {
// 		printf("Terminal not found in termcap database.\n");
// 		return 1;
// 	}

// 	// Get cursor motion capability
// 	// char* cm_cap = tgetstr("so", NULL);
// 	// char* cm_cap = tgetstr("so", NULL);
// 	// char* cm_cap = tgetstr("se", &term_buffer);
// 	char* cm_cap = tgetstr("nd", &input);
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
// 	// tputs(cr_cap, 1, putchar);
// 	// tputs(cm_cap, 1, putchar);

// 	return 0;
// }

// int cursor_plc(char *input)
// {
// 	(void)input;
//     // Buffer to hold the terminfo data
//     char term_buffer[2048];

//     // Initialize the terminfo database
//     if (tgetent(term_buffer, getenv("TERM")) != 1) {
//         printf("Failed to initialize the terminfo database.\n");
//         return 1;
//     }

//     // Retrieve the capability string for "carriage return" (CR)
//     char* cr_capability = tgetstr("cr", NULL);

//     // Retrieve the capability string for "cursor left" (CUB)
//     char* cub_capability = tgetstr("cub", NULL);

//     if (cr_capability != NULL && cub_capability != NULL) {
//         // Move the cursor to the previous end of line using tputs
//         tputs(cr_capability, 1, putchar);
//         tputs(cub_capability, 1, putchar);
//         fflush(stdout);  // Flush output to ensure the cursor movement is visible
//     } else {
//         // The capabilities were not found
//         printf("The necessary capabilities are not defined for this terminal.\n");
//     }

//     return 0;
// }


int cursor_plc(char *input) {
    // Buffer to hold the terminfo data]
	(void)input;
    // char term_buffer[2048];
	char *term_buffer = malloc(sizeof(char) * 2048);

    // Retrieve the terminal information
    if (tgetent(term_buffer, getenv("TERM")) != 1) {
        printf("Failed to retrieve terminal information.\n");
        return 1;
    }

    // Retrieve the capability string for "carriage return" (CR)
    char* cr_capability = tgetstr("cr", &term_buffer);

    // Retrieve the capability string for "cursor left" (CUB1)
    char* cub_capability = tgetstr("cub1", &term_buffer);

    if (cr_capability != NULL && cub_capability != NULL) {
        // Move the cursor to the previous end of line using tputs
        if (tputs(cr_capability, 1, putchar) == ERR ||
            tputs(cub_capability, 1, putchar) == ERR) {
            printf("Failed to move the cursor.\n");
            return 1;
        }
        fflush(stdout);  // Flush output to ensure the cursor movement is visible
    } else {
        // The capabilities were not found
        printf("The necessary capabilities are not defined for this terminal.\n");
        return 1;
    }

    return 0;
}
