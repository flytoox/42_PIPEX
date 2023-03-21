# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#include <string.h>

int main()
{
	int s =0;
	if (!s)
		printf("%d", strncmp("hh", "h\n", strlen("h\n") - 1));
	else
		printf("mm");
}