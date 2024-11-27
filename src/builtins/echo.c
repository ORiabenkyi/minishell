/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tavdiiev <tavdiiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:53:39 by tavdiiev          #+#    #+#             */
/*   Updated: 2024/10/05 20:33:21 by tavdiiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

//check if there's only one '-' 
//followed by one or multiple 'n' in the string
static bool is_only_n(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] != '-' || (arg[i] == '-' && arg[i + 1] == '\0'))
		return (false);
	i++;
	while (arg[i] && arg[i] == 'n')
		i++;
	if (arg[i] == '\0')
		return (true);
	return (false);
}

static void	print_args(char **args, bool is_only_n_fl, int i)
{
	if (!args[i] && !is_only_n_fl)
	{
	ft_putchar_fd('\n', STDOUT_FILENO);
	return ;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], STDOUT_FILENO);
		if (args[i + 1])
			ft_putchar_fd(' ', STDOUT_FILENO);
		else if (!args[i + 1] && !is_only_n_fl)
			ft_putchar_fd('\n', STDOUT_FILENO);
		i++;
	}
}

//echo -nnnn -n string and echo -n -n -n -n string
//same as echo -n string
int	echo(char **args)
{
	int		i;
	bool	is_only_n_fl;

	is_only_n_fl = false;
	i = 1;
	while (args[i] && is_only_n(args[i]))
	{
		is_only_n_fl = true;
		i++;
	}
	print_args(args, is_only_n_fl, i);
	return (EXIT_SUCCESS);
}
