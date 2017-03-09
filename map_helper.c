/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:54:23 by pluu              #+#    #+#             */
/*   Updated: 2017/02/08 17:29:27 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_seg_dots(char **as)
{
	int	ndots;

	ndots = 0;
	while (**as != '#')
	{
		ndots++;
		(*as)++;
	}
	return (ndots);
}

int		get_dim(int len)
{
	int	len_sq;
	int	big_sq;
	int sq;
	int	normsucks;

	normsucks = g_npieces * 4;
	len_sq = len * len;
	sq = get_big_sq(normsucks);
	big_sq = sq * sq;
	if (g_npieces == 1 || len_sq > big_sq)
		return (len);
	return (sq);
}

int		get_big_sq(int num)
{
	int	i;
	int	sq;

	i = 2;
	while (1)
	{
		sq = i * i;
		if (sq == num)
			return (i);
		else if (sq > num)
			break ;
		else
			return (i);
		i++;
	}
	return (i);
}

int		get_num_dots(char *s)
{
	int	dots;
	int flag;

	dots = 0;
	flag = 0;
	while (*s)
	{
		if (*s == '.')
		{
			dots++;
			flag = 1;
		}
		else if (flag == 1)
			break ;
		s++;
	}
	return (dots);
}
