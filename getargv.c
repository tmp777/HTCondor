#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{


	void menu();


	char cmd[100];
	char string[20];
	char string2[20];
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
	printf("   3.VM instance create/setting              4. VM instance stop   \n");
	printf("   5.VM instance ssh connect                                       \n");
	printf("   7.VM destroy(halt)                                              \n");
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
			menu();
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
			printf("Choose your machine to destroy: ");
			scanf("%s", string);
			if(strcmp(string, "all") ==0){
				printf("Do you really delete all of your Machines?(Yes or No): ");
				scanf("%s", string2);

				if(strcmp(string2, "Yes") ==0){
					system("cd Vagrant && vagrant halt ");
				}
				else if(strcmp(string2, "No") ==0){
					break;}

			}else{
				printf("Do  you relly delete %s(Yes, No) ?", string2);
				scanf("%s", string2);
				if(strcmp(string2, "Yes" ) == 0 ){
				sprintf(cmd, "cd Vagrant && vagrant halt %s", string);
				system(cmd);}
				else if(strcmp(string2, "No") ==0){
						break;
				}
			}
			
			break;	
		case 99:
			system("kill `ps -ef | grep ./test | grep -v grep | awk '{print $2}'`");
			break;

	}
	}
}


void menu(){

	int number = 0;
	while(1){
	  printf("                                                                   \n");
	  printf("-------------------------------------------------------------------\n");
      printf("                 Before Create VM, do Settings                     \n");
      printf("-------------------------------------------------------------------\n");
      printf("   1.Edit Vgrantfile                        2. Check ssh-config    \n");
      printf("   3.Check /etc/ansible/hosts               4. Network checking    \n");
      printf("   5.condor_setup.yml                                              \n");
	  printf("   7.Readme                                 8. Create              \n");
      printf("                                            99. Exit               \n");
      printf("-------------------------------------------------------------------\n");
	  printf("                                                                   \n");

      printf("Enter an integer:");
      scanf("%d", &number);
      switch(number){
          case 1:
             printf("vagrantfile");
			 system("cd Vagrant && vi Vagrantfile");
             break;
		  case 2:
			 system("cd Vagrant && vagrant ssh-config");
			 break;
          case 3:
             printf("absible/hosts");
			 system("sudo vi /etc/ansible/hosts");
             break;
          case 4:
             printf("network check");
			 system("ansible all -m ping");
             break;
          case 5:
             printf("check");
			 system("cd Ansible && vi condor_setup.yml");
             break;
		  case 7:
			 system("cat readme.txt");
			 break;
		  case 8:
			 system("cd Vagrant && vagrant up ; cd .. ; cd Ansible && ansible-playbook condor_setup.yml");
			 break;
	  }
	  if(number == 99)
	    break;
              

	}
	}



