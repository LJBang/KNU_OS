## HW2

#### 개요
디바이스 드라이브 프로그램을 짜서 raspberrypi의 gpio핀에 연결된 LED를 키보드 입력을 통해서 제어한다.  

#### 코드 구조  
**main.c**  
main함수 1개로 구성, scanf문을 통해 A, B 둘 중 하나를 입력 받는다.  

A를 입력 받았을 경우  
디바이스 디렉토리의 ‘ledtest’ 파일을 실행하고, 반복문을 통해 write함수와 read함수를 세번 수행한다.  
0.5초마다 한 번씩 점멸해야 하므로 두 함수 사이에 0.5초의 딜레이를 유지한다.
write/read함수는 ‘led_module.c’파일의 gpio_write/gpio_read 함수와 연결된다.  
write함수는 값으로 1을 저장하고 있는 문자열인 on을 인자로 받아 실행해 LED를 켜고,  
0.5초가 지난 뒤 ‘0’값을 저장하는 off 문자열을 인자로 받아서 다시 실행해 LED불을 끈다.  
read함수는 문자열 변수 buf에 on 문자열과 off문자열을 다시 저장하고 이를 printf함수를 통해서 출력해 write/read함수가 제대로 동작하였는지 확인한다.  

B를 입력 받았을 경우  
scanf함수를 통해 문자를 하나 더 입력 받는다.  
입력 받은 문자가 1일 경우 write함수의 on문자열을 인자로 넣고 실행시켜 LED의 불을 키고, 0을 입력 받았을 경우 LED불을 끈다.


**led_module.c**  
GPIO_MAJOR 값은 243, GPIO_MINOR 값은 0, LED와 연결된 GPIO_NUM 값은 6번으로 지정했다.  
start_module함수에서 GPIO의 입출력 모두를 6번으로 지정했다.  
gpio_read함수에서는 인자로 받은 문자열을 복사한 다음 리턴 값으로 되돌려준다.  
gpio_write함수에서는 인자로 받은 문자열을 삼항연산자를 통해서 `0`값과 비교한 후  
문자열이 `0`값과 같으면 GPIO_CLR 함수를 통해서 LED가 연결된 gpio에 신호를 보내 LED불을 끄고,  
`0`값과 같지 않다면 LED불을 킨다.  
module_init을 통해 모듈을 실행하고 module_exit을 통해 모듈을 종료한다.  

Makefile을 통해 led_module.c파일을 컴파일하고, led_module.ko파일을 생성한다.  
Insmod 명령어를 통해 led_module.ko파일을 ‘led_module’이라는 모듈로 등록하고,  
이를 이용해 mknod를 통해서 ‘ledtest’라는 디바이스 드라이버를 생성한다.  
