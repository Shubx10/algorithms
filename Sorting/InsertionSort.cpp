#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i = 0; i < n; ++i){
        int j = i;
        while(j > 0 && arr[j - 1] > arr[j]){
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}

int main(){
    int arr[] = {9, 6, 7, 2, 5, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
    return 0;
}
