/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tavdiiev <tavdiiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:55:18 by tavdiiev          #+#    #+#             */
/*   Updated: 2024/08/10 21:07:14 by tavdiiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

static int	check_data_create_pipes(t_data *data)
{
	printf("data=%p\ndata->cmd=%p\n", data, data->cmd);
	printf("data->cmd->name=%s\n", data->cmd->name);
	if (!data || !data->cmd)
	{
		printf("!data || !data->cmd\n");
		return (EXIT_SUCCESS);
	}
	if (!data->cmd->name)//no commands only infile or outfile
	{
		printf("if (!data->cmd->name)\n");
		printf("data->cmd->io=%p\n", data->cmd->io);
		if (data->cmd->io
			&& !is_valid_fd(data->cmd->io))
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	if (!create_pipes(data))//create pipes if needed
		return (EXIT_FAILURE);
	return (CMD_NOT_FOUND);
}

static int	wait_children(t_data *data)
{
	pid_t	wpid;
	int		status;
	int		save_status;

	close_fds(data->cmd, false);
	save_status = 0;
	wpid = 0;
	while (wpid != -1 || errno != ECHILD)
	{
		wpid = waitpid(-1, &status, 0);
		if (wpid == data->pid)
			save_status = status;
		continue ;
	}
	if (WIFSIGNALED(save_status))
		status = 128 + WTERMSIG(save_status);
	else if (WIFEXITED(save_status))
		status = WEXITSTATUS(save_status);
	else
		status = save_status;
			printf("wait_children: status=%d\n", status);
	return (status);
}

static int	create_children(t_data *data)
{
	t_command	*current_command;

printf("in create_children\n");
int status_execute_command;
	current_command = data->cmd;
	while (data->pid != 0 && current_command)
	{
		data->pid = fork();
		if (data->pid == -1)
			return (error_msg_command("fork", NULL, strerror(errno), EXIT_FAILURE));
		else if (data->pid == 0)
			status_execute_command = execute_command(data, current_command);
		current_command = current_command->next;
	}
	printf("status_execute_command=%d\n", status_execute_command);//not printed if succesfull
	return (wait_children(data));
}

int	execute(t_data *data)
{
	int	status;

	status = check_data_create_pipes(data);
		printf("status after check_data_create_pipes=%d\n", status);
	if (status != CMD_NOT_FOUND)
		return (status);
	printf("data->cmd->is_piped=%d\n", data->cmd->is_piped);
	if (!data->cmd->is_piped && !data->cmd->prev
	&& is_valid_fd(data->cmd->io))//no pipes, no prev command
	{
		redirect_io_file(data->cmd->io);
		status = execute_builtin(data, data->cmd);
		restore_stdin_stdout(data->cmd->io);
	}
	printf("the end of execute, status=%d\n", status);
	if (status != CMD_NOT_FOUND)//builtin
		return (status);
	return (create_children(data));//not builtins
}