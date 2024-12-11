#include <stdio.h>
#include <string.h>
#define MAX 5

typedef struct {
    int priority; 
    char data[50]; 
} Element;

typedef struct {
    Element arr[MAX];
    int size; 
} PriorityQueue;

void initQueue(PriorityQueue *queue) {
    queue->size = 0;
}

int isEmpty(PriorityQueue *queue) {
    return queue->size == 0;
}

int isFull(PriorityQueue *queue) {
    return queue->size == MAX;
}

void enqueue(PriorityQueue *queue, int priority, char *data) {
    if (isFull(queue)) {
        printf("Hang doi da day. Khong the them phan tu.\n");
        return;
    }

    int i = queue->size - 1;
    while (i >= 0 && queue->arr[i].priority > priority) {
        queue->arr[i + 1] = queue->arr[i]; 
        i--;
    }

    queue->arr[i + 1].priority = priority;
    strcpy(queue->arr[i + 1].data, data);
    queue->size++;

    printf("Da them phan tu (%d, \"%s\") vao hang doi.\n", priority, data);
}

void dequeue(PriorityQueue *queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong. Khong co phan tu de lay.\n");
        return;
    }

    printf("Da lay phan tu co uu tien cao nhat: \"%s\" (uu tien %d).\n", queue->arr[0].data, queue->arr[0].priority);

    for (int i = 1; i < queue->size; i++) {
        queue->arr[i - 1] = queue->arr[i];
    }
    queue->size--;
}

void printQueue(PriorityQueue *queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong.\n");
        return;
    }

    printf("Hang doi hien tai: ");
    for (int i = 0; i < queue->size; i++) {
        printf("(%d, \"%s\") ", queue->arr[i].priority, queue->arr[i].data);
    }
    printf("\n");
}


int main() {
    PriorityQueue queue;
    initQueue(&queue);

    enqueue(&queue, 2, "Task A");
    printQueue(&queue);

    enqueue(&queue, 1, "Task B");
    printQueue(&queue);

    enqueue(&queue, 3, "Task C");
    printQueue(&queue);

    dequeue(&queue);
    printQueue(&queue);

    dequeue(&queue);
    printQueue(&queue);

    return 0;
}
