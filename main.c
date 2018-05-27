#include "ft_printf.h"
#include <wchar.h>
#include <locale.h>

int			ft_printf(const char *restrict format, ...);

int main(int argc, char **argv)
{
	wchar_t c;

	setlocale(LC_ALL, "");
	c = L'€';
	printf("%d\n", ft_printf("%010x\n", 542));
	printf("%d\n", printf   ("%010x\n", 542));
	
	// system("leaks a.out");
}