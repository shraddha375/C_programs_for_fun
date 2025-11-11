#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(nums[0]), comp);

    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]){
            return true;
        }
    }
    return false;
}

int main() {
    int nums[] = {1,2,3,1};  // Input array
    bool expectedAnswer = true;    // Expected output
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    bool answer = containsDuplicate(nums, numsSize);
    
    // Judge checks
    assert(answer == expectedAnswer);

    printf("Assertions passed.\n");
    return 0;
}

