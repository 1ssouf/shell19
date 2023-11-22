/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:48:33 by ialousse          #+#    #+#             */
/*   Updated: 2023/11/13 13:48:35 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	set_sig_cmd_in(t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp)
	{
		if (tmp->heredoc)
			return (sig_cmd_heredoc_in());
		tmp = tmp->next;
	}
	return (sig_cmd_in());
}

int	set_sig_cmd_out(t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp)
	{
		if (tmp->heredoc)
			return (sig_cmd_heredoc_out());
		tmp = tmp->next;
	}
	return (sig_cmd_out());
}
