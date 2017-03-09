/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:47:42 by pluu              #+#    #+#             */
/*   Updated: 2017/02/08 18:44:01 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	*map;

	g_npieces = 0;
	if (argc == 2)
	{
		if (!first_read(*(argv + 1)) || g_npieces == 0)
		{
			ft_putstr("error\n");
			exit(2);
		}
		g_pieces = (char**)malloc(sizeof(char*) * (g_npieces + 1));
		second_read(*(argv + 1));
		g_dim = get_dim(get_len_pieces());
		map = gen_map();
		solve_helper(map);
		ft_memdel((void**)&map);
		free_pieces();
	}
	else
	{
		ft_putstr("usage: ./fillit input_file\n");
		exit(1);
	}
	return (0);
}
