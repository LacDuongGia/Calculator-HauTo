//#include <stdio.h>
//
//typedef struct NODE {
//	char info;
//	NODE* pNext;
//} NODE;
//
//typedef struct {
//	NODE* pHead = NULL;
//	NODE* pTail = NULL;
//} LQUEUE;
//
//bool IsEmpty(LQUEUE q) 
//{
//	if (q.pHead == NULL)
//		return true;
//	return false;
//}
//
//NODE* SearchLast(LQUEUE q)
//{
//	NODE* p = q.pHead;
//	while (p != NULL)
//	{
//		if (p->pNext == NULL)
//			return p;
//		p = p->pNext;
//	}
//}
//
//NODE* CreateNode(char x)
//{
//	NODE* p = new NODE;
//	p->info = x;
//	p->pNext = NULL;
//	return p;
//}
//
//NODE* InsertTail(LQUEUE &q, char x)
//{
//	NODE* k = CreateNode(x);
//	NODE* last = SearchLast(q);
//	if (last == NULL)
//	{
//		k->pNext = q.pHead;
//		q.pHead = k;
//	}
//	else
//	{
//		last->pNext = k;
//	}
//	return k;
//}
//
//bool Push(LQUEUE &q, char x) {
//	NODE* p = InsertTail(q, x);
//	if (p != NULL)
//		return true;
//	return false;
//}
//
//void DeleteHead(LQUEUE &q)
//{
//	NODE* p = q.pHead;
//	if (!IsEmpty(q))
//	{
//		q.pHead = p->pNext;
//		delete p;
//	}
//}
//
//char Pop(LQUEUE &q) {
//	if (!IsEmpty(q)) {
//		char x = q.pHead->info;
//		DeleteHead(q);
//		return x;
//	}
//	return NULL;
//}
//
//char GetFront(LQUEUE q) {
//	if (!IsEmpty(q)) {
//		char x = q.pHead->info;
//		return x;
//	}
//	return NULL;
//}
//char GetRear(LQUEUE q) {
//	if (!IsEmpty(q)) {
//		char x = q.pTail->info;
//		return x;
//	}
//	return NULL;
//}
//
//void insertInfoQueue(LQUEUE &q)
//{
//	char x;
//	do
//	{
//		scanf("\n");
//		scanf("%c", &x);
//		if (x == 'z')
//		{
//			printf("Ban da dung viec nhap thong tin\n");
//			break;
//		}
//		Push(q, x);
//	} while (x != 'z');
//}
