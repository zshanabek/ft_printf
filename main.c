#include "ft_printf.h"
#include <wchar.h>
#include <locale.h>

int			ft_printf(const char *restrict format, ...);

int main(int argc, char **argv)
{
	int i;

	setlocale(LC_ALL, "");

	ft_printf("%443d", 43);
	
}