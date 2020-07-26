#include "ft_printf.h"

int	parser(int c, va_list arg, t_flags flags)
{
	int count;

	count = 0;
	if (c == 'c')
		count += print_char(arg, flags);
	if (c == 's')
		count = print_str(va_arg(arg, char *), flags);
	if (c == 'd' || c == 'i')
		count = print_int(va_arg(arg, int), flags);
	if (c == 'u')
		count = print_uint(va_arg(arg, unsigned int), flags);
	if (c == 'x')
		count = print_hex(va_arg(arg, unsigned int), flags);
	if (c == 'X')
		count = print_upper_hex(va_arg(arg, unsigned int), flags);
	if (c == '%')
		count = print_percent(flags);
	if (c == 'p')
		count = print_ptr(va_arg(arg, unsigned long long), flags);
	return(count);

}

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
		if (line[i] == '%' && line[i + 1] == '\0') // это условие для "%"
			return (-1);
		if (line[i] == '%' && line[i + 1])
		{
			i++;
			i = check_flags(line, i, &flags, arg);
			if (is_specifier(line[i]))
					count += parser((char)flags.type, arg, flags);
			 else if (line[i]) // это если "%\n"
				 return (-1);
		}
		else if (line[i] != '%') // это если после спецификаторов идет строка
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