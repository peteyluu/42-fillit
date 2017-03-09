/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:15:09 by pluu              #+#    #+#             */
/*   Updated: 2017/02/08 15:32:43 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strnew(size_t size)
{
	char *s;

	s = (char*)malloc(sizeof(*s) * (size + 1));
	if (!s)
		return (NULL);
	else
		ft_bzero(s, size + 1);
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *p;

	p = b;
	while (len--)
		*p++ = (unsigned char)c;
	return (b);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	char	*pres;

	if (!s)
		return (NULL);
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	pres = res;
	s += start;
	while (len-- && *s)
		*pres++ = *s++;
	*pres = '\0';
	return (*pres == '\0' ? res : NULL);
}

char	*strtrim(char const *s)
{
	char const	*ps;
	char		*res;
	size_t		vars[2];

	if (!s)
		return (NULL);
	ps = s;
	vars[0] = 0;
	while (is_empty(*ps++))
		vars[0]++;
	vars[1] = ft_strlen(s);
	ps = s + (vars[1] - 1);
	while (is_empty(*ps--))
		vars[1]--;
	if (vars[0] < vars[1])
	{
		if (!(res = ft_strsub(s, vars[0], vars[1] - vars[0])))
			return (NULL);
	}
	else
	{
		if (!(res = ft_strnew(0)))
			return (NULL);
	}
	return (res);
}
