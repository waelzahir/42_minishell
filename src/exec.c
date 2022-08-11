/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:24:48 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/11 18:04:55 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

void    visitor(t_btree *root, char **env)
{
   if (!root)
    return ;
    visitor(root->l_child, env);
    visitor(root->r_child, env);
    if (root->e_type == CMD)
    {
        exec_fu(root->content, env);
    }
}
int is_expanded(int type)
{
    if (type == arg || type == darg)
        return (1);
    return (0);
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
                printf("%s \n", token[i]->def);
            }
            i++;
    }
}
void    exec_fu(t_token **token, char **env)
{
    expan_iter(token, env);
}