/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-ghd <hael-ghd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:26:33 by hael-ghd          #+#    #+#             */
/*   Updated: 2023/12/23 18:19:46 by hael-ghd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
int		check_new_line(char *all);
char	*mul_str(char *all, char *str);
char	*copy_line(char *str);
char	*save_free(char *str, char *p);
int		leng(char *str);
char	*find_leak(char *all);

#endif