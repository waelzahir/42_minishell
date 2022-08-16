/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 01:16:48 by sel-kham          #+#    #+#             */
/*   Updated: 2022/08/16 01:01:56 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

/*
* Still needs ENV variables
*/

int	ft_cd(char **args)
{
	char	*home_path;
	t_sdata	data;

	data.exit_status = 1;
	if (!args)
		return (data.exit_status);
	if (!args[1])
	{
		home_path = getenv("HOME");
		if (!home_path)
		{
			perror("Home :");
			return (data.exit_status);
		}
		if (!chdir(home_path))
			return (data.exit_status = 0);
		perror("HOME: ");
		return (data.exit_status);
	}
	if (!chdir(args[1]))
		return (data.exit_status = 0);
	perror("Directory: ");
	return (data.exit_status);
}

int	main(int argc, char **argv)
{
	if (!argc || !argv)
		return (1);
	return (ft_cd(argv));
}
