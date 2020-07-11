#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int				pre_printf(const char *s, va_list arg)
{
	int			i;
	t_flags		flags;
	int			count;

	count = 0;
	i = 0;
	while (s[i])
	{
		flags = init_flags();
		if (s[i] == '%' && s[i + 1] == '\0')
			return (-1);
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			i = check_flags(s, i, &flags, arg);
			if (is_specifier(s[i]))
				count += parser((char)flags.type, flags, arg);
			else if (s[i] && ft_putchar(s[i]))
				return (-1);
		}
		else if (s[i] != '%')
			count += ft_putchar(s[i]);
		i++;
	}
	return (count);
}

int				ft_printf(const char *s, ...)
{
	const char	*line;
	va_list		av;
	int			count;

	count = 0;
	if (!(line = ft_strdup(s)))
		return (-1);
	va_start(av, s);
	count += pre_printf(line, av);
	va_end(av);
	free((char *)line);
	return (count);
}

/*int	pre_printf(const char *s, va_list arg)
{
	int count;
	int i;
	t_flags flags;

	i = 0;
	count = 0;
	while (s[i])
	{
		flags = init_flags();
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			i = check_flags(s, i, &flags, arg);			
			if (is_specifier(s[i]))
				count += parser((char)flags.type, flags, arg); 
				// count += parser(s[i], arg, flags);
		}	// count += parser((char)flags.type, arg, flags);
		else
			count += ft_putchar(s[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list arg;
	const char *line;
	int count;

	count = 0;
	if (!(line = ft_strdup(s)))
		return (-1);
	va_start(arg, s);
	count = pre_printf(line, arg);
	va_end(arg);
	free((char *)line);
	return (count);
}
*/

/*int ft_printf(char *s, ...)
{
	va_list			arg; // declare a variable arg, which we use to manipulating the argument list containing variable arguments of ft_printf
	char			*line;
	int c;

	va_start(arg, s); // initializing arg variable with function's last fixed argument
	//(va_start() uses this to figure out where the variable arguments begin
	//letters = va_arg(arg, char*);
//	i = va_arg(arg, unsigned int); // fetches the next argument from the argument list.
	// The 2nd parameter to va_arg() is the data type of the argument we expect
	// NOTE: va_arg() function will never receive arguments of type char, short int, or float!!!
	// va_arg() function only accept arguments of type char *, unsigned int, int or double
	//
	line = s;
	while (*line != '\0')
	{
		while(*line != '%')
		{
			ft_putchar(*line);
			line++;
		}

		line++; // это мы передвинули знак, на символ после процента

			if (*line == 'c')
			{
				print_char(arg);
			}
			if (*line == 's')
			{
				print_str(arg);
			}
			if (*line == 'u')
			{
				print_uint(arg);
			}
			if (*line == 'd')
			{
				print_int(arg);
			}
		line++;
	}
	va_end(arg); //when we're finished processing the all arguments, we call va_end(), which performs any necessary cleanup
	return (0);
}
*/
int main()
{
	int a = ft_printf("%-c", 'i');
	printf("%d\n", a);
	int i = printf("%-c", 'i');
	printf("%d\n", i);
	return(0);
}
