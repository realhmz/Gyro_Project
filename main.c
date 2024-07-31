/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:45:48 by het-taja          #+#    #+#             */
/*   Updated: 2024/07/31 13:05:27 by het-taja         ###   ########.fr       */
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
    init(data);
    while (1)
    {
        cord = readline("");
        parce(data, cord);
        render(data);
        // free(cord);
        // cord = NULL;

    }
        mlx_loop(data->mlx);
    
}