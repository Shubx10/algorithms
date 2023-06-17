#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){
    int start = 0;
    int end = size - 1;
    
    while(start <= end){
        int mid = start + (end - start) / 2;

        if(arr[mid] == key){
            return mid;
        }else if(key > arr[mid]){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {2, 3, 4, 10, 40};
    int key = 16;
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, size, key);
    if(result == -1){
        cout<< "Key is not present in array";
    }else{
        cout<< "Key is present at index "<< result << endl;
    }
    return 0;
}
