// 插入排序

function insertSort(arr) {
	for (var i = 1; i < arr.length; i++) {
		var temp = arr[i];
		var j = 0;
		for (j = i; j > 0 && arr[j - 1] > temp; j--) {
			arr[j] = arr[j - 1];
		}
		arr[j] = temp;
	}
}

// 测试
var N = 4;
var arr = [];
for (var i = 0; i < N; i++) {
	arr.push(Math.floor(Math.random() * N * 2));
}
console.log(arr);
insertSort(arr);
console.log(arr);
