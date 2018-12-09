#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

typedef struct NODE
{
	char info;
	NODE* pNext;
}NODE;

typedef struct STACK
{
	NODE* pHead = NULL;
}STACK;

NODE* createNode(char x)
{
	NODE* p = new NODE;
	p->info = x;
	p->pNext = NULL;
	return p;
}

bool isEmpty(STACK s)
{
	if (s.pHead == NULL)
		return true;
	return false;
}

NODE* insertHead(STACK &s, char x)
{
	NODE* p = createNode(x);
	p->pNext = s.pHead;
	s.pHead = p;
	return p;
}

bool push(STACK &s, char x)
{
	NODE* p = insertHead(s, x);
	if (p != NULL)
		return true;
	return false;
}

NODE* SearchLast(STACK s)
{
	NODE* p = s.pHead;
	while (p != NULL)
	{
		if (p->pNext == NULL)
			return p;
		p = p->pNext;
	}
}

NODE* InsertTail(STACK &s, char x)
{
	NODE* q = createNode(x);
	NODE* last = SearchLast(s);
	if (last == NULL)
	{
		q->pNext = s.pHead;
		s.pHead = q;
	}
	else
	{
		last->pNext = q;
	}
	return q;
}

bool pushQ(STACK &s, char x) {
	NODE* p = InsertTail(s, x);
	if (p != NULL)
		return true;
	return false;
}

char getTop(STACK s)
{
	if (!isEmpty(s))
	{
		char x = s.pHead->info;
		return x;
	}
	return NULL;
}

void deleteHead(STACK &s)
{
	NODE* p = s.pHead;
	if (!isEmpty(s))
	{
		s.pHead = p->pNext;
		delete p;
	}
}

char pop(STACK &s)
{
	char x;
	x = getTop(s);
	deleteHead(s);
	return x;
}

void insertInfo(STACK &s)
{
	char x;
	do
	{
		scanf("\n");
		scanf("%c", &x);
		if (x == 'j')
		{
			printf("Ban da dung viec nhap thong tin\n");
			break;
		}
		push(s, x);
	} while (x != 'j');
}
void insertInfoQ(STACK &s)
{
	char x;
	do
	{
		scanf("\n");
		scanf("%c", &x);
		if (x == 'z')
		{
			printf("Ban da dung viec nhap thong tin\n");
			break;
		}
		pushQ(s, x);
	} while (x != 'z');
}
void xuatStack(STACK s)
{
	NODE* p = s.pHead;
	printf("Du lieu cua Stack la:\n");
	while (p != NULL)
	{
		printf(" %c ", p->info);
		p = p->pNext;
	}
}
//int main()
//{
//	STACK s;
//	printf("Nhap du lieu (Nhap 0 thi dung viec nhap):\n");
//	insertInfo(s);
//	xuatStack(s);
//	_getch();
//}
