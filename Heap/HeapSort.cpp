#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    // Find the largest among root, left, and right child.
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If the left child is larger than the root.
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If the right child is larger than the root.
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Changing and heapifying if the root is not the largest.
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void min_heapify(int arr[], int n, int i) 
{ 
    int smallest = i;  
    int left = 2 * i + 1;  
    int right = 2 * i + 2; 
  
    if (left < n && arr[left] < arr[smallest]) 
        smallest = left; 
  
    if (right < n && arr[right] < arr[smallest]) 
        smallest = right; 
  
    if (smallest != i) { 
        swap(arr[i], arr[smallest]); 
        min_heapify(arr, n, smallest); 
    } 
}

void heapSort(int arr[], int n) {
    // Build max heap.
    for (int i = n / 2 - 1; i >= 0; i--)
        min_heapify(arr, n, i);

    // Extracting elements from the heap.
    for (int i = n - 1; i >= 0; i--) {
        // Swapping the root element with the last element.
        swap(arr[0], arr[i]);

        // Repeatedly heapify on shrinked heap.
        min_heapify(arr, i, 0);
    }
}

void print_Array(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr[] = {1, 12, 9, 5, 6, 10, 2, 4, 13, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);

    cout << "The sorted array is: \n";
    print_Array(arr, n);
}
