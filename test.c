#include "srcs/ft_printf.h"
#include "libft/libft.h"

#include <stdio.h> // erase dis

//TODO clean find - py_print out of here in libft?

int find(char *str, int c)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (-1);
}

int find_term_char(char *str)
{
	int i;
	char *term = "cspdiuxX%";

	i = -1;
	while (str[++i])
		if (find(term, str[i]) != -1)
			return (i); 
	return (-1);
}

void py_print(char *str, int start, int end) // add length protection + start bigger than end error + start bigger than strlen
{
	while (end > start)
		ft_putchar_fd(str[start++], 1);
}

char *str_index_dup(char *str, int start, int end) // add length protection + start bgger that end error + start bigger than strlen + malloc error
{
	char *new_str;
	int str_size;
	int i;

	str_size = end - start;
	if (str_size < 0 || start > ft_strlen(str) || end > ft_strlen(str) ||
			start >= end)
		return (NULL);
	if ((new_str = malloc(sizeof(char) * (str_size + 1)))) //malloc
		i = 0;
		while (end > start)
			new_str[i++] = str[start++];
		new_str[i] = '\0';
		return (new_str);
	return (NULL);
}

int no_fmt(char *fmt) // is this needed now?
{
	if (*fmt == '\0')
		ft_putstr_fd("", 1);
	else if (find(fmt, '%') == -1)
		ft_printf("s", fmt);
	return (1);
}

int get_pointer(t_list *current, void *pointer)
{
	((t_block*)current->content)->param = pointer;
	return (1);
}

int get_int(t_list *current, int nbr)
{
	void *value;

	if ((value = malloc(sizeof(int))))
	{
		value = &nbr;
		((t_block*)current->content)->param = value;
		return (1);
	}
	return (-1);
}

int		nbr_len(unsigned long nbr, int base_len)
{
	int		i;

	i = 1;
	while (nbr /= base_len)
		i++;
	return (i);
}

char	*utoa_base(unsigned int nbr, const char *base)
{
	char	*str;
	int		base_len;
	int		i;

	base_len = ft_strlen(base);
	i = nbr_len(nbr, base_len);
	if (base_len < 2)
		return (NULL);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	str[i--] = base[(nbr % base_len)];
	nbr /= base_len;
	while (nbr != 0)
	{
		str[i--] = base[(nbr % base_len)];
		nbr /= base_len;
	}
	printf("%s\n", str);
	return (str);
}

char	*ultoa_base(unsigned long nbr, const char *base)
{
	char	*str;
	int		base_len;
	int		i;

	base_len = ft_strlen(base);
	i = nbr_len(nbr, base_len);
	if (base_len < 2)
		return (NULL);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	str[i--] = base[(nbr % base_len)];
	nbr /= base_len;
	while (nbr != 0)
	{
		str[i--] = base[(nbr % base_len)];
		nbr /= base_len;
	}
	printf("%s\n", str);
	return (str);
}

int		convert_hex(t_list *current) // send t_block maybe
{

	unsigned int arg;

	arg = *((unsigned int*)((t_block*)current->content)->param);
	printf("%d %x\n", arg, arg);
	// add to converted
	return (1);
}

int		get_wildcard(t_list *current, va_list args)
{
	char *block;
	int i;
	int flag; // to check if theres a wildcard?

	block = ((t_block*)current->content)->raw_block;
	i = 0;
	flag = 0;
	while (*block)
	{
		if (*block == '*')
		{
			((t_block*)current->content)->wildcard[i] = va_arg(args, int);
			//printf("%d\n", ((t_block*)current->content)->wildcard[i]);
			flag = 1;
			i++;
		}
		block++;
	}
	return (flag);
}

void get_param(t_list *lst, ...)
{
	va_list args;
	char type;

	va_start(args, lst);
	
	if (!lst)
		return ;
	while (lst)
	{
		type = (((t_block*)lst->content)->type);
		printf("%s %c\n", (((t_block*)lst->content)->raw_block), type);
		get_wildcard(lst, args); // check if use arg
		if (find("cdiuxX", type) != -1)
		{
			if (get_int(lst, va_arg(args, int)) == -1) // add protection malloc fail -1
				printf("malloc error get_param!");
		}
		else if (find("sp", type) != -1)
			get_pointer(lst, va_arg(args, void *));
		lst = lst->next;
	}
}

char get_type(char *block)
{
	int len;
	char c;

	len = ft_strlen(block);
	c = block[--len];
	return (c);
}

int parsing_str(char *fmt)
{
	//TODO "cspdiuxX%" & "" & no % just a string
	char *tmp;
	t_list *lst;
	t_list *current;

	lst = NULL;

	if (find(fmt, '%') == -1) // idk if this goes here
		no_fmt(fmt);
	else
	{
		while (*fmt)
		{
			if (*fmt == '%')
			{
				// fill lst
				
				if (!(current = ft_lstnew((t_block*)malloc(sizeof(t_block))))) // fix protection
					return (-1);
				tmp = str_index_dup(fmt ,find(fmt , '%'), find_term_char(fmt + 1) + 2);
				((t_block*)current->content)->raw_block = tmp;
				((t_block*)current->content)->type = get_type(tmp);
				ft_lstadd_back(&lst, current);
				
				// pass to other block
				fmt = fmt + find_term_char(fmt + 1) + 1;
			}
			fmt++;
		}
		//ft_putnbr_fd(ft_lstsize(lst), 1);
		get_param(lst, 10, 3, "hello");
	}
	return (1);
}

int main()
{
	//printf("\ntest : %*.*d\n", 10, 6, 12359);
	
	/*printf("");
	printf("%%");
	printf("%5.%");*/

	/* -- tests for parsing var string -- */
	
	char *test = "%x jhoerhfow%drhfiue%srfgh \n"; // is this a bug?
	//parsing_str(test);
	printf("pointer test printf: %p\n", test);
	printf("x test printf: %x\n", 15);
	printf("X test printf: %X\n", 15);
	printf("U test printf: %u\n", 1);
	printf("pointer in decimal printf: %lu\n", (unsigned long) test);
	printf("pointer test ultoa: ");
	char *str1 = ultoa_base((unsigned long) test, "0123456789abcdef");
	char *str2 = ft_strjoin("0x", str1);
	printf("lol: %s\n", str2);
	//clean_str("Good day Sir\n");
	//clean_str("");
	//clean_str("%ac %s %p %d %i %u %x %X %% %5.%");
	//printf("%d %d", find(test , '%'), find_term_char(test + 1));
	//ft_printf("p", "hello my friend", 4, 5);
}
