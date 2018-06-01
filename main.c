#include "ft_printf.h"
#include <wchar.h>
#include <locale.h>

int			ft_printf(const char *restrict format, ...);

int main(int argc, char **argv)
{
	ft_printf("%#.3o\n", 1);	
	printf   ("%#.3o\n", 1);
}