#include "ft_printf.h"
#include <wchar.h>
#include <locale.h>

int			ft_printf(const char *restrict format, ...);

int main(int argc, char **argv)
{
	wchar_t c;

	setlocale(LC_ALL, "");
	c = L'€';
	ft_printf("%#6o\n", 2500);
	system("leaks a.out");
}