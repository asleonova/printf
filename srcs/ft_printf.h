#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags
{
    int flag_minus; // 0
    int flag_zero; // 0
    int star; // 0
    int precision; // -1 
    int width; // 0
    int type; // 0
}              t_flags;

t_flags init_flags(void);
t_flags	ft_flag_minus(t_flags flags);
t_flags	ft_flag_digit(char c, t_flags flags);
t_flags	ft_flag_width(t_flags flags, va_list av);
int flags_precision(const char *s, int i, va_list arg, t_flags *flags);
int check_flags(const char *s, int i, t_flags *flags, va_list arg);
int is_flag(int c);
int is_digit(int c);
int is_specifier(int c);
int	parser(int c, va_list arg, t_flags flags);
int ft_width(int width, int minus, int zero);

int ft_printf(const char *s, ...);
int	pre_printf(const char *s, va_list arg);
int	ft_strlen(char *str);
int	ft_putstr(char *str, int len);
int num_len(int nb);
char	*ft_strdup(const char *src);

int	ft_putchar(char c);
int print_char(va_list arg, t_flags flags);

unsigned int num_len_base(unsigned int num, int base);
int hex_check(int num, char x);
char	*ft_strrev(char *str) ;
int print_hex(unsigned int nb, t_flags flags);
char *put_hex(unsigned int nb);
char *put_upper_hex(unsigned int nb);
int print_hex_result(char *hex, t_flags flags);
int		hex_check_flags(char *hex, t_flags flags); 
int		print_upper_hex(unsigned int nb, t_flags flags);

void	put_int(int nb);
int		print_int(int nb, t_flags flags);
int     print_int_result(char *str_nb, int nb, t_flags flags);

void	put_uint(unsigned int nb);
int unum_len(unsigned int nb);
int		print_uint(unsigned int nb, t_flags flags);
int		uint_check_flags(char *str_nb, t_flags flags);
int     print_uint_result(char *str_nb, t_flags flags);
char     *ft_itoa_uint(unsigned int nb);
int		print_percent(t_flags flags);
int print_ptr_result(char *ptr, t_flags flags);
int		ptr_check_flags(char *ptr, t_flags flags);
int		print_ptr(unsigned long long nb, t_flags flags);


int		print_str(char *str, t_flags flags);




# endif