import java.util.Random;

/**
 * 冒泡排序
 */
public class BubbleSort {
    public static void bubbleSort(int[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = 0; j < arr.length - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    public static final int N = 10000;

    public static void main(String[] args) {
        int[] arr = new int[N];
        Random r = new Random();
        for ( int i = 0; i < N; i++) {
            arr[i] = r.nextInt(N * 10);
        }
        bubbleSort(arr);
        for (var i : arr) {
            System.out.printf("%d ", i);
        }
    }
}
