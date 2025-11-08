/*
    Consider two variables: 1. One holds the index of the latest unique value 2. Other iterates over the array
    
*/

#include <stdio.h>
#include <assert.h>

int removeDuplicates(int* nums, int numsSize) {
    int i = 0, j;
    
    for(j = 0; j < numsSize; j++){
        if(nums[i] != nums[j]){
            nums[i + 1] = nums[j];
            i++;
        }
    }
    
    return (i + 1);
}

int main() {
    int nums[] = {0,0,1,1,1,2,2,3,3,4};  // Input array
    int expectedNums[] = {0,1,2,3,4};    // Expected output
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int expectedSize = sizeof(expectedNums) / sizeof(expectedNums[0]);

    int k = removeDuplicates(nums, numsSize);

    // Judge checks
    assert(k == expectedSize);
    for (int i = 0; i < k; i++) {
        assert(nums[i] == expectedNums[i]);
    }

    printf("All assertions passed.\n");
    printf("k = %d\n", k);
    printf("Unique elements: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}

