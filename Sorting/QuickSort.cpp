#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high, int pivot){
    int PIndex = low;
    for (int i = low; i <= high; i++){
        if (arr[i] <= pivot){
            swap(arr[PIndex], arr[i]);
            PIndex++;
        }
    }
    PIndex--;
    return PIndex;
}

void quickSort(int arr[], int low, int high){
    if (low < high){
        int pivot = arr[high];
        int PIndex = partition(arr, low, high, pivot);
        quickSort(arr, low, PIndex - 1);
        quickSort(arr, PIndex + 1, high);
    }
}

int main(){
    int arr[7] = {6, 8, 0, -3, 7, 1, 9};
    int n = sizeof(arr) / sizeof(int);

    quickSort(arr, 0, n - 1);
    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
