/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_read_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:23:38 by pluu              #+#    #+#             */
/*   Updated: 2017/02/08 16:25:00 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_piece(char **as, char *ac, int *ai)
{
	if (valid_temp(*as) && valid_piece(*as))
	{
		g_npieces++;
		*ai = 0;
		*ac = 0;
		return (1);
	}
	else
		clean_up(as);
	return (0);
}

void	off_by_one(char **as)
{
	if (!valid_temp(*as) || !valid_piece(*as))
		g_npieces = 0;
	else
		g_npieces++;
	ft_memdel((void**)as);
}

void	populate_piece(char *buf, char **as, int *ai)
{
	(*as)[*ai] = buf[0];
	(*ai)++;
}

int		valid_temp(char *s)
{
	int		h;
	int		d;
	int		n;

	h = 0;
	d = 0;
	n = 0;
	while (*s)
	{
		if (*s == '.')
			d++;
		else if (*s == '#')
			h++;
		else if (*s == '\n')
			n++;
		else
			return (0);
		s++;
	}
	if (h == 4 && d == 12 && n == 4)
		return (1);
	return (0);
}

int		valid_piece(char *s)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == '#')
		{
			if (s[i + 1] == '#')
				cnt++;
			if (s[i - 1] == '#')
				cnt++;
			if (s[i + 5] == '#')
				cnt++;
			if (s[i - 5] == '#')
				cnt++;
		}
		i++;
	}
	return (cnt == 6 || cnt == 8 ? 1 : 0);
}
