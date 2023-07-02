#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    // Set the prompt text
    rl_set_prompt("minishell> ");

    // Read and process user input
    char* input;
    while ((input = readline("Prompt: ")) != NULL) {
        // Process the input here

        // Add the input to the readline history
        // add_history(input);

        // Move to the beginning of the current line

        // Set the prompt and display it on the same line
        // rl_set_prompt("minishell> ");
        rl_
        rl_replace_line("", 0);
        rl_on_new_line();
        rl_redisplay();
    }

    return 0;
}