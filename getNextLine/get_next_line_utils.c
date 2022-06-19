/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartine <hmartine@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:34:04 by hmartine          #+#    #+#             */
/*   Updated: 2022/06/19 19:51:58 by hmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include "get_next_line.h"

int ft_strlen(char *c)
{
	int	num;

	num = 0;
	while (c[num])
		num++;
	return (num);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	num;

	if (!dst && !src)
		return (NULL);
	num = 0;
	if (n)
	{
		while (num < n)
		{
			((unsigned char *)dst)[num] = ((unsigned char *)src)[num];
			num++;
		}
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) * sizeof(char)) + 1);
	if (!str)
		return (NULL);

	(void)ft_memcpy(str, s1, ft_strlen(s1));
	(void)ft_memcpy(str + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (str);
}

/*
char	*ft_strjoin(char *s1, char *s2)
{
	char 	*str;
	int		n;
	int		m;

	n = 0;
	m = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) * sizeof(char)) + 1);
	while (n < ft_strlen(s1))
	{
		str[n] = s1[n];
		n++;
	}
	while (m < ft_strlen(s2))
	{
		str[n + m] = s2[m];
		m++;
	}
	free(s1);
	return (str);
}
*/

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	ns;
	char	*str;

	if (!s)
		return (NULL);
	ns = ft_strlen(s);
	if ((start >= ns) || (len == 0))
		return (ft_calloc(1, sizeof(char)));
	if (len > ns)
		len = ns;
	str = (char*)malloc(sizeof(char)*len + 1);
	if (!str)
		return (NULL);
	ns = ft_strlcpy(str, s + start, len + 1);
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			n;
	size_t			i;

	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	n = size * count;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	if (dstsize > 0)
	{
		while ((src[i] != '\0') && (i < dstsize -1))
		{
			dst[i] = src [i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	char *p;

	p = (char *)s;
	c = (char)c;
	while (*p != c)
	{
		if (*p == '\0')
			return (NULL);
		p++;
	}
	return (p);
}

char	*ft_strdup(const char *s1)
{
	int		c;
	int		i;
	char	*str;
	
	c = 0;
	i = 0;
	while (s1[i] != '\0')
		i++;
	str = (char *)malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	while (s1[c] != '\0')
	{
		str[c] = s1[c];
		c++;
	}
	str[c] = '\0';
	return ((char*)str);	
}
