#include "ft_printf.h"
/**
 ** print_string - prints a string, returns the amount of characters printed
 */

int		print_str(va_list arg, t_flags flags)
{
	int count;
	char *str;
	int len;

	str = va_arg(arg, char *);
	len = ft_strlen(str);
	ft_width(flags.width, len, 0);
	count += ft_putstr(str, len);

	return (count);
}
