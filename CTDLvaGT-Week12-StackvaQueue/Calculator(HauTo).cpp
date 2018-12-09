#include "Stack.h"
#include "Stack2.h"
#include "Queue.h"

int doUuTien(char o1)
{
	switch (o1)
	{
	case '(':
		return 0;
	case '+':
		return 1;
	case '-':
		return 1;
	case '*':
		return 2;
	case '/':
		return 2;
		//Neu o1 == NULL thi tra ve -1 (truong hop dac biet khi stack s chua co phan tu)
	default:return -1;
	}
}
float tinhGiaTri(char dau, char o2, char o3)
{
	switch (dau)
	{
	case '+':
		return o2 + o3;
	case '-':
		return o2 - o3;
	case '*':
		return o2 * o3;
	case '/':
	{
		if (o3 == 0)
			return NULL;
		else
			return o2 / o3;
	}
	default: break;
	}
}

void bieuDienTrungToBangHauTo(STACK &s, STACK &kq, STACK &str)
{
	char x;
	for (str.pHead; str.pHead != NULL; str.pHead)
	{
		if (str.pHead->info >= '0' && str.pHead->info <= '9')
		{
			x = pop(str);
			pushQ(kq, x);
		}
		else if (str.pHead->info == '(')
		{
			x = pop(str);
			push(s, x);
		}
		else if (str.pHead->info == '+' || str.pHead->info == '-' || str.pHead->info == '*' || str.pHead->info == '/')
		{
			x = pop(str);
			//Vong lap so sanh o1 voi cac phan tu trong stack s
			do
			{
				if (doUuTien(x) <= doUuTien(getTop(s)))
				{
					char q = pop(s);
					pushQ(kq, q);
				}
				else
				{
					push(s, x);
					break;
				}
			} while (1);
		}
		else if (str.pHead->info == ')')
		{
			//Xoa phan tu ')' trong stack str
			pop(str);
			while (s.pHead->info != '('&&s.pHead != NULL)
			{
				x = pop(s);
				pushQ(kq, x);
			}
			pop(s);
		}
	}
	if (str.pHead == NULL)
	{
		while (s.pHead != NULL)
		{
			x = pop(s);
			pushQ(kq, x);
		}
	}
}

float tinhGiaTriBieuThucHauTo(STACK &kq, STACK btht)
{
	char dau;
	int x, y;
	float k;
	for (btht.pHead; btht.pHead != NULL; btht.pHead)
	{
		if (btht.pHead->info >= '0'&&btht.pHead->info <= '9')
		{
			k = pop(btht);
			push(kq, k);
		}
		else if (btht.pHead->info == '+' || btht.pHead->info == '-' || btht.pHead->info == '*' || btht.pHead->info == '/')
		{

			x = pop(kq) - '0';
			y = pop(kq) - '0';
			dau = pop(btht);
			k = tinhGiaTri(dau, y, x);
			push(kq, k + 48);
		}
	}
	return kq.pHead->info - 48;
}

int main()
{
	STACK str;
	STACK s;
	STACK kq;
	STACK giaTri;
	printf("Nhap bieu thuc can tinh toan:\n");
	insertInfoQ(str);
	bieuDienTrungToBangHauTo(s, kq, str);
	xuatStack(kq);
	printf("\n");
	printf("Tinh toan gia tri bieu thuc hau to\n");
	printf("Gia tri bieu thuc hau to sau la: %.1f\n", tinhGiaTriBieuThucHauTo(giaTri, kq));
	_getch();
}
