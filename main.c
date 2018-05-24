#include "ft_printf.h"
#include <wchar.h>
#include <locale.h>

int main(int argc, char **argv)
{
	wchar_t c;

	setlocale(LC_ALL, "");
	c = L'€';


	ft_printf("%p\n", &c);
	printf("%p\n", &c);
	
}