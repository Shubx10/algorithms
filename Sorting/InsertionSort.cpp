#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n){
    int i, j;
    for(i = 1; i < n; i++){
        int var = arr[i];
        for(j = i - 1; j >= 0; j--){
            if(arr[j] > var){
                arr[j + 1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j + 1] = var;
    }
}

int main(){
    int arr[] = { 9, 6, 7, 2, 5, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
