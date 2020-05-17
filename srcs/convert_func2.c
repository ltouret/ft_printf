/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_func2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 19:32:22 by ltouret           #+#    #+#             */
/*   Updated: 2020/05/16 19:33:27 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// TODO ERASE PRINTFS

int		convert_c(t_list *current)
{
	if ((((t_block*)current->content)->converted = malloc(sizeof(char) * 2)))
	{
		((t_block*)current->content)->converted[0] =
			*(char *)((t_block*)current->content)->param;
		((t_block*)current->content)->converted[1] = '\0';
		printf("%c\n", *((t_block*)current->content)->converted);
		return (1);
	}
	return (-1);
}

int		convert_str(t_list *current)
{
	char			*arg;

	arg = (char *)((t_block*)current->content)->param;
	if ((((t_block*)current->content)->converted = arg))
	{
		printf("%s\n", ((t_block*)current->content)->converted);
		return (1);
	}
	else if ((((t_block*)current->content)->converted = ft_strdup("(null)")))
	{
		printf("%s\n", ((t_block*)current->content)->converted);
		return (1);
	}
	return (-1);
}
