/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:46:37 by ialousse          #+#    #+#             */
/*   Updated: 2023/11/13 13:46:38 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pipe_child(t_cmd *tmp, int *pfd, int fdin, t_mini *shell)
{
	if (!tmp->heredoc)
		dup2(fdin, STDIN_FILENO);
	if (tmp->heredoc)
		mini_heredoc(tmp);
	if (tmp->next)
		dup2(pfd[1], STDOUT_FILENO);
	close(pfd[0]);
	if (!tmp->str[0])
		exit(0);
	if (mini_inout(shell, tmp))
		exit(1);
	if (tmp && !builts_in(shell, tmp->str))
	{
		if (exec_bin(tmp->str, shell))
			return ;
	}
	exit(shell->exit_status);
}

void	close_my_pipes(int *pfd, t_mini *shell, pid_t pid)
{
	int		status;
	int		i;
	pid_t	pid2;

	pid2 = waitpid(-1, &status, 0);
	while (pid2 > 0)
	{
		if (pid2 == pid)
		{
			i = -1;
			while (++i < (shell->nb_cmds) * 2)
				close(pfd[i]);
			if (WIFEXITED(status))
				shell->exit_status = WEXITSTATUS(status);
		}
		pid2 = waitpid(-1, &status, 0);
	}
	free(pfd);
}

int	pipes(t_mini *shell, int *pfd)
{
	int		fdin;
	int		i;
	pid_t	pid;
	t_cmd	*tmp;

	fdin = 420;
	tmp = shell->cmd;
	i = 0;
	while (tmp)
	{
		set_sig_cmd_out(shell->cmd);
		pid = fork();
		if (!pid && set_sig_cmd_in(tmp))
			pipe_child(tmp, pfd + i, fdin, shell);
		close(pfd[i + 1]);
		fdin = pfd[i];
		tmp = tmp->next;
		i += 2;
	}
	close_my_pipes(pfd, shell, pid);
	return (0);
}
