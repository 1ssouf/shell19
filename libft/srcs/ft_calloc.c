/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:36:15 by ialousse          #+#    #+#             */
/*   Updated: 2023/11/13 13:36:16 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pt;

	pt = (char *)malloc(count * size * sizeof(void));
	if (!pt)
		return (0);
	ft_bzero(pt, count * size);
	return ((void *)pt);
}
