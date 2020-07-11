#include "ft_printf.h"
/**
 ** print_string - prints a string, returns the amount of characters printed
 */

int		print_str(va_list arg)
{
	int i;
	char *str;

	str = va_arg(arg, char *);
	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}