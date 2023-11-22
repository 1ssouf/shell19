/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:35:11 by ialousse          #+#    #+#             */
/*   Updated: 2023/11/13 13:35:13 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_set_element(void)
{
	g_percent = '\0';
	g_flag = '\0';
	g_point = 0;
	g_prec1 = 0;
	g_prec2 = 0;
	g_res = 0;
	g_error = 0;
}

int	ft_printf(const char *string, ...)
{
	int	result;

	result = 0;
	if (!string)
		return (0);
	va_start(g_arg, string);
	while (*string)
	{
		ft_set_element();
		if (!(*string == '%'))
		{
			result++;
			write(1, string, 1);
		}
		else if (ft_get_element(&string) == -1)
			return (result);
		result += g_res;
		string++;
	}
	va_end(g_arg);
	return (result);
}
