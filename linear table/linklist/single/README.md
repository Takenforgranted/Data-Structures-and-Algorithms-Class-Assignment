<div style="text-align: center;">
  <h1>单链表操作项目</h1>
</div>

这是一个用C语言编写的单链表操作项目，包括了一些基本的单链表操作功能，如插入、删除、查找等。

## 项目文件结构

项目包含以下文件：

- **`s_link.h`**: 单链表的头文件，定义了单链表的数据结构。
- **`s_link_operation.h`**: 单链表操作的头文件，声明了操作函数的原型。
- **`main_example.c`**: 主程序文件，提供了一个包含了以上函数的使用示例，包括初始化单链表、用户界面和单链表操作的演示。

## 单链表数据结构

在 **`s_link.h`** 文件中，定义了以下单链表数据结构：

```c
typedef float datatype;
typedef struct single_node
{
    datatype data;
    struct single_node* next;
} s_node;

typedef struct single_linklist
{
    s_node* head;
} s_linklist;
```

- **`datatype`**: 定义了单链表元素的数据类型。
- **`s_node`**: 定义了单链表节点的结构，包括数据域 **`data`** 和指向下一个节点的指针 **`next`**。
- **`s_linklist`**: 定义了单链表的结构，包括指向链表头节点的指针 **`head`**。

## 单链表操作函数

在**`s_link_operation.h`** 文件中，声明了以下单链表操作函数的原型：

```c
s_node* InitSingleNode();
s_linklist* InitSingleLinkedList();
void DestroySingleNode(s_node* node);
void DestroySingleLinkedList(s_linklist* L);
int JudgeSingleLinkListEmpty(const s_linklist* L);
int JudgeSingleLinkListLength(const s_linklist* L);
void ArrayToSingleLinkList(datatype a[], int size, s_linklist* L);
void PrintLinkList(const s_linklist* L);
datatype GetElemLinkList(const s_linklist* L, int i);
int LocateElemLinkList(const s_linklist* L, datatype e);
int InsertLinkList(s_linklist* L, datatype x, int i);
int DeleteLinkList(s_linklist* L, int i);
```

下面是这些函数的简要说明：

- **`InitSingleNode()`**: 创建并初始化一个单链表节点。
- **`InitSingleLinkedList()`**: 创建并初始化一个单链表。
- **`DestroySingleNode(s_node* node)`**: 销毁一个单链表节点，释放内存。
- **`DestroySingleLinkedList(s_linklist* L)`**: 销毁一个单链表，包括销毁链表中的所有节点。
- **`JudgeSingleLinkListEmpty(const s_linklist* L)`**: 判断单链表是否为空。
- **`JudgeSingleLinkListLength(const s_linklist* L)`**: 获取单链表的长度。
- **`ArrayToSingleLinkList(datatype a[], int size, s_linklist* L)`**: 将数组转换为单链表。
- **`PrintLinkList(const s_linklist* L)`**: 打印单链表内容。
- **`GetElemLinkList(const s_linklist* L, int i)`**: 获取单链表中指定位置的元素。
- **`LocateElemLinkList(const s_linklist* L, datatype e)`**: 在单链表中寻找第一个与给定元素相等的元素的位置。
- **`InsertLinkList(s_linklist* L, datatype x, int i)`**: 在单链表的指定位置插入一个元素。
- **`DeleteLinkList(s_linklist* L, int i)`**: 从单链表中删除指定位置的元素。

## 使用示例

在 **`main_example.c`** 文件中，提供了一个包含了以上函数的使用示例。该示例初始化一个单链表，并提供了一个用户界面，允许用户执行不同的操作，如插入、删除、查找、打印等。

### 初始化单链表

```c
s_linklist* L = InitSingleLinkedList();  // 初始化单链表
// …………中间省略掉的各种代码……………
float initData[] = {1.2, 2.4, 3.6, 4.8, 5.2};  // 初始数据数组
int initDataSize = sizeof(initData) / sizeof(initData[0]);
ArrayToSingleLinkList(initData, initDataSize, L);
```

### 用户界面

用户可以通过选择不同的操作来测试单链表的功能。以下是可用的操作选项：

1. 插入元素
2. 删除元素
3. 获取单链表长度
4. 判断单链表是否为空
5. 打印单链表内容
6. 查找元素位置
7. 获取指定位置的元素
8. 退出程序

### 示例操作

示例中演示了如何执行一些基本的操作，例如插入元素、删除元素、获取单链表长度、判断单链表是否为空等。用户可以根据需要选择不同的操作，并根据程序提示提供必要的输入。

## 如何编译和运行

你可以使用GCC编译器来编译项目文件。确保GCC已经正确安装并配置好。

~~不会吧，不会吧，在2023年都不用更加先进、便捷、好看的各种IDE和代码编辑器。~~

~~哥嫩咋就这嘞 ~ 连让俺带劲了本事儿都莫有 :heart: 真不中 ~ 孬种 :heart: 孬种 :heart: 孬种 ~ （大半夜写readme的哪有不疯的！！！）~~

## 注意事项

- 请确保你的GCC编译器已正确安装和配置。
- 本项目是一个基本示例，你可以根据自己的需求进行扩展和修改。

## 许可证

本项目采用 [MIT 许可证](LICENSE)。