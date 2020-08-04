#include <stdio.h>
#include <string.h>
#include "myheader.h"

Student StAr[11]={{"1","학생1"},{"2","학생2"},{"3","학생3"},{"4","학생4"},{"5","학생5"},{"6","학생6"},{"7","학생7"},{"8","학생8"},{"9","학생9"},{"10","학생10"}};
// StAr이라는 Student배열을 만들어 학생 10명의 정보를 저장.

void search(char kwd[10]){
	int t, index; // StAr내의 주소를 저장할 index와 학번과 이름을 구별해줄 변수 t 선언

	for(int i=0;i<10;i++){ // 10명의 정보중 인자로 받아온 문자열과 일치하는 문자열을 찾기위한 반복문
		if(strcmp(kwd,StAr[i].name)==0){
			t=1; 
			index=i; 
		} // 문자열 kwd와 학생의 이름이 같다면 StAr 배열 내 주소를 저장하고 t에 1의 값을 저장
		else if(strcmp(kwd,StAr[i].numb)==0){
			t=2;
			index=i;
		} // kwd와 학번이 같다면 주소를 저장하고 t에 2의 값을 저장
	}
	if(t==1){
		printf("--> %s \n", StAr[index].numb);
		// t=1이라면 학생의 학번을 출력
	}
	else if(t==2){
		printf("--> %s \n", StAr[index].name);
		// t=2면 학생의 이름을 출력
	}
	else printf("다시 입력해주세요.\n");
	// kwd와 일치하는 단어가 없을경우 다시입력하라고 출력

};
