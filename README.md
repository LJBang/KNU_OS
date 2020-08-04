# KNU_OS
COMP312 / 강순주 교수님의 운영체제 / 2020.1  
c 언어와 우분투 운영체제를 사용.
- - -  
## 수업 키워드
- 우분투를 통한 리눅스 컴파일방법인 `Makefile` 사용  
- OS의 4대역할  
    + 프로세스관리, 자원관리, 메모리관리, 입출력장치관리  
- Process State Diagram  
- Process와 Thread  
- Scheduling  
- Socket을 이용한 네트워크 통신  
- Raspberrypi를 이용한 Kernel mode Programming  
- Semaphore & mutex 
- DeadLock
- Memory Management & Virtual Memory
- 


## 실습
- [Q1](./HW/q1/q1.md)
    >서버와 클라이언트간 소켓통신을 활용해 에코프로그램 제작
- [Q2](./HW/q2/q2.md)
    >서버에 두명의 클라이언트가 접속해 가위바위보를 할 수 있도록 프로그램 구성

## 과제
- [HW1](./HW/hw1/hw.md)  
    >학생 10명의 학번과 이름 정보를 통해 이름을 입력하면 학번이 나오고, 학번을 입력하면 이름이 나오는 프로그램 제작.  
- [HW2](./HW/hw2/hw.md)  
    >사칙연산을 수행하는 파일과 myshell 제작, myshell에서 사칙연산 파일을 실행하여 수행가능.  
- [HW3](./HW/hw3/hw.md)  
    >thread를 여러개 만들어 thread간 스케쥴링을 확인하는 프로그램
- [HW3b](./HW/hw3b/hw.md)  
    >HW03의 프로그램에서 스레드를 줄이더라도 결과값에 오류가 생기도록 새로운 함수를 추가하고, mutex를 사용하여 thread간 스케쥴링을 조절해 정상적인 결과값을 출력한다.  
- [HW4](./HW/hw4/hw.md)  
    >Stack과 Heap이 같은 메모리를 사용하므로, Stack과 Heap을 늘려가면서 두 영역이 충돌하는지 확인하고, 그 지점을 찾는다.  
- [HW5_1](./HW/hw5_1/hw.md)  
    >디바이스 드라이브 프로그램을 짜서 raspberrypi의 gpio핀에 연결된 LED를 키보드 입력을 통해서 제어한다.  
- [HW5_2](./HW/hw5_2/hw.md)  
    >디바이스 드라이브 프로그램을 짜서 raspberrypi의 gpio핀에 연결된 LED를 다른 gpio에 연결된 버튼을 통해서 제어한다.  

