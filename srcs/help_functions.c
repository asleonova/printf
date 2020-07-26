#include "ft_printf.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		size++;
	if (!(dest = malloc(sizeof(*dest) * (size + 1))))
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
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