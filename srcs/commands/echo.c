/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:45:52 by ialousse          #+#    #+#             */
/*   Updated: 2023/11/13 13:45:54 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	norm(char **cmd, int *no_backslash)
{
	int	tmp;
	int	i;

	tmp = 0;
	i = 1;
	while (cmd[i] && !ft_strncmp(cmd[i], "-n", 2))
	{
		while (cmd[i][++tmp])
		{
			if (cmd[i][tmp] != 'n' || cmd[i][0] != '-')
			{
				tmp = -1;
				break ;
			}
		}
		if (tmp == -1)
			break ;
		*no_backslash = 1;
		i++;
	}
	return (i);
}

int	echo(char **cmd)
{
	int	no_backslash;
	int	i;

	if (!cmd[1])
	{
		printf("\n");
		return (0);
	}
	no_backslash = 0;
	i = norm(cmd, &no_backslash);
	if (!cmd[i])
		return (0);
	while (cmd[i])
	{
		printf("%s", cmd[i++]);
		if (cmd[i])
			printf(" ");
	}
	if (!no_backslash)
		printf("\n");
	return (0);
}
