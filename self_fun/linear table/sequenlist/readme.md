<div style="text-align: center;">
  <h1>顺序表操作项目</h1>
</div>
这是一个用C语言编写的顺序表操作项目，包括了一些基本的顺序表操作功能，如插入、删除、查找等。

## 项目文件结构

项目包含以下文件：

- **`main.c`**: 主程序文件，提供了一个包含了以上函数的使用示例，包括初始化顺序表、用户界面和顺序表操作的演示。
- **`sequenlist.h`**: 顺序表的头文件，定义了顺序表的数据结构和基本操作。
- **`sequenlist_operation.h`**: 顺序表操作的头文件，声明了操作函数的原型。
- **`mixed.c`**: 将上述三个文件中的内容整合在了单文件中，用于演示示例。

## 顺序表数据结构

在 **`sequenlist.h`** 文件中，定义了以下顺序表数据结构：

```c
typedef int datatype;
typedef struct
{
    datatype data[maxsize];
    int last;
} sequenlist;
```

- **`maxsize`**: 定义了顺序表的最大容量。
- **`datatype`**: 定义了顺序表元素的数据类型。
- **`sequenlist`**: 定义了顺序表的结构，包括数据数组**`data`**和顺序表的当前长度**`last`**。

## 顺序表操作函数

在**`sequenlist_operation.h`** 文件中，声明了以下顺序表操作函数的原型：

```c
sequenlist* InitList();
void DestroyList(sequenlist* L);
int JudgeListEmpty(const sequenlist* L);
int JudgeListLength(const sequenclist* L);
void ArrayToSequenList(int array[], int size, sequenlist* L);
void PrintList(const sequenlist* L);
int GetElemList(sequenlist* L, int i);
int LocateElemList(sequenlist* L, int e);
int InsertList(sequenlist* L, datatype x, int i);
int DeleteList(sequenlist* L, int i);
```

下面是这些函数的简要说明：

- **`InitList()`**: 初始化顺序表并返回一个指向新创建顺序表的指针。
- **`DestroyList(sequenlist* L)`**: 销毁顺序表，释放内存。
- **`JudgeListEmpty(const sequenlist* L)`**: 判断顺序表是否为空。
- **`JudgeListLength(const sequenlist* L)`**: 获取顺序表的长度。
- **`ArrayToSequenList(int array[], int size, sequenlist* L)`**: 将整数数组复制到顺序表中。
- **`PrintList(const sequenlist* L)`**: 打印顺序表内容。
- **`GetElemList(sequenlist* L, int i)`**: 获取指定位置的元素。
- **`LocateElemList(sequenlist* L, int e)`**: 查找指定元素的位置。
- **`InsertList(sequenlist* L, datatype x, int i)`**: 在指定位置插入元素。
- **`DeleteList(sequenlist* L, int i)`**: 删除指定位置的元素。

## 使用示例

在 **`main.c`** 文件中，提供了一个包含了以上函数的使用示例。该示例初始化一个顺序表，并提供了一个用户界面，允许用户执行不同的操作，如插入、删除、查找、打印等。

### 初始化顺序表

```c
sequenlist* L = InitList();  // 初始化顺序表
// …………中间省略掉的各种代码……………
int initData[] = { 1, 2, 3, 4, 5 };  // 初始数据数组 (Initial data array)
int initDataSize = sizeof(initData) / sizeof(initData[0]);
ArrayToSequenList(initData, initDataSize, L);
```

### 用户界面

用户可以通过选择不同的操作来测试顺序表的功能。以下是可用的操作选项：

1. 插入元素
2. 删除元素
3. 获取顺序表长度
4. 判断顺序表是否为空
5. 打印顺序表内容
6. 查找元素位置
7. 获取指定位置的元素
8. 退出程序

### 示例操作

示例中演示了如何执行一些基本的操作，例如插入元素、删除元素、获取顺序表长度、判断顺序表是否为空等。用户可以根据需要选择不同的操作，并根据程序提示提供必要的输入。

## 如何编译和运行

### ~~不会吧，不会吧，在2023年都不用更加先进、便捷、好看的各种IDE和代码编辑器。~~
### 哥嫩咋就这嘞 ~ 连让俺带劲了本事儿都莫有 :heart: 真不中 ~ 孬种 :heart: 孬种 :heart: 孬种 ~ （大半夜写readme.md的哪有不疯的！！！）

你可以使用GCC编译器来编译项目文件。确保GCC已经正确安装并配置好。

### 编译项目

在命令行中执行以下命令来编译项目：

```bash
gcc main.c -o main -Wall
```

这将生成一个名为 **`main`** 的可执行文件。

### 运行项目

运行项目可执行文件：

```bash
./main
```

现在，你可以通过菜单选项来测试不同的顺序表操作。

## 注意事项

- 请确保你的GCC编译器已正确安装和配置。
- 本项目中提供的顺序表容量为 **`maxsize`**，你可以根据需要修改它。
- 这个项目是一个基本示例，你可以根据自己的需求进行扩展和修改。

## 许可证

~~本项目采用 [MIT 许可证](LICENSE)。~~

妈的，纯粹就是自己写着玩的，能商用个屁，要是真的落魄到需要借用的话注释里面提一嘴权当作**acknowledgement**。