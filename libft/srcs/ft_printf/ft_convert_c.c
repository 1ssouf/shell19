/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:34:26 by ialousse          #+#    #+#             */
/*   Updated: 2023/11/13 13:34:27 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_get_c(int c)
{
	int	i;

	i = 0;
	if (g_flag == '*')
		while (i++ < g_prec1 - 1)
			write(1, " ", 1);
	else if (g_flag == '0')
		while (i++ < g_prec1 - 1)
			write(1, "0", 1);
	ft_putchar_fd(c, 1);
	if (g_flag == '-')
		while (i++ < g_prec1 - 1)
			write(1, " ", 1);
	return (ft_ternint(g_prec1 && g_flag != '.', g_prec1, 1));
}
