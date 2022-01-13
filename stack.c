#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Stack
{
    int *arr;
    int len, cap;
} Stack;

Stack create(unsigned int capacity)
{
    Stack sl = {(int *)malloc(sizeof(int) * capacity), 0, capacity};
    return sl;
}

void push(Stack *sl, int val)
{
    if (sl->len == sl->cap)
    {
        printf("\nSTACK OVERFLOW ENCOUNTERED!");
        exit(1);
    }
    sl->arr[sl->len] = val;
    sl->len++;
}

int pop(Stack *sl)
{
    if (sl->len == 0)
    {
        printf("\nSTACK UNDERFLOW ENCOUNTERED!");
        exit(1);
    }
    sl->len--;
    return sl->arr[sl->len];
}

int peek(Stack *sl, unsigned int idx)
{
    return sl->arr[idx];
}

bool is_full(Stack *sl)
{
    if (sl->len == sl->cap)
        return true;
    return false;
}

bool is_empty(Stack *sl)
{
    if (sl->len == 0)
        return true;
    return false;
}

int count(Stack *sl)
{
    return sl->len;
}

void print(Stack *sl)
{
    printf("Stack: %d", sl->arr[0]);
    for (int i = 1; i < sl->len; i++)
        printf(", %d", sl->arr[i]);
    printf("\n");
}

int main(void)
{
    printf("Creating the stack to work on...\n");
    Stack obj = create(5);
    Stack *objp = &obj;

    push(objp, 3);
    push(objp, 4);
    push(objp, 5);
    print(objp);

    printf("\nPopping an item..\n");
    printf("Deleted item: %d\n", pop(objp));
    print(objp);

    printf("\nPeeking an item..\n");
    printf("Value peeked is: %d\n", peek(objp, 1));
}
