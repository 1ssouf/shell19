/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:38:15 by ialousse          #+#    #+#             */
/*   Updated: 2023/11/13 13:38:16 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*src_bis;
	char		*dst_bis;

	dst_bis = (char *)dst;
	src_bis = (const char *)src;
	if (!dst_bis && !src_bis)
		return (0);
	while (n-- > 0)
		dst_bis[n] = src_bis[n];
	return ((void *)dst_bis);
}
