#include "ft_printf.h"

/**
 ** print_char - prints a character, returns the amount of characters printed
 * */
/*int		print_char(va_list arg, t_flags flags)
{
	char c;

	c = va_arg(arg, int);
	return (view_char(c, flags));
}
*/
/*int view_char(va_list arg, t_flags flags)
{
    int count;
    char c;

    count = 0;
    if (flags.flag_minus == 1) // если у нас флаг "-", то сначала распечатать букву
    {
        c = va_arg(arg, int);
        ft_putchar(c);
    }  
    count = ft_width(flags.width, 1, 0); // добавить пробелы (сколько - это значение в flags.width + посчитать эти пробелы)
    if (flags.flag_minus == 0) // если не было флага "-", то сначала будут отступы
    {
        c = va_arg(arg, int);
        ft_putchar(c); // а потом напечатается символ
    }
    return (count + 1);  // +1 - это для самого чара
}
*/

int	view_char(char c, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.flag_minus == 1)
		ft_putchar(c);
	count = ft_width(flags.width, 1, 0);
	if (flags.flag_minus == 0)
		ft_putchar(c);
	return (count + 1);
}

/*int		print_char(va_list arg)
{
	char c;

	c = va_arg(arg, int);
	ft_putchar(c);
	return(1);
}
*/