#include "ft_printf.h"

int print_ptr_result(char *ptr, t_flags flags)
{
	int count;
	int len;

	len = ft_strlen(ptr);
	count = ft_putstr("0x", 2);
	if (flags.precision >= 0)
	{
		count += ft_width(flags.precision, len, 1);
		count += ft_putstr(ptr, flags.precision);
	}
	else
		count += ft_putstr(ptr, len);	
	return (count);

}
int		ptr_check_flags(char *ptr, t_flags flags)
{
	int count;
	int len;
	count = 0;

	len = ft_strlen(ptr);
	if (flags.precision < len)
		flags.precision = len;
	if (flags.flag_minus == 1)
		count += print_ptr_result(ptr, flags);
	count += ft_width(flags.width, len + 2, 0);
	if (flags.flag_minus == 0)
		count += print_ptr_result(ptr, flags);
	return(count);
}

char *put_ptr(unsigned long long nb)
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
	return (rev_hex);
}

int		print_ptr(unsigned long long nb, t_flags flags)
{
	char *ptr;
	int count;

	count = 0;
	if (flags.precision == 0 && nb == 0)
	{
		count += ft_width(flags.width, 2, 0);
		count += ft_putstr("0x", 2);
		return (count);
	}
	if (nb == 0 && flags.precision >= 0)
		flags.width -= 1;
	ptr = put_ptr(nb);
	count += ptr_check_flags(ptr, flags);
	free (ptr);
	return (count); 
}