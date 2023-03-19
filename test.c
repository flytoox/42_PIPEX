# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int main()
{
	int fd = open(".mm", O_CREAT | O_RDWR, 666);

	write(fd, "mmmmmmmmm", 9);
	write(fd, "\nhhhhhhhh", 9);
}