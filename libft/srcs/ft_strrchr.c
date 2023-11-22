/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:40:24 by ialousse          #+#    #+#             */
/*   Updated: 2023/11/13 13:40:25 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	if (c == 0)
		return ((char *)s + ft_strlen((char *)s));
	len = ft_strlen((char *)s);
	while (len--)
		if (s[len] == c)
			return ((char *)s + len);
	return (0);
}
