#include <bits/stdc++.h>
using namespace std;

void traverse(int arr[], int n){
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
}

void bubbleSort(int arr[], int n){
    bool swapped;
    for(int i = n - 1; i > 0; --i){
        swapped = false;
        for(int j = 0; j < i; ++j){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if(swapped == false) break;
    }
}

int main(){
    int arr[5] = {36, 2, 45, 25, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Unsorted Array - \n";
    traverse(arr, n);
    bubbleSort(arr, n);
    cout << "\nSorted Array - \n";
    traverse(arr, n);
    return 0;
}
