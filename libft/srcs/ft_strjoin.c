/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:39:33 by ialousse          #+#    #+#             */
/*   Updated: 2023/11/13 13:39:35 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*pt;

	pt = (char *)ft_calloc(sizeof(char), \
					(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!pt)
		return (0);
	i = -1;
	while (s1 && s1[++i])
		pt[i] = s1[i];
	i -= 1;
	while (s2 && s2[++i - ft_strlen(s1)])
		pt[i] = s2[i - ft_strlen(s1)];
	return (pt);
}
