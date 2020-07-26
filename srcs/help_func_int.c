#include "ft_printf.h"

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
	if (nb == 0)
		str[0] = '0';
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