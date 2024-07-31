/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:36:29 by het-taja          #+#    #+#             */
/*   Updated: 2024/07/31 11:38:21 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gyro.h"

static int	find_new_line(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*ft_rest(char *rest)
{
	char	*temp;
	int		i;

	if (!rest)
		return (NULL);
	i = find_new_line(rest);
	if (i != -1)
	{
		temp = ft_strdup(rest + i + 1);
		free(rest);
		rest = temp;
		return (rest);
	}
	free(rest);
	return (NULL);
}

static char	*ft_line(char *rest)
{
	char	*line;
	int		i;
	int		ind;

	i = 0;
	if (ft_strlen(rest) <= 0)
		return (NULL);
	ind = find_new_line(rest);
	if (ind == -1)
	{
		line = ft_strdup(rest);
		return (line);
	}
	line = malloc(sizeof(char) * ind + 2);
	if (!line)
		return (NULL);
	while (rest[i] != '\n')
	{
		line[i] = rest[i];
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}

static char	*ft_read(int fd, char *rest, char *buff)
{
	char	*temp;
	int		i;

	i = 1;
	while (i > 0 && find_new_line(rest) == -1)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i > 0)
		{
			buff[i] = '\0';
			temp = ft_strjoin(rest, buff);
			free(rest);
			rest = temp;
		}
	}
	free(buff);
	buff = NULL;
	if (i == -1)
	{
		free(rest);
		return (NULL);
	}
	return (rest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*str;
	int		len1;
	int		len2;

	str = NULL;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	if (s1 || s2)
	{
		str = malloc(sizeof(char) * (len1 + len2) + 1);
		if (!str)
			return (NULL);
		while (i < len1)
		{
			str[i] = s1[i];
			i++;
		}
		len2 = 0;
		while (i < len1 + ft_strlen(s2))
			str[i++] = s2[len2++];
		str[len1 + ft_strlen(s2)] = '\0';
	}
	return (str);
}


char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	rest = ft_read(fd, rest, buff);
	line = ft_line(rest);
	rest = ft_rest(rest);
	return (line);
}
