/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 14:07:45 by pluu              #+#    #+#             */
/*   Updated: 2017/02/08 16:24:49 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		first_read(char *s)
{
	int		fd;
	int		ret;
	char	prev_char;

	if ((fd = open(s, O_RDONLY)) == -1)
		return (0);
	ret = 0;
	prev_char = 0;
	piece_cnt(fd, ret, prev_char);
	if (close(fd) == -1)
		return (0);
	return (1);
}

void	piece_cnt(int fd, int ret, char c)
{
	int		vars[2];
	char	buf[BUF_SIZ + 1];
	char	*curr_piece;

	if (!(curr_piece = ft_strnew(20)))
		return ;
	vars[0] = 0;
	while ((ret = read(fd, buf, BUF_RD)))
	{
		buf[ret] = '\0';
		if ((vars[1] = is_next_piece(buf, curr_piece, &c, &vars[0])) == 1)
		{
			if (is_piece_helper(&curr_piece, &c, &vars[0]))
				continue ;
			else
				return ;
		}
		else if (vars[1] == 0)
		{
			clean_up(&curr_piece);
			return ;
		}
		populate_piece(buf, &curr_piece, &vars[0]);
	}
	off_by_one(&curr_piece);
}

int		is_piece_helper(char **as, char *ac, int *ai)
{
	if (is_piece(as, ac, ai))
	{
		ft_memdel((void**)as);
		if (!(*as = ft_strnew(20)))
			return (0);
	}
	else
	{
		clean_up(as);
		return (0);
	}
	return (1);
}

int		is_next_piece(char *buf, char *s, char *ac, int *ai)
{
	if (*ai > 0)
		*ac = s[*ai - 1];
	if (buf[0] == '\n' && *ac == '\n')
		return (1);
	else if (*ai == 20)
		return (0);
	return (2);
}

void	clean_up(char **as)
{
	ft_memdel((void**)as);
	g_npieces = 0;
}
