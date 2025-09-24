#include <stdio.h>

void selectionSort(int arr[], int arrSize){

    int index;
    int temp;

    for (int i = 0; i < arrSize - 1; i++){
        index = i;
        for (int j = i + 1; j < arrSize; j++) {
            if (arr[j] < arr[index]) {
                index = j;
            }
        }

        temp = arr[index];
        arr[index] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    selectionSort(arr, n);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}
