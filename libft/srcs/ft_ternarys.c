/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ternarys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:40:39 by ialousse          #+#    #+#             */
/*   Updated: 2023/11/13 13:40:41 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_ternint(int boolean, int a, int b)
{
	if (boolean)
		return (a);
	return (b);
}

char	ft_ternchar(int boolean, char a, char b)
{
	if (boolean)
		return (a);
	return (b);
}

unsigned long	ft_ternul(int boolean, unsigned long a, unsigned long b)
{
	if (boolean)
		return (a);
	return (b);
}
