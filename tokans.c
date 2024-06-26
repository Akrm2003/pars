/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokans.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asid-ahm <asid-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:42:01 by asid-ahm          #+#    #+#             */
/*   Updated: 2024/06/25 14:46:00 by asid-ahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define PIPE_TOKEN 1
#define COMMAND_TOKEN 2
// Function to create a new token
t_tokens* create_token(int type, const char* command) {
    t_tokens* new_token = (t_tokens*)malloc(sizeof(t_tokens));
    new_token->type = type;
    new_token->cmd = ft_strdup(command);
    new_token->next = NULL;
    return new_token;
}

// Function to append a token to the token list
void append_token(t_tokens** head, t_tokens* new_token) {
    if (*head == NULL) {
        *head = new_token;
    } else {
        t_tokens* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_token;
    }
}

// Function to tokenize the input string based on pipes
t_tokens    *tokenize_by_pipe(const char* input) {
    t_tokens    *head = NULL;
    char* input_copy = ft_strdup(input); // Make a copy of the input string
    char* token_str = mystrtok(input_copy, "|");

    while (token_str != NULL) {
        // Trim leading and trailing whitespace
        while (*token_str == ' ') token_str++;
        char* end = token_str + ft_strlen(token_str) - 1;
        while (end > token_str && *end == ' ') end--;
        *(end + 1) = '\0';

        // Create a command token
        t_tokens* new_token = create_token(COMMAND_TOKEN, token_str);
        append_token(&head, new_token);

        // Move to the next token
        token_str = mystrtok(NULL, "|");
        if (token_str != NULL) {
            // Create a pipe token
            t_tokens* pipe_token = create_token(PIPE_TOKEN, "|");
            append_token(&head, pipe_token);
        }
    }

    free(input_copy);
    return head;
}

// Function to print tokens for debugging
void print_tokens(t_tokens* head) {
    t_tokens* temp = head;
    while (temp != NULL) {
        printf("Type: %d, Command: %s\n", temp->type, temp->cmd);
        temp = temp->next;
    }
}

// Function to free the token list
void free_tokens(t_tokens* head) {
    t_tokens* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp->cmd);
        free(temp);
    }
}

// int main() {
//     const char* input = "input.txt < cmd1 | cmd2 > out1 >> out2 >> out3";
//     t_tokens* tokens = tokenize_by_pipe(input);
//     print_tokens(tokens);
//     free_tokens(tokens);
//     return 0;
// }

