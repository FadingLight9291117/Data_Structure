#! python3
# insertSort.py-插入排序

def insertSort(arr):
	for i in range(1, len(arr)):
		temp = arr[i]							# 摸下一张牌
		j = i
		while (j > 0 and arr[j-1] > temp):		
			arr[j] = arr[j-1]				# 向左移动空位
			j -= 1
		arr[j] = temp							# 放入牌
	return arr

# 测试
arr = [-2, 21, 3, 23, 10, -3, 0, -1]
arr = insertSort(arr)
print(arr)
