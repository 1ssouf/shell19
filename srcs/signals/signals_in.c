/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:48:21 by ialousse          #+#    #+#             */
/*   Updated: 2023/11/13 13:48:23 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	sigint_cmd_heredoc_in(int code)
{
	(void)code;
	usleep(88);
	exit(130);
}

void	sigint_cmd_in(int code)
{
	(void)code;
	exit(130);
}

void	sigquit_cmd_in(int code)
{
	(void)code;
	exit(131);
}

void	sigquit_cmd_heredoc_in(int code)
{
	(void)code;
	rl_on_new_line();
	rl_redisplay();
}
