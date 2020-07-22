#include "ft_printf.h"

int		print_percent(t_flags flags)
{
	int count;

	count = 0;
	if (flags.flag_minus == 1)
		count += ft_putchar('%');
	count += ft_width(flags.width, 1, flags.flag_zero);
	if (flags.flag_minus == 0)
		count += ft_putchar('%');
	return (count);
}
