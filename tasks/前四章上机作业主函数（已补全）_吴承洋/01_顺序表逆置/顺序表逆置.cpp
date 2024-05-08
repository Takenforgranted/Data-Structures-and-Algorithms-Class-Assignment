//˳�������.cpp
#include <stdio.h>
#include <malloc.h>
typedef char datatype;
const int maxsize = 1024;

typedef struct {
	datatype data[maxsize];
	int last;
} sequenlist;
void create(sequenlist *&);
void print(sequenlist *);
void invert(sequenlist *);

int main() {
	sequenlist *L;
	create(L);//����˳���
	print(L);//���˳���
	invert(L);//����˳�����ֵ�ĺ���
	print(L);//���˳���

	return 0;
}

//����˳���
void create(sequenlist *&L) {
	L = (sequenlist *)malloc(sizeof(sequenlist));
	L->last = 0;
	char ch;
	while ((ch = getchar()) != '*') {
		L->last++;
		L->data[L->last] = ch;
	}
}

//���˳���
void print(sequenlist *L) {
	for (int i = 1; i <= L->last; i++)
		printf("%2c", L->data[i]);
	printf("\n");
}

//���˳��������㷨
void invert(sequenlist *L) {
	int i = 1, j = L->last;
	while (i < j) {
		int t = L->data[i];
		L->data[i] = L->data[j];
		L->data[j] = t;
		i++;
		j--;
	}


}

