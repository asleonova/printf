#include "ft_printf.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		size++;
	if (!(dest = malloc(sizeof(*dest) * (size + 1))))
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

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

int	parser(int c, va_list arg, t_flags flags)
{
	int count;

	count = 0;
	if (c == 'c')
		count += view_char(arg, flags);
	if (c == 's')
		count = print_str(arg, flags);
	if (c == 'd' || c == 'i')
		count = print_int(arg, flags);
	if (c == 'u')
		count = print_uint(arg);
	if (c == 'x')
		count = print_hex(arg);
	if (c == 'X')
		count = print_hex(arg);
	if (c == '%')
		count = print_percent();
	if (c == 'p')
		count = print_ptr(arg);
	return(count);

}
