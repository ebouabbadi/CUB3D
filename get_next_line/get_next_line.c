/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:03:04 by ebouabba          #+#    #+#             */
/*   Updated: 2022/12/13 19:03:05 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/***************************************\
*                FT_EOL                 *
\***************************************/
int	g_ft_eol(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		if (s[i++] == '\n')
			return (i);
	return (i);
}

/***************************************\
*          	 	FT_SANL 	            *
\***************************************/
void	g_ft_sanl(char *sr, int i)
{
	char	*p;

	p = sr + i;
	while (*p)
		*sr++ = *p++;
	while (sr < p)
		*sr++ = '\0';
}

/***************************************\
*             FT_STRDUP                 *
\***************************************/
char	*g_ft_strdup(const char *s)
{
	char	*p;
	int		i;

	i = 0;
	p = malloc(g_ft_strlen((char *)s) + 1);
	if (!p)
		return (NULL);
	while (*s)
		p[i++] = *s++;
	p[i] = '\0';
	return (p);
}

/***************************************\
*			GET_NEXT_LINE			    *
\***************************************/
char	*g_get_line(int fd)
{
	static char	sr_fd[1 + 1];
	char		*join;
	int			x;

	join = g_ft_strdup(sr_fd);
	while (!g_ft_memchr(join, '\n', 1) && join)
	{
		x = read (fd, sr_fd, 1);
		if ((x == -1 && !*sr_fd) || !(x || join) || !(x || *join))
			return (g_ft_del(join));
		sr_fd[x] = '\0';
		join = g_ft_strjoin(join, sr_fd);
		if (x < 1 || !join)
			break ;
	}
	if (!join || !*join)
		return (g_ft_del(join));
	g_ft_sanl(sr_fd, g_ft_eol(sr_fd));
	return (g_ft_substr(join, 0, g_ft_eol(join)));
}

char	*get_next_line(int fd)
{
	if (fd < 0 || 1 <= 0)
		return (NULL);
	return (g_get_line(fd));
}
