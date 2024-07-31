/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:44:53 by het-taja          #+#    #+#             */
/*   Updated: 2024/07/31 11:45:14 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gyro.h"


int	ft_toupper(int x)
{
	if (x >= 97 && x <= 122)
		return (x - 32);
	return (x);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 != '\0' || *s2 != '\0') && n > 0)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		n--;
		s1++;
		s2++;
	}
	return (0);
}
