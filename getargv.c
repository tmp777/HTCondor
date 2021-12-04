#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

	int i=0;
	const char *str = printf("cd Vagrant && vagrant status %s", argv[1]);
	int retval;
	retval = system(str);
	printf("Exit Status %d %s\n" , retval, argv[1]);

	for (i =0; i < argc ; i++)
		printf("argv[%d]: %s\n", i, argv[i]);
	exit(0);
}

