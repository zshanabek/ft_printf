#include "ft_printf.h"

int main(int argc, char **argv)
{
	ft_printf("1 |%14u\n", 45);
	ft_printf("2 |%014u\n", 45);
	ft_printf("3 |%-14u\n", 45);
	ft_printf("4 |%14.4u\n", 45);
	ft_printf("5 |%-14.4u\n", 45);

	ft_printf("=====================\n");

	printf("1 |%14u\n", 45);
	printf("2 |%014u\n", 45);
	printf("3 |%-14u\n", 45);
	printf("4 |%14.4u\n", 45);
	printf("5 |%-14.4u\n", 45);
}