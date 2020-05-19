/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_wid_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 16:23:10 by ltouret           #+#    #+#             */
/*   Updated: 2020/05/19 16:24:17 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_pre(t_block *block) //erase if not necessary
{
	int		i;
	int		pre;

	i = 0;
	while (block->raw_block[i] && block->raw_block[i] != '.')
		i++;
	i++;
	pre = ft_atoi(&(block->raw_block[i]));
	return (pre);
}

int		wid_len(t_block *block)
{
	int		len;

	len = ft_strlen(block->converted);
	if (block->type == 'c' && (*(char *)block->param == '\0'))
		len++;
	return (len);
}

void	handle_minus_wid(t_block *block, int zero)
{
	int		i;
	
	if (zero && (get_pre(block) < 0 || !(ft_find(block->raw_block, '.') != -1)))
	{
		i = 0;
		while (block->converted[i] && block->converted[i] != '-')
			i++;
		if (block->converted[i] == '-')
		{
			block->converted[i] = '0';
			block->converted[0] = '-';
		}
	}
}

int		int_wid(t_block *block, int wid, int minus, int zero)
{
	int		len;
	char	*pre_str;
	char	*tmp;

	len = wid_len(block);
	if (wid > len)
	{
		if (!(pre_str = malloc(sizeof(char) * (wid - len + 1))))
			return (-1);
		if (zero && !minus && (get_pre(block) < 0 || !(ft_find(block->raw_block, '.') != -1))) // ask about dis???
			ft_memset(pre_str, '0', wid - len);
		else
		{
			ft_memset(pre_str, ' ', wid - len);
		}
		pre_str[wid - len] = '\0';
		if (minus)
		{
			if (!(tmp = ft_strjoin(block->converted, pre_str))) //ask dis ok?
				return (-1);
		}
		else if (!(tmp = ft_strjoin(pre_str, block->converted)))
			return (-1);
		free(pre_str);
		free(block->converted);
		block->converted = tmp;
		handle_minus_wid(block, zero);
	}
	return (1);
}
