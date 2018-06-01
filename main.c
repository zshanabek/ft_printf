#include "ft_printf.h"
#include <wchar.h>
#include <locale.h>

int			ft_printf(const char *restrict format, ...);

int main(int argc, char **argv)
{
	ft_printf   ("%044x", 44);
	system("leaks a.out");	
}