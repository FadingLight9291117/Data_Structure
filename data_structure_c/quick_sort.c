/*
    快速排序
*/

#include <stdio.h>
/*
    两数交换函数
*/
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
    选主元
    首尾和中间三个数中间大小的作为主元，并放在倒数第二个位置
    返回主元
*/
int medium3(int *a, int left, int right)
{
     int center = (left + right) / 2;
    if (a[left] > a[center])
    {
        swap(&a[left], &a[center]);
    }
    if (a[center] > a[right])
    {
        swap(&a[center], &a[right]);
    }
    if (a[left] > a[center])
    {
        swap(&a[center], &a[left]);
    }
    swap(&a[center], &a[right - 1]); // 将主元放入倒数第二个位置
    return a[right - 1];
}

/*
    插入排序
*/
void insert_sort(int *arr, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = arr[i];
        int j;
        for (j = i; i > left; j--)
        {
            if (arr[j - 1] > temp)
            {
                arr[j] = arr[j - 1];
            }
            else
            {
                break;
            }
        }
        arr[j] = temp;
    }
}

/*
    快速排序核心函数
*/
void quickSort(int *arr, const int left, const int right)
{
    int cutOff = 10;                            //  定阈值
    if (right - left >= cutOff)                 // 元素个数大于阈值，使用快排
    {                                           // 快速排序
        int pivot = medium3(arr, left, right); // 选主元
        int l = left - 1;
        int r = right - 2;
        while (1)
        {
            while (arr[l] < pivot) // 从左至右找到一个比主元大的元素
            {
                l++;
            }
            while (arr[r] > pivot) // 从右至左找到一个比主元小的元素
            {
                r--;
            }
            if (l < r) // 交换
            {
                swap(&arr[l], &arr[r]);
                l++;
                r--;
            }
            else
            {
                break;
            }
        }
        swap(&arr[l], &arr[right - 1]);
        quickSort(arr, left, l - 1);
        quickSort(arr, l + 1, right);
    }
    else //  元素个数小于阈值，使用插入排序
    {
        insert_sort(arr, left, right);
    }
}

/*
    统一接口
*/
void quick_sort(int *arr, int len)
{
    quickSort(arr, 0, len - 1);
}

/*
    测试
*/
#define n 100000
#include <stdlib.h>
int main()
{
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = rand();
    }
    quick_sort(a, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
        if (i > 0 && a[i] < a[i - 1])
        {
            printf("error");
            break;
        }
    }
    return 0;
}