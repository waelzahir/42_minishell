/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:24:48 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/13 18:38:38 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

int is_expanded(int type)
{
    if (type == arg || type == darg)
        return (1);
    return (0);
}

void    visitor(t_btree *root, char **env)
{
   if (!root)
    return ;
    visitor(root->l_child, env);
    visitor(root->r_child, env);
    if (root->num == CMD)
    {
        exec_fu(root->content, env);
    }
}



void    expan_iter(t_token   **token, char  **env)
{
    int i;

    i = 0;
    while (token[i])
    {
        if (is_expanded(token[i]->type))
            {
                token[i]->def = expander(token[i]->def, env);
            }
            i++;
    }
}
char    **get_redirection(t_token    **token)
{
    t_stack *red;
    char    **rdrec;
    int i;

    i = 0;
    red = init_stack();
    if (!red)
        return (printf("red alloc error\n"), NULL);
    while (token[i])
    {
        if (token[i]->type == redirec)
                push_stack(red, ft_strdup(token[i]->def));
        i++;
    }
    if (red->size == 0)
        return (free(red),  NULL);
    rdrec = (char   **)red->stack;
    return (rdrec);
}
void    apply_redir(char    **redir)
{
    int i = 0;
    if (!redir)
        return ;
    while (redir[i])
    {
        printf("%s\n", redir[i]);
        i++;
    }
}
char    *collector(char *s1, char   *s2)
{
    char    *ret;
    
    if (s1 && s2)
    {
        ret = ft_strjoin(s1, s2);    
        free(s1);
        free(s2);
        return (ret);
    }
    if (!s1 && s2)
    {
        ret = ft_strdup(s2);
        free(s2);
        return (ret);
    }
    if (s1 && !s2)
        {
            ret = ft_strdup(s1);
            free(s1);
            return ret;
        }
    return (NULL);
}
char    **join_cmd(t_token  **tokens)
{
    char    *join;
    t_stack *stack;
    int i;

    i = 0;
    stack = init_stack();
    join  = NULL;
    while (tokens[i])
    {
        if (tokens[i]->type == space && join)
        {
            push_stack(stack, join);
            join = NULL;
        }
        else if (tokens[i]->type == space && join != NULL)
        {
            free(tokens[i]->def);
            free(tokens[i]);
        }
        else
            join = collector(join, tokens[i]->def);
        i++;
    }
    if (join)
    push_stack(stack, join);

    return ((char   **)stack->stack);
}
char   **joining(t_token  **token)
{
    t_stack *clean;
     char   **val;
    int i;

    i = 0;
    clean   = init_stack();
    while (token[i])
    {
        if (token[i]->type == redirec)
            {
                free(token[i]->def);
                free(token[i]);
            }
            else
                push_stack(clean, token[i]);
        i++;
    }
    val =  join_cmd((t_token **)clean->stack);
    i = 0;
    while (val[i])
        {
            ft_putendl_fd(val[i], 1);
            i++;
        }
    free(clean);
    return (val);
}
void    exec_fu(t_token **token, char **env)
{
    char **redir;
    char    **cmd;
    //char    *path;

    expan_iter(token, env);
    redir = get_redirection(token);
    if (redir)
        apply_redir(redir);
    cmd = joining(token);
    int i;
    i = 0;
  
}