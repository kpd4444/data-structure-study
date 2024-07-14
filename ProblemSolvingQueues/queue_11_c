#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define SIZE 100
typedef char element;


typedef struct DequeType {
    element elem[SIZE];
    int front, rear;

}DequeType;

void initDeque(DequeType* D)
{
    D->front = D->rear = 0; // 0부터 시작
}

int isEmpty(DequeType* D)
{
    return D->front == D->rear;
}

int isFull(DequeType* D)
{
    return (D->rear + 1) % SIZE == D->front; // 포화상태
}


void addRear(DequeType* D, char e)
{
    if (isFull(D))
    {
        printf("FULL\n");
        return;
    }
    D->rear = (D->rear + 1) % SIZE;
    D->elem[D->rear] = e;
}

void addFront(DequeType* D, char e) {
    if (isFull(D)) {
        printf("Full");
        return;
    }
    D->elem[D->front] = e;
    D->front = (D->front - 1 + SIZE) % SIZE;
}



void print(DequeType* D)
{
    printf("front pos : %d, rear pos : %d\n", D->front, D->rear);

    if (!isEmpty(D))
    {
        int i = D->front;
        do
        {
            i = (i + 1) % SIZE;
            printf("[%c] ", D->elem[i]);
            if (i == D->rear)
                break;
        } while (i != D->front);

    }
    printf("\n");
}



element deleteFront(DequeType* D)
{
    if (isEmpty(D))
    {
        printf("Empty\n");
        return 0;
    }
    D->front = (D->front + 1) % SIZE;
    return D->elem[D->front];
}

element deleteRear(DequeType* D)
{
    if (isEmpty(D))
    {
        printf("Empty\n");
        return 0;
    }
    element e = D->elem[D->rear];
    D->rear = (D->rear - 1 + SIZE) % SIZE;
    return e;
}

element getFront(DequeType* D)
{
    if (isEmpty(D))
    {
        printf("Empty\n");
        return 0;
    }
    return D->elem[(D->front + 1) % SIZE];
}

element getRear(DequeType* D)
{
    if (isEmpty(D))
    {
        printf("Empty\n");
        return 0;
    }
    element e = D->elem[D->rear];

    return e;
}


int main() {
	
    printf("문자열을 입력하시오: ");
    char str[SIZE];
    char c;
    int i = 0;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (c != ' ' && c != '\'' && c != '\"' && c != ',' && c != '.') {
            if (c >= 'A' && c <= 'Z') {
                c = c + ('a' - 'A');
            }
            str[i] = c;
            i++;
        }
    }
    str[i] = '\0';
    int n = strlen(str);
    
    DequeType d;
    initDeque(&d);
    
    for (int i = 0; i < n; i++) {
        addRear(&d, str[i]);
    }

    int check = 1;

    for (int i = 0; i < n; i++) {
        if (deleteRear(&d) != str[i]) {
            check = 0;
            break;
        }
    }

    if (check) {
        printf("회문입니다.");
    }
    else {
        printf("회문x");
    }

	return 0;
}
