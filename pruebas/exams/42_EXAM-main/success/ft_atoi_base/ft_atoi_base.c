int get_value(char c)
{
	if (c >= '0' && c <= '9')
		return c - '0';
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	else
		return -1;
}

int	ft_atoi_base(const char *str, int str_base)
{
	int result = 0;
	int is_negative = 1;
	int value;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;

	if(*str == '-')
	{
		is_negative = -1;
		str++;
	}

	while ((value = get_value(*str)) >= 0 && value < str_base)
	{
		result = (result * str_base) + value;
		str++;
	}
	return result * is_negative;
}