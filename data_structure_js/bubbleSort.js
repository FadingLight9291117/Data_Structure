/**
 * 冒泡排序
 */

function bubbleSort(arr) {
    const len = arr.length;
    for (let i = 0; i < len - 1; i++) {
        for (let j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                const temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/**
 * 测试
 */
const N = 100000
const arr = [];
for (let i = 0; i < N; i++) {
    arr.push(Math.round(Math.random() * 100000));
}
bubbleSort(arr)
console.log(arr)