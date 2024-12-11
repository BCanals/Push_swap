#include <stdio.h>
#include "libft/libft.h"


int main()
{
	printf("rb\n");
	printf("rrb\n");
	printf("pa\n");
	}
/*
// el problema es que quan fa split fa free a la cadena escrita a ma i aixo dona problema
int main (int argc, char **argv)
{
	argc++;
	argv++;
	//char **check;
	int rtrn;
	//int i;
	int len = ft_strlen(*argv);
	char *temp = ft_calloc(len + 1, sizeof(char));
	temp[len] = '\n';
	ft_memcpy(temp, *argv, len);
	ft_putstr_fd(temp, 0);
	//char *cmd = ft_calloc(3, sizeof(char));
	//cmd[0] = 'r';
	//cmd[1] = 'r';

	rtrn = 0;
	//i = -1;
	//char *s = ft_calloc(50, sizeof(char));
	if (ft_strstr("rrr\nrra\nrrb\nrr\nra\nrb\nss\nsa\nsb\npa\npb\n", temp))
		rtrn = 1;
	//check = ft_split(s, ' ');
	//while (check[++i])
	//	if (ft_strcmp(check[i], test) == 0)
	//		rtrn = 1;
	printf("%i\n", rtrn);
	//ft_free_array(check);
}*/
