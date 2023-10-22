#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node//压栈和出栈都在栈顶进行(这里的栈顶指前一段)
{
    char val;//数据
    struct node* next;//指针
}pnode;
typedef struct seqstack
{
    int size;//记录栈的大小
    pnode* top;//指向栈顶元素
}phead;
phead*  initstack()//创建栈
{
    phead* istack=(phead*)malloc(sizeof(phead));//为头节点分配空间
    if(istack!=NULL)//健壮性判断
    {
        istack->top=NULL;
        istack->size=0;
    }
    return istack;
}
int isempty(phead* istack)//判断栈为空
{
    if(istack->top==NULL)
    {
        return 1;//栈为空
    }
    return 0;//栈不为空
}
pnode* seqstack_top(phead* istack)//获取栈顶元素的数据节点
{
    if(istack->size!=0)//栈不为空
    {
        return istack->top;//返回的是栈顶的数据节点而不是栈顶的元素
    }
    return NULL;
}
pnode* seqstack_pop(phead* istack)//弹出栈顶元素
{
    if(isempty(istack)==0)//栈不为空
    {
        pnode* account=istack->top;//记录栈顶的数据节点
        istack->top=istack->top->next;//指向栈顶下一个元素
        istack->size--;//记录栈的大小
        return account;//返回弹出的数据节点
    }
    return NULL;
}
void seqstack_push(phead* istack,char x)//压栈(入栈)
{
   pnode* temp;//进行压栈的数据节点
   temp=(pnode*)malloc(sizeof(pnode));
   temp->val=x;//填充数据域
   temp->next=istack->top;//连接栈顶的数据节点
   istack->top=temp;//充当栈顶
   istack->size++;//记录栈大小的变化
   return;
}
 //下面是中缀表达式转后缀表达式的函数
 char buffer[256]={0};//即对数组中每个数据都初始化为'\0'(\0的ascill码是0)
 //buffer为结果串
 void char_put(char ch)//用来将字符放入放入结果串
 {
     static int index=0;//static定义静态变量,放函数中表示index只初始化一次,只保留index的改变
     buffer[index++]=ch;
 }
 int priority(char ch)//用来比较优先级
 {
     int ret=0;
     switch(ch)
     {
        case '+'://case穿透,即上一个case没有break语句时会继续向下执行
        case '-':
            ret=1;
            break;
        case '*':
        case '/':
            ret=2;
            break;
        default://这里直接break也可以
            break;
     }
     return ret;
 }
 int is_number(char ch)//是不是数字
 {
     return(ch>='0'&&ch<='9');//数字返回1，否则返回0
 }
 int is_operator(char ch)//是不是运算符
 {
     return(ch=='+'||ch=='-'||ch=='*'||ch=='/');
 }
 int is_left(char ch)//是不是左括号
 {
     return(ch=='(');
 }
 int is_right(char ch)//是不是右括号
 {
     return(ch==')');
 }
 int transform(char str[])//使用const保护数据,函数用来将中缀转换成后缀
 {
     phead* istack=initstack();//创建一个栈
     int i=0;
     while(str[i]!='\0')//遍历整个字符串
    {
        //判断是不是数字
        if(is_number(str[i])==1)
        {
            if(is_number(str[i+1])==1)//后面1也是数字,则直接放
            {
                char_put(str[i]);//数字直接放入结果串(即输出)
            }
            else//后面不是数字,添加一个空格作为分隔符
            {
                char_put(str[i]);
                char_put(' ');
            }
        }
        else if(is_operator((str[i]))==1)
        {
            if(str[i+1]=='0'&&str[i]=='/')
            {
                printf("ILLEGAL");
                return 0;
            }
            if(isempty(istack)==0)//栈不为空
            {
                while((isempty(istack)==0)&&(priority(str[i])<=(priority(seqstack_top(istack)->val))))//栈不为空并且新运算符优先级不高于栈顶
                {
                    char_put(seqstack_pop(istack)->val);//满足条件的栈顶就弹出直到不满足条件
                    char_put(' ');
                }
            }
            seqstack_push(istack,str[i]);//再将该运算符入栈
        }
        else if(is_left(str[i]))//左括号直接入栈
        {
            seqstack_push(istack,str[i]);
        }
        else if(is_right(str[i]))//判断是不是右括号
        {
            while(is_left(seqstack_top(istack)->val)!=1)//栈顶不是左括号的情况
            {
                char_put(seqstack_pop(istack)->val);//弹出并存储到结果串
                if(isempty(istack)==1)//栈为空仍未找到左括号
                {
                    printf("没有匹配到左括号\n");
                    return -1;
                }
            }
            //此时匹配到了左括号
            seqstack_pop(istack);
            //弹出左括号,这里并不用保存,即两个括号相抵消
        }
        else
        {
            printf("有不能识别的字符\n");
            return -1;
        }
        i++;
    }
    //遍历完了已经
    if(str[i]=='\0')//成功遍历到字符串末尾
    {
        while(isempty(istack)==0)//弹出全部栈中元素
        {
            if(seqstack_top(istack)->val=='(')//栈顶元素为左括号
            {
                printf("有没有匹配到的'(',缺少')'\n");
                return -1;
            }
            char_put(seqstack_pop(istack)->val);//将栈中元素放入最终串
        }
    }
    else
    {
        printf("The traversal is not complete.！\n");
    }
    return 1;
 }
int main()
{
    char str[1024]={0};//将数组每个元素赋值为'\0'
    printf("Please enter a quadratic expression:\n");
    scanf("%s",str);
    int number=transform(str);
    if(number==-1)
    {
        printf("Expression conversion error:\n");
    }
    else if(number==1)
    {
        printf("transformed expression: %s\n",buffer);
    }
    else
    {
        return 0;
    }
}