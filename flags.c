#include "ft_printf.h"

t_flags init_flags(void)
{
t_flags flags;

flags.flag_minus = 0;
flags.flag_zero = 0;
flags.star = 0;
flags.dot = -1;
flags.type = 0;
flags.width = 0;

return (flags);
}

t_flags	ft_flag_digit(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - 48);
	return (flags);
}

t_flags	ft_flag_width(t_flags flags, va_list av)
{
	flags.star = 1;
	flags.width = va_arg(av, int);
	if (flags.width < 0)
	{
		flags.flag_minus = 1;
		flags.width *= -1;
	}
	return (flags);
}

t_flags flag_minus(t_flags flags)
{
    flags.flag_minus = 1;
    flags.flag_zero = 0;
    return (flags);
}

int check_flags(const char *s, int i, t_flags *flags, va_list arg)
{
    while (s[i])
    {
        if (!is_digit(s[i]) && !is_specifier(s[i]) && !is_flag(s[i]))
			break ;
        if (s[i] == '-')
            *flags = flag_minus(*flags);
        if (s[i] == '*')
			*flags = ft_flag_width(*flags, arg);
		if (is_digit(s[i]))
			*flags = ft_flag_digit(s[i], *flags);
        if (is_specifier(s[i]))
        {
            flags->type = s[i]; // записать в структуру значение спецификатора
            break ;
        }
       i++;
    }
    return (i);   
}
