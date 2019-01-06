/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 17:38:39 by wta               #+#    #+#             */
/*   Updated: 2018/08/09 04:22:39 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long		sign;
	long		res;
	long		saved_res;

	sign = 1;
	res = 0;
	saved_res = 0;
	while (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r'
			|| *str == '\t' || *str == '\v')
		str++;
	sign = (*str == '-') ? -1 : 1;
	str = (*str == '-' || *str == '+') ? str + 1 : str;
	while (*str >= '0' && *str <= '9')
	{
		saved_res = res;
		if (sign == 1 && saved_res < 0)
			return (-1);
		else if (sign == -1 && saved_res < 0)
			return (0);
		res = res * 10 + (int)(*str++ - '0');
	}
	return (res * sign);
}
