/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudoui <abaudoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:28:13 by abaudoui          #+#    #+#             */
/*   Updated: 2024/11/25 18:48:44 by abaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_del_line(char *str)
{
	size_t	i;
	size_t	npos;

	npos = 0;
	if (!str || !str[0])
		return ;
	while (str[npos] && str[npos] != '\n')
		npos++;
	if (str[npos] == 0)
	{
		str[0] = '\0';
		return ;
	}
	i = 0;
	while (str[i + npos + 1])
	{
		str[i] = str[i + npos + 1];
		i++;
	}
	str[i] = '\0';
}

char	*ft_getline(char *line, char *str)
{
	size_t	len;
	char	*temp;
	size_t	i;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	temp = ft_calloc(len + ft_strlen(line) + 1, 1);
	if (!temp)
		return (free(line), NULL);
	ft_strncpy(temp, line, ft_strlen(line) + len + 1);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		temp[i + ft_strlen(line)] = str[i];
		i++;
	}
	if (str[i] == '\n')
		temp[i + ft_strlen(line)] = '\n';
	free(line);
	return (temp);
}

int	ft_read(int fd, char str[BUFFER_SIZE + 1])
{
	int	n;

	n = read(fd, str, BUFFER_SIZE);
	str[n] = '\0';
	return (n);
}

char	*get_next_line(int fd)
{
	static char	str[BUFFER_SIZE + 1];
	char		*line;
	int			n;

	if (BUFFER_SIZE < 0)
		return (0);
	line = ft_calloc(1, 1);
	n = BUFFER_SIZE;
	line = ft_getline(line, str);
	if (line == 0)
		return (NULL);
	ft_del_line(str);
	while (ft_strchr(line, '\n') == 0 && n == BUFFER_SIZE)
	{
		n = ft_read(fd, str);
		line = ft_getline(line, str);
		if (line == 0)
			return (NULL);
		ft_del_line(str);
	}
	if (!line[0] || n < 0)
		return (free(line), NULL);
	return (line);
}

/* int	main(void)
{
	char	*l;
	int		fd;

	fd = open("hello.txt", O_RDONLY);
	l = get_next_line(fd);
	printf("line 1 = %s", l);
	free(l);
	l = get_next_line(fd);
	printf("line 2 = %s", l);
	free(l);
	 	l = get_next_line(fd);
		__builtin_printf("line 3 = %s", l);
		free(l);
		l = get_next_line(fd);
		__builtin_printf("line 4 = %s", l);
		free(l);
			l = get_next_line(fd);
		__builtin_printf("line 5 = %s", l);
		free(l);
		l = get_next_line(fd);
		__builtin_printf("line 6 = %s", l);
		free(l);
		l = get_next_line(fd);
		__builtin_printf("line 7 = %s", l);
		free(l);
		l = get_next_line(fd);
		__builtin_printf("line 8 = %s", l);
		free(l);
		l = get_next_line(fd);
		__builtin_printf("line 9 = %s", l);
		free(l);
		l = get_next_line(fd);
		__builtin_printf("line 10 = %s", l);
		free(l);
		l = get_next_line(fd);
		__builtin_printf("line 11 = %s", l);
		free(l);
		l = get_next_line(fd);
		__builtin_printf("line 12 = %s", l);
		free(l);
		l = get_next_line(fd);
		__builtin_printf("line 13 = %s", l);
		free(l);  
	close(fd);
	return (0);
} */
