#include "ft_printf.h"
#include <wchar.h>
#include <locale.h>

int			ft_printf(const char *restrict format, ...);

int main(int argc, char **argv)
{
	wchar_t c;

	setlocale(LC_ALL, "");
	c = L'€';
	printf("%d\n", ft_printf("%05d\n", 42));
	printf("%d\n", printf   ("%05d\n", 42));	
	// system("leaks a.out");
}