/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:45:48 by het-taja          #+#    #+#             */
/*   Updated: 2024/07/31 18:31:38 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gyro.h"

int main(int ac, char **av)
{
    t_data *data;
    char *cord;

    data = malloc(sizeof(t_data));
    data->map = malloc(sizeof(t_map_coord));
    ft_get_map(av[1], data->map);
    int fd = open("out", O_RDONLY);
    init(data);
    while (1)
    {
        // cord = readline("");
        cord = get_next_line(fd);
        if (!cord)
        {
            close(fd);
            fd = open("out", O_RDONLY);
            continue;
            // exit(0);
        }
        parce(data, cord);
        render(data);
        // free(cord);
        // cord = NULL;
        usleep(20000);

    }
        mlx_loop(data->mlx);
    
}