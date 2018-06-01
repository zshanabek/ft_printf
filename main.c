#include "ft_printf.h"
#include <wchar.h>
#include <locale.h>

int			ft_printf(const char *restrict format, ...);

int main(int argc, char **argv)
{
	setlocale(LC_ALL, "");
	wchar_t *str = L"©";
	wchar_t c = L'©';
	ft_printf("%S %C %ls %lc\n", str, c, str, c);
	printf   ("%S %C %ls %lc\n", str, c, str, c);
}