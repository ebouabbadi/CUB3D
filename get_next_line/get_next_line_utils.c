/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:02:56 by ebouabba          #+#    #+#             */
/*   Updated: 2022/12/13 19:02:57 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/***************************************\
*              FT_STLEN                 *
\***************************************/
size_t	g_ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/***************************************\
*               FT_DEL                  *
\***************************************/
void	*g_ft_del(const char *s)
{
	int	len;

	if (!s)
		return (NULL);
	len = g_ft_strlen(s);
	while (len--)
		*(char *)(s + len) = 0;
	free((void *)s);
	return (NULL);
}

/***************************************\
*              FT_MEMCHR                *
\***************************************/
int	g_ft_memchr(const void *s, int c, size_t len)
{
	char	*h;
	int		i;

	i = 0;
	if (!s)
		return (0);
	h = (char *)s;
	i = g_ft_strlen(s) - 1;
	while (i >= 0 && h[i] && len--)
		if (h[i--] == (char) c)
			return (1);
	return (0);
}

/***************************************\
*                FT_STRJOIN             *
\***************************************/
char	*g_ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	char	*rjoin;
	int		ss1;

	if (!s1)
		return (NULL);
	ss1 = g_ft_strlen((char *)s1);
	join = malloc(ss1 + g_ft_strlen(s2) + 1);
	rjoin = join;
	while (*s1)
		*join++ = *s1++;
	g_ft_del(s1 - ss1);
	while (*s2)
		*join++ = *s2++;
	*join = '\0';
	return (rjoin);
}

/***************************************\
*                FT_SUBSTR              *
\***************************************/
char	*g_ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	n;

	if (!s)
		return (NULL);
	n = g_ft_strlen(s);
	if (start > n)
		n = 0;
	else if (len + start > n)
		n = n - start;
	else
		n = len;
	sub = malloc(n + 1);
	if (!sub)
		return (g_ft_del(s));
	sub[n] = '\0';
	while (n--)
		sub[n] = s[start + n];
	g_ft_del(s);
	return ((char *)sub);
}
