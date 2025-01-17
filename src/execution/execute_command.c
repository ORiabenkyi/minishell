/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tavdiiev <tavdiiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:10:59 by tavdiiev          #+#    #+#             */
/*   Updated: 2024/11/03 16:30:33 by tavdiiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

int	execute_builtin(t_data *data, t_command *cmd)
{
	printf("in execute_builtin\n");
	if (ft_strncmp(cmd->name, "cd", 3) == 0)
		return(cd(data, cmd->args));
	else if (ft_strncmp(cmd->name, "echo", 5) == 0)
		return(echo(cmd->args));
	else if (ft_strncmp(cmd->name, "env", 4) == 0)
		return(env(data, cmd->args));
	else if (ft_strncmp(cmd->name, "export", 7) == 0)
		return(export(data, cmd->args));
	else if (ft_strncmp(cmd->name, "pwd", 4) == 0)
		return(pwd());
	else if (ft_strncmp(cmd->name, "unset", 6) == 0)
		return(unset(data, cmd->args));
	else if (ft_strncmp(cmd->name, "exit", 5) == 0)
		return(ft_exit(data, cmd->args));
	return (CMD_NOT_FOUND);
}

static int execute_external_command(t_data *data, t_command *cmd)
{
	printf("in execute_external_command\n");
		// printf("cmd->args[0]=%s\n", cmd->args[1]);
	if (!cmd->name || cmd->name[0] == '\0')
		return (CMD_NOT_FOUND);
	if (command_is_dir(cmd->name))
		return (CMD_NOT_FOUND);
	cmd->path = get_valid_command_path(data, cmd->name);
	if (!cmd->path)
		return (CMD_NOT_FOUND);
	printf("in execute_external_command before execve\n");
	printf("cmd->path=%s\n", cmd->path);
	if (execve(cmd->path, cmd->args, data->env) == -1)
		error_msg_command("execve", NULL, strerror(errno), errno);
	return (EXIT_FAILURE);
}

//If the command is in the current directory, you need to use ./command to run it:
// ./command - exe file in the current directory
//if command is not a built-in or external shell command but an executable file present 
//in a specific location on the filesystem:
// /usr/local/bin/command if the command is in /usr/local/bin.
//or if it is a built-in command, like ls: /usr/bin/ls
static int	execute_local_binary_or_absolute_path(t_data *data, t_command *cmd)
{
	printf("in execute_local_binary_or_absolute_path\n");
	int status;

	status = is_command_not_found_or_not_executable(data, cmd);
	if (status)
		return (status);
	if (execve(cmd->name, cmd->args, data->env) == -1)
		return (error_msg_command("execve", NULL, strerror(errno), errno));
	return (EXIT_FAILURE);
}

int	execute_command(t_data *data, t_command *current_command)
{
	int	status;
	
	printf("in execute_command\n");
	printf("command->name=%s\n", current_command->name);
	if (!current_command || !current_command->name)
		exit_shell(data, error_msg_command("child", NULL,
				"parsing error: no command to execute!", EXIT_FAILURE));
	if (!is_valid_fd_or_no_fd(current_command->io))
		exit_shell(data, EXIT_FAILURE);
	redirect_io_pipe(data->cmd, current_command);
	redirect_io_file(current_command->io);
	close_fds(data->cmd, false);
	if (!ft_strchr(current_command->name, '/'))
	{
		status = execute_builtin(data, current_command);
		// printf("status after execute_builtin=%d\n", status);//in case of a pipe redirection the output goes to the pipe
		if (status != CMD_NOT_FOUND)//if it is a builtin command
		exit_shell(data, status);
		status = execute_external_command(data, current_command);
		// printf("status after execute_external_command=%d\n", status);//not printed if successful
		if (status != CMD_NOT_FOUND)
		exit_shell(data, status);
	}
	status = execute_local_binary_or_absolute_path(data, current_command);// contains '/' or doesn't contain '/' (not builtin and not external)
	exit_shell(data, status);
	return (status);
}
