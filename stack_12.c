#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 100

typedef char element;

typedef struct StackType
{
	int top;
	element stack[N];

}StackType;

void init(StackType* S) {
	S->top = -1;
}

int isFull(StackType* S) {
	return S->top == N - 1;
}

int isEmpty(StackType* S) {
	return S->top == -1;
}

void push(StackType* S, char c) {
	if (isFull(S))
		printf("Overflow!\n");
	else {
		S->top++;
		S->stack[S->top] = c;
	}
}

element peek(StackType* S) {
	if (isEmpty(S)) {
		printf("Empty!\n");
		return -1;
	}
	element c = S->stack[S->top];
	return c;
}

element pop(StackType* S) {
	if (isEmpty(S)) {
		printf("Empty!\n");
		return -1;
	}
	element c = S->stack[S->top];
	S->top--;
	return c;
}



int main() {
	StackType s;
	init(&s);

	char word[N];
	printf("문자열을 입력하시오: ");
	scanf("%s", word);
	int n = strlen(word);

	char c;
	
	for (int i = 0; i < n; i++) {
		c = word[i];
		if (c >= 'A' && c <= 'Z') {
			c = c + ('a' - 'A');
		}
		word[i] = c;
	}
	push(&s, word[0]);
	int num = 1;
	for (int i = 1; i < n; i++) {
		if (word[i] == peek(&s)) {
			num++;
			push(&s, word[i]);
		}
		else {
			printf("%d%c", num, peek(&s));
			while (!isEmpty(&s)) {
				pop(&s);
			}
			push(&s, word[i]);
			num = 1;
		}
		if (i == n - 1) {
			printf("%d%c", num, peek(&s));
		}
	}

	return 0;
}

