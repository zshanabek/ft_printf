#include "ft_printf.h"

int		find_minus(const char *flags)
{
	char *minus;

	minus = ft_strchr(flags, '-');
	if (minus)
		return (1);
	return (0);
}

int		find_spec(const char *flags)
{
	char *spec;
	int i;

	i = 0;
	while (flags[i])
		i++;
	if (is_specifier(flags[i]))
		return (1);
	return (0);
}

int		find_zero(const char *flags)
{
	int i;

	i = 0;
	while (flags[i])
	{
		if (ft_isdigit(flags[i - 1]) == 0 && flags[i] == '0')
			return (1);
		i++;
	}
	return (0);
}

int		find_plus(const char *flags)
{
	char *plus;

	plus = ft_strchr(flags, '+');
	if (plus)
		return (1);
	return (0);
}

int		find_space(const char *flags)
{
	char *space;

	space = ft_strchr(flags, ' ');
	if (space)
		return (1);
	return (0);
}

int		find_hash(const char *flags)
{
	char *hash;

	hash = ft_strchr(flags, '#');
	if (hash)
		return (1);
	return (0);
}
