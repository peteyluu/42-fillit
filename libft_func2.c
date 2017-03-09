/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:21:04 by pluu              #+#    #+#             */
/*   Updated: 2017/02/08 15:31:04 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putstr(char const *s)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_memdel(void **ap)
{
	if (!ap)
		return ;
	if (!*ap)
		return ;
	free(*ap);
	*ap = NULL;
}

char	*ft_strdup(const char *s1)
{
	char *str;
	char *tmp;

	str = (char *)malloc(sizeof(*str) * (ft_strlen(s1) + 1));
	if (!str)
		return (0);
	tmp = str;
	while (*s1)
		*tmp++ = *s1++;
	*tmp = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (*s++)
		cnt++;
	return (cnt);
}
