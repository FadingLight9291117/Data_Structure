/*
    选择排序
*/

#include <stdio.h>
/*
    选择排序函数
    params:
        *arr-数组指针
        len-数组长度
*/
void select_sort(int *arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    { // 一次选择
        int min = i;
        for (int j = i; j < len; j++)
        { // 选择出最小的那一个
            min = arr[j] < arr[min] ? j : min;
        }
        int temp = arr[min]; // 交换元素
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

/*
    测试
*/
int main()
{
    int a[8] = {3, 12, 5, 2, -2, 10, -29, 4};
    select_sort(a, 8);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}

/*
    总结:
        1. 使用 异或 或 加减 交换值时的致命缺陷
        当SWAP(x, y)中x,y为同一数据时（比如x和y都为同一数组的同一位置的元素时），会发生计算错误。
        因为当改变x时y也同时改变。
        因此使用temp临时变量最为妥当。
*/