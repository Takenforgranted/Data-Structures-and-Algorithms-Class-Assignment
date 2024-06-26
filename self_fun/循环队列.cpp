//循环队列入队出队
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
//循环队列的结构类型定义
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

//置空队
void setnull(qu* sq)
{
   sq->rear = m - 1;
   sq->quelen = 0;
}

// 判断是否队满
int JudgeFull(qu* sq)
{
   if (sq->quelen == m) {
      printf("队列已满。\n");
      return 1;
   }
   else {
      printf("队列未满。\n");
      return 0;
   }
}

// 添加入队算法
void enqueue(qu* sq, datatype x)
{
   if (sq->quelen == m) {
      printf("队列已满，无法入队。\n");
      return;
   }
   sq->rear = (sq->rear + 1) % m;
   sq->cycque[sq->rear] = x;
   sq->quelen++;
}

// 添加出队算法
datatype* dequeue(qu* sq)
{
   if (sq->quelen == 0) {
      printf("队列为空，无法出队。\n");
      return NULL;
   }
   datatype* p = &(sq->cycque[(sq->rear - sq->quelen + 1 + m) % m]);
   sq->quelen--;
   return p;
}