#include "ft_printf.h"

int print_int_result(char *str_nb, int nb, t_flags flags)
{
	int count;
	int len;
	count = 0;

	len = ft_strlen(str_nb);
	 if (flags.precision >= 0 && flags.precision < ft_strlen(str_nb))
		 flags.precision = len;
	if (nb < 0 && flags.precision >= 0)
			ft_putchar('-');
	if (flags.precision >= 0)
		count += ft_width(flags.precision - 1, len - 1, 1); // это потому что при точности надо нулями заполнить
	count += ft_putstr(str_nb, len);	
	return (count);

}
int		int_check_flags(char *str_nb, int nb, t_flags flags)
{
	int count;
	int len;
	count = 0;

	len = ft_strlen(str_nb);
	if (flags.precision >= 0 && flags.precision < ft_strlen(str_nb))
		flags.precision = len;
	if (flags.flag_minus == 1)
		count += print_int_result(str_nb, nb, flags);
	if (flags.precision >= 0)
	{
		flags.width = flags.width - flags.precision; // это чтоб узнать кол-во отступов
		count += ft_width(flags.width, 0, 0);
	}
	if (flags.precision < 0)
		count += ft_width(flags.width, len, flags.flag_zero);
	if (flags.flag_minus == 0)
		count += print_int_result(str_nb, nb, flags);
	return(count);
}

int		print_int(int nb, t_flags flags)
{
	char *str_nb;
	int count;
	int tmp;

	count = 0;
	tmp = nb;

	if (flags.precision == 0 && nb == 0)
	{
		count += ft_width(flags.width, 0, 0);
		return (count);
	}
	if (nb < 0 && (flags.flag_zero == 1 || flags.precision >= 0)) // если точность задана или стоит флаг "минус" и если отриц число
	{
		if (flags.flag_zero == 1 && flags.precision == -1)
			ft_putchar('-');
		nb *= -1;
		flags.width--; // иначе печатает на один 0 больше из-за минуса
		count++;
	}
	str_nb = ft_itoa(nb);
	count += int_check_flags(str_nb, tmp, flags);
	free (str_nb);
	return (count); 
}