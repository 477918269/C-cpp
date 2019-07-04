#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	printf("pid : %d\n", getpid());
	printf("ppid : %d\n", getppid());
	return 0;
}
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	int ret = fork();
	if (ret == 0)
		printf("I am child : %d, ret : %d", getpid(), ret);
	else
		printf("I am father: %d, ret : %d", getpid(), ret);
	sleep(1);
	return 0;
}
