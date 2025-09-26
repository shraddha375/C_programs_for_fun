#include <stdio.h>

void printArray(int arr[], int arrSize){
    for (int i  = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }
}

void mergeSort(int arr[], int first_index, int last_index) {
    
    if (last_index - first_index + 1 > 1){
        int firstArr_firstIndex = first_index;
        int firstArr_lastIndex = first_index + ((last_index - first_index + 1)/2) - 1 + ((last_index - first_index + 1)%2);
        int secondArr_firstIndex = firstArr_lastIndex + 1;
        int secondArr_lastIndex = last_index;
        int temp[last_index - first_index + 1];
        // printf("First Mergesort\t 1st array firstIndex = %d, 1st array lastIndex = %d\n", firstArr_firstIndex, firstArr_lastIndex);
        mergeSort(arr, firstArr_firstIndex, firstArr_lastIndex);
        // printf("Second Mergesort\t 2nd array firstIndex = %d, 2nd array lastIndex = %d\n", secondArr_firstIndex, secondArr_lastIndex);
        mergeSort(arr, secondArr_firstIndex, secondArr_lastIndex);
        
        int i = firstArr_firstIndex;
        int j = secondArr_firstIndex;

        for (int k = 0; k < (last_index - first_index + 1); k++){
            if (j == secondArr_lastIndex + 1) {
                temp[k] = arr[i];
                i++;
            }
            else if (i == firstArr_lastIndex + 1) {
                temp[k] = arr[j];
                j++;
            }
            else {
                if (arr[i] < arr[j]){
                    temp[k] = arr[i];
                    i++;
                }
                else {
                    temp[k] = arr[j];
                    j++;
                }
            }
        }

        for (int k = 0; k < (last_index - first_index + 1); k++){
            arr[first_index + k] = temp[k];
        }
        
        /*
        while ((i != firstArr_lastIndex + 1) && (j != secondArr_lastIndex + 1)) {
            printf("Hi\t i = %d, j = %d\n", i, j);
            if (arr[i] < arr[j]){i++;}
            else {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                j++;
            }
        } 
        */    
        // printArray(arr, arrSize); 
        // printf("\n");
    }
}

int main(){

    int arr[] = {12, 11, 13, 5 , 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    mergeSort(arr, 0, n - 1);
    printf("Sorted Array: ");
    printArray(arr, n);
    printf("\n");

    return 0;
}
