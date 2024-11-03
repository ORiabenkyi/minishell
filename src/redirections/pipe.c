/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tavdiiev <tavdiiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:03:51 by tavdiiev          #+#    #+#             */
/*   Updated: 2024/11/03 16:41:00 by tavdiiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

bool	create_pipes(t_data *data)
{
	t_command	*curr_command;

	curr_command = data->cmd;
	printf("in create_pipes\n");
	while (curr_command)
	{
		printf("in while create pipes\n");
		printf("curr_command->name=%s\n", curr_command->name);
		if (curr_command->next)
		{
			printf("in if create pipes\n");
			curr_command->pipe_fd = malloc(sizeof(*curr_command->pipe_fd) * 2);
			if (!curr_command->pipe_fd || pipe(curr_command->pipe_fd) != 0)
			{
			// 	free_data(data, false);//todo
				return (false);
			}
		}
		curr_command = curr_command->next;
	}
	printf("the end of create_pipes\n");
	return (true);
}

void	close_pipe_fds(t_command *command_list, t_command *current_command)
{
	while (command_list)
	{
		if (command_list != current_command && command_list->pipe_fd)
		{
			close(command_list->pipe_fd[0]);
			close(command_list->pipe_fd[1]);
		}
		command_list = command_list->next;
	}
}

bool	redirect_io_pipe(t_command *command_list, t_command *current_command)
{
	printf("in redirect_io_pipe\n");
	if (!current_command)
		return (false);
	if (current_command->prev)//todo && current_command->prev->is_piped
		dup2(current_command->prev->pipe_fd[0], STDIN_FILENO);//Redirect stdin to pipe read end
	if (current_command->next)//if (this_cmd->is_piped), if it is the 1st command in a pipe line
		dup2(current_command->pipe_fd[1], STDOUT_FILENO);//Redirect stdout to pipe write end		
	close_pipe_fds(command_list, current_command);
	printf("the end of redirect_io_pipe\n");
	return (true);
}
