## HW2

#### 개요
메인 프로그램에서 argument를 전역변수로 받아  
전역변수에 덧셈을 하는 thread 5000개, 뺄셈을 하는 thread 5000개를 만들어 각자 시행하고 결과값을 출력

#### 코드 구조  
add()  
반복문을 이용해 전역변수에 1을 더하는 작업을 10번, 100번, 1000번 반복한다.
	
sub()  
반복문을 이용해 전역변수에 1을 빼는 작업을 10번, 100번, 1000번 반복한다.
	
main  
Thread id를 받을 변수를 배열을 이용해서 10000개를 생성한다.  
main함수의 argument를 전역변수 num에 저장한다.  
add() thread, sub() thread를 각 5000개씩 만든다.  
pthread_join을 사용해서 자식 스레드들이 종료될 때까지 기다린다.  
num값을 출력한다.  