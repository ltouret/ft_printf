/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:48:36 by ltouret           #+#    #+#             */
/*   Updated: 2019/10/28 12:52:41 by ltouret          ###   ########.fr       */
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
	int			i;
	long int	temp;
	char		*str;

	i = ft_len(n);
	temp = (long int)(n);
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
