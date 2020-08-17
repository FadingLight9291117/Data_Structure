/**
 * 快速排序
 */

function swap(arr, a, b) {
	const temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

/**
 * 选主元 
 */
function medium3(arr, left, right) {
	const center = Math.floor((left + right) / 2); // js中 / 不是取整
	if (arr[left] > arr[center]) {
		swap(arr, left, center);
	}
	if (arr[center] > arr[right]) {
		swap(arr ,center, right);
	}
	if (arr[left] > arr[center]) {
		swap(arr, left, center);
	}
	swap(arr, center, right - 1);
	return arr[right - 1];
}

/**
 * 快排核心函数 
 */
function quickSortCore(arr, left, right) {
	const cutOff = 8; // 1. 定阈值, 阈值不能
	if (right - left >= cutOff) {
		const pivot = medium3(arr, left, right); 	// 2. 选主元
		let l = left;
		let r = right - 1;
		while (true) {
			while (arr[++l] < pivot) ;
			while (arr[--r] > pivot) ;
			if (l < r) {				// 两数交换
				swap(arr, l, r);
			} 
			else {
				break;
			}
		}
		swap(arr, l, right - 1);
		quickSortCore(arr, left, l - 1);
		quickSortCore(arr, l + 1, right);
	} 
	else {									// 阈值内用插入排序
		insertSort(arr, left, right);
	}
}

/**
 * 插入排序 
 */
function insertSort(arr ,left, right) {
	for (let i = left + 1; i <= right; i++) {
		let temp = arr[i];
		let j = 0;
		for (j = i; j > 0 && arr[j-1] > temp; j--) { // 这里要先j > 0 后 arr[j - 1] > temp, 否则会溢出
			arr[j] = arr[j-1];
		}
		arr[j] = temp;
	}
}

/**
 * 统一接口
 */
function quickSort(arr) {
	return quickSortCore(arr, 0, arr.length - 1);
}

/**
 * 测试
 */
const n = 10;
let arr = [];
for (let i = 0; i < n; i++) {
	arr.push(Math.round(Math.random() * n));
}
console.log(arr);
quickSort(arr);
console.log(arr);