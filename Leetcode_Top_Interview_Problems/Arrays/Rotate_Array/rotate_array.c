#include <stdio.h>
#include <assert.h>

void rotate(int* nums, int numsSize, int k) {
    if (numsSize == 0) return;
    k = k % numsSize;

    int temp[numsSize];

    for (int i = 0; i < numsSize; i++) {
        temp[(i + k) % numsSize] = nums[i];
    }

    // Copy back into original array
    for (int i = 0; i < numsSize; i++) {
        nums[i] = temp[i];
    }
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};  // Input array
    int expectedNums[] = {5, 6, 7, 1, 2, 3, 4};    // Expected output
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 3;

    rotate(nums, numsSize, k);
    
    //for (int i = 0; i < numsSize; i++){
    //    printf("nums = %d\n", nums[i]);
    //}
    
    // Judge checks
    for (int i = 0; i < numsSize; i++){
        assert(nums[i] == expectedNums[i]);
    }

    printf("Assertions passed.\n");
    return 0;
}

