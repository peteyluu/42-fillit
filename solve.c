/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:35:06 by pluu              #+#    #+#             */
/*   Updated: 2017/02/08 16:38:10 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	solve_helper(char *map)
{
	while (1)
	{
		if (solve(0, map, 'A'))
			break ;
		else
		{
			g_dim++;
			map = gen_map();
		}
	}
	ft_putstr(map);
}

int		solve(int k, char *map, char c)
{
	int		i;
	char	*dup_map;

	if (k == g_npieces)
		return (1);
	i = 0;
	while (i < g_dim_sq)
	{
		if (map[i] == '.')
		{
			dup_map = ft_strdup(map);
			if (is_safe(dup_map, i, g_pieces[k], c))
			{
				ft_memdel((void**)&dup_map);
				is_safe(map, i, g_pieces[k], c);
				if (solve(k + 1, map, c + 1))
					return (1);
				else
					remove_piece(&map, i, c);
			}
			ft_memdel((void**)&dup_map);
		}
		i++;
	}
	return (0);
}

void	remove_piece(char **amap, int i, char c)
{
	while (i < g_dim_sq)
	{
		if ((*amap)[i] == c)
			(*amap)[i] = '.';
		i++;
	}
}

int		is_safe(char *map, int i, char *s, char c)
{
	int	ndots;
	int flag;
	int z_flag;

	ndots = 0;
	flag = 0;
	z_flag = 0;
	while (i < g_dim_sq && (*s))
	{
		if (ndots >= 1)
			is_safe_helper(&i, &ndots);
		if (map[i] == '.' && *s == '#')
		{
			map[i] = c;
			s++;
			flag = 1;
		}
		else if (flag == 1 || z_flag == 1)
			break ;
		if (*s == '.')
			is_safe_helper2(&s, &ndots, &z_flag);
		i++;
	}
	return (*s == '\0' ? 1 : 0);
}
