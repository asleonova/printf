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
