import java.util.Random;
/*
 * 快速排序
 */
class QuickSort {

	// 两数交换
	public static void swap(int[] arr, int a, int b) {
		int temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}

	// 	选主元
	public static int medium3(int[] arr, int left, int right) {
		int center = (left + right) / 2;
		if (arr[left] > arr[center]) {
			swap(arr, left, center);
		}
		if (arr[center] > arr[right]) {
			swap(arr, center, right);
		}
		if (arr[left] > arr[center]) {
			swap(arr, left, center);
		}
		swap(arr, center, right - 1);
		return arr[right - 1];
	}

	public static void insertSort(int[] arr, int left, int right) {
		for (int i = left + 1; i <= right; i++ ) {					// 注意是<=right
			int temp = arr[i];
			int j;
			for (j = i; j > left && arr[j - 1] > temp; j--) {
				arr[j] = arr[j - 1];
			}
			arr[j] = temp;
		}
	}

	public static void quickSortCore(int[] arr, int left, int right) {
		// 1. 定阈值
		int cutOff = 5;
		if (right - left >= cutOff) {	// 快速排序
			// 2. 选主元
			int pivot = medium3(arr, left, right);
			int l = left + 1;
			int r = right - 2;
			while (true) {
				while (arr[l] < pivot) {
					l++;
				}
				while (arr[r] > pivot) {
					r--;
				}
				if (l < r) {
					swap(arr, l, r);
					l++;
					r--;
				}
				else {
					break;
				}
			}
			swap(arr, l, right - 1);
			quickSortCore(arr, left, l - 1);
			quickSortCore(arr, l + 1, right);
		} else {
			insertSort(arr, left, right);	// 插入排序
		}
	}

	// 统一接口
	public static void quickSort(int[] arr) {
		quickSortCore(arr, 0, arr.length - 1);
	}

	public static  final int N = 100;

	public static void main(String[] args) {
		int[] a = new int[N];
		Random r = new Random();
		for (int i = 0; i < N; i++) {
			a[i] = r.nextInt(N * 10);
		}
		quickSort(a);
		for (int value : a) {
			System.out.printf("%d ", value);
		}
	}
}