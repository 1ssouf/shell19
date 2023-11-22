/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:39:54 by ialousse          #+#    #+#             */
/*   Updated: 2023/11/13 13:39:58 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*res;

	if (!s || !f)
		return (0);
	i = -1;
	res = (char *)ft_calloc(sizeof(char), ft_strlen(s) + 1);
	if (!res)
		return (0);
	while (++i < ft_strlen(s))
		res[i] = f(i, s[i]);
	return (res);
}
