/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:45:58 by ialousse          #+#    #+#             */
/*   Updated: 2023/11/13 13:45:59 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	write_exit_error(int b2o, char *arg)
{
	if (b2o)
	{
		ft_putstr_fd("minishell: exit: too many argument\n", STDERR_FILENO);
		return (1);
	}
	ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd(": numeric argument required", STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (255);
}

int	mini_exit(t_mini *shell, char **cmd)
{
	int	i;

	if (!cmd[1])
	{
		shell->exit = 1;
		return (shell->exit_status);
	}
	if (cmd[2])
		return (write_exit_error(1, cmd[1]));
	i = 0;
	while (cmd[1][i] && (ft_isdigit(cmd[1][i]) || cmd[1][i] == '-'))
		i++;
	if (cmd[1][i])
	{
		shell->exit = 1;
		return (write_exit_error(0, cmd[1]));
	}
	shell->exit = 1;
	return (ft_atoi(cmd[1]));
}
