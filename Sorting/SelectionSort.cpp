#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int size){
    int i, j, minIndex;
    for (i = 0; i < size - 1; i++){
        minIndex = i;
        for (j = i + 1; j < size; j++){
            if (arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

int main(){
    int arr[] = { 9, 6, 7, 2, 5, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
