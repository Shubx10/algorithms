# Takeaways 🚀
<br>

>Bubble Sort
<ul>
    <li>Best Case Complexity - O(n) - when list is already sorted</li>
    <li>Average Case Complexity - O($n^2$)</li>
    <li>Worst Case Complexity - O($n^2$)</li>
    <li>Space Complexity - O(1)</li>
    <li>Stable Algorithm</li>
    <li>In-place Algorithm</li>
</ul>

```cpp
void bubbleSort(int arr[], int n){
    bool swapped;
    for(int i = n - 1; i > 0; --i){
        swapped = false;
        for(int j = 0; j <= i - 1; j++){
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
    <li>Best Case Complexity - O(n) - when list is already sorted</li>
    <li>Average Case Complexity - O($n^2$)</li>
    <li>Worst Case Complexity - O($n^2$)</li>
    <li>Space Complexity - O(1)</li>
    <li>Stable Algorithm</li>
    <li>In-place Algorithm</li>
</ul>

```cpp
void insertionSort(int arr[], int n){
    for(int i = 0; i < n; ++i){
        int j = i;
        while(j > 0 && arr[j - 1] > arr[j]){
            swap(arr[j - 1], arr[j]);
            j--;
        }
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
void selectionSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minIndex]){
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
    <li>Worst Case Complexity - O($n^2$) - This case occurs when pivot is either the greatest or smallest element of the array.</li>
    <li>Space Complexity - O(log n) in average case | O(n) in worst case</li>
    <li>Unstable Algorithm</li>
    <li>In-place Algorithm</li>
</ul>

```cpp
int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low, j = high;
    while(i < j){
        while(arr[i] <= pivot && i <= high - 1){
            i++;
        }
        while(arr[j] > pivot && j >= low + 1){
            j--;
        }
        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int PIndex = partition(arr, low, high);
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
