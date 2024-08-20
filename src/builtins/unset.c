/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tavdiiev <tavdiiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:45:42 by tavdiiev          #+#    #+#             */
/*   Updated: 2024/08/19 20:43:20 by tavdiiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

int	unset(t_data *data, char **args)
{
	int	i;
	int	env_var_index;

	i = 1;
	while (args[i])
	{
		if (!is_valid_key(args[i]))
			return (EXIT_FAILURE);
		else
		{
			env_var_index = get_env_index(data->env, args[i]);
			if (env_var_index != -1)
				unset_env(data, env_var_index);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
