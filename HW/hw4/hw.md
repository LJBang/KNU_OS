## HW2

#### 개요
Stack과 Heap이 같은 메모리를 사용하므로, Stack과 Heap을 늘려가면서 두 영역이 충돌하는지 확인하고 그 지점을 찾는다.  
이번 과제에서는 While문을 통한 반복으로 malloc함수를 이용해 Heap의 메모리를 유한하게 할당한 후  
RecusiveRoutine() 함수를 사용해 Stack영역의 메모리를 무한하게 할당하는 방법으로 진행하였다.  

#### 코드 구조

main함수에서 argument를 2개 받는다. 첫번째 인자는 할당할 Heap의 개수를 결정한다.  
두번째 인자는 Heap에 할당된 가상 메모리를 물리적 메모리에 쓰거나, 읽거나, 아무것도 하지 않을지 결정한다.  
먼저 Stack의 시작 점과, Heap의 시작 점을 표시한 후  
while 반복문 안에서 MemoryPtr포인터 변수에 malloc() 함수를 사용해서 1mb씩 Heap 메모리에 저장하고, 메모리의 주소를 출력하는 것을 반복한다.  

Heap영역에 정해진 수만큼 동적 메모리 할당이 완료되면 그 후에RecursiveRoutine함수를 호출한다.  
RecursiveRoutine 함수는 무한히 재귀반복을 하면서, 1mb의 변수를 선언하고, 메모리의 주소를 출력한다.  
Commas, prepend, preprintf 함수를 사용해서 주소 값을 보기 좋게 4자리 씩 끊어 준다.  
