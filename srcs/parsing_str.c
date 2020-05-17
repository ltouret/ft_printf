/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leet <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 19:31:08 by leet              #+#    #+#             */
/*   Updated: 2020/05/16 18:15:59 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_term_char(char *str)
{
	int		i;
	char	*term = "cspdiuxX%";

	i = -1;
	while (str[++i])
		if (ft_find(term, str[i]) != -1)
			return (i);
	return (-1);
}

char	*str_index_dup(char *str, int start, int end) // add length protection + start bgger that end error + start bigger than strlen + malloc error
{
	char	*new_str;
	int		str_size;
	int		i;

	str_size = end - start;
	if (str_size < 0 || start > ft_strlen(str) || end > ft_strlen(str) ||
			start >= end)
		return (NULL);
	if ((new_str = malloc(sizeof(char) * (str_size + 1))))
	{
		i = 0;
		while (end > start)
			new_str[i++] = str[start++];
		new_str[i] = '\0';
		return (new_str);
	}
	return (NULL);
}

char	get_type(char *block)
{
	int		len;
	char	c;

	len = ft_strlen(block);
	c = block[--len];
	return (c);
}

void	init_cont(t_list *current)
{
	((t_block*)current->content)->raw_block = NULL;
	((t_block*)current->content)->param = NULL;
	((t_block*)current->content)->wildcard[0] = NULL;
	((t_block*)current->content)->wildcard[1] = NULL;
	((t_block*)current->content)->converted = NULL;
}

int		parsing_str(char *fmt, t_list **lst)
{
	char	*tmp;
	t_list	*current;
	t_block	*block;

	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (!(block = malloc(sizeof(t_block))))
				return (-1);
			if (!(current = ft_lstnew((void *)block)))
				return (-1);
			init_cont(current);
			tmp = str_index_dup(fmt, ft_find(fmt, '%'),
			find_term_char(fmt + 1) + 2);
			((t_block*)current->content)->raw_block = tmp;
			((t_block*)current->content)->type = get_type(tmp);
			ft_lstadd_back(lst, current);
			fmt = fmt + find_term_char(fmt + 1) + 1;
		}
		fmt++;
	}
	return (1);
}
