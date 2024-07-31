/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:48:48 by het-taja          #+#    #+#             */
/*   Updated: 2024/07/31 13:05:09 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gyro.h"

void    parce(t_data *data, char *cord)
{
    char **cordinates;
    // if (!cord)
    //     return
    cordinates = ft_split(cord, ',');
    data->Xa = atof(cordinates[0]);
    data->Ya = atof(cordinates[1]);
    data->Za = atof(cordinates[2]);
    printf("cords are x :%f  y : %f z %f \n\n", data->Xa, data->Ya, data->Za);
    
}