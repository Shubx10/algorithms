# Takeaways 🚀
<br>

>Bubble Sort
<ul>
    <li>Best Case Complexity - O(n)</li>
    <li>Average Case Complexity - O($n^2$)</li>
    <li>Worst Case Complexity - O($n^2$)</li>
    <li>Space Complexity - O(1)</li>
    <li>Stable Algorithm</li>
    <li>In-place Algorithm</li>
</ul>

```cpp
void bubbleSort(int arr[], int n){
    bool swapped;
    for(int i = 0; i < n - 1; i++){
        swapped = false;
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if(swapped == false)
            break;
    }
}
```
<br>

>Insertion Sort
<ul>
    <li>Best Case Complexity - O(n)</li>
    <li>Average Case Complexity - O($n^2$)</li>
    <li>Worst Case Complexity - O($n^2$)</li>
    <li>Space Complexity - O(1)</li>
    <li>Stable Algorithm</li>
    <li>In-place Algorithm</li>
</ul>

```cpp
void insertionSort(int arr[], int n){
    int i, j;
    for(i = 1; i < n; i++) {
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
```
<br>

>Selection Sort
<ul>
    <li>Best Case Complexity - O($n^2$)</li>
    <li>Average Case Complexity - O($n^2$)</li>
    <li>Worst Case Complexity - O($n^2$)</li>
    <li>Space Complexity - O(1)</li>
    <li>Unstable Algorithm</li>
    <li>In-place Algorithm</li>
</ul>

```cpp
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
```
<br>

>Merge Sort
<ul>
    <li>Best Case Complexity - O(n logn)</li>
    <li>Average Case Complexity - O(n logn)</li>
    <li>Worst Case Complexity - O(n logn)</li>
    <li>Space Complexity - O(n)</li>
    <li>Stable Algorithm</li>
    <li>Out-place Algorithm</li>
</ul>

```cpp
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
```
<br>

>Quick Sort
<ul>
    <li>Best Case Complexity - O(n logn)</li>
    <li>Average Case Complexity - O(n logn)</li>
    <li>Worst Case Complexity - O($n^2$)</li>
    <li>Space Complexity - O(log n)</li>
    <li>Unstable Algorithm</li>
    <li>In-place Algorithm</li>
</ul>

```cpp
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
```
<br>

>Heap Sort
<ul>
    <li>Best Case Complexity - O(n logn)</li>
    <li>Average Case Complexity - O(n logn)</li>
    <li>Worst Case Complexity - O(n logn)</li>
    <li>Space Complexity - O(1)</li>
    <li>Unstable Algorithm</li>
    <li>In-place Algorithm</li>
</ul>

```cpp
void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
      
    if(left < n && arr[left] > arr[largest]) 
        largest = left;
    if(right < n && arr[right] > arr[largest])
        largest = right;
    
    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n){ 
    for(int i = n / 2 - 1; i >= 0; --i){
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n){
    buildHeap(arr, n);
    for(int i = n - 1; i >= 0; --i){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
```
