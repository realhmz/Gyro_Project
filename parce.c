/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:48:48 by het-taja          #+#    #+#             */
/*   Updated: 2024/07/31 11:00:32 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gyro.h"

void    parce(t_data *data, char *cord)
{
    char **cordinates;
    // if (!cord)
    //     return
    cordinates = ft_split(cord, ',');
    data->Xa = ft_atoi(cordinates[0]);
    data->Ya = ft_atoi(cordinates[1]);
    data->Za = ft_atoi(cordinates[2]);
    printf("cords are x :%d  y : %d z %d \n", data->Xa, data->Ya, data->Za);
    
}