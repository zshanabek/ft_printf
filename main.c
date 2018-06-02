#include "ft_printf.h"
#include <wchar.h>
#include <locale.h>

int			ft_printf(const char *restrict format, ...);

int main()
{
	setlocale(LC_ALL, "");

	printf("%d\n", ft_printf("%"));
	printf("%d\n", printf   ("%"));
}