/*
    冒泡排序
*/

#include <stdio.h>
/*
    冒泡排序函数
    params:
        *arr-待排数组指针
        len-数组长度
*/
void bubble_sort(int *arr, const int len)
{
    for (int i = 0; i < len - 1; i++)
    { // 外循环-第几轮冒泡
        for (int j = 0; j < len - i - 1; j++)
        { // 内循环-冒泡
            if (arr[j] > arr[j + 1])
            { // 如果前一个元素大于后一个元素 交换
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/*
    测试成功
*/
int main()
{
    int a[8] = {3, 12, 5, 2, -2, 10, -29, 4};
    bubble_sort(a, 8);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}