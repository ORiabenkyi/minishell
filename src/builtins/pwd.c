/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tavdiiev <tavdiiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 20:31:41 by tavdiiev          #+#    #+#             */
/*   Updated: 2024/10/11 20:48:19 by tavdiiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

int pwd(void)
{
	char	buf[PATH_MAX];

	if (!getcwd(buf, PATH_MAX))
		error_msg_command("pwd", NULL, strerror(errno), errno);
	else
	{
		ft_putendl_fd(buf, STDOUT_FILENO);
		return (EXIT_SUCCESS);		
	}
	return (EXIT_FAILURE);
}
