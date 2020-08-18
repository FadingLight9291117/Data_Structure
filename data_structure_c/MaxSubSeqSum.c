/**
 * 最大子列和问题：求一个序列中的最大的子列的和
 */
#include<stdio.h>

/* 1. 贪心算法，全部求出来  */
int MaxSubSeqSum1(int *arr, int len) {
    int thisSum, maxSum = 0;
    for (int i = 0; i < len; i++) {     // 从
        for (int j = i; j < len; j++) {
            thisSum = 0;
            for (int k = i; k <= j; k++) {
                thisSum += arr[k];
            }
            if (thisSum > maxSum) {
                maxSum = thisSum;
            }
        }
    }
    return maxSum;
}

/* 2. 贪心算法 */
int MaxSubSeqSum2(int *arr, int len) {
    int thisSum, maxSum = 0;
    for (int i = 0; i < len; i++) {
        thisSum = 0;
        for (int j = i; j < len; j++) {
            thisSum += arr[j];
            if (thisSum > maxSum) {
                maxSum = thisSum;
            }
        }
    }
    return maxSum;
}

/* 3. 分治法 */
int Max3(int one, int two, int three) {
    int max = one;
    if (two > max) {
        max = two;
    }
    if (three > max) {
        max = three;
    }
    return max;
}
int DivideAndConquer(int *arr, int left, int right) {
    /* 求arr从left到right的最大子段和 */
    if (right == left) {
        if (arr[left] > 0) {
            return arr[left];
        }
        else {
            return 0;
        }
    }

    int maxLeftSum, maxRightSum;    // 存放左右最大子段和
    int maxLeftBorderSum, maxRightBorderSum; // 中间部分最大子段和
    int leftBorderSum, rightBorderSum;

    int center = (left + right) / 2;

    maxLeftSum = DivideAndConquer(arr, left, center);
    maxRightSum = DivideAndConquer(arr, center + 1, right);

    /* 求跨段的最大字列和 */
    maxLeftBorderSum = maxRightBorderSum = 0;
    leftBorderSum = rightBorderSum = 0;
    // 从中线向左扫描
    for (int i = center; i >= 0; i--) {
        leftBorderSum += arr[i];
        if (leftBorderSum > maxLeftBorderSum) {
            maxLeftBorderSum = leftBorderSum;
        }
    }
    // 从中线向右扫描
    for (int i = center + 1; i <= right; i++) {
        rightBorderSum += arr[i];
        if (rightBorderSum > maxRightBorderSum) {
            maxRightBorderSum = rightBorderSum;
        }
    }

    // 返回三个中最大的一个
    return Max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
}
// 统一接口
int MaxSubSeqSum3(int *arr, int len) {
    return DivideAndConquer(arr, 0, len - 1);
}

/* 4. 在线处理 */
int MaxSubSeqSum4(int *arr, int len) {
    int thisSum = 0;
    int maxSum = 0;
    for (int i = 0; i < len; ++i) {
        thisSum += arr[i];
        if (thisSum < 0) {
            thisSum = 0;
        }
        else if (thisSum > maxSum) {
            maxSum = thisSum;
        }
    }

    return maxSum;
}

int main() {
    int arr[10] = {2,3,-2,-2,0,12,-2,1,4,-1};
    int result = MaxSubSeqSum4(arr, 10);
    printf("%d\n", result);
    return 0;
}