/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:48:52 by ialousse          #+#    #+#             */
/*   Updated: 2023/11/13 13:48:54 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	lst_first(t_cmd **list)
{
	if (list && *list)
		while ((*list)->prev)
			*list = (*list)->prev;
}

void	lst_last(t_cmd **list)
{
	if (list && *list)
		while ((*list)->next)
			*list = (*list)->next;
}

char	**sort_env(char **export)
{
	char	*tmp;
	int		i;
	int		j;

	j = -1;
	while (export[++j])
		;
	while (--j)
	{
		i = -1;
		while (export[++i + 1])
		{
			if (ft_strncmp(export[i], export[i + 1], ft_strlen(export[i])) > 0)
			{
				tmp = export[i];
				export[i] = export[i + 1];
				export[i + 1] = tmp;
			}
		}
	}
	return (export);
}
