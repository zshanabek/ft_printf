#include "ft_printf.h"

int find_minus(char *flags)
{
	char *minus;

	minus = ft_strchr(flags, '-');
	if (minus)
		return (1);	
	return (0);
}

int find_zero(char *flags)
{
	char *zero;

	zero = ft_strchr(flags, '0');
	if (zero)
		return (1);	
	return (0);
}

int find_plus(char *flags)
{
	char *plus;

	plus = ft_strchr(flags, '+');
	if (plus)
		return (1);	
	return (0);
}

int find_space(char *flags)
{
	char *space;

	space = ft_strchr(flags, ' ');
	if (space)
		return (1);	
	return (0);
}

int find_hash(char *flags)
{
	char *hash;

	hash = ft_strchr(flags, '#');
	if (hash)
		return (1);	
	return (0);
}