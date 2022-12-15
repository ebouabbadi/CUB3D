/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:03:11 by ebouabba          #+#    #+#             */
/*   Updated: 2022/12/13 19:03:12 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

size_t	g_ft_strlen(const char *s);
void	*g_ft_del(const char *s);
char	*g_ft_strjoin(char const *s1, char const *s2);
int		g_ft_memchr(const void *s, int c, size_t len);
char	*g_ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);

#endif
