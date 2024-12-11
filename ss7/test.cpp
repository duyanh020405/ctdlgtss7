#include <stdio.h>
#include <stdlib.h>
#define MAX 8 

typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Queue;
void initializeQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(Queue* queue) {
    return (queue->front == -1);
}

int isFull(Queue* queue) {
    return ((queue->rear + 1) % MAX == queue->front);
}

void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Hang doi da day, vui long thu lai sau.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->arr[queue->rear] = value;
    printf("Da them: %d\n", value);
}

int dequeue(Queue * queue){
	if(isEmpty(queue)){
		printf("ham doi rong , khong the xoa");
		return -1;
	}
	else{
		queue->front = (queue->front+1) %MAX;
	}
}
void printList(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong.\n");
        return;
    }
    printf("Cac phan tu trong hang doi:\n");
    int i = queue->front;
    while (1) {
        printf("%d\n", queue->arr[i]);
        if (i == queue->rear) break;
        i = (i + 1) % MAX;
    }
}

int main() {
    int value;
    Queue queue;
    initializeQueue(&queue);

    while (1) {
        printf("\n================= Menu ====================\n");
        printf("0. Thoat\n");
        printf("1. Them phan tu\n");
        printf("2. Xoa phan tu\n");
        printf("3. In cac phan tu\n");
        printf("===========================================\n");
        int choice;
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                exit(0);
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 2:
                value = dequeue(&queue);
                break;
            case 3:
                printList(&queue);
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    }

    return 0;
}

