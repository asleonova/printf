#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags
{
    int flag_minus; //0
    int flag_zero; // 0
    int star; // 0
    int precision; // -1 
    int width; //0
    int type; //0
}              t_flags;

int ft_printf(const char *s, ...);
int	ft_strlen(char *str);
int	ft_putstr(char *str, int len);
int		print_char(va_list arg, t_flags flags);
t_flags init_flags(void);
int	pre_printf(const char *s, va_list arg);
int	ft_printf(const char *s, ...);
char	*ft_strdup(const char *src);
int	ft_putchar(char c);
int is_flag(int c);
int is_digit(int c);
int is_specifier(int c);
int	parser(int c, va_list arg, t_flags flags);
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
int		print_int(va_list arg, t_flags flags);
int		print_uint(va_list arg);
int		print_percent();
int		print_ptr();
int		print_str(va_list arg, t_flags flags);
int view_char(va_list arg, t_flags flags);
int ft_width(int width, int minus, int zero);
int check_flags(const char *s, int i, t_flags *flags, va_list arg);
t_flags	ft_flag_minus(t_flags flags);
t_flags	ft_flag_digit(char c, t_flags flags);
t_flags	ft_flag_width(t_flags flags, va_list av);
int		ft_flag_dot(const char *input, int i, t_flags *flags, va_list av);
int				ft_view_input(const char *input, va_list av);
int flags_precision(const char *s, int i, va_list arg, t_flags *flags);



# endif