#ifndef MYHEADER_H //중복선언 방지를 위한 헤더가드
#define MYHEADER_H 

typedef struct _Student{
	char numb[10];
	char name[10];
} Student;  // 학생의 이름과 학번을 데이터로 하는 _Student라는 구조체를 정의 후 Student type으로 정의


void search(char kwd[10]); // Search() 함수를 정의, 함수의 내용은 각 c파일에 따로 정의함

typedef struct listNode{
	char name[10];
	char numb[10];
	struct listNode *nextPtr;
}ListNode; // 학생의 이름과 학번을 데이터로 갖는 listNode라는 단일 연결 리스트 구조체를 만들어,  ListNode 라는 type을 만듦


#endif
