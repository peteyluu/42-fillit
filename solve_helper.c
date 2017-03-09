/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:39:58 by pluu              #+#    #+#             */
/*   Updated: 2017/02/08 16:40:02 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_pieces(void)
{
	int	i;

	i = 0;
	while (i < g_npieces)
	{
		ft_memdel((void**)&g_pieces[i]);
		i++;
	}
	free(g_pieces);
	g_pieces = NULL;
}

void	is_safe_helper(int *ai, int *andots)
{
	*ai += *andots;
	*andots = 0;
}

void	is_safe_helper2(char **as, int *andots, int *az_flag)
{
	*andots = norm_dots(get_seg_dots(as));
	if (g_dim > 4)
		*az_flag = 1;
}

int		norm_dots(int n)
{
	if (g_dim == 2)
		n -= g_dim;
	else if (g_dim == 3)
		n--;
	else if (g_dim > 4)
	{
		if (n == 2)
			n = g_dim - n;
		else if (n == 3)
			n += (g_dim - n - 1);
		else
			n += (g_dim - n);
	}
	return (n);
}

void	add_new_line(char **amap)
{
	int i;
	int	tmp;

	i = 0;
	tmp = g_dim;
	while (i < g_dim_sq)
	{
		if (i == tmp)
		{
			(*amap)[tmp] = '\n';
			tmp += (g_dim + 1);
		}
		else
			(*amap)[i] = '.';
		i++;
	}
}
