#include "push_swap.h"

static int	read_digits(const char *s, long long limit, long long *number)
{
	long long	n;
	int		digit;

	n = 0;
	while (*s >= '0' && *s <= '9')
	{
		digit = *s - '0';
		if (n > (limit - digit) / 10)
			return (0);
		n = n * 10 + digit;
		s++;
	}
	if (*s != '\0')
		return (0);
	*number = n;
	return (1);
}

int	parse_value(const char *s, int *value)
{
	long long	n;
	long long	limit;
	int		sign;

	if (!s || !*s)
		return (0);
	sign = 1;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	if (!*s)
		return (0);
	limit = 2147483647LL;
	if (sign == -1)
		limit = 2147483648LL;
	if (!read_digits(s, limit, &n))
		return (0);
	*value = (int)(n * sign);
	return (1);
}
