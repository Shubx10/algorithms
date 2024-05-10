#include <iostream>
using namespace std;

void printArray(int arr[], int length){
    for(int i = 0; i < length; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void merge(int nums[], int low, int mid, int high){
    int size = high - low + 1;
    int temp[size];
    int left = low, right = mid + 1, k = 0;
    while(left <= mid && right <= high){
        if(nums[left] <= nums[right]){
            temp[k++] = nums[left++];
        }else{
            temp[k++] = nums[right++];

        }
    }
    while(left <= mid){
        temp[k++] = nums[left++];
    }
    while(right <= high){
        temp[k++] = nums[right++];
    }
    int p = 0;
    for(int i = low; i <= high; ++i){
        nums[i] = temp[p++];
    }
}
void mergeSort(int nums[], int low, int high){
    if(low >= high){
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(nums, low, mid);
    mergeSort(nums, mid + 1, high);
    merge(nums, low, mid, high);
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
