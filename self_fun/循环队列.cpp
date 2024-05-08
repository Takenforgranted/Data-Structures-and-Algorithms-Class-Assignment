//ѭ��������ӳ���
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
//ѭ�����еĽṹ���Ͷ���
const int m = 5;
typedef int datatype;
typedef struct
{
   datatype cycque[m];
   int  rear, quelen;
}qu;
void setnull(qu*);
int JudgeFull(qu*);
void enqueue(qu*, datatype);
datatype* dequeue(qu*);

int main()
{
   qu* sq;
   datatype x, * p;
   int key, s = -1;
   sq = (qu*)malloc(sizeof(qu));
   setnull(sq);
   do {
      printf("1.Enter Queue   2.Delete Queue  3.Judge IFFull   -1.Quit:");
      scanf("%d", &key);
      switch (key) {
      case 1:  printf("Enter the Data:"); scanf("%d", &x);
         enqueue(sq, x);  break;
      case 2:  p = dequeue(sq);
         if (p != NULL) printf("%d\n", *p);
         break;
      case 3: s = JudgeFull(sq); printf("%d\n", s);
         break;
      case -1: exit(0);
      default: printf("Error Command!!!");
      }
   } while (1);
}

//�ÿն�
void setnull(qu* sq)
{
   sq->rear = m - 1;
   sq->quelen = 0;
}

// �ж��Ƿ����
int JudgeFull(qu* sq)
{
   if (sq->quelen == m) {
      printf("����������\n");
      return 1;
   }
   else {
      printf("����δ����\n");
      return 0;
   }
}

// �������㷨
void enqueue(qu* sq, datatype x)
{
   if (sq->quelen == m) {
      printf("�����������޷���ӡ�\n");
      return;
   }
   sq->rear = (sq->rear + 1) % m;
   sq->cycque[sq->rear] = x;
   sq->quelen++;
}

// ��ӳ����㷨
datatype* dequeue(qu* sq)
{
   if (sq->quelen == 0) {
      printf("����Ϊ�գ��޷����ӡ�\n");
      return NULL;
   }
   datatype* p = &(sq->cycque[(sq->rear - sq->quelen + 1 + m) % m]);
   sq->quelen--;
   return p;
}