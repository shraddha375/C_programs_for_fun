#include <stdio.h>

void bubbleSort(int arr[], int arrSize) {
    int temp;
    for (int i = 0; i < arrSize; i++) {
        for (int j = 0; j < arrSize - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp; 
            }
        }
    }
}

void printArray(int arr[], int arrSize){
    for (int i  = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }
}

int main(){

    int arr[] = {64, 25, 34, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    bubbleSort(arr, n);
    printf("Sorted Array: ");
    printArray(arr, n);
    printf("\n");

    return 0;
}
