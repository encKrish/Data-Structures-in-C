#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Queue
{
    int *arr;
    int front_idx, rear_idx;
    int len, cap;
} Queue;

Queue create(unsigned int capacity)
{
    Queue qe = {(int *)malloc(sizeof(int) * capacity), -1, -1, 0, capacity};
    return qe;
}

void enqueue(Queue *qe, int val)
{
    if (qe->len == qe->cap)
    {
        printf("\nQUEUE OVERFLOW ENCOUNTERED!");
        exit(1);
    }
    if (qe->front_idx == -1)
        qe->front_idx = 0;

    qe->rear_idx++;
    qe->rear_idx %= qe->cap;

    qe->arr[qe->rear_idx] = val;
    qe->len++;
}

int dequeue(Queue *qe)
{
    if (qe->len == 0)
    {
        printf("\nQUEUE UNDERFLOW ENCOUNTERED!");
        exit(1);
    }

    int val = qe->arr[qe->front_idx];
    qe->front_idx++;
    qe->front_idx %= qe->cap;

    qe->len--;
    return val;
}

int peek_front(Queue *qe, unsigned int idx)
{
    if (idx >= qe->len)
    {
        printf("\nCannot peek that far! Not enough elements.");
        exit(1);
    }
    idx += qe->front_idx;
    idx %= qe->cap;
    return qe->arr[idx];
}

int peek_rear(Queue *qe, unsigned int idx)
{
    if (idx >= qe->len)
    {
        printf("\nCannot peek that far! Not enough elements.");
        exit(1);
    }
    int sidx = qe->rear_idx - idx;
    if (sidx < 0)
        sidx += qe->cap;
    return qe->arr[sidx];
}

bool is_full(Queue *qe)
{
    if (qe->len == qe->cap)
        return true;
    return false;
}

bool is_empty(Queue *qe)
{
    if (qe->len == 0)
        return true;
    return false;
}

int count(Queue *qe)
{
    return qe->len;
}

void print(Queue *qe)
{
    printf("Queue: %d", qe->arr[qe->front_idx]);
    for (int i = 1; i < qe->len; i++)
    {
        int idx = (qe->front_idx + i) % qe->cap;
        printf(", %d", qe->arr[idx]);
    }
    printf("\n");
}

void print_direct(Queue *qe)
{
    printf("WARNING: print_direct can print values illegal to access in the queue!\n");
    printf("Queue (direct): %d", qe->arr[0]);
    for (int i = 1; i < qe->len; i++)
        printf(", %d", qe->arr[i]);
    printf("\n");
}

int main(void)
{
    Queue obj = create(3);
    Queue *objp = &obj;

    enqueue(objp, 3);
    enqueue(objp, 4);
    enqueue(objp, 5);
    print(objp);

    printf("Dequeued item: %d\n", dequeue(objp));
    print(objp);

    enqueue(objp, 6);
    print(objp);
    printf("Dequeued item: %d\n", dequeue(objp));
    print(objp);
    print_direct(objp);
    printf("Peeking 2nd from front: %d\n", peek_front(objp, 1));
    printf("Dequeued item: %d\n", dequeue(objp));
    print(objp);
    enqueue(objp, 7);
    print(objp);
    enqueue(objp, 8);
    print(objp);
    printf("Peeking 2nd from rear: %d\n", peek_rear(objp, 1));
    printf("Dequeued item: %d\n", dequeue(objp));
    print(objp);
    enqueue(objp, 9);
    print(objp);

    // printf("\nPeeking an item..\n");
    // printf("Value peeked is: %d\n", peek(objp, 1));
}
