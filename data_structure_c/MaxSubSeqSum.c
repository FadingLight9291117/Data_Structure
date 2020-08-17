/**
 * 最大子列和问题：求一个序列中的最大的子列的和
 */
#include<stdio.h>

/* 1. 贪心算法，全部求出来  */
int maxSubSeqSum1(int *arr, int len) {
    int thisSum, maxSum = 0;
    for (int i = 0; i < len; i++) {
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

/* */
int maxSubSeqSum2(int *arr, int len) {
    
}

int main() {
    int arr[10] = {2,3,-2,-2,0,12,-12,1,4,-1};
    int result = maxSubSeqSum1(arr, 10);
    printf("%d\n", result);
    return 0;
}