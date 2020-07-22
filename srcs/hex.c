#include "ft_printf.h"
/**
 * put_str_base - sends characters to be written on standard output
 * @str: String to parse
 */
void		put_str_base(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
/**
 * num_len - Calculates the length for an number in a base
 * @num: The number for which the length is being calculated
 * @base: Base to be calculated by
 * Return: An integer representing the length of a number
 */
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

/**
 * hex_check - Checks which hex function is calling it
 * @num: Number to convert into letter
 * @x: Tells which hex function is calling it
 * Return: Ascii value for a letter
 */
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

char		*ft_strcpy(char *dst, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
/**
 * ft_strrev - reverses a string in place
 *
 * @str: string to reverse
 * Return: A pointer to a character
 */

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