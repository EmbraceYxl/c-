# include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];
	int length;
}SqList;

bool ListInsert(SqList &L, int i,ElemType e) {
	if (i<1 || i>L.length + 1)
		return false;
	if (L.length >= MaxSize)
		return false;
	for (int j = L.length; j >= i; j--)
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = e;
	L.length++;
	return true;
}

// 删除某一个元素
bool ListDel(SqList& L,int i ,ElemType &e) {
	if (i<1 || i>L.length)
		return false;
	if (L.length == 0) {
		return false;
	}
	e = L.data[i - 1];
	for (int j = i; j < L.length; j++)
		L.data[j - 1] = L.data[j];
	L.length--;
	return true;
}


// 判断某一个元素是否存在
int LocateElem(SqList L, ElemType e) {
	int i;
	for (i = 0; i < L.length; i++)
		if (L.data[i] == e)
			return i + 1;
	return 0;
}

void PrintList(SqList& L) {
	for (int i = 0; i < L.length; i++) {
		printf("%5d", L.data[i]);
	}
	printf("\n");
}

int main() {
	SqList L; 
	bool ret,ret_d,ret_f;
	ElemType del_num,elem_pos; 
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.data[3] = 11;
	L.data[4] = 60;
	L.data[5] = 7;
	L.data[6] = 5;
	L.length = 7;
	ret = ListInsert(L, 2, 60);
	if (ret) {
		printf("插入成功\n");
		PrintList(L);
	}
	else
	{
		printf("插入失败");
	}
	ret_d = ListDel(L, 2, del_num);
	if (ret_d) {
		printf("删除成功！！！\n");
		printf("删除的元素为  %d\n", del_num);
		PrintList(L);
	}
	else
	{
		printf("删除失败！！！\n");
	}
	L.data[4] = 66;
	elem_pos = LocateElem(L, 60);
	if (elem_pos) {
		printf("所在的位置是 %d 位\n", elem_pos);
		PrintList(L);
	}
	else
	{
		printf("该元素不存在！！！\n");
		PrintList(L);
	}
	return 0;
}
