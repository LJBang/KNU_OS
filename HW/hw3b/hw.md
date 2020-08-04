## HW2

#### 개요
HW03의 프로그램에서 스레드를 줄이더라도 결과값에 오류가 생기도록 새로운 함수를 추가하고,  
mutex를 사용하여 thread간 thread간 스케쥴링을 조절해 다시 정상적인 결과값을 출력한다.
#### 코드 구조  
먼저 뮤텍스 정보를 저장하기위해 전역변수로 pthread_mutex_t를 선언한다.  

swap(int k)  
스레드의 점유시간을 높여 오류가 있는 결과값을 만들기 위해서  
인자 k와 변수 tmp값을 10000번 서로 변환하고, k값을 반환한다.

add()  
Mutex_lock()함수를 사용해 critical section을 보호한다.  
반복문을 이용해 전역변수에 1을 더하는 작업을 10번 반복한다.  
반복문이 끝났으므로 mutex_unlock을 사용해 critical section 보호를 해제한다.  

sub()  
Mutex_lock()함수를 사용해 critical section을 보호한다.  
반복문을 이용해 전역변수에 1을 빼는 작업을 10번 반복한다.  
반복문이 끝났으므로 mutex_unlock을 사용해 critical section 보호를 해제한다.  
	
main  
Thread id를 받을 변수를 배열을 이용해서 10개를 생성한다.  
Pthread_mutex_init 함수를 사용해 뮤텍스를 초기화 한다.  
main함수의 argument를 전역변수 num에 저장한다.  
add() thread, sub() thread를 각 5개씩 만든다.  
pthread_join을 사용해서 자식 스레드들이 종료될 때까지 기다린다.  
num값을 출력한다.  
Pthread_mutex_destroy를 사용해 뮤텍스를 소멸시킨다.  
