#include <stdio.h>

void quickSort (int arr[], int first_index, int last_index, int arrSize){
    //printf("---------------------------\n");
    //printf("Start:\t first index = %d, last index = %d\n", first_index, last_index);
    //printf("Before Sorting: ");
    //for (int i = 0; i < arrSize; i++) {
    //    printf("%d ", arr[i]);
    //}
    //printf("\n");
    if ((last_index - first_index + 1) > 1) {
    
        int pivot = arr[first_index];
        int secondHalf_firstIndex = last_index;
        int firstHalf_lastIndex = first_index;
        int temp;

        for (int i = first_index + 1; i <= last_index; i++) {
            if (arr[i] > pivot) {
                // if its the first element of the second half
                if (secondHalf_firstIndex == last_index) {secondHalf_firstIndex = i;}
            }
            else {
                firstHalf_lastIndex  = i;
                if (secondHalf_firstIndex != last_index) {
                    temp = arr[i];
                    arr[i] = arr[secondHalf_firstIndex];
                    arr[secondHalf_firstIndex] = temp;
                    firstHalf_lastIndex = secondHalf_firstIndex;
                    secondHalf_firstIndex++;
                }
            }
        }

        temp = arr[first_index];
        arr[first_index] = arr[firstHalf_lastIndex];
        arr[firstHalf_lastIndex] = temp;
        
        //printf("After Sorting: ");
        //for (int i = 0; i < arrSize; i++) {
        //    printf("%d ", arr[i]);
        //}
        //printf("\n");
        
        if (firstHalf_lastIndex == first_index) {
            firstHalf_lastIndex = first_index + 1;
        }
        firstHalf_lastIndex = firstHalf_lastIndex - 1;

        //printf("Inside:\t [first_index = %d - firstHalf_lastIndex = %d], [secondHalf_firstIndex = %d - last_index = %d]\n", first_index, firstHalf_lastIndex, secondHalf_firstIndex, last_index);
        //printf("---------------------------\n");
        quickSort(arr, first_index, firstHalf_lastIndex, arrSize);
        quickSort(arr, secondHalf_firstIndex, last_index, arrSize);

    }

}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    //int arr[] = {64, 25, 12, 22, 11};
    int arr[] = {50, 70, 20, 30, 80, 10, 40, 45};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    quickSort(arr, 0, n - 1, n);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}
