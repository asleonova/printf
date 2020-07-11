#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags
{
    int flag_minus; //0
    int flag_zero; //0
    int star; // 0
    int dot; // -1 
    int width; //0
    int type; //0
}              t_flags;

int ft_printf(const char *s, ...);
int		print_char(va_list arg);
int	view_char(char c, t_flags flags);
t_flags init_flags(void);
int	pre_printf(const char *s, va_list arg);
int	ft_printf(const char *s, ...);
char	*ft_strdup(const char *src);
int	ft_putchar(char c);
int is_flag(int c);
int is_digit(int c);
int is_specifier(int c);
int parser(int c, t_flags flags, va_list arg);
void		put_str_base(char *str);
unsigned int num_len_base(unsigned int num, int base);
int hex_check(int num, char x);
char		*ft_strcpy(char *dst, char *src);
char	*ft_strrev(char *str) ;
int print_hex(va_list arg);
int print_heX(va_list arg);
void	put_int(int nb);
void	put_uint(unsigned int nb);
int num_len(int nb);
int		print_int(va_list arg);
int		print_uint(va_list arg);
int		print_percent();
int		print_ptr();
int		print_str(va_list arg);
int ft_width(int width, int minus, int zero);
int check_flags(const char *s, int i, t_flags *flags, va_list arg);
t_flags flag_minus(t_flags flags);


# endif