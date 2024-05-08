//模式匹配的程序代码
#include<stdio.h>
#include<string.h>
#include<malloc.h>
//顺序串的结构类型定义
#define maxsize 100
typedef struct
{
	char str[maxsize];
	int len;
}seqstring;

int  Index(seqstring*, seqstring*);

int main()
{
	seqstring* S, * subS;
	S = (seqstring*)malloc(sizeof(seqstring));
	subS = (seqstring*)malloc(sizeof(seqstring));
	printf("输入串："); gets(S->str);
	S->len = strlen(S->str);
	printf("输入子串："); gets(subS->str);
	subS->len = strlen(subS->str);
	if (Index(S, subS) > 0) printf("匹配成功！\n");
	else printf("匹配失败！\n");
}

//添加顺序串的朴素模式匹配算法
int  Index(seqstring* s, seqstring* sub_s)
{
	if (s->len < sub_s->len) {
		return -1;
	}
	for (int i = 0; i < s->len - sub_s->len + 1; i++) {
		int sign = 1;
		for (int j = 0, k = i; j < sub_s->len; j++, k++) {
			if (s->str[k] != sub_s->str[j]) {
				sign = 0;
			}
		}
		if (sign == 1) {
			return 1;
		}
	}
	return -1;
}














