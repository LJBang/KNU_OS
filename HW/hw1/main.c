#include <stdio.h>
#include <string.h> // 문자열 처리하기 위함
#include <stdlib.h> // malloc, free 사용하기 위함
#include "myheader.h" // 직접 만든 헤더

int main(){
	
	char input[10];

	printf("입력: ");
	scanf("%[^\n]s",input);

	search(input); // search() 함수는 각 c파일에 따로 구현함

	return 0;
}
