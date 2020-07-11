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
	char	tmp;
    char    *dst;
	int		i;
	int		j;
    

	i = 0;
	j = 0;
	while (str[j]) 
		j++; 
	j--; 
    //if(!(dst = malloc(sizeof(char) * j + 1)))
        //return (NULL);
    //ft_strcpy(dst, str);
    dst = ft_strdup(str);
	while (j >= i)  
	{
		tmp = dst[i]; 
		dst[i] = dst[j]; 
		dst[j] = tmp; 
		i++; 
		j--; 
	}
	return (dst);
}


int print_hex(va_list arg)
{
    int len;
	unsigned int num;
	int rem_num;
	char *hex_tmp;
	char *rev_hex;

	num = va_arg(arg, unsigned int);

	if (num == 0)
		return (ft_putchar('0'));
	len = num_len_base(num, 16);
	if (!(hex_tmp = malloc(sizeof(char) * len + 1)))
		return (-1);
	len = 0; 
    while (num > 0) //123
	{
		rem_num = num % 16;  // 11 ; 7 
		if (rem_num > 9)
		{
			rem_num = hex_check(rem_num, 'x');
			hex_tmp[len] = rem_num; // [0] - b
		}
		else
			hex_tmp[len] = rem_num + '0'; // [1] - 7 convert int to char
		num = num / 16; // 7 ; 0.4
        len++;
	}
	hex_tmp[len] = '\0';
	rev_hex = ft_strrev(hex_tmp);
	put_str_base(rev_hex);
	free(hex_tmp);
	free(rev_hex);
	return (len);
}

/**
 * print_heX - Prints a representation of a decimal number on base16 Uppercase
 * @list: List of the arguments passed to the function
 * Return: Number of characters printed
 */

int print_heX(va_list arg)
{
    int len;
	unsigned int num;
	int rem_num;
	char *hex_tmp;
	char *rev_hex;

	num = va_arg(arg, unsigned int);

	if (num == 0)
		return (ft_putchar('0'));
	if (num < 1) // вот это условие мне кажется можно убрать
		return (-1);
	len = num_len_base(num, 16);
	if (!(hex_tmp = malloc(sizeof(char) * len + 1)))
		return (-1);
	len = 0; 
    while (num > 0)
	{
		rem_num = num % 16;
		if (rem_num > 9)
		{
			rem_num = hex_check(rem_num, 'X');
			hex_tmp[len] = rem_num;
		}
		else
			hex_tmp[len] = rem_num + '0'; 
		num = num / 16; 
        len++;
	}
	hex_tmp[len] = '\0';
	rev_hex = ft_strrev(hex_tmp);
	if (rev_hex == NULL) // это тоже скорее всего нужно убрать просто
		return (-1);
	put_str_base(rev_hex);
	free(hex_tmp);
	free(rev_hex);
	return (len);
}