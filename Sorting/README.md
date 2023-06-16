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
