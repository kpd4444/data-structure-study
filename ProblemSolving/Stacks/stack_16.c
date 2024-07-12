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
	
	printf("문자열을 입력하시오: ");
	char str[N];
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
	printf("%s", str);
	int n = strlen(str);
	for (int i = 0; i < n; i++) {
		push(&s, str[i]);
	}
	int check = 1;
	for (int i = 0; i < n; i++) {
		if (pop(&s) != str[i]) {
			check = 0;
			break;
		}
	}
	if (check == 1) {
		printf("회문입니다\n");
	}
	else {
		printf("회문 아닙니다\n");
	}
	return 0;
}
