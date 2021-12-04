#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	printf("                    Local HTCondor Control Panel                   \n");
	printf("           Cloud Computing, Computer Science Department            \n");
	printf("                    at Chungbuk National University  by.keum       \n");
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
              printf("Typing your Machine!(If you want to start all machine, please enter 'all'):");
			  scanf("%s",string);
			  if (strcmp(string, "all")==0){
				  system("cd Vagrant && vagrant up");
				  }
			  else{
              sprintf(cmd, "cd Vagrant && vagrant up %s", string);
              system(cmd);}
		    break;
			}
		case 3:
			printf("vagrantfile, ansible setting");
			break;
		case 4:
			printf("Choose your Machine(All Machine will shutdown, please enter 'all'):");
			scanf("%s",string);
			if(strcmp(string, "all")==0){
			system("cd Vagrant && vagrant halt");
			}
			else{
				sprintf(cmd, "cd Vagrant && vagrant halt %s", string);
				system(cmd);
			}
			break;
		case 5:
			printf("Typing your machine connect to SSH:");
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




}


