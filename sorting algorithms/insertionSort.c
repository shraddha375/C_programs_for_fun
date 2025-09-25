#include <stdio.h>

void insertionSort(int arr[], int arrSize) {
    int temp;
    for (int i = 1; i < arrSize; i++) {
        while (arr[i] < arr[i - 1]) {
            if (i == 0) {
                break;
            }
            temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
            i--;
        }
    }
}

void printArray(int arr[], int arrSize){
    for (int i  = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }
}

int main(){

    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    insertionSort(arr, n);
    printf("Sorted Array: ");
    printArray(arr, n);
    printf("\n");

    return 0;
}
