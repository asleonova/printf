#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int				pre_printf(const char *line, va_list arg)
{
	int			i;
	t_flags		flags;
	int			count;

	count = 0;
	i = 0;
	while (line[i])
	{
		flags = init_flags();
		if (line[i] == '%' && line[i + 1])
		{
			i++;
			i = check_flags(line, i, &flags, arg);
			if (is_specifier(line[i]))
				{
					count += parser((char)flags.type, arg, flags);
				}
			else if (line[i])
				count += ft_putchar(line[i]);
		}
		else if (line[i] != '%')
			count += ft_putchar(line[i]);
		i++;
	}
	return (count);
}


int				ft_printf(const char *s, ...)
{
	const char	*line;
	va_list		arg;
	int			count;

	count = 0;
	if (!(line = ft_strdup(s)))
		return (-1);
	va_start(arg, s);
	count = pre_printf(line, arg);
	va_end(arg);
	free((char *)line);
	return (count);
}

/*int ft_printf(char *s, ...)
{
	va_list			arg; // declare a variable arg, which we use to manipulating the argument list containing variable arguments of ft_printf
	char			*line;
	int c;

	va_start(arg, s); // initializing arg variable with function's last fixed argument
	//(va_start() uses this to figure out where the variable arguments begin
	//letters = va_arg(arg, char*);
//	i = va_arg(arg, unsigned int); // fetches the next argument from the argument list.
	// The 2nd parameter to va_arg() is the data type of the argument we expect
	// NOTE: va_arg() function will never receive arguments of type char, short int, or float!!!
	// va_arg() function only accept arguments of type char *, unsigned int, int or double
	//
	line = s;
	while (*line != '\0')
	{
		while(*line != '%')
		{
			ft_putchar(*line);
			line++;
		}

		line++; // это мы передвинули знак, на символ после процента

			if (*line == 'c')
			{
				print_char(arg);
			}
			if (*line == 's')
			{
				print_str(arg);
			}
			if (*line == 'u')
			{
				print_uint(arg);
			}
			if (*line == 'd')
			{
				print_int(arg);
			}
		line++;
	}
	va_end(arg); //when we're finished processing the all arguments, we call va_end(), which performs any necessary cleanup
	return (0);
}
*/

#include <stdio.h>
#include <limits.h>

int main()
{
	int	*tab = malloc(sizeof(int) * 10);
	int	*tab2 = malloc(0);

	//int a = ft_printf("%d\n", -66656);
	//printf("%d\n", a);
	//int i = printf("%d\n", -66656);
	//printf("%d\n", i);

	ft_printf("--------------------%%c--------------------\n");
	printf("01) standart PRINTF : |%c|\n", 'a');
	ft_printf("01) my       PRINTF : |%c|\n", 'a');
	printf("02) standart PRINTF : |%-c|\n", 'z');
	ft_printf("02) my       PRINTF : |%-c|\n", 'z');
	printf("03) standart PRINTF : |%-----c|\n", '!');
	ft_printf("03) my       PRINTF : |%-----c|\n", '!');
	printf("04) standart PRINTF : |%5c|\n", 'R');
	ft_printf("04) my       PRINTF : |%5c|\n", 'R');
	printf("05) standart PRINTF : |%-5c|\n", 'R');
	ft_printf("05) my       PRINTF : |%-5c|\n", 'R');
	printf("06) standart PRINTF : |%1c|\n", '3');
	ft_printf("06) my       PRINTF : |%1c|\n", '3');
	printf("07) standart PRINTF : |%c|\n", '\0');
	ft_printf("07) my       PRINTF : |%c|\n", '\0');
	printf("08) standart PRINTF : |%5c|\n", '\0');
	ft_printf("08) my       PRINTF : |%5c|\n", '\0');
	printf("09) standart PRINTF : |%-5c|\n", '\0');
	ft_printf("09) my       PRINTF : |%-5c|\n", '\0');
	printf("10) standart PRINTF : |%1c|\n", '\0');
	ft_printf("10} my       PRINTF : |%1c|\n", '\0');
	ft_printf("--------------------%%s--------------------\n");
	printf("01) standart PRINTF : |%s|\n", "salut");
	ft_printf("01) my       PRINTF : |%s|\n", "salut");
	printf("02) standart PRINTF : |%-s|\n", "test");
	ft_printf("02) my       PRINTF : |%-s|\n", "test");
	printf("03) standart PRINTF : |%---------s|\n", "test2");
	ft_printf("03) my       PRINTF : |%----------s|\n", "test2");
	printf("04) standart PRINTF : |%10s|\n", "42");
	ft_printf("04) my       PRINTF : |%10s|\n", "42");
	printf("05) standart PRINTF : |%-10s|\n", "42");
	ft_printf("05) my       PRINTF : |%-10s|\n", "42");
	printf("06) standart PRINTF : |%2s|\n", "string");
	ft_printf("06) my       PRINTF : |%2s|\n", "string");
	printf("07) standart PRINTF : |%-2s|\n", "string");
	ft_printf("07) my       PRINTF : |%-2s|\n", "string");
	printf("08) standart PRINTF : |%.15s|\n", "precision");
	ft_printf("08) my       PRINTF : |%.15s|\n", "precision");
	printf("09) standart PRINTF : |%.4s|\n", "precision");
	ft_printf("09) my       PRINTF : |%.4s|\n", "precision");
	printf("10) standart PRINTF : |%.0s|\n", "precision");
	ft_printf("10) my       PRINTF : |%.0s|\n", "precision");
	printf("11) standart PRINTF : |%s|\n", "\0\0\0\0\0");
	ft_printf("11) my       PRINTF : |%s|\n", "\0\0\0\0\0");
	printf("12) standart PRINTF : |%10s|\n", "\0\0\0\0\0");
	ft_printf("12) my       PRINTF : |%10s|\n", "\0\0\0\0\0");
	printf("13) standart PRINTF : |%s|\n", "");
	ft_printf("13) my       PRINTF : |%s|\n", "");
	printf("14) standart PRINTF : |%-.2s|\n", "boom");
	ft_printf("14) my       PRINTF : |%-.2s|\n", "boom");
	printf("15) standart PRINTF : |%10.8s|\n", "google");
	ft_printf("15) my       PRINTF : |%10.8s|\n", "google");
	printf("16) standart PRINTF : |%10.2s|\n", "twitter");
	ft_printf("16) my       PRINTF : |%10.2s|\n", "twitter");
	printf("17) standart PRINTF : |%2.10s|\n", "samsung");
	ft_printf("17) my       PRINTF : |%2.10s|\n", "samsung");
	printf("18) standart PRINTF : |%2.5s|\n", "printf");
	ft_printf("18) my       PRINTF : |%2.5s|\n", "printf");
	printf("19) standart PRINTF : |%-10.2s|\n", "424242424242");
	ft_printf("19) my       PRINTF : |%-10.2s|\n", "424242424242");
	printf("20) standart PRINTF : |%1.0s|\n", "123456789");
	ft_printf("20) my       PRINTF : |%1.0s|\n", "123456789");
	printf("20) standart PRINTF : |%-1.0s|\n", "123456789");
	ft_printf("20) my       PRINTF : |%-1.0s|\n", "123456789");
	//printf("21) standart PRINTF : |%s|\n", NULL);
	//ft_printf("21) my       PRINTF : |%s|\n", NULL);
	//printf("22) standart PRINTF : |%10s|\n", NULL);
	//ft_printf("22) my       PRINTF : |%10s|\n", NULL);
	//printf("23) standart PRINTF : |%-10s|\n", NULL);
	//ft_printf("23) my       PRINTF : |%-10s|\n", NULL);
	printf("24) standart PRINTF : |%.1s|\n", "covid-19");
	ft_printf("24) my       PRINTF : |%.1s|\n", "covid-19");
	printf("25) standart PRINTF : |%10.8s|\n", NULL);
	ft_printf("25) my       PRINTF : |%10.8s|\n", NULL);
	printf("26) standart PRINTF : |%10.2s|\n", "covid-19");
	ft_printf("26) my       PRINTF : |%10.2s|\n", "covid-19");
	printf("27) standart PRINTF : |%2.10s|\n", NULL);
	ft_printf("27) my       PRINTF : |%2.10s|\n", NULL);
	printf("28) standart PRINTF : |%2.5s|\n", "covid-19");
	ft_printf("28) my       PRINTF : |%2.5s|\n", "covid-19");
	printf("29) standart PRINTF : |%-10.2s|\n", "covid-19");
	ft_printf("29) my       PRINTF : |%-10.2s|\n", "covid-19");
	printf("30) standart PRINTF : |%1.0s|\n", NULL);
	ft_printf("30) my       PRINTF : |%1.0s|\n", NULL);
	printf("31) standart PRINTF : |%-1.s|\n", NULL);
	ft_printf("31) my       PRINTF : |%-1.s|\n", NULL);
	free(tab);
	free(tab2);
	ft_printf("--------------------%%d--------------------\n");
	printf("01) standart PRINTF : |%d|\n", 42);
	ft_printf("01) my       PRINTF : |%d|\n", 42);
	printf("02) standart PRINTF : |%i|\n", 42);
	ft_printf("02) my       PRINTF : |%i|\n", 42);
	printf("03) standart PRINTF : |%-d|\n", 42);
	ft_printf("03) my       PRINTF : |%-d|\n", 42);
	printf("04) standart PRINTF : |%10d|\n", 100);
	ft_printf("04) my       PRINTF : |%10d|\n", 100);
	printf("05) standart PRINTF : |%-10d|\n", 64);
	ft_printf("05) my       PRINTF : |%-10d|\n", 64);
	printf("06) standart PRINTF : |%.10d|\n", 100);
	ft_printf("06) my       PRINTF : |%.10d|\n", 100);
	printf("07) standart PRINTF : |%10.5d|\n", 100);
	ft_printf("07) my       PRINTF : |%10.5d|\n", 100);
	printf("08) standart PRINTF : |%5.10d|\n", 64);
	ft_printf("08) my       PRINTF : |%5.10d|\n", 64);
	printf("09) standart PRINTF : |%1.1d|\n", 16);
	ft_printf("09) my       PRINTF : |%1.1d|\n", 16);
	printf("10) standart PRINTF : |%d|\n", -42);
	ft_printf("10) my       PRINTF : |%d|\n", -42);
	printf("11) standart PRINTF : |%10d|\n", -42);
	ft_printf("11) my       PRINTF : |%10d|\n", -42);
	printf("12) standart PRINTF : |%.10d|\n", -42);
	ft_printf("12) my       PRINTF : |%.10d|\n", -42);
	printf("13) standart PRINTF : |%10.5d|\n", -16);
	ft_printf("13) my       PRINTF : |%10.5d|\n", -16);
	printf("14) standart PRINTF : |%5.10d|\n", -16);
	ft_printf("14) my       PRINTF : |%5.10d|\n", -16);
	printf("15) standart PRINTF : |%1.1d|\n", -20);
	ft_printf("15) my       PRINTF : |%1.1d|\n", -20);
	printf("16) standart PRINTF : |%-10d|\n", -50);
	ft_printf("16) my       PRINTF : |%-10d|\n", -50);
	printf("17) standart PRINTF : |%2d|\n", -20);
	ft_printf("17) my       PRINTF : |%2d|\n", -20);
	printf("18) standart PRINTF : |%.2d|\n", -20);
	ft_printf("18) my       PRINTF : |%.2d|\n", -20);
	printf("19) standart PRINTF : |%2d|\n", -1);
	ft_printf("19) my       PRINTF : |%2d|\n", -1);
	printf("20) standart PRINTF : |%.2d|\n", -1);
	ft_printf("20) my       PRINTF : |%.2d|\n", -1);
	printf("21) standart PRINTF : |%-10d|\n", -80);
	ft_printf("21) my       PRINTF : |%-10d|\n", -80);
	printf("22) standart PRINTF : |%-.10d|\n", -80);
	ft_printf("22) my       PRINTF : |%-.10d|\n", -80);
	printf("23) standart PRINTF : |%06d|\n", 35);
	ft_printf("23) my       PRINTF : |%06d|\n", 35);
	printf("24) standart PRINTF : |%06d|\n", -35);
	ft_printf("24) my       PRINTF : |%06d|\n", -35);
	printf("25) standart PRINTF : |%05.3d|\n", 5);
	ft_printf("25) my       PRINTF : |%05.3d|\n", 5);
	printf("26) standart PRINTF : |%03.5d|\n", 5);
	ft_printf("26) my       PRINTF : |%03.5d|\n", 5);
	printf("27) standart PRINTF : |%05.3d|\n", -5);
	ft_printf("27) my       PRINTF : |%05.3d|\n", -5);
	printf("28) standart PRINTF : |%03.5d|\n", -5);
	ft_printf("28) my       PRINTF : |%03.5d|\n", -5);
	printf("29) standart PRINTF : |%d| |%d|\n", INT_MAX, INT_MIN);
	
	//ft_printf("%d\n", INT_MIN);
	ft_printf("29) my       PRINTF : |%d| |%d|\n", INT_MAX, INT_MIN);
	printf("30) standart PRINTF : |%d| |%d|\n", INT_MAX + 1, INT_MIN - 1);
	ft_printf("30) my       PRINTF : |%d| |%d|\n", INT_MAX + 1, INT_MIN - 1);
	printf("31) standart PRINTF : |%.d|\n", 0);
	ft_printf("31) my       PRINTF : |%.d|\n", 0);
	printf("32) standart PRINTF : |%.d|\n", 100);
	ft_printf("32) my       PRINTF : |%.d|\n", 100);
	printf("33) standart PRINTF : %.d, %.0d\n", 0, 0);
	ft_printf("33) my       PRINTF : %.d, %.0d\n", 0, 0);
	
	return(0);
}
