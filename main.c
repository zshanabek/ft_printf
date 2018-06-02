#include "ft_printf.h"
#include <wchar.h>
#include <locale.h>

int			ft_printf(const char *restrict format, ...);

int main()
{
	setlocale(LC_ALL, "");
	wchar_t *str = L"ø";
	wchar_t c = L'ø';

	printf("len: %d\n", c);
	printf("%d\n", ft_printf("%S %C %ls %lc\n", str, c, str, c));
	printf("%d\n", printf   ("%S %C %ls %lc\n", str, c, str, c));	
}