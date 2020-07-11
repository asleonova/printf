
#include "ft_printf.h"

void	put_int(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	if (nb > 9)
	{
		put_int(nb / 10);
		put_int(nb % 10);
	}
	else
		ft_putchar(nb + '0');
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

/** print_int - prints integer, returns the amount of characters printed
 */

int		print_int(va_list arg)
{
	int nb;

	nb = va_arg(arg, int);
	put_int(nb);
	return(num_len(nb));
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