/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:02:23 by dalabrad          #+#    #+#             */
/*   Updated: 2024/04/30 11:02:18 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	if (n == 0)
		return ;
	while (n > 0)
	{
		*p = 0;
		p++;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rtrn;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) + ft_strlen(s2);
	rtrn = (char *)malloc(sizeof(char) * (len + 1));
	if (!rtrn)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		rtrn[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		rtrn[i + ft_strlen(s1)] = s2[i];
		i++;
	}
	rtrn[len] = '\0';
	return (rtrn);
}
