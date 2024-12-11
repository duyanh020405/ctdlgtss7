#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// Dinh nghia cau truc Queue
typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(Queue* queue) {
    return queue->front == -1;
}

int isFull(Queue* queue) {
    return queue->rear == MAX - 1;
}

void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Hang doi da day, khong the them phan tu.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0; 
    }
    queue->rear++;
    queue->arr[queue->rear] = value;
}

void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong, khong the lay phan tu.\n");
        return;
    }
    printf("Da lay phan tu %d ra khoi hang doi.\n", queue->arr[queue->front]);
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++; 
    }
}

void printList(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong.\n");
        return;
    }
    printf("Hang doi bao gom cac phan tu: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

void ktrong(Queue* queue){
	if (isEmpty(queue)) {
        printf("Hang doi rong.\n");
        return;
    }else{
    	printf("Hang doi co phan tu.\n");
	}
}
void peek(Queue* queue){
		if (isEmpty(queue)) {
        printf("Hang doi rong.\n");
        return;
    }
    queue->arr[queue->front];
    printf("phan tu dau tien :%d",queue->arr[queue->front]);
}
int main() {
    int value;
    Queue queue;
    initQueue(&queue);

    do {
        printf("\n=================Menu====================\n");
        printf("0. Thoat\n");
        printf("1. Them phan tu\n");
        printf("2. In phan tu\n");
        printf("3. Xoa phan tu dau\n");
        printf("4. Kiem tra rong \n");
        printf("5. Lay phan tu dau\n");
        printf("Nhap lua chon: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Thoat chuong trinh.\n");
                exit(0);
            case 1:
                printf("Moi ban nhap gia tri: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 2:
                printList(&queue);
                break;
            case 3:
                dequeue(&queue);
                break;
            case 4:
                ktrong(&queue);
                break;
            case 5:
                peek(&queue);
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
                break;
        }
    } while (1);

    return 0;
}

