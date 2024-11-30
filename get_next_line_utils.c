/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudoui <abaudoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:28:16 by abaudoui          #+#    #+#             */
/*   Updated: 2024/11/25 18:26:56 by abaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int ch)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == (char)ch)
			return ((char *)(str + i));
		i++;
	}
	if (str[i] == (char)ch)
		return ((char *)(str + i));
	return (0);
}

void	*ft_calloc(size_t nb, size_t size)
{
	void	*p;
	size_t	i;

	if (size != 0 && nb > SIZE_MAX / size)
		return (NULL);
	p = malloc(nb * size);
	if (!p)
		return (0);
	i = 0;
	while (i < nb * size)
	{
		*(char *)(p + i) = 0;
		i++;
	}
	return (p);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != 0)
		i++;
	return (i);
}

void	ft_strncpy(char *dest, const char *s, size_t n)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0' && i < n)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
}
