#include "ft_printf.h"
/**
 ** print_string - prints a string, returns the amount of characters printed
 */

/*int 	str_output (char *str, t_flags flags)
{
	int count;
	int len;
	len = ft_strlen(str);
	if (flags.precision >= 0 && flags.precision > len)
			flags.precision = len;
	count = 0;
	if (flags.flag_minus == 1)
		count += ft_putstr(str, len);
	count += ft_width(flags.width, len, 0);
	if (flags.flag_minus == 0)
		count += ft_putstr(str, len);
}
*/
int		print_str(char *str, t_flags flags)
{
	int count;
	int len;

	count = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (flags.precision >= 0 && flags.precision > len)
			flags.precision = len;
	if (flags.precision < 0)
	{	
		if (flags.flag_minus == 1)
			count += ft_putstr(str, len);
		count += ft_width(flags.width, len, 0);
		if (flags.flag_minus == 0)
			count += ft_putstr(str, len);
	}
	if (flags.precision >= 0)
	{
		if (flags.flag_minus == 1)
			count += ft_putstr(str, flags.precision);
		count += ft_width(flags.width, flags.precision, 0);
		if (flags.flag_minus == 0)
			count += ft_putstr(str, flags.precision);
	}
	return (count);
}
