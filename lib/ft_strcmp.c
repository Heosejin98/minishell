/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:54:42 by seheo             #+#    #+#             */
/*   Updated: 2022/08/04 12:09:52 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *arr1, const char *arr2)
{
	int	i;

	i = 0;
	while (arr1[i] != '\0' || arr2[i] != '\0')
	{
		if (arr1[i] > arr2[i])
			return (-1);
		else if (arr1[i] < arr2[i])
			return (-1);
		i++;
	}
	return (1);
}
