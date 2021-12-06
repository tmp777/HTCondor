
I. Local 영역에서 VirtualBox 를 사용해서 머신에 HTCondor Pool을 설치 후 동작 시켜주는 프로그램입니다.


 1) 이 프로그램은 Vagrant, Ansible 을 활용해 HTCondor을 쉽게 조작 할 수 있게만든 HTCondor Panel 입니다. 
 2) HTcondor Pool이 동작중에 동적으로 HTcondor pool 에 들어있는  VM 을 추가/제거 가 가능합니다. 
 3) 프로그램 실행방법 :  ./start 로 프로그램을 실행시키시면 됩니다. 
 4) '5.VM instance ssh connect' 를 통해서 각각의 VM에 ssh로 원격접근이 가능합니다. 
 5) 위의 과정들을 통해서 HTcondor 가 각각의 머신에 설치됩니다. 
 



II. Panel에서 '3. VM instance Create' 을 설명해주는 부분입니다.


우선 VM을 만들어 주고 네트워크를 연결시켜서 각각의 VM 에 condor을 설치해주는 작업을 합니다.
위의 작업이 모두 진행되면 HTcondor pool 을 실행시킬 준비가 완료 된 것 입니다.


1. Edit Vgrantfile (Vagrant up)
*******************************************************
   Vgrantfile 에 들어가시면 'NODE_COUNT =' 가있습니다. 
  'NODE_COUNT= X'  의 숫자대로 worker(slave) VM 이 생성됩니다. 
   예를 들어 NODE_COUNT =2 이면 master +node1, node2 가 생성이 됩니다.
   위의 설정을 진행 해주어 몇개의 node를 생성 시킬지 준비합니다.  



2. Check ssh-config
*******************************************************
   VM 이 실행이 되었으니, 이제 여기에 htcondor 을 설치해줘야합니다. 설치를 위해서는 ansible에서 제공하는  play-book 을 이용해야합니다. 
   vagrant ssh-config 에서 주는 VM정보를 /etc/ansible/hosts에 추가 해주면 추가된 hosts 끼리 통신이 가능하게 됩니다. 
   /etc/ansible/hosts  IdentityFile 정보를 넣기 위해서  ssh-config 를 실행해주어 각 VM 의 정보를 받아옵니다. 

3. Check /etc/ansible/hosts
*******************************************************
   ssh-config 에서 받아온 IdentityFile hosts 정보를 Ip와 같이 입력해줍니다. 


4. Network Check
*******************************************************
   Ansible 을 사용 하기전에 VM 의 네트워크 통신이 제대로 되어있나 확인하는 작업입니다.
   ansible all -m ping 명령어를 통해서 네트워크 통신을 확인합니다. 

5. condor_setup.yml
*******************************************************
   playbook 을 이용해서 각각의 VM에 설치해줄 프로그램들이 적혀있는 yml 파일입니다. 
   본인의 입맛대로 파일 내용을 변경 하실 수 있습니다. 
   ansible-playbook condor_setup.yml 을 통해서 모든 VM 에 설정한 대로 HTCondor 프로그램이 설치됩니다.

8. Create
*******************************************************
   create 실행하면 위에서 설정한 일련의 과정들이 자동으로 진행 됩니다. 
   (ssh 암호 인증 과정에서  yes/no 부분에서는 yes 해주셔야합니다.)


