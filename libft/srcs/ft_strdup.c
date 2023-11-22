/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:39:23 by ialousse          #+#    #+#             */
/*   Updated: 2023/11/13 13:39:25 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *str)
{
	char	*pt;
	int		size;

	size = ft_strlen(str);
	pt = (char *)ft_calloc(sizeof(char), (size + 1));
	if (!pt)
		return (0);
	size = 0;
	while (*str)
		pt[size++] = *str++;
	return (pt);
}
