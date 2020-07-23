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
		if (line[i] == '%' && line[i + 1] == '\0')
			return (-1);
		if (line[i] == '%' && line[i + 1])
		{
			i++;
			i = check_flags(line, i, &flags, arg);
			if (is_specifier(line[i]))
					count += parser((char)flags.type, arg, flags);
			else if (line[i])
				return (-1);
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

/*
#include <stdio.h>
#include <limits.h>

int main()
{
	ft_printf("%0*i\n", -7, -54);
	return (0);
	
	 int	*tab = malloc(sizeof(int) * 10);
	int	*tab2 = malloc(0);
	
	ft_printf("--------------------%%p--------------------\n");
	printf("01) standart PRINTF : |%p|\n", "salut");
	ft_printf("01) my       PRINTF : |%p|\n", "salut");
	printf("02) standart PRINTF : |%-p|\n", tab2);
	ft_printf("02) my       PRINTF : |%-p|\n", tab2);
	printf("03) standart PRINTF : |%---------p|\n", "test2");
	ft_printf("03) my       PRINTF : |%----------p|\n", "test2");
	printf("04) standart PRINTF : |%10p|\n", "42");
	ft_printf("04) my       PRINTF : |%10p|\n", "42");
	printf("05) standart PRINTF : |%-10p|\n", "42");
	ft_printf("05) my       PRINTF : |%-10p|\n", "42");
	printf("06) standart PRINTF : |%2p|\n", tab);
	ft_printf("06) my       PRINTF : |%2p|\n", tab);
	printf("07) standart PRINTF : |%-2p|\n", tab);
	ft_printf("07) my       PRINTF : |%-2p|\n", tab);
	printf("08) standart PRINTF : |%p|\n", "\0\0\0\0\0");
	ft_printf("08) my       PRINTF : |%p|\n", "\0\0\0\0\0");
	printf("09) standart PRINTF : |%20p|\n", "\0\0\0\0\0");
	ft_printf("09) my       PRINTF : |%20p|\n", "\0\0\0\0\0");
	printf("10) standart PRINTF : |%p|\n", "");
	ft_printf("10) my       PRINTF : |%p|\n", "");
	printf("11) standart PRINTF : |%p|\n", NULL);
	ft_printf("11) my       PRINTF : |%p|\n", NULL);
	printf("12) standart PRINTF : |%10p|\n", NULL);
	ft_printf("12) my       PRINTF : |%10p|\n", NULL);
	printf("13) standart PRINTF : |%-10p|\n", NULL);
	ft_printf("13) my       PRINTF : |%-10p|\n", NULL);
	printf("14) standart PRINTF : |%.1p|\n", NULL);
	ft_printf("14) my       PRINTF : |%.1p|\n", NULL);
	printf("15) standart PRINTF : |%10.2p|\n", NULL);
	ft_printf("15) my       PRINTF : |%10.2p|\n", NULL);
	printf("16) standart PRINTF : |%2.5p|\n", NULL);
	ft_printf("16) my       PRINTF : |%2.5p|\n", NULL);
	printf("17) standart PRINTF : |%-10.2p|\n", NULL);
	ft_printf("17) my       PRINTF : |%-10.2p|\n", NULL);
}
*/