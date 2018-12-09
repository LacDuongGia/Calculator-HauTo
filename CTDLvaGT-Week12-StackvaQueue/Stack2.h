//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <conio.h>
//
//typedef struct NODE
//{
//	char info;
//	NODE* pNext;
//}NODE;
//
//typedef struct STACK
//{
//	NODE* pHead = NULL;
//}STACK;
//
//NODE* createNode2(char x)
//{
//	NODE* p = new NODE;
//	p->info = x;
//	p->pNext = NULL;
//	return p;
//}
//
//bool isEmpty2(STACK stc)
//{
//	if (stc.pHead == NULL)
//		return true;
//	return false;
//}
//
//NODE* insertHead2(STACK &stc, char x)
//{
//	NODE* p = createNode(x);
//	p->pNext = stc.pHead;
//	stc.pHead = p;
//	return p;
//}
//
//bool push2(STACK &stc, char x)
//{
//	NODE* p = insertHead2(stc, x);
//	if (p != NULL)
//		return true;
//	return false;
//}
//
//char getTop2(STACK stc)
//{
//	if (!isEmpty(stc))
//	{
//		char x = stc.pHead->info;
//		return x;
//	}
//	return NULL;
//}
//
//void deleteHead2(STACK &stc)
//{
//	NODE* p = stc.pHead;
//	if (!isEmpty(stc))
//	{
//		stc.pHead = p->pNext;
//		delete p;
//	}
//}
//
//char pop2(STACK &stc)
//{
//	char x;
//	x = getTop(stc);
//	deleteHead(stc);
//	return x;
//}
//
//int insertInfo2(STACK &stc)
//{
//	char x;
//	int k;
//	do
//	{
//		scanf("%c", &x);
//		if (x == 27)
//		{
//			printf("Ban da dung viec nhap thong tin\n");
//			break;
//		}
//		push(stc, x);
//		k++;
//	} while (x != 27);
//	return k;
//}
//void xuatStack2(STACK stc)
//{
//	NODE* p = stc.pHead;
//	printf("Du lieu cua Stack la:\n");
//	while (p != NULL)
//	{
//		printf(" %c ", p->info);
//		p = p->pNext;
//	}
//}
////int main()
////{
////	STACK s;
////	printf("Nhap du lieu (Nhap 0 thi dung viec nhap):\n");
////	insertInfo(s);
////	xuatStack(s);
////	_getch();
////}
//
