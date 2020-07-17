
#include "ft_printf.h"
#include <stdio.h>

int num_len(int nb)
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

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

int	ft_putstr(char *str, int len)
{
	int	count;

	count = 0;
	while (str[count] && count < len)
		ft_putchar(str[count++]);
	return (count);
}

char *ft_itoa(int nb)
{
	int i;
	int len;
	char *str;

	i = 0;
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	len =  num_len(nb);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = 0;
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

void	put_uint(unsigned int nb)
{
	if (nb > 9)
	{
		put_uint(nb / 10);
		put_uint(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}


int		int_check_flags(char *str_nb, int nb, t_flags flags)
{
	int count;

	count = 0;
	if (flags.flag_minus == 1)
	{
		if (nb < 0 && flags.precision >= 0)
			ft_putchar('-');
		if (flags.precision >= 0)
			count += ft_width(flags.precision, num_len(nb) - 1, 1); // это потому что при точности надо нулями заполнить
		count += ft_putstr(str_nb, num_len(nb));	
	}
	if (flags.precision >= 0)
	{
		flags.width = flags.width - flags.precision; // это чтоб узнать кол-во отступов
		count += ft_width(flags.width, 0, 0);
	}
	if (flags.precision < 0)
		count += ft_width(flags.width, num_len(nb), flags.flag_zero);
	if (flags.flag_minus == 0)
	{
		if (nb < 0 && flags.precision >= 0)
			ft_putchar('-');
		if (flags.precision >= 0 && nb < 0)
			count += ft_width(flags.precision, num_len(nb) - 1, 1);// это потому что при точности надо нулями заполнить
		if (flags.precision >= 0 && nb >= 0) 
			count += ft_width(flags.precision, num_len(nb), 1);
		count += ft_putstr(str_nb, ft_strlen(str_nb));
	}
	return(count);
}

int		print_int(va_list arg, t_flags flags)
{
	char *str_nb;
	int nb;
	int count;
	int tmp;

	nb = va_arg(arg, int);
	tmp = nb;
	if (nb < 0 && (flags.flag_zero == 1 || flags.precision >= 0)) // если точность задана или стоит флаг "минус" и если отриц число
	{
		if (flags.flag_zero == 1 && flags.precision == -1)
			ft_putchar('-');
		else
			flags.width--;
		nb *= -1;
		count++;
	}
	str_nb = ft_itoa(nb);
	count += int_check_flags(str_nb, tmp, flags);
	free (str_nb);
	return (count);
}

/** print_uint - prints unsigned integer, returns the amoubt of characters printed
 */
int		print_uint(va_list arg)
{
	unsigned int nb;

	nb = va_arg(arg, unsigned int);
	if (nb < 1) // это если юзер подаст отрицательное число после знака процента
 	   return (-1);
	put_uint(nb);
	return(num_len(nb));
}

