#include "ft_printf.h"


void	ft_analyze_c(char c, t_item *form, char *flags, int *count)
{
	ft_putchar(c);
}

void	ft_analyze_percent(t_item *form, char *flags, int *count)
{
	char *padding_str;

	padding_str = ft_strnew(0);	
	if (find_minus(flags))
		form->minus = true;
	else if (find_zero(flags))
		form->zero = true;
	form->padding = get_width(flags) - 1;
	if (form->padding > 0 && form->zero)
		padding_str = ft_strfill(form->padding, '0');
	else if (form->padding > 0)
		padding_str = ft_strfill(form->padding, ' ');
	if (form->minus == false)
		ft_putstr(padding_str);
	ft_putchar('%');
	if (form->minus == true)
		ft_putstr(padding_str);
}

void	ft_analyze_s(char *str, t_item *form, char *flags, int *count)
{
	char *output;
	char *padding_str;

	output = ft_strnew(0);
	padding_str = ft_strnew(0);	
	if (find_minus(flags))
		form->minus = true;
	output = ft_strsub(str, 0, get_precision(flags));
	form->padding = calculate_padding_s(output, form, flags);
	if (form->padding > 0)
		padding_str = ft_strfill(form->padding, ' ');
	if (form->minus == false)
		ft_putstr(padding_str);
	ft_putstr(output);	
	if (form->minus == true)
		ft_putstr(padding_str);
	*count += (ft_strlen(padding_str) + ft_strlen(output));
}


void	make_output_u(t_item *form, char *output, int *count)
{
	char *zeros_str;
	char *padding_str;	

	zeros_str = ft_strnew(0);
	padding_str = ft_strnew(0);	
	if (form->precision > 0)
		zeros_str = ft_strfill(form->precision, '0');
	if (form->padding > 0 && form->zero == true)
		padding_str = ft_strfill(form->padding , '0');
	else if (form->padding > 0 && form->zero == false)
		padding_str = ft_strfill(form->padding, ' ');
	if (ft_strlen(padding_str) > 0 && form->minus == false)
		ft_putstr(padding_str);
	if (ft_strlen(zeros_str) > 0)
		ft_putstr(zeros_str);
	if(form->hash && (form->specifier == 'x' || form->specifier == 'p'))
		ft_putstr("0x");
	if(form->hash && form->specifier == 'o')
		ft_putstr("0");
	ft_putstr(output);
	if (ft_strlen(padding_str) > 0 && form->minus == true) 
		ft_putstr(padding_str);
	*count += (ft_strlen(padding_str) + ft_strlen(zeros_str) + ft_strlen(output));	
}

void	ft_analyze_u(uintmax_t num, t_item *form, char *flags, int *count)
{
	char *output;

	if (find_minus(flags))
		form->minus = true;
	if (find_zero(flags))
		form->zero = true;
	if (find_hash(flags) || form->specifier == 'p')
		form->hash = true;
	if (form->specifier == 'o')
		output = ft_itoa_base_u(num, 8);
	else if (form->specifier == 'x' || form->specifier == 'p')
		output = ft_itoa_base_u(num, 16);		
	else
		output = ft_itoa_u(num);	
	form->precision  = calculate_zeros_u(ft_atoi(output), flags);
	form->padding = calculate_padding_u(ft_atoi(output), form, flags);

	make_output_u(form, output, count);
}

void	ft_analyze_x(uintmax_t num, t_item *form, char *flags, int *count)
{
	char *output;

	if (find_minus(flags))
		form->minus = true;
	if (find_zero(flags))
		form->zero = true;
	if (find_hash(flags))
		form->hash = true;
	output = ft_itoa_base_u(num, 16);
	form->precision  = calculate_zeros_u(ft_atoi(output), flags);
	form->padding = calculate_padding_u(ft_atoi(output), form, flags);
	make_output_u(form, output, count);
}

void	ft_analyze_p(int num, t_item *form, char *flags, int *count)
{
	char *output;

	if (find_minus(flags))
		form->minus = true;
	if (find_zero(flags))
		form->zero = true;
	output = ft_itoa_base(num, 8);
	form->precision  = calculate_zeros(ft_atoi(output), flags);
	form->padding = calculate_padding(ft_atoi(output), form, flags);
	
	make_output_u(form, output, count);
}