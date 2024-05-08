#include <stdio.h>
#include <malloc.h>
#include <string.h>

// ���嵥����ṹ����
typedef char datatype;
typedef struct node
{
	datatype data;
	struct node* next;
} linklist;

// ����˳��ջ�ṹ����
const int maxsize = 40;
typedef struct
{
	datatype elements[maxsize];
	int top;
} stack;

void setnull(stack*&);
int length(linklist*);
void printlink(linklist*);
void create(linklist*&, datatype*);
void push(stack*, datatype);
datatype pop(stack*);
int symmetry(linklist*, stack*); // ���ַ����Ƿ����ĶԳƵĺ�������

int main()
{
	linklist* head;
	stack* s;
	datatype str[80];
	gets(str);
	create(head, str);
	printlink(head);
	setnull(s);
	if (symmetry(head, s)) {
		printf("�ַ���\"%s\"���ĶԳ�\n", str);
	}
	else {
		printf("�ַ���\"%s\"�������ĶԳ�\n", str);
	}
	return 0;
}

// ջ��ʼ��
void setnull(stack*& s)
{
	s = (stack*)malloc(sizeof(stack));
	s->top = -1;
}

// ��������
int length(linklist* head)
{
	linklist* p = head->next;
	int n = 0;
	while (p != NULL) {
		n++;
		p = p->next;
	}
	return n;
}

// ���������
void printlink(linklist* head)
{
	linklist* p = head->next;
	while (p != NULL) {
		printf("%c", p->data);
		p = p->next;
	}
	printf("\n");
}

// ��������ͷ���ĵ�����
void create(linklist*& head, datatype* str)
{
	datatype* p = str;
	linklist* s, * r;
	head = (linklist*)malloc(sizeof(linklist));
	r = head;
	while (*p != '\0') {
		s = (linklist*)malloc(sizeof(linklist));
		s->data = *p;
		r->next = s;
		r = s;
		p++;
	}
	r->next = NULL;
}

// ˳��ջ��ջ
void push(stack* s, datatype e)
{
	s->top++;
	s->elements[s->top] = e;
}

// ˳��ջ��ջ
datatype pop(stack* s)
{
	datatype temp;
	s->top--;
	temp = s->elements[s->top + 1];
	return temp;
}

// �ж��ַ����Ƿ����ĶԳ��㷨
/*ԭ��
���Ƚ��ַ����ֳ����룬��ǰ�벿���ַ���ջ��
Ȼ�󽫺�벿���ַ���ջ���ַ�����Ƚϣ����ȫ����ȣ����ж��ַ���Ϊ���ĶԳơ�
*/
int symmetry(linklist* head, stack* s)
{
	int len = length(head);
	int mid = len / 2;

	linklist* p = head->next;

	// ��ǰ�벿���ַ���ջ
	for (int i = 0; i < mid; i++) {
		push(s, p->data);
		p = p->next;
	}

	// ����ַ�������Ϊ�����������м��ַ�
	if (len % 2 != 0) {
		p = p->next;
	}

	// �Ƚ�ջ���ַ���ʣ�ಿ���ַ��Ƿ�Գ�
	while (p != NULL) {
		if (pop(s) != p->data) {
			return 0; // �������ĶԳ�
		}
		p = p->next;
	}

	return 1; // �����ĶԳ�
}
