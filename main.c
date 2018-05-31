#include "ft_printf.h"
#include <wchar.h>
#include <locale.h>

int			ft_printf(const char *restrict format, ...);

int main(int argc, char **argv)
{
	int i;

	set_locale(LC_ALL, "");
	ft_printf("%lc\n", L'暖');
	printf   ("%lc\n", L'暖');
}