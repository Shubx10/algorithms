#include <iostream>
using namespace std;

void printArray(int arr[], int length){
    for(int i = 0; i < length; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int low, int mid, int high){
    int i = 0, j = 0, k = low;
    int lengthLeft = mid - low + 1;
    int lengthRight = high - mid;

    int arrLeft[lengthLeft], arrRight[lengthRight];

    for(int a = 0; a < lengthLeft; a++){
        arrLeft[a] = arr[low + a];
    }
    for(int a = 0; a < lengthRight; a++){
        arrRight[a] = arr[mid + 1 + a];
    }

    while(i < lengthLeft && j < lengthRight){
        if(arrLeft[i] <= arrRight[j]) {
            arr[k++] = arrLeft[i++];
        }else{
            arr[k++] = arrRight[j++];
        }
    }

    while(i < lengthLeft){
        arr[k++] = arrLeft[i++];
    }

    while(j < lengthRight){
        arr[k++] = arrRight[j++];
    }
}

void mergeSort(int arr[], int low, int high){
    int mid;
    if(low < high){
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main(){
    int arr[] = {9, 14, 4, 6, 14, 8, 7};
    int length = sizeof(arr) / sizeof(int);

    cout << "Array before calling the mergeSort : ";
    printArray(arr, length);
    mergeSort(arr, 0, length - 1);
    cout << "Array after calling the mergeSort : ";
    printArray(arr, length);
    
    return 0;
}
