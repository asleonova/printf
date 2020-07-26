#include "ft_printf.h"

unsigned int num_len_base(unsigned int num, int base)
{
	unsigned int i;

	i = 0;
    while(num > 0)
	{
		num = num / base;
        i++;
	}
	return (i);
}

int hex_check(int num, char x)
{
	char *hex = "abcdef";
	char *Hex = "ABCDEF";

	num = num - 10; // 1
	if (x == 'x')
		return (hex[num]); // 1
	else
		return (Hex[num]);
	return (0);
}
char	*ft_strrev(char *str)
{
	int		i;
	int		length;
	char	buff;

	i = 0;
	length = ft_strlen(str);
	while (length - 1 > i)
	{
		buff = str[i];
		str[i] = str[length - 1];
		str[length - 1] = buff;
		length--;
		i++;
	}
	return (str);
}

int		hex_check_flags(char *hex, t_flags flags)
{
	int count;
	int len;
	count = 0;

	len = ft_strlen(hex);
	if (flags.precision >= 0 && flags.precision < ft_strlen(hex))
		flags.precision = len;
	if (flags.flag_minus == 1)
		count += print_hex_result(hex, flags);
	if (flags.precision >= 0)
	{
		flags.width = flags.width - flags.precision; // это чтоб узнать кол-во отступов
		count += ft_width(flags.width, 0, 0);
	}
	if (flags.precision < 0)
		count += ft_width(flags.width, len, flags.flag_zero);
	if (flags.flag_minus == 0)
		count += print_hex_result(hex, flags);
	return(count);
}
