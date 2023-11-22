/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:47:49 by ialousse          #+#    #+#             */
/*   Updated: 2023/11/13 13:47:51 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	stop_parse_error(t_mini *shell)
{
	t_cmd	*tmp;

	tmp = shell->cmd;
	lst_first(&tmp);
	while (tmp)
	{
		if (tmp->end_parse_error)
		{
			shell->nb_cmds = 0;
			free_cmd(tmp);
			shell->cmd = NULL;
			return ;
		}
		tmp = tmp->next;
	}
}

void	parser(char *ans, t_mini *shell)
{
	shell->cmd = NULL;
	shell->nb_cmds = check_operator(ans, shell);
	stop_parse_error(shell);
	if (!shell->nb_cmds)
		return ;
	replace_spec_char(shell);
}
