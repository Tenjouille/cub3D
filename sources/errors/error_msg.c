/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:42:40 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/08 11:42:41 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	ft_map_error_msg(void)
{
	ft_putstr_fd("Error\n Bad map configuration.\nHere is an exemple of ", 2);
	ft_putstr_fd("valid map to run cu3D : \n\nNO ./path_to_north_texture\n", 2);
	ft_putstr_fd("SO ./path_to_south_texture\nWE ./path_to_west_texture\n", 2);
	ft_putstr_fd("EA ./path_to_the_east_texture\nF 255,0,0\nC 0,0,255\n", 2);
	ft_putstr_fd("111111\n100101\n101001\n1100N1\n111111\n", 2);
}
