#include "srcs/ft_printf.h"

#include <stdio.h> // erase dis

void py_print(char *str, int start, int end) // add length protection + start bigger than end error + start bigger than strlen
{
	while (end > start)
		ft_putchar_fd(str[start++], 1);
}

int main()
{
	printf("pr len: %d\n", printf("%c", '\0'));
	ft_printf("%c", '\0');
	printf("pr len: %d\n", printf("%c", 'a'));
	ft_printf("%c", 'a');
	/*
	char *test = "hello %*.*d %.3d %-5d %u %p %c%s %%\n";
	ft_printf(test, 5, 4, -10, 1, 4, 3, "n", 'a', "sapo");
	printf("hislen: %d\n", printf(test,  5, 4, -10, 1, 4, 3, "n", 'a', "sapo"));
	printf("hislen: %d\n", printf("li%-5cli\n", 'a'));
	printf("hislen: %d\n", printf("%c", '\0'));
	ft_printf("%c", '\0');
	ft_printf("li%-5cli\n", 'a');
	*/
	//ft_printf("%05d\n", -3);
	//ft_printf("mine:%5c\n", '\0');
	//printf("hiss:%5c\n", '\0');
	/*printf("%.0s\n", "heelo");
	printf("%.0d\n", 0);
	printf ("%-.10s\n", "hey");
	printf("%c\n", '\0');
	int a = printf("%d %% a\n", 30);
	printf("%d\n", a);
	printf("%d\n", printf("%c\n", '-'));*/
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
