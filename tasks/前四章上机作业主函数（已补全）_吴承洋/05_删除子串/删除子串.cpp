//ɾ���Ӵ��ĳ������
#include<stdio.h>
#include<string.h>
#include<malloc.h>
//˳�򴮵Ľṹ���Ͷ���
#define maxsize 256
typedef struct
{
	char str[maxsize];
	int length;
}seqstring;

void strPut(seqstring*);
int min(int a, int b);
void strDelete(seqstring*, int, int);
int main()
{
	seqstring* S;
	int pos, len;
	S = (seqstring*)malloc(sizeof(seqstring));
	printf("���봮��"); gets(S->str);
	S->length = strlen(S->str);
	strPut(S);
	printf("ɾ���Ŀ�ʼλ��:");scanf("%d", &pos);
	printf("ɾ�����ַ�����:");scanf("%d", &len);
	strDelete(S, pos, len);
	strPut(S);
}

//�����
void strPut(seqstring* S)
{
	int i;
	for (i = 0;i < S->length;i++)
		printf("%c", S->str[i]);
	printf("\n");printf("Length:%d\n", S->length);
}


//���ɾ���Ӵ��㷨
int min(int a, int b)
{
	if (a <= b) {
		return a;
	}
	else {
		return b;
	}

}

void strDelete(seqstring* s, int pos, int len)
{
	if (pos < 0 || pos > s->length || len < 0 || pos + len > s->length) {
		return;
	}
	for (int i = pos; i < s->length - len; i++) {
		s->str[i] = s->str[i + len];
	}
	s->length -= len;
}

