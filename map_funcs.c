/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:37:24 by pluu              #+#    #+#             */
/*   Updated: 2017/02/08 16:37:57 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*gen_map(void)
{
	char	*map;

	g_dim_sq = g_dim * g_dim + g_dim;
	map = ft_strnew(g_dim_sq);
	add_new_line(&map);
	return (map);
}

int		get_len_pieces(void)
{
	int	i;
	int z_case;
	int	tmp_len;
	int max_len;
	int	h_v_len[2];

	i = -1;
	max_len = 0;
	while (++i < g_npieces)
	{
		h_v_len[0] = get_hort_len(g_pieces[i]);
		h_v_len[1] = get_vert_len(g_pieces[i]);
		tmp_len = (h_v_len[0] > h_v_len[1]) ? h_v_len[0] : h_v_len[1];
		if (h_v_len[0] == h_v_len[1])
		{
			if ((z_case = get_num_dots(g_pieces[i])) == 2 || z_case == 4)
				tmp_len++;
		}
		if (tmp_len > max_len || tmp_len == 4)
		{
			if ((max_len = tmp_len) == 4)
				return (max_len);
		}
	}
	return (max_len);
}

int		get_vert_len(char *s)
{
	int	len;
	int flag;

	len = 0;
	flag = 0;
	while (*s)
	{
		if (*s == '#' && flag == 0)
		{
			len++;
			flag = 1;
		}
		else if (*s == '.')
			flag = 0;
		if (len == 4)
			return (4);
		s++;
	}
	return (len);
}

int		get_hort_len(char *s)
{
	int	long_len;
	int	curr_len;

	long_len = 0;
	curr_len = 0;
	while (*s)
	{
		if (*s == '#')
			curr_len++;
		else if (curr_len > long_len)
		{
			if ((long_len = curr_len) == 4)
				return (4);
			curr_len = 0;
		}
		else
			curr_len = 0;
		s++;
	}
	if (curr_len > long_len)
		long_len = curr_len;
	return (long_len);
}
