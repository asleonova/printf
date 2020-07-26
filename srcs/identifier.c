#include "ft_printf.h"

int is_flag(int c)
{
	return ((c == '-') || (c == ' ') || (c == '0') || (c == '.') || (c == '*'));
}

int is_digit(int c)
{
    return (c >= '0' && c <= '9');
}

int is_specifier(int c) // will return the 1st expression if it can be converted to true 1 if not - 0, otherwise, it'll return the 2nd expression
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
			|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int ft_width(int width, int minus, int zero)
{
    int count;

    count = 0;
    while (width - minus > 0)
    {
        if (zero)
            ft_putchar('0');
        else 
            ft_putchar(' ');
        width--;
        count++;
    }
    return (count);
}