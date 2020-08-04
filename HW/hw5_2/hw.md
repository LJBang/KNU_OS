## HW2

#### 개요

#### 코드 구조
**main.c**
디바이스 디렉토리의 ‘ledtest’ 파일을 실행하고,  
while문 내부에 write함수를 통해서 device drive와의 연결을 유지한다.  

**led_module.c**
Gpio의 입력값을 받기 위해서 <linux/gpio.h>헤더파일을 추가한다.  
GPIO_NUM1에 LED의 gpio핀 번호인 6을 넣고, GPIO_NUM2에 button의 gpio핀 번호인 21을 넣는다.  
Start_module함수에서 버튼을 input으로, led를 output으로 지정해 준다.  
Gpio_write함수에서 버튼의 gpio 입력 값을 받아서 만약 입력 값이 0이라면 버튼이 안 눌려져 있는 상태이므로 LED를 켜고,  
입력 값이 1이라면, LED를 끈다.
