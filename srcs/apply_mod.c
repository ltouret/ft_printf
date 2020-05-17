/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 19:55:21 by ltouret           #+#    #+#             */
/*   Updated: 2020/05/18 00:27:09 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// TODO ERASE COMMENTS AND PRINTFS AND ADD apply_mod

int		replace_wldcard(t_list *current, int i, int wild_index)
{
	char	*tmp;
	char	*tmp2;
	char	*str_wildcard;

	if (!(tmp = str_index_dup(((t_block*)current->content)->raw_block, 0, i)))
		return (-1);
	if (!(str_wildcard =
		ft_itoa(*((t_block*)current->content)->wildcard[wild_index])))
		return (-1);
	if (!(tmp2 = ft_strjoin(tmp, str_wildcard)))
		return (-1);
	free(tmp);
	free(str_wildcard);
	if (!(tmp =
		ft_strjoin(tmp2, &((t_block*)current->content)->raw_block[i + 1])))
		return (-1);
	free(tmp2);
	free(((t_block*)current->content)->raw_block);
	((t_block*)current->content)->raw_block = tmp;
	printf("replace_wldcard: %s\n", ((t_block*)current->content)->raw_block);
	return (1);
}

int		check_wldcards(t_list *current)
{
	int		i;
	int		wild_index;

	i = 0;
	wild_index = 0;
	while (((t_block*)current->content)->raw_block[i])
	{
		if (((t_block*)current->content)->raw_block[i] == '*')
		{
			if ((replace_wldcard(current, i, wild_index) == -1))
				return (-1);
			wild_index++;
		}
		i++;
	}
	return (1);
}

void	get_flags(t_list *current, int *zero, int *minus)
{
	char	*block;

	block = ((t_block*)current->content)->raw_block;
	while (*block)
	{
		if (*block == '%') // why tf continue cant be used here
			;
		else if (*block == '0')
			*zero = 1;
		else if (*block == '-')
			*minus = 1;
		else
			return ;
		block++;
	}
	return ;
}
