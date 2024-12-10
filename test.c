#include <stdio.h>
#include "libft/libft.h"


// el problema es que quan fa split fa free a la cadena escrita a ma i aixo dona problema

int main (int argc, char **argv)
{
	argc++;
	argv++;
	char **check;
	int rtrn;
	int i;
	char *temp = ft_calloc(2, sizeof(char));
	temp[0] = '\n';
	char *test = ft_strjoin(*argv, temp);

	rtrn = 0;
	i = -1;
	char *s = ft_calloc(50, sizeof(char));
	ft_memcpy(s, "rrr\n rra\n rrb\n rr\n ra\n rb\n ss\n sa\n sb\n pa\n pb\n",49);
	check = ft_split(s, ' ');
	while (check[++i])
		if (ft_strcmp(check[i], test) == 0)
			rtrn = 1;
	printf("%i\n", rtrn);
	ft_free_array(check);
}
