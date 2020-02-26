/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 13:33:51 by ltouret           #+#    #+#             */
/*   Updated: 2020/02/18 19:11:38 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

typedef struct		s_block
{
	char	*raw_block;
	int		wildcard[2];
	char	*converted;
	void	*param;
	char	type;
}					t_block;
int					ft_printf(const char *fmt, ...);

#endif
