#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"myheader.h"

void search(char kwd[10]){
	
	// 학생 10명을 Linked_List형태로 저장
	ListNode *Head = malloc(sizeof(ListNode));

	ListNode *St1 = malloc(sizeof(ListNode));
	strcpy(St1->name,"학생1");
	strcpy(St1->numb,"1");
	Head->nextPtr = St1;
	
	ListNode *St2 = malloc(sizeof(ListNode));
	strcpy(St2->name,"학생2");
	strcpy(St2->numb,"2");
	St1->nextPtr = St2;
	
	ListNode *St3 = malloc(sizeof(ListNode));
	strcpy(St3->name,"학생3");
	strcpy(St3->numb,"3");
	St2 ->nextPtr = St3;
	
	ListNode *St4 = malloc(sizeof(ListNode));
	strcpy(St4->name,"학생4");
	strcpy(St4->numb,"4");
	St3 ->nextPtr = St4;
	
	ListNode *St5 = malloc(sizeof(ListNode));
	strcpy(St5->name,"학생5");
	strcpy(St5->numb,"5");
	St4 ->nextPtr = St5;
	
	ListNode *St6 = malloc(sizeof(ListNode));
	strcpy(St6->name,"학생6");
	strcpy(St6->numb,"6");
	St5 ->nextPtr = St6;
	
	ListNode *St7 = malloc(sizeof(ListNode));
	strcpy(St7->name,"학생7");
	strcpy(St7->numb,"7");
	St6 ->nextPtr = St7;

	ListNode *St8 = malloc(sizeof(ListNode));
	strcpy(St8->name,"학생8");
	strcpy(St8->numb,"8");
	St7 ->nextPtr = St8;
 
	ListNode *St9 = malloc(sizeof(ListNode));
	strcpy(St9->name,"학생9");
	strcpy(St9->numb,"9");
	St8 ->nextPtr = St9;
 
	ListNode *St10 = malloc(sizeof(ListNode));
	strcpy(St10->name,"학생10");
	strcpy(St10->numb,"10");
	St9 ->nextPtr = St10;
	St10 -> nextPtr = NULL;
 
	int t=0; // 출력이 되었는지 확인하는 변수 t
	ListNode *temp=Head->nextPtr; // 연결 리스트들을 처음부터 탐색하기위해 temp 에 Head값을 저장

	while(temp != NULL){ // temp가 연결 리스트들을 순차적으로 탐색하면서 kwd와 같은 문자열 찾기
		if(strcmp(kwd,temp->name)==0){
			printf("-->%s\n",temp->numb); // kwd와 이름이 같다면 학번 출력
			t=1;
		}
		else if(strcmp(kwd,temp->numb)==0){
			printf("-->%s\n",temp->name); // kwd와 학번이 같다면 이름 출력
			t=1;
		}
		temp = temp->nextPtr;

	}
	if(t==0) printf("다시 입력해주세요\n");
	//kwd와 일치하는 문자열이 없을경우 다시입력해주세요 출력

	// malloc으로 할당된 메모리 해제
	free(Head);
	free(temp);
	free(St1);
	free(St2);
	free(St3);
	free(St4);
	free(St5);
	free(St6);
	free(St7);
	free(St8);
	free(St9);
	free(St10);
};
