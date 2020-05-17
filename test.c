#include "srcs/ft_printf.h"

#include <stdio.h> // erase dis

void py_print(char *str, int start, int end) // add length protection + start bigger than end error + start bigger than strlen
{
	while (end > start)
		ft_putchar_fd(str[start++], 1);
}

int		str_wid(t_block *block, int wid, int minus)
{
	int		len;
	char	*pre_str;
	char	*tmp;

	len = ft_strlen(block->converted);
	if (wid > len)
	{
		if (!(pre_str = malloc(sizeof(char) * (wid - len + 1))))
			return (-1);
		ft_memset(pre_str, ' ', wid - len);
		pre_str[wid - len] = '\0';
		if (minus)
		{
			if (!(tmp = ft_strjoin(block->converted, pre_str)))
				return (-1);
		}
		else if (!(tmp = ft_strjoin(pre_str, block->converted)))
			return (-1);
		free(pre_str);
		free(block->converted);
		block->converted = tmp;
	}
	return (1);
}

int		apply_wid(t_list *current, int zero, int minus)
{
	int			wid;
	int			i;
	t_block		*block;

	(void) zero;
	i = 0;
	block = ((t_block*)current->content);
	while (block->raw_block[i] &&
		ft_find("%-0", block->raw_block[i] == '%') != -1)
		i++;
	wid = ft_atoi(&(block->raw_block[i]));
	//if (ft_find("cdiuxXp%", block->type) != -1)
	//	if (int_wid(block, wid, minus,  zero) == -1)
	//		return (-1);
	if (ft_find("s", block->type) != -1)
		if (str_wid(block, wid, minus) == -1)
			return (-1);
	return (1);
}

int		apply_mod(t_list *lst) // this goes to apply_mod.c
{
	int	zero;
	int	minus;

	while (lst)
	{
		zero = 0;
		minus = 0;
		if (check_wldcards(lst) == -1)
			return (-1);
		get_flags(lst, &zero, &minus);
		if (apply_pre(lst) == -1)
			return (-1);
		if (apply_wid(lst, zero, minus) == -1)
			return (-1);
		lst = lst->next;
	}
	return 1;
}

int main()
{
	char *test = "hello %*.*d %.3d %-05d %u %p %c%s %%\n";
	ft_printf(test, 5, 4, -10, 1, 4, 3, "n", 'a', "sapo");
	printf("%.0s\n", "heelo");
	printf("%.0d\n", 0);
	//printf("\ntest : %*.*d\n", 10, 6, 12359);
	/*printf("");
	printf("%%");
	printf("%5.%");*/

	/* -- tests for parsing var string -- */
	
	//char *test = "%*.d %u %p %c %%\n";
	//wtf is this sh*t - rpi
	//printf("%d\n");
	//printf("%d\n");

	/*char *str1 = ultoa_base((unsigned long) test, "0123456789abcdef");
	char *str2 = ft_strjoin("0x", str1);
	printf("lol: %s\n", str2);*/
	
	//printf("%d %d", find(test , '%'), find_term_char(test + 1));
	//ft_printf("p", "hello my friend", 4, 5);
}
