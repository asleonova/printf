#include "ft_printf.h"

int unum_len(unsigned int nb)
{
	int len;
	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}
/*char			*ft_itoa_uint(unsigned int nb)
{
	char	*str;
	int		size;

	size = unum_len(nb);
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (0);
	str[size--] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[size] = (nb % 10) + '0';
		nb = nb / 10;
		size--;
	}
	return (str);
}
*/
char *ft_itoa_uint(unsigned long long nb)
{
	char *str;
    int len;
    int i;

	i = 0;
	len =  unum_len(nb);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = 0;
	if (nb == 0)
		return (ft_strdup("0"));
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * -1;
		i++;
	}
	while (i < len--)
	{
		str[len] = (nb % 10) + '0';
		nb = nb / 10;
 	}
	 return (str);
}

int print_uint_result(char *str_nb, t_flags flags)
{
	int count;
	int len;
	count = 0;

	len = ft_strlen(str_nb);
	if (flags.precision >= 0 && flags.precision < ft_strlen(str_nb))
		flags.precision = len;
	if (flags.precision >= 0)
		count += ft_width(flags.precision - 1, len - 1, 1); // это потому что при точности надо нулями заполнить
	count += ft_putstr(str_nb, len);	
	return (count);

}
int		uint_check_flags(char *str_nb, t_flags flags)
{
	int count;
	int len;
	count = 0;

	len = ft_strlen(str_nb);
	if (flags.precision >= 0 && flags.precision < ft_strlen(str_nb))
		flags.precision = len;
	if (flags.flag_minus == 1)
		count += print_uint_result(str_nb, flags);
	if (flags.precision >= 0)
	{
		flags.width = flags.width - flags.precision; // это чтоб узнать кол-во отступов
		count += ft_width(flags.width, 0, 0);
	}
	if (flags.precision < 0)
		count += ft_width(flags.width, len, flags.flag_zero);
	if (flags.flag_minus == 0)
		count += print_uint_result(str_nb, flags);
	return(count);
}

int		print_uint(unsigned int nb, t_flags flags)
{
	char *str_nb;
	int count;
	unsigned long long tmp;

	count = 0;
	tmp = (unsigned int)(4294967295 + 1 + nb);

	if (flags.precision == 0 && nb == 0)
	{
		count += ft_width(flags.width, 0, 0);
		return (count);
	}
	str_nb = ft_itoa_uint(tmp);
	count += uint_check_flags(str_nb, flags);
	free (str_nb);
	return (count); 
}
