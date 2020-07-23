#include "ft_printf.h"

t_flags init_flags(void)
{
t_flags flags;

flags.flag_minus = 0;
flags.flag_zero = 0;
flags.star = 0;
flags.precision = -1; // -1 это означает, что precision не установлен. 0 - значит precision = 0
flags.type = 0;
flags.width = 0;

return (flags);
}

t_flags	flags_digit(char c, t_flags flags)
{
    if (flags.star == 1)
        flags.width = 0;
	flags.width = (flags.width * 10) + (c - '0'); // конвертим чары в инт
	return (flags);
}

int flags_precision(const char *s, int i, va_list arg, t_flags *flags)
{
    if (s[++i] == '*')
    {
        flags->precision = va_arg(arg, int); // если точность = звездочка, то передаем ее в аргументы
        i++;
    }
    else 
    {
        flags->precision = 0;
        while (is_digit(s[i]))
            flags->precision = (flags->precision * 10) + (s[i++] - '0'); // конвертим все чары в инты 
    }
    return (i);
}

t_flags	flags_width(t_flags flags, va_list arg)
{
	flags.star = 1;
	flags.width = va_arg(arg, int);
    if (flags.width < 0) // для отрицательного значения ширины
	{
        flags.flag_zero = 0;
		flags.flag_minus = 1;
		flags.width *= -1;
	}
	return (flags);
    
}

int check_flags(const char *s, int i, t_flags *flags, va_list arg)
{
    while (s[i])
    {
        if (!is_digit(s[i]) && !is_specifier(s[i]) && !is_flag(s[i]))
			break ;
        if (s[i] == '0' && flags->width == 0 && flags->flag_minus == 0)
            flags->flag_zero = 1;
        if (s[i] == '-')
            {
                flags->flag_minus = 1;
                flags->flag_zero = 0; //  flag '0' is ignored when flag '-' is present - это настоящий принтф ворнинг сообщает
            }

        if (s[i] == '*')
			*flags = flags_width(*flags, arg);
        if (s[i] == '.')
            i = flags_precision(s, i, arg, flags);
        if (is_digit(s[i]))
            *flags = flags_digit(s[i], *flags);
        if (is_specifier(s[i]))
        {
            flags->type = s[i]; // записать в структуру значение спецификатора
            break ;
        }
       i++;
    }
    return (i);   
}
