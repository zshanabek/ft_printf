#include "ft_printf.h"
#include <wchar.h>
#include <locale.h>

int			ft_printf(const char *restrict format, ...);

int main(int argc, char **argv)
{
ft_printf("1 |%14o\n", 45);
ft_printf("2 |%014o\n", 45);
ft_printf("3 |%#14o\n", 45);
ft_printf("4 |%#014o\n", 45);
ft_printf("5 |%-14o\n", 45);
ft_printf("6 |%-#14o\n", 45);
ft_printf("7 |%14.4o\n", 45);
ft_printf("8 |%-#14.4o\n", 45);
ft_printf("======================\n");
printf	 ("1 |%14o\n", 45);
printf	 ("2 |%014o\n", 45);
printf	 ("3 |%#14o\n", 45);
printf	 ("4 |%#014o\n", 45);
printf	 ("5 |%-14o\n", 45);
printf	 ("6 |%-#14o\n", 45);
printf	 ("7 |%14.4o\n", 45);
printf	 ("8 |%-#14.4o\n", 45);
}