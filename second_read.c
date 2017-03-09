/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 19:58:40 by pluu              #+#    #+#             */
/*   Updated: 2017/02/08 15:17:06 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		second_read(char *s)
{
	int		fd;
	int		ret;
	char	prev_char;

	if ((fd = open(s, O_RDONLY)) == -1)
		return (0);
	ret = 0;
	prev_char = 0;
	populate_pieces(fd, ret, prev_char);
	if (close(fd) == -1)
		return (0);
	return (1);
}

void	populate_pieces(int fd, int ret, char c)
{
	int		vars[2];
	char	buf[BUF_SIZ + 1];
	char	*curr_piece;

	if (!(curr_piece = ft_strnew(20)))
		return ;
	vars[0] = 0;
	vars[1] = 0;
	while ((ret = read(fd, buf, BUF_RD)))
	{
		buf[ret] = '\0';
		if (vars[0] > 0)
			c = curr_piece[vars[0] - 1];
		if (c == '\n' && buf[0] == '\n')
		{
			g_pieces[vars[1]++] = search_and_replace(strtrim(curr_piece));
			vars[0] = 0;
			c = 0;
			continue ;
		}
		populate_piece(buf, &curr_piece, &vars[0]);
	}
	g_pieces[vars[1]++] = search_and_replace(strtrim(curr_piece));
	g_pieces[vars[1]] = NULL;
	ft_memdel((void**)&curr_piece);
}

char	*search_and_replace(char *s)
{
	char	*ps;

	ps = s;
	while (*ps)
	{
		if (*ps == '\n')
			*ps = '.';
		ps++;
	}
	return (s);
}

int		is_empty(char c)
{
	return (c == '.' || c == '\n' ? 1 : 0);
}
