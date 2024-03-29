/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:48:41 by ialousse          #+#    #+#             */
/*   Updated: 2023/11/13 13:48:42 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_env(t_env *env)
{
	t_env	*tmp;

	if (!env)
		return ;
	while (env->next)
	{
		tmp = env;
		env = env->next;
		free(tmp->str);
		free(tmp);
	}
	free(env->str);
	free(env);
}

void	free_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;

	lst_first(&cmd);
	if (!cmd)
		return ;
	while (cmd)
	{
		tmp = cmd;
		if (cmd->fdin)
			free(cmd->fdin);
		if (cmd->fdout)
			free(cmd->fdout);
		if (cmd->str)
			free_double_char(cmd->str);
		if (cmd->limit_string)
			free_double_char(cmd->limit_string);
		cmd = cmd->next;
		free(tmp);
	}
	free(cmd);
}

void	free_double_char(char **str)
{
	int	i;

	if (!str)
		return ;
	i = -1;
	while (str[++i])
		free(str[i]);
	free(str[i]);
	free(str);
}
