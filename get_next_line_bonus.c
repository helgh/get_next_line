/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-ghd <hael-ghd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:16:27 by hael-ghd          #+#    #+#             */
/*   Updated: 2023/12/24 20:26:46 by hael-ghd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*find_leak(char *all)
{
	if (all == NULL)
		return (NULL);
	free(all);
	return (NULL);
}

int	check_new_line(char *all)
{
	if (all == NULL)
		return (0);
	while (*all != 0)
	{
		if (*all == 10)
			return (1);
		all++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*all[OPEN_MAX];
	char		*part;
	int			i;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	part = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (part == NULL)
		return (all[fd] = find_leak(all[fd]));
	i = 1;
	while (i != 0)
	{
		if (check_new_line(all[fd]) == 1)
			break ;
		i = read(fd, part, BUFFER_SIZE);
		if (i == -1)
			return (free(part), all[fd] = find_leak(all[fd]));
		part[i] = 0;
		all[fd] = mul_str(all[fd], part);
	}
	free(part);
	part = copy_line(all[fd]);
	all[fd] = save_free(all[fd], part);
	return (part);
}
