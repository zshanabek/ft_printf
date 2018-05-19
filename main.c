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

	s = ft_itoa_base(c, 2);
	len = ft_strlen(s);

	if (MB_CUR_MAX != 1)
	{
		if (len <= 7)
			write(1, &c, 1);
		else if (len <= 11)
		{
			ft_putchar((c >> 6) + 0b11000000);
			ft_putchar((c & 0b111111) + 0b10000000);
		}
		else if (len <= 16)
		{
			ft_putchar((c >> 12) + 0b11100000);
			ft_putchar(((c >> 6) & 0b111111) + 0b10000000);		
			ft_putchar((c & 0b111111) + 0b10000000);
		}
		else
		{
			ft_putchar((c >> 18) + 0b11110000);		
			ft_putchar(((c >> 12) & 0b111111) + 0b10000000);
			ft_putchar(((c >> 6) & 0b111111) + 0b10000000);		
			ft_putchar((c & 0b111111) + 0b10000000);
		}
	}
}