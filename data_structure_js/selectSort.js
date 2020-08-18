// 选择排序
function selectSort(arr) {
	for (var i = 0; i < arr.length - 1; i++) {
		var min = i;
		for (var j = i + 1; j < arr.length; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		// min 和 i 交换
		var temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

// 测试
var N = 6;
var arr = [];
for (var i = 0; i < N; i++) {
	arr.push(Math.floor(Math.random() * N * 2));
}
console.log(arr);
selectSort(arr);
console.log(arr);