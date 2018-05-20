#include "ft_printf.h"
#include <wchar.h>
#include <locale.h>

int main(int argc, char **argv)
{
	wchar_t c;

	char *s;
	int len;
	setlocale(LC_ALL, "");
	c = L'€';

	printf("%d\n", ft_printf("%30.3d\n",42));
	printf("%d\n", printf	("%30.3d\n",42));	
}