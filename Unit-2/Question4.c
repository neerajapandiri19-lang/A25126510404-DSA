#include <stdio.h>
#define SIZE 5

int queue[SIZE], front = -1, rear = -1;

void insert(int value) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue is full (overflow).\n");
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("Inserted: %d\n", value);
}

void deleteItem(void) {
    if (front == -1) {
        printf("Queue is empty (underflow).\n");
        return;
    }
    printf("Deleted: %d\n", queue[front]);
    if (front == rear) front = rear = -1;
    else front = (front + 1) % SIZE;
}

void display(void) {
    int i;
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main(void) {
    insert(10); insert(20); insert(30); insert(40); insert(50);
    display();
    deleteItem(); deleteItem();
    display();
    insert(60); insert(70); 
    display();
    insert(80);             
    deleteItem();
    display();
    return 0;
}
