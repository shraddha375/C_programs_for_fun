#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int singleNumber(int* nums, int numsSize) {

    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i];
    }

    return result;
}

int main() {
    int nums[] = {4, 1, 2, 1, 2};  // Input array
    int expectedAnswer = 4;    // Expected output
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int answer = singleNumber(nums, numsSize);
    
    // Judge checks
    assert(answer == expectedAnswer);

    printf("Assertions passed.\n");
    return 0;
}
