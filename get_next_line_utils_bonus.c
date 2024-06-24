/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-ghd <hael-ghd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:18:22 by hael-ghd          #+#    #+#             */
/*   Updated: 2023/12/22 00:44:16 by hael-ghd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	leng(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (*(str + i) != 0)
		i++;
	return (i);
}

char	*save_free(char *str, char *p)
{
	int		i;
	int		c;
	char	*s;
	char	*part;

	c = 0;
	if (str == NULL || p == NULL)
		return (NULL);
	i = leng(str);
	while (*(str + c) != 0 && *(str + c) != 10)
		c++;
	if (*(str + c) == 10)
		c++;
	s = malloc(sizeof(char) * ((i - c) + 1));
	if (s == NULL)
		return (str = find_leak(str));
	part = s;
	while (c++ < i)
		*(s)++ = *(str + c - 1);
	*s = 0;
	if (*part == 0)
		return (str = find_leak(str), free(s), NULL);
	free(str);
	return (part);
}

char	*copy_line(char *str)
{
	char	*s;
	char	*p;
	int		i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (*(str + i) != 0 && *(str + i) != 10)
		i++;
	if (*(str + i) == 10)
		i++;
	s = malloc(sizeof(char) * (i + 1));
	if (s == NULL)
		return (str = find_leak(str));
	p = s;
	while (i-- > 0)
		*(s)++ = *(str)++;
	*s = 0;
	return (p);
}

char	*mul_str(char *all, char *str)
{
	char	*s;
	char	*al;
	char	*part;
	int		i;

	i = leng(all);
	if (all == NULL && *str == 0)
		return (NULL);
	s = malloc(sizeof(char) * (i + leng(str) + 1));
	if (s == NULL)
		return (all = find_leak(all));
	part = s;
	al = all;
	if (i != 0)
	{
		while (*al != 0)
			*(s)++ = *(al)++;
	}
	while (*str != 0)
		*(s)++ = *(str)++;
	*s = 0;
	return (all = find_leak(all), part);
}
