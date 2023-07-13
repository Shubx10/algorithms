# Takeaways 🚀
<br>

>Complexity of Heap Data Structure
<ul>
  <li>Build Heap - O(n)
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
class Solution
{
    public:
    
    void heapify(int arr[], int n, int i)  
    {
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

    void buildHeap(int arr[], int n)  
    { 
        for(int i = n / 2 - 1; i >= 0; --i){
            heapify(arr, n, i);
        }
    }

    void heapSort(int arr[], int n)
    {
        buildHeap(arr, n);
        for(int i = n - 1; i >= 0; --i){
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};
```
<br>

>Insertion and Deletion in Heap
<ul>
  <li> Time Complexity - O(log n)
  <li> Space Complexity - O(n)
</ul>

```cpp
#include <bits/stdc++.h>
using namespace std;
 
void heapify(vector<int> &heap, int i){
 int size = heap.size();
 int largest = i;
 int l = 2 * i + 1;
 int r = 2 * i + 2;
 
 if (l < size && heap[l] > heap[largest])
   largest = l;
 if (r < size && heap[r] > heap[largest])
   largest = r;
 
 if (largest != i){
   swap(heap[i], heap[largest]);
   heapify(heap, largest);
 }
}
 
void insert(vector<int> &heap, int newNum){
 int size = heap.size();
 
 if (size == 0)
   heap.push_back(newNum);
 else
   heap.push_back(newNum);
   for (int i = size / 2 - 1; i >= 0; i--)
     heapify(heap, i);
}
 
void deleteNode(vector<int> &heap, int num){
 int size = heap.size();
 int i;
 
 for (i = 0; i < size; i++)
   if (num == heap[i])
     break;
  
 swap(heap[i], heap[size - 1]);
 heap.pop_back();
 for (int i = size / 2 - 1; i >= 0; i--)
   heapify(heap, i);
}
```
