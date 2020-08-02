#! python3
# selectSort.py-选择排序

def selectSort(arr):
	for i in range(len(arr) - 1):
		min = i
		for j in range(i, len(arr)): # 选一个最小的
			min = j if arr[j] < arr[min] else min
		arr[i], arr[min] = arr[min], arr[i] # 交换元素
	return arr

# 测试
arr = [-2, 21, 3, 23, 10, -3, 0, -1]
arr = selectSort(arr)
print(arr)