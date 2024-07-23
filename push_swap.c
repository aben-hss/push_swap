#include "push_swap.h"

int	cs_atoi(char *str, char **free_it)
{
	unsigned long	ret;
	int				sign;

	ret = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		ret = ret * 10 + (*str) - '0';
		str++;
		if (ret > 2147483647 && sign == 1)
			return (dealloc(free_it), ft_putstr_fd("Error\n", 2), exit(1), 0);
		if (ret > 2147483648 && sign == -1)
			return (dealloc(free_it), ft_putstr_fd("Error\n", 2), exit(1), 0);
	}
	return ((int)ret * sign);
}

int	check_error(char *str)
{
	char	*clear;

	clear = str;
	while (*str == ' ')
		str++;
	if (!*str)
	{
		free(clear);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	while (*str)
	{
		if (!(ft_isdigit(*str) || ft_strchr("+- ", *str)))
			return (free(clear), ft_putstr_fd("Error\n", 2), 1);
		if (ft_strchr("+-", *str) && (!ft_isdigit(*(str + 1))
				|| *(str - 1) != ' '))
		{
			free(clear);
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		str++;
	}
	return (0);
}

char	*get_chars(char **av)
{
	int		i;
	int		j;
	char	*temp;
	char	*clear;

	i = 0;
	j = 0;
	temp = NULL;
	while (av[i])
	{
		clear = av[i];
		while (clear[j] == ' ')
			j++;
		if (!clear[j])
		{
			free(temp);
			write(1, "Error\n", 6);
			exit(1);
		}
		temp = ft_strjoin(temp, " ");
		temp = ft_strjoin(temp, av[i++]);
	}
	return (temp);
}

void	check_overflow(char **chars)
{
	int	i;

	i = 0;
	while (chars[i])
		cs_atoi(chars[i++], chars);
}

int	main(int ac, char **av)
{
	char	*str;
	char	**nums;
	t_stack	*a;
	t_stack	*b;
	size_t	stack_size;

	b = NULL;
	str = get_chars(av + 1);
	if (ac <= 1)
		return (0);
	if (check_error(str))
		return (1);
	nums = ft_split(str, ' ');
	check_overflow(nums);
	a = store_nums(nums);
	if (check_dubs(a))
		return (clear_stack(a), write(1, "Error\n", 6));
	if (!check_storted(a))
	{
		stack_size = get_stack_size(a);
		rank_nodes(a);
		if (stack_size == 2)
			swap_it(&a, 'a');
		else if (stack_size == 3)
			sort_three(&a, &b);
		else if (stack_size == 4)
			sort_four(&a, &b);
		else if (stack_size == 5)
			sort_five(&a, &b);
		else
			sort_all(&a, &b);
	}
	clear_stack(a);
}
