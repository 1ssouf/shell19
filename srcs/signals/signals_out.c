/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_out.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:48:27 by ialousse          #+#    #+#             */
/*   Updated: 2023/11/13 13:48:29 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	sigint_cmd_heredoc_out(int code)
{
	(void)code;
	usleep(88);
	write(STDERR_FILENO, "\n", 2);
}

void	sigquit_cmd_out(int code)
{
	(void)code;
	write(STDERR_FILENO, "Quit: 3\n", 8);
}

void	sigint_cmd_out(int code)
{
	(void)code;
	write(STDERR_FILENO, "\n", 1);
}

void	sigquit_cmd_heredoc_out(int code)
{
	(void)code;
	printf("\r");
}
