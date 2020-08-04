#! python3
# bubbleSort.py-冒泡排序

def bubbleSort(arr):
    for i in range(len(arr) - 1):
        for j in range(len(arr) - i - 1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr


# 测试
arr = [-2, 21, 3, 23, 10, -3, 0, -1]
arr = bubbleSort(arr)
print(arr)
