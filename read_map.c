/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:29:35 by het-taja          #+#    #+#             */
/*   Updated: 2024/07/31 11:53:48 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gyro.h"

int	get_height(char *filename)
{
	char *line;
	int height;
	int fd;
	int i = 0;

	height = 0;
	fd = open(filename, O_RDONLY);
	line = malloc(10000);
	read(fd, line,9999);
	line[9999] = '\0';
	while (line && line[i])
	{
		if (line[i] == '\n')
			height++;
		i++;
	}
	free(line);
	close(fd);
	return(height);
}

int	get_width(char *filename)
{
	int		width;
	char	*line;
	int		i;
	int 	fd;

	i = 0;
	width = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("open error");
	line = get_next_line(fd);
	if (!line)
		ft_error("invalid map (empty)");
	while(line[i] && line[i] != '\n')
	{
		while (line[i] && line[i] != '\n' && line[i] == ' ')
			i++;
		if (line[i] && line[i] != '\n')
		{
			width++;
			while (line[i] && line[i] != '\n' && line[i] != ' ')
				i++;
		}
	}
	free(line);
	if(close(fd) == -1)
		ft_error("close error <width>");
	return (width);	
}

void	ft_fill_matrix(t_map_coord *map, char *line)
{
	char	**num;
	int		i;
	int		j;
	char	*tmp;
	static int x = 0;

	num = ft_split(line, ' ');
	i = 0;
	while (num[i] && i < map->abscissa)
	{
		map->matrix[x][i] = malloc(sizeof(int) * 2);
		if (!map->matrix[x][i])
			ft_error("malloc error");
		j = 0;
		map->matrix[x][i][0] = ft_atoi(num[i]);
		while (num[i][j] && num[i][j] != ',')
			j++;
		tmp = num[i];
		if (num[i][j] == ',')
			map->matrix[x][i][1] = ft_atoi_base((tmp + j + 1), "0123456789ABCDEF");

		else
			map->matrix[x][i][1] = -1;
		free(num[i]);
		i++;
	}
	if (i != map->abscissa)
		ft_error("error: fdf file has irregular width");

	free(num);
	x++;
}

void	ft_get_altitude_min_max(t_map_coord *map)
{
	int	i;
	int	j;

	i = 0;
	map->altitude_min = map->matrix[0][0][0];
	map->altitude_max = map->matrix[0][0][0];
	while (i < map->ordinate)
	{
		j = 0;
		while (j < map->abscissa)
		{
			if (map->matrix[i][j][0] < map->altitude_min)
				map->altitude_min = map->matrix[i][j][0];
			if (map->matrix[i][j][0] > map->altitude_max)
				map->altitude_max = map->matrix[i][j][0];
			j++;
		}
		i++;
	}
}

void	ft_get_map(char *filename, t_map_coord *map)
{
	char	*line;
	int		i;
	int		fd;

	map->abscissa = get_width(filename);
	map->ordinate = get_height(filename);
	
	printf("hight  %d  and whidth %d \n\n", map->ordinate, map->abscissa);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("open error");
	i = 0;
	map->matrix = malloc(sizeof(int **) * map->ordinate);
	if (!map->matrix)
		ft_error("malloc error");
	while ((line = get_next_line(fd)) != NULL)
	{
		map->matrix[i] = malloc(sizeof(int *) * map->abscissa);
		if(!map->matrix[i])
			ft_error("malloc error");
		ft_fill_matrix(map, line);
		free(line);
		i++;
	}
	ft_get_altitude_min_max(map);
	if (close(fd) == -1)
		ft_error("file close error");
}