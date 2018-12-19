/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 18:19:46 by wta               #+#    #+#             */
/*   Updated: 2018/12/19 15:27:57 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include "../libft/includes/libft.h"
#include "filler.h"

int	main(void)
{
	t_info	info;

	init_info(&info);
	if (get_player(&info) == 0)
		return (0);
	if (get_map_info(&info) == 0)
		return (0);
	ft_putnbr_fd(info.width, 2);
	ft_putnbr_fd(info.height, 2);
	ft_printf("0 0\n");
	return (0);
}
