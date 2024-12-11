#include <stdio.h>
#include <stdlib.h>
#define MAX 8 
typedef struct {
	int arr[MAX];
	int front;
	int rear;
	
}Quene;
//khoi tao hang doi
void intitalQuene(Quene* quene){
	quene->front = -1;
	quene->rear  = -1;
	
}

// kiem tra hang doi 
int isEmpty(Quene* quene){
	if(quene->front == -1){
		return 1;
	}
	return 0;
}

int isFull(Quene* quene){
	if(quene->rear <= MAX-1){
		return 1;
	}
	return 0;
}

// them 1 phan tu 
void enquene(Quene* quene, int value){
	if(isFull(quene)){
		printf("hang doi da day , vui long thu lai sau\n");
		return;
	}
	if(isEmpty(quene)){
		quene->front = 0;
	}
	quene->rear++;
	quene->arr[quene->rear] = value;
	
}
void printList(Quene*quene){
	printf("danh sach list : \n");
	for(int i = quene->front ; i<=quene->rear; i++){
		printf("%d\n",&quene->arr[i]);
	}
}
int main(){
	int value;
	Quene quene;
	intitalQuene(&quene);
	do{
		printf("\n=================Menu====================\n");
		printf("0.thoat");
		printf("1.them phan tu");
		printf("2.in phan tu");
		int choice;
		scanf("%d",&choice);
		switch(choice){
			case 0 :
				exit(0);
			case 1 :
				printf("moi ban nhap gia tri : ");
				scanf("%d",&value);
				enquene(&quene,value);
				break;
			case 2:
				printList(&quene);
				break;
		}
	}
	while(1==1){
		return 1;
	};
	

	
}
