# Takeaways 🚀
<br>

>Complexity of Heap Data Structure
<ul>
  <li>Get Min or Max Element - O(1)
  <li>Remove Min or Max Element - O(log n)
  <li>Insert an Element - O(log n)
</ul>
<br>

>Heap Sort
<ul>
  <li> Time Complexity - O(n log(n))
  <li> Space Complexity - O(1)
</ul>

```cpp
// Heap Sort in C++
 
  void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    if (largest != i) {
      swap(arr[i], arr[largest]);
      heapify(arr, n, largest);
    }
  }
  
  void heapSort(int arr[], int n) {
    // Building max heap by heapifying the elements
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(arr[0], arr[i]);
      heapify(arr, i, 0);
    }
  }
```
