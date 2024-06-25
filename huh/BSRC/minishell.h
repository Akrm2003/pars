#ifndef MINISHELL_H
# define MINISHELL_H

# include <string.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/SRC/libft.h"

/*
    yooo we need to sit together soon 
    what i understood was the pipe is on a level on its own
    its like a delemiter for example
    (< input cmd1 -flag | cmd2 > out1 > out2 >> out3) = {in tokens}
    token1 = (< input cmd1 -flag) command
    token2 = | pipe
    token3 = (out1 > out2 >> out3)
    we need to discuss the aproach
*/
///// still not sure on how we will handle quotes
typedef struct s_tokens {
    int             type;
    char            *cmd;
    struct s_tokens *next;
} t_tokens; /// this is seprated by pipes

// typedef struct s_cmd{
    
// } t_cmd;


int         update_quote_state(char current_char , int *quote_state);
int         check_quotes(char *command);
char	    *get_next_line(int fd);
char	    *get_ft_strjoin(char *s1, char *s2);
char	    *get_ft_strchr(const char *s, int c);
char        *mystrtok(char *s, const char *delim);
t_tokens    *create_token(int type, const char* command);
t_tokens    *tokenize_by_pipe(const char* input);
void        append_token(t_tokens **head, t_tokens *new_token);
void        print_tokens(t_tokens *head);
void        free_tokens(t_tokens *head);

#endif