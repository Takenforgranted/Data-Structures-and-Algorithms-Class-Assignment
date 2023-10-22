sequenlist* InitList();

void DestroyList(sequenlist* L);

int JudgeListEmpty(const sequenlist* L);

int JudgeListLength(const sequenlist* L);

void ArrayToSequenList(float array[], int size, sequenlist* L);

void PrintList(const sequenlist* L);

datatype GetElemList(sequenlist* L, int i);

int LocateElemList(sequenlist* L, int e);

int InsertList(sequenlist* L, datatype x, int i);

int DeleteList(sequenlist* L, int i);

/**
 * 初始化顺序表
 *
 * 该函数用于创建并初始化一个空的顺序表。
 *
 * @return 返回一个指向新创建的顺序表的指针。
 *         如果内存分配失败，返回NULL。
 */
sequenlist* InitList()
{
    sequenlist* L = (sequenlist*)malloc(sizeof(sequenlist));
    // 检查内存分配是否成功
    if (L == NULL) {
        return NULL;  // 内存分配失败，返回NULL
    }
    L->last = 0;  // 初始化顺序表长度为0，表示空表
    return L;
}


/**
 * 销毁顺序表
 *
 * 该函数用于释放顺序表所占用的内存空间，并将顺序表指针置为NULL。
 *
 * @param L 顺序表指针，指向要销毁的顺序表
 */
void DestroyList(sequenlist* L)
{
    free(L);  // 释放顺序表的内存空间
    L = NULL; // 将顺序表指针置为NULL，防止野指针
}


/**
 * 判断顺序表是否为空
 *
 * 该函数用于判断顺序表是否为空表。
 *
 * @param L 顺序表指针，指向要判断的顺序表
 * @return 当顺序表为空时返回1，否则返回0
 */
int JudgeListEmpty(const sequenlist* L)
{
    return L->last == 0;  // 若顺序表长度为0，则为空表，返回1；否则返回0
}


/**
 * 获取顺序表的长度
 *
 * 该函数用于获取顺序表的当前长度。
 *
 * @param L 顺序表指针，指向要获取长度的顺序表
 * @return 返回顺序表的长度
 */
int JudgeListLength(const sequenlist* L)
{
    return L->last;  // 返回顺序表的长度即为顺序表中元素的个数
}


/**
 * 将数组转换为顺序表
 *
 * 该函数将一个数组的元素逐个复制到顺序表中，并更新顺序表的长度。
 *
 * @param array 要复制的数组
 * @param size 数组的大小
 * @param L 指向目标顺序表的指针
 * @return 无返回值
 */
void ArrayToSequenList(float array[], int size, sequenlist* L)
{
    if (L == NULL || size > maxsize) {
        printf("Error - Your wild ambition is too mega!!!\n");
    }
    // 将数组中的元素逐个复制到顺序表中
    for (int i = 0; i < size; i++) {
        L->data[i] = array[i];
    }
    L->last = size; // 更新顺序表的长度
}



/**
 * 打印顺序表内容
 *
 * 该函数用于打印顺序表中的元素内容。
 *
 * @param L 顺序表指针，指向要打印的顺序表
 */
void PrintList(const sequenlist* L)
{
    printf("SequenList is: ");
    if (L->last == 0) {
        printf("Empty!!!\n");
    }
    else {
        for (int i = 0; i < L->last; i++) {
            printf("%.2f ", L->data[i]);
        }
        printf("\n");
    }
}


/**
 * 获取顺序表中第 i 个元素的值
 *
 * 该函数用于从顺序表中获取指定位置的元素的值。
 *
 * @param L 顺序表指针，指向要操作的顺序表
 * @param i 要获取的元素位置（从1开始计数）
 * @return 返回第 i 个元素的值，如果位置 i 非法，则返回 -1e9 表示错误
 */
datatype GetElemList(sequenlist* L, int i)
{
    if (i < 1 || i > L->last) {
        printf("Error - Illegal Read Position!!!");
        return -1e9;  // 返回一个表示错误的特殊值
    }
    else {
        int x = L->data[i - 1];
        return x;  // 返回第 i 个元素的值
    }
}


/**
 * 寻找第一个与给定元素相等的元素位置
 *
 * 该函数用于在顺序表中寻找第一个与给定元素 e 相等的元素的位置。
 *
 * @param L 顺序表指针，指向要操作的顺序表
 * @param e 要寻找的元素的值
 * @return 返回第一个与 e 相等的元素的位置（从1开始计数），如果未找到则返回0表示未找到
 */
int LocateElemList(sequenlist* L, int e)
{
    for (int i = 0; i < L->last; i++) {
        if (L->data[i] == e) {
            return i + 1;  // 返回元素位置（从1开始计数）
        }
    }

    return 0;  // 未找到与 e 相等的元素，返回0表示未找到
}



/**
 * 在顺序表中插入元素
 *
 * 该函数用于在顺序表的指定位置插入一个元素。
 *
 * @param L 顺序表指针，指向要插入元素的顺序表
 * @param x 待插入的元素值
 * @param i 插入位置的索引，从1开始计数
 * @return 操作是否成功，成功返回1，失败返回0
 */
int InsertList(sequenlist* L, datatype x, int i)
{
    // 检查顺序表是否已满
    if (L->last >= maxsize) {
        printf("Error - The List is Full!!!");
        return 0;
    }
    // 检查插入位置是否合法
    else if (i < 1 || i > L->last + 1) {
        printf("Error - Illegal Insert Position!!!");
        return 0;
    }
    // 插入元素到指定位置
    else {
        int j;
        // 从最后一个元素开始，依次向后移动一个位置
        for (j = L->last; j >= i; j--) {
            L->data[j] = L->data[j - 1];
        }
        // 在指定位置插入新元素
        L->data[i - 1] = x;
        // 更新顺序表的元素数量
        L->last++;
        return 1;
    }
}


/**
 * 在顺序表中删除元素
 *
 * 该函数用于从顺序表中删除指定位置的元素。
 *
 * @param L 顺序表指针，指向要删除元素的顺序表
 * @param i 删除位置的索引，从1开始计数
 * @return 操作是否成功，成功返回1，失败返回0
 */
int DeleteList(sequenlist* L, int i)
{
    // 检查删除位置是否合法
    if (i < 1 || i > L->last) {
        printf("Error - Illegal Delete Position!!!");
        return 0;
    }
    else {
        int j;
        // 从删除位置开始，将后面的元素依次向前移动一个位置
        for (j = i; j <= L->last - 1; j++) {
            L->data[j - 1] = L->data[j];
        }
        // 更新顺序表的元素数量
        L->last--;
        return 1;
    }
}