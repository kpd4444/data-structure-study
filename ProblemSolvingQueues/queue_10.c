#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define SIZE 100

typedef int element;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

typedef int element;

typedef struct QueueType {
    element elem[SIZE];
    int front, rear;

}QueueType;

void initQueue(QueueType* Q)
{
    Q->front = Q->rear = 0; // 0부터 시작
}

int isEmpty(QueueType* Q)
{
    return Q->front == Q->rear;
}

int isFull(QueueType* Q)
{
    return (Q->rear + 1) % SIZE == Q->front; // 포화상태
}

void enqueue(QueueType* Q, char e)
{
    if (isFull(Q))
    {
        printf("FULL\n");
        return;
    }
    Q->rear = (Q->rear + 1) % SIZE;
    Q->elem[Q->rear] = e;
}

void print(QueueType* Q)
{
    printf("front pos : %d, rear pos : %d\n", Q->front, Q->rear);

    if (!isEmpty(Q))
    {
        int i = Q->front;
        do
        {
            i = (i + 1) % SIZE;
            printf("[%c] ", Q->elem[i]);
            if (i == Q->rear)
                break;
        } while (i != Q->front);

    }
    printf("\n");
}

element dequeue(QueueType* Q)
{
    if (isEmpty(Q))
    {
        printf("Empty\n");
        return 0;
    }
    Q->front = (Q->front + 1) % SIZE;
    return Q->elem[Q->front];
}

element peek(QueueType* Q)
{
    if (isEmpty(Q))
    {
        printf("Empty\n");
        return 0;
    }
    return Q->elem[(Q->front + 1) % SIZE];
}


int Fib(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	QueueType q;
	initQueue(&q);

	enqueue(&q, 0);
	enqueue(&q, 1);

	int i = 2;
	int num1, num2;
	while (i <= n) {
		
		i++;
		num1 = dequeue(&q);
        //printf("num1 = %d\n", num1);
		num2 = peek(&q);
        //printf("num2 = %d\n", num2);
		enqueue(&q, num1 + num2);
		if (i > n) {
			break;
		}
	}
    return num1 + num2;
}


int main() {
	
	printf("%d", Fib(5));

	return 0;
}
