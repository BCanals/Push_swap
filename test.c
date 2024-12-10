#include <stdio.h>
#include "libft/libft.h"

int main (int argc, char **argv)
{
	
	
	
	argc++;
	argv++;
	char *line = "r";
	char *check = "rrr\nrra\nrrb\nrr\nra\nrb\nss\nsa\nsb\npa\npb\n";
	printf("%i\n", ft_strstr(check, line));
}
