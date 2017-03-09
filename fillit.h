/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:33:53 by pluu              #+#    #+#             */
/*   Updated: 2017/02/08 16:49:57 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUF_SIZ 4096
# define BUF_RD 1
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int		g_npieces;
char	**g_pieces;
int		g_dim;
int		g_dim_sq;

char	*ft_strnew(size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*strtrim(char const *s);
void	ft_putstr(char const *s);
void	ft_putchar(char c);
void	ft_memdel(void **ap);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
int		first_read(char *s);
int		valid_temp(char *s);
int		valid_piece(char *s);
void	piece_cnt(int fd, int ret, char c);
void	off_by_one(char **as);
void	populate_piece(char *buf, char **as, int *ai);
int		is_piece(char **as, char *ac, int *ai);
void	clean_up(char **as);
int		is_next_piece(char *buf, char *s, char *ac, int *ai);
int		is_piece_helper(char **as, char *ac, int *ai);
int		second_read(char *s);
void	populate_pieces(int fd, int ret, char c);
char	*search_and_replace(char *s);
int		is_empty(char c);
int		get_len_pieces(void);
int		get_hort_len(char *s);
int		get_vert_len(char *s);
int		get_num_dots(char *s);
int		get_dim(int len);
char	*gen_map(void);
int		get_big_sq(int num);
void	add_new_line(char **amap);
void	solve_helper(char *map);
int		solve(int k, char *map, char c);
int		is_safe(char *map, int i, char *s, char c);
void	is_safe_helper(int *ai, int *andots);
void	is_safe_helper2(char **as, int *andots, int *az_flag);
void	remove_piece(char **amap, int i, char c);
int		get_seg_dots(char **as);
int		norm_dots(int n);
void	free_pieces(void);

#endif
