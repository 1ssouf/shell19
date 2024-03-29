/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:46:31 by ialousse          #+#    #+#             */
/*   Updated: 2023/11/13 13:46:33 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exec_bin(char **cmd, t_mini *shell)
{
	char	*path;
	pid_t	pid;
	int		status;

	pid = fork();
	if (!pid)
	{
		if (!cmd)
			exit(1);
		path = pathfinder(cmd[0], shell->env);
		if (!path || execve(path, cmd, shell->basic_env) == -1)
		{
			ft_putstr_fd("minishell: ", STDERR_FILENO);
			ft_putstr_fd(cmd[0], STDERR_FILENO);
			ft_putstr_fd(": command not found\n", STDERR_FILENO);
			exit(127);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			shell->exit_status = WEXITSTATUS(status);
	}
	return (0);
}

int	builts_in(t_mini *shell, char **cmd)
{
	if (!cmd)
		return (0);
	if (!ft_strncmp(cmd[0], "pwd", 4))
		shell->exit_status = pwd(shell->env, cmd);
	else if (!ft_strncmp(cmd[0], "env", 4))
		shell->exit_status = aff_env(shell->env, cmd);
	else if (!ft_strncmp(cmd[0], "exit", 5))
		shell->exit_status = mini_exit(shell, cmd);
	else if (!ft_strncmp(cmd[0], "export", 7))
		shell->exit_status = export(shell->env, cmd, shell);
	else if (!ft_strncmp(cmd[0], "unset", 6))
		shell->exit_status = unset(cmd, shell->env, shell);
	else if (!ft_strncmp(cmd[0], "echo", 5))
		shell->exit_status = echo(cmd);
	else if (!ft_strncmp(cmd[0], "cd", 3))
		shell->exit_status = cd(shell, cmd);
	else
		return (0);
	return (1);
}
