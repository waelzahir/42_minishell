/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 01:16:48 by sel-kham          #+#    #+#             */
/*   Updated: 2022/08/16 15:53:25 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

/*
* Still needs ENV variables
*/

int	ft_cd(char **args)
{
	char	*home_path;

	if (!args)
		return (1);
	if (!args[1])
	{
		home_path = getenv("HOME");
		if (!home_path)
		{
			perror("Home :");
			return (1);
		}
		if (!chdir(home_path))
			return (0);
		perror("HOME: ");
		return (1);
	}
	if (!chdir(args[1]))
		return (0);
	perror("Directory: ");
	return (1);
}

int	main(int argc, char **argv)
{
	if (!argc || !argv)
		return (1);
	return (ft_cd(argv));
}
