#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int size;
} Deque;

void initDeque(Deque *deque) {
    deque->front = -1;
    deque->rear = -1;
    deque->size = 0;
}


int isEmpty(Deque *deque) {
    return deque->size == 0;
}

int isFull(Deque *deque) {
    return deque->size == MAX;
}

void addFront(Deque *deque, int data) {
    if (isFull(deque)) {
        printf("Deque dã day. Không the thêm phan tu.");
        return;
    }
    if (deque->front == -1) {
        deque->front = deque->rear = 0;
    } else {
        deque->front = (deque->front - 1 + MAX) % MAX;
    }
    deque->arr[deque->front] = data;
    deque->size++;
    printf("Da them phan tu %d vao dau Deque.", data);
}

void addRear(Deque *deque, int data) {
    if (isFull(deque)) {
        printf("Deque dã day");
        return;
    }
    if (deque->rear == -1) {
        deque->front = deque->rear = 0;
    } else {
        deque->rear = (deque->rear + 1) % MAX;
    }
    deque->arr[deque->rear] = data;
    deque->size++;
    printf("Da them phan tu %d vao cuoi Deque.
", data);
}

void removeFront(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque rong. Không the lay.");
        return;
    }
    printf("Da lay phan tu %d tu dau Deque.
", deque->arr[deque->front]);
    deque->front = (deque->front + 1) % MAX;
    deque->size--;
    if (deque->size == 0) {
        deque->front = deque->rear = -1;
    }
}


void removeRear(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque rong. Không the lay.");
        return;
    }
    printf("Da lay phan tu %d tu cuoi Deque.
", deque->arr[deque->rear]);
    deque->rear = (deque->rear - 1 + MAX) % MAX;
    deque->size--;
    if (deque->size == 0) {
        deque->front = deque->rear = -1;
    }
}

void printDeque(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque rong.
");
        return;
    }

    printf("Deque hien tai: ");
    for (int i = 0, idx = deque->front; i < deque->size; i++) {
        printf("%d ", deque->arr[idx]);
        idx = (idx + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Deque deque;
    initDeque(&deque);

    addFront(&deque, 10);
    printDeque(&deque);

    addRear(&deque, 20);
    printDeque(&deque);

    addFront(&deque, 5);
    printDeque(&deque);

    removeFront(&deque);
    printDeque(&deque);

    removeRear(&deque);
    printDeque(&deque);

    return 0;
}
