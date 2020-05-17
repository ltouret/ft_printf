/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 18:01:13 by ltouret           #+#    #+#             */
/*   Updated: 2020/05/16 19:33:49 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// TODO ERASE PRINTFS

int		convert_hex(t_list *current)
{
	unsigned int	arg;

	arg = *(unsigned int*)((t_block*)current->content)->param;
	if ((((t_block*)current->content)->converted = utoa_base(arg,
					"0123456789abcdef")))
	{
		printf("%s\n", ((t_block*)current->content)->converted);
		return (1);
	}
	return (-1);
}

int		convert_upper_hex(t_list *current)
{
	unsigned int	arg;

	arg = *(unsigned int*)((t_block*)current->content)->param;
	if ((((t_block*)current->content)->converted = utoa_base(arg,
					"0123456789ABCDEF")))
	{
		printf("%s\n", ((t_block*)current->content)->converted);
		return (1);
	}
	return (-1);
}

int		convert_int(t_list *current)
{
	int				arg;

	arg = *(int*)((t_block*)current->content)->param;
	if ((((t_block*)current->content)->converted = ft_itoa(arg)))
	{
		printf("%s\n", ((t_block*)current->content)->converted);
		return (1);
	}
	return (-1);
}

int		convert_uint(t_list *current)
{
	unsigned int	arg;

	arg = *(unsigned int*)((t_block*)current->content)->param;
	if ((((t_block*)current->content)->converted = utoa_base(arg,
					"0123456789")))
	{
		printf("%s\n", ((t_block*)current->content)->converted);
		return (1);
	}
	return (-1);
}

int		convert_ptr(t_list *current)
{
	unsigned long	arg;
	char			*tmp;

	arg = (unsigned long)((t_block*)current->content)->param;
	if ((((t_block*)current->content)->converted = ultoa_base(arg,
					"0123456789abcdef")))
	{
		if ((tmp = ft_strjoin("0x", ((t_block*)current->content)->converted)))
		{
			free(((t_block*)current->content)->converted);
			((t_block*)current->content)->converted = tmp;
			printf("%s\n", tmp);
			return (1);
		}
	}
	return (-1);
}
