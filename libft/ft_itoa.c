/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:48:36 by ltouret           #+#    #+#             */
/*   Updated: 2020/02/26 16:39:53 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_len(int nb)
{
	int		i;

	i = (0 >= nb) ? 1 : 0;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	int		temp;
	char	*str;

	i = ft_len(n);
	temp = n;
	if ((str = (char*)malloc((i + 1) * sizeof(char))))
	{
		str[i--] = '\0';
		if (0 > temp)
			str[0] = '-';
		else if (temp == 0)
			str[0] = '0';
		while (temp != 0)
		{
			str[i] = (temp % 10) > 0 ? (temp % 10) + 48 : (-temp % 10) + 48;
			temp /= 10;
			i--;
		}
	}
	return (str);
}
