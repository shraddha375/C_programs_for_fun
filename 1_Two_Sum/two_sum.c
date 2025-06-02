#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    //nums is an array
    //numsSize is the size of that array
    //target is the target value
    //returnSize is 2 if found else 0

    //Part 1: Need to store the output array somewhere
    //result is an array
    int* result = (int*)malloc(2 * sizeof(int));
    if (result == NULL) {
        *returnSize = 0;
        return NULL; // Memory allocation failed
    }

    //Part 2: Main logic of finding the two numbers
    for(int i = 0; i < numsSize; i++) {
        for(int j = i + 1; j < numsSize; j++) {
            if (*(nums + i) + *(nums + j) == target) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }   

    // Part 3: If no such numbers found
    // If no solution found
    *returnSize = 0;
    free(result); // Free the allocated memory
    return NULL;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    int* indices = twoSum(nums, sizeof(nums) / sizeof(nums[0]), target, &returnSize);
    
    if (indices != NULL) {
        printf("Indices: [%d, %d]\n", indices[0], indices[1]);
    } else {
        printf("No solution found.\n");
    }
    
    return 0;
}
