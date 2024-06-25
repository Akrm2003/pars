#include "minishell.h"

int main(){
    char        *str;
    t_tokens    *token;

    while(42)
    {
        printf("minishell > \n");
        str = get_next_line(0);
        check_quotes(str);
        // const char* input = "input.txt < cmd1 | cmd2 > out1 >> out2 >> out3";
        token = tokenize_by_pipe(str);
        print_tokens(token);
        free_tokens(token);
        // printf("str = %s\n", str);
    }
    return (0);
}
        // if (ft_strchr(str, '\"'))
        //     return (1);