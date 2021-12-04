#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	char cmd[100];
	char string[20];
	int number =0;
	while(1)
	{
    printf("\n");	
	printf("\n");
	printf("-------------------------------------------------------------------\n");
	printf("                 Local HT condor Control Panel                     \n");
	printf("           Cloud Computing, Computer Science Department            \n");
	printf("                              at Chungbuk National University      \n");
	printf("-------------------------------------------------------------------\n");
	printf("   1.VM instance lists                       2. VM instance start  \n");
	printf("   3.VM instance create                      4. VM instance stop   \n");
	printf("   5.VM instance ssh connect                                       \n");
	printf("   7.Setting(Vagrantfile & Ansible)          8. VM destroy         \n");
	printf("                                             99. Quit              \n");
	printf("-------------------------------------------------------------------\n");

	printf("Enter an integer:");
	scanf("%d", &number);

	switch(number){
		case 1:
			system("cd Vagrant && vagrant status");
			break;
		case 2:
			{ 
              printf("typing your Machine:");
			  scanf("%s",string);
              sprintf(cmd, "cd Vagrant && vagrant up %s", string);
              system(cmd);
		    break;
			}
		case 3:
			printf("create() Vagrantfile에있는NODE수정해줘야하는데? ANsible");
			break;
		case 4:
			printf("shutdown all or choose one Machine");
			system("cd Vagrant && vagrant halt");
			break;
		case 5:
			printf("typing your ssh connecting machine:");
			scanf("%s", string);
			sprintf(cmd, "cd Vagrant && vagrant ssh %s", string);
			system(cmd);
			break;
		case 7:
			printf("Instance Setting()");
			system("cd Vagrant && cat Vagrantfile");
			break;
		case 8:
			printf("destroy ...주의해..");
			system("cd Vagrant && ls -al ");
			break;
		case 99:
			system("kill `ps -ef | grep ./test | grep -v grep | awk '{print $2}'`");
			break;

	}
	}



	int i=0;
//	const char *str = printf("cd Vagrant && vagrant status %s", argv[1]);
//	int retval;
//	retval = system(str);
//	printf("Exit Status %d %s\n" , retval, argv[1]);

	for (i =0; i < argc ; i++)
		printf("argv[%d]: %s\n", i, argv[i]);
	exit(0);
}


