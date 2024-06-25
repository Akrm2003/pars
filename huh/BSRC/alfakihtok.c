/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alfakihtok.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisalah <louisalah@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:47:20 by louisalah         #+#    #+#             */
/*   Updated: 2024/06/24 20:07:32 by louisalah        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *mystrchr(const char *str, const char c)
{
    while(*str)
    {
        if(*str == c) return (char *)str;
        str++;
    }
    return NULL;
}

unsigned int mystrspn(const char *s1, const char *s2)
{
    unsigned int len =0;
    //return 0 if any one is NULL
    if((s1 == NULL) || (s2 == NULL))
        return len;
    while(*s1 && mystrchr(s2,*s1++))
    {
        len++;
    }
    return len;
}

char *mystrpbrk(const char *str, const char *brk)
{
    while(*str)
    {
        if(mystrchr(brk, *str)) return (char *)str;
        str++;
    }
    return NULL;
}
char *mystrtok(char *s, const char *delim)
{
    static char *olds;
    char *token;

    if (s == NULL)
        s = olds;

    /* Scan leading delimiters.  */
    s += mystrspn(s, delim);

    /* if *s points to the null byte \0, that means
        we have reached the end of the string and
        we return NULL
    */
    if (s && *s == '\0')
    {
        olds = s;
        return (NULL);
    }

    /* Find the end of the token.  */
    token = s;
    s = mystrpbrk(token, delim);
    if (s == NULL)
        /* This token finishes the string.  */
        olds = mystrchr(token, '\0');
    else
    {
        /* Terminate the token and make OLDS point past it.  */
        *s = '\0';
        olds = s + 1;
    }
    return (token);
}