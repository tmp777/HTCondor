VM 만들어 주는 과정을 설명해주는 README txt파일 입니다.


우선 VM을 만들어 주고 네트워크를 연결시켜서 각각의 VM 에 condor을 설치해주는 작업을 합니다.
위의 작업이 모두 진행되면 HTcondor pool 을 실행시킬 준비가 완료 된 것 입니다.



1. Edit Vgrantfile / Vagrant up
***************************************************
   Vgrantfile 에 들어가면 NODE_COUNT = 가있습니다. 
   NODE_COUNT 의 숫자대로 worker VM 이 생성됩니다. 
   예를 들어 NODE_COUNT =2 이면 master, node1 , node2 가 생성이 됩니다.
   Vagrant up 을 실행하면 VM 이 생성이 됩니다. 



2. Edit ansible/hosts / vagrant ssh-config
******************************************************
VM 이 실행이 되었으니, 이제 여기에 htcondor 을 설치해줘야합니다. 설치를 위해서는 ansible에서 제공하는  play-book 을 이용해야합니다. vagrant ssh-config 에서 주는 VM정보를 /etc/ansible/hosts에 추가 해주면 추가된 hosts 끼리 통신이 가능하게 됩니다. 


3. Check Ansible Network
***********************************************
playbook을 돌리기전에 VM 들이 연결이 잘되었는지 체크를 해주는 단계 입니다. 


4. Edit condor_setup.yml
****************************************************
우리는 condor_setup.yml을 모든 VM에 설치할 예정입니다. 
혹시 수정할 사항이 있으면 수정 후에 playbook으로 실행시킵시다.


5. playbook
*******************************************************
 이제 playbook 명령어를 입력하면 모든 VM 에 위의 설정대로 condor가 설치됩니다. 
 8.Create 실행하면 vagrant up 이후에 playbook이 자동으로 실행됩니다. 


