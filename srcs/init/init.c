/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:46:55 by ialousse          #+#    #+#             */
/*   Updated: 2023/11/13 13:46:57 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	check_env(t_mini *shell)
{
	t_env	*tmp;
	char	new_pwd[200];
	char	*var;

	var = NULL;
	tmp = shell->env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->str, "PWD", 3))
			break ;
		tmp = tmp->next;
	}
	if (!tmp)
	{
		var = ft_strdup("PWD=");
		getcwd(new_pwd, 200);
		var = ft_strjoin_gnl(var, new_pwd);
		export_name(var, shell->env, shell);
		free(var);
	}
}

int	init(t_mini *shell, char **env)
{
	shell->cmd = NULL;
	shell->basic_env = env;
	shell->exit = 0;
	shell->fdin = 0;
	shell->fdout = 1;
	if (init_env(shell, env))
		return (1);
	check_env(shell);
	up_shlvl(shell);
	return (0);
}
