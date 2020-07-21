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

#include <stdio.h>
#include <limits.h>

int main()
{
	printf("01) standart PRINTF : |%u|\n", 34);
	ft_printf("01) my       PRINTF : |%u|\n", 34);
	printf("02) standart PRINTF : |%u|\n", -34);
	ft_printf("02) my       PRINTF : |%u|\n", -34);
	printf("03) standart PRINTF : |%-u|\n", 50);
	ft_printf("03) my       PRINTF : |%-u|\n", 50);
	printf("04) standart PRINTF : |%10u|\n", 90);
	ft_printf("04) my       PRINTF : |%10u|\n", 90);
	printf("05) standart PRINTF : |%.10u|\n", 90);
	ft_printf("05) my       PRINTF : |%.10u|\n", 90);
	printf("06) standart PRINTF : |%15u|\n", -100);
	ft_printf("06) my       PRINTF : |%15u|\n", -100);
	printf("07) standart PRINTF : |%.15u|\n", -100);
	ft_printf("07) my       PRINTF : |%.15u|\n", -100);
	printf("08) standart PRINTF : |%10.5u|\n", 52);
	ft_printf("08) my       PRINTF : |%10.5u|\n", 52);
	printf("09) standart PRINTF : |%5.10u|\n", 52);
	ft_printf("09) my       PRINTF : |%5.10u|\n", 52);
	printf("10) standart PRINTF : |%20.15u|\n", -100000);
	ft_printf("10) my       PRINTF : |%20.15u|\n", -100000);
	printf("11) standart PRINTF : |%15.20u|\n", -100000);
	ft_printf("11) my       PRINTF : |%15.20u|\n", -100000);
	printf("12) standart PRINTF : |%-10u|\n", 144);
	ft_printf("12) my       PRINTF : |%-10u|\n", 144);
	printf("13) standart PRINTF : |%-.10u|\n", 144);
	ft_printf("13) my       PRINTF : |%-.10u|\n", 144);
	printf("14) standart PRINTF : |%-20u|\n", -20000000);
	ft_printf("14) my       PRINTF : |%-20u|\n", -20000000);
	printf("15) standart PRINTF : |%08u|\n", 64);
	ft_printf("15) my       PRINTF : |%08u|\n", 64);
	printf("16) standart PRINTF : |%03.4u|\n", 10);
	ft_printf("16) my       PRINTF : |%03.4u|\n", 10);
	printf("17) standart PRINTF : |%u|\n", 0);
	ft_printf("17) my       PRINTF : |%u|\n", 0);
	printf("18) standart PRINTF : |%.u|\n", 0);
	ft_printf("18) my       PRINTF : |%.u|\n", 0);
	printf("19) standart PRINTF : |%10u|\n", 0);
	ft_printf("19) my       PRINTF : |%10u|\n", 0);
	printf("20) standart PRINTF : |%.u|\n", 88);
	ft_printf("20) my       PRINTF : |%.u|\n", 88);
	printf("21) standart PRINTF : |%u|\n", UINT_MAX);
	ft_printf("21) my       PRINTF : |%u|\n", UINT_MAX);
	printf("22) standart PRINTF : |%u| |%u|\n", (unsigned int)-1, UINT_MAX + 3);
	ft_printf("22) my       PRINTF : |%u| |%u|\n", (unsigned int)-1, UINT_MAX + 3);
}