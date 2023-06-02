#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
int main()
{
	int fd,sz;
	fd=creat("file1.dat", S_IREAD|S_IWRITE);
	if(fd==-1)
		printf("Error in opening file1.dat\n");
	else
	{ 
		printf("\nfile1.dat opened for read/write access\n");
		printf("\nfile1.dat is currently empty");
	}
	close(fd);
	fd = open("file1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("r1");
		exit(1);
	}
	sz = write(fd, "hello world\n", strlen("hello world\n"));
	close(fd);
	printf("Written something into file\n");
	char *c = (char *) calloc(100, sizeof(char));
	fd = open("file1.txt", O_RDONLY);
	if (fd < 0) { perror("r1"); exit(1); }
	sz = read(fd, c, 12);
	c[sz] = '\0';
	printf("Those bytes are as follows: % s\n", c);
}
