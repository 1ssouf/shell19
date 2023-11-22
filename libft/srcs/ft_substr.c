/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:40:34 by ialousse          #+#    #+#             */
/*   Updated: 2023/11/13 13:40:36 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*pt;

	if (!s)
		return (0);
	i = -1;
	if (ft_strlen(s) < start)
	{
		pt = (char *)ft_calloc(sizeof(char), 1);
		if (!pt)
			return (0);
		return (pt);
	}
	pt = (char *)ft_calloc(sizeof(char), len + 1);
	if (!pt)
		return (0);
	while (++i < len)
		pt[i] = s[start + i];
	return (pt);
}
