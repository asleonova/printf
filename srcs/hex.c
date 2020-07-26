#include "ft_printf.h"


char *put_hex(unsigned int nb)
{
    int len;
	int rem_num;
	char *hex_tmp;
	char *rev_hex;

	if (nb == 0)
		return (ft_strdup("0"));
	if (!(hex_tmp = malloc(sizeof(char) * num_len_base(nb, 16) + 1)))
		return (NULL);
	len = 0; 
    while (nb > 0) //123
	{
		rem_num = nb % 16;  // 11 ; 7 
		if (rem_num > 9)
			hex_tmp[len] = rem_num + 87; // [0] - b
		else
			hex_tmp[len] = rem_num + '0'; // [1] - 7 convert int to char
		nb = nb / 16; // 7 ; 0.4
        len++;
	}
	hex_tmp[len] = '\0';
	rev_hex = ft_strrev(hex_tmp);
	// free(hex_tmp);
	return (rev_hex);
}

char *put_upper_hex(unsigned int nb)
{
    int len;
	int rem_num;
	char *hex_tmp;
	char *rev_hex;

	if (nb == 0)
		return (ft_strdup("0"));
	if (!(hex_tmp = malloc(sizeof(char) * num_len_base(nb, 16) + 1)))
		return (NULL);
	len = 0; 
    while (nb > 0) //123
	{
		rem_num = nb % 16;  // 11 ; 7 
		if (rem_num > 9)
			hex_tmp[len] = rem_num + 55; // [0] - b
		else
			hex_tmp[len] = rem_num + '0'; // [1] - 7 convert int to char
		nb = nb / 16; // 7 ; 0.4
        len++;
	}
	hex_tmp[len] = '\0';
	rev_hex = ft_strrev(hex_tmp);
	// free(hex_tmp);
	return (rev_hex);
}

int print_hex_result(char *hex,t_flags flags)
{
	int count;
	int len;

	count = 0;
	len = ft_strlen(hex);
	if (flags.precision >= 0 && flags.precision < ft_strlen(hex))
		flags.precision = len;
	if (flags.precision >= 0)
		count += ft_width(flags.precision - 1, len - 1, 1); // это потому что при точности надо нулями заполнить
	count += ft_putstr(hex, len);	
	return (count);

}

int		print_hex(unsigned int nb, t_flags flags)
{
	char *hex;
	int count;

	count = 0;

	if (flags.precision == 0 && nb == 0)
	{
		count += ft_width(flags.width, 0, 0);
		return (count);
	}
	hex = put_hex(nb);
	count += hex_check_flags(hex, flags);
	free (hex);
	return (count); 
}

int		print_upper_hex(unsigned int nb, t_flags flags)
{
	char *hex;
	int count;

	count = 0;

	if (flags.precision == 0 && nb == 0)
	{
		count += ft_width(flags.width, 0, 0);
		return (count);
	}
	hex = put_upper_hex(nb);
	count += hex_check_flags(hex, flags);
	free (hex);
	return (count); 
}