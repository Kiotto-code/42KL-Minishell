// # include <stdio.h>
// # include <stdlib.h>
// # include <signal.h>
// # include <termios.h>
// # include <sys/types.h> //pid_t data type
// # include <sys/errno.h>
// # include <sys/wait.h>
// # include <readline/history.h>
// # include <readline/readline.h>
// # include <unistd.h>
// # include <curses.h>
// # include <term.h>


// int main() {
//     struct termios term;
//     tcgetattr(0, &term);

//     // Disable ICANON flag to enable non-canonical mode
//     term.c_lflag &= ~(ICANON);
//     tcsetattr(0, TCSANOW, &term);

//     // Use readline as usual
//     char* input = readline("Enter input: ");
//     printf("You entered: %s\n", input);

//     return 0;
// }

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <readline/readline.h>

// void disableAutomaticNewLine() {
//     struct termios term;
//     tcgetattr(STDIN_FILENO, &term);

//     term.c_lflag &= ~(ICANON | ECHO);
//     tcsetattr(STDIN_FILENO, TCSANOW, &term);
// }

// int main() {
//     // disableAutomaticNewLine();

//     char* input = readline("Enter input: ");
//     printf("You entered: %s\n", input);

//     return 0;
// }


#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

void disableAutomaticNewLine() {
    rl_prep_terminal(1);
}

int main() {
    disableAutomaticNewLine();

    char* input = readline("Enter input: ");
    printf("You entered: %s\n", input);

    return 0;
}
