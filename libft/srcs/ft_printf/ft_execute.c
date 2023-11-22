/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:35:00 by ialousse          #+#    #+#             */
/*   Updated: 2023/11/13 13:35:02 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	ft_ajust_elem(void)
{
	if (g_flag && g_flag != '.' && g_prec1 < 0)
	{
		g_flag = '-';
		g_prec1 = -g_prec1;
	}
	if (g_flag == '.' && g_prec1 < 0)
	{
		g_flag = 0;
		g_prec1 = 0;
	}
	if (g_point && g_prec2 < 0)
	{
		g_point = 0;
		g_prec2 = 0;
	}
}

int	ft_get_element(const char **string)
{
	(*string)++;
	ft_set_element();
	g_flag = ft_get_first_flag(string);
	ft_get_first_precision(string);
	ft_get_second(string);
	ft_ajust_elem();
	g_res = ft_execute(string, "sicxXupd%", -1, "0123456789abcdef");
	if (g_error)
		return (-1);
	return (g_res);
}
