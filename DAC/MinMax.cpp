#include <iostream>
#include <climits>
using namespace std;
 
void findMinAndMax(int nums[], int low, int high, int &min, int &max){
    // if the array contains only one element
    if(low == high){
        if(max < nums[low]){           
            max = nums[low];
        }
        if(min > nums[high]){     
            min = nums[high];
        }
        return;
    }
 
    // if the array contains only two elements
    if(high - low == 1){
        if(nums[low] < nums[high]){
            if(min > nums[low]){       
                min = nums[low];
            }
            if(max < nums[high]){      
                max = nums[high];
            }
        }
        else{
            if(min > nums[high]){      
                min = nums[high];
            }
            if(max < nums[low]){       
                max = nums[low];
            }
        }
        return;
    }
 
    int mid = (low + high) / 2;
    // recursion for the left subarray
    findMinAndMax(nums, low, mid, min, max);
    // recursion for the right subarray
    findMinAndMax(nums, mid + 1, high, min, max);
}
 
int main(){
    int nums[] = { 7, -3, 9, 3, 0, 6, 7, 64, 4 };
    int max = INT_MIN, min = INT_MAX;
    int n = sizeof(nums) / sizeof(nums[0]);
    findMinAndMax(nums, 0, n - 1, min, max);
 
    cout << "The minimum array element is " << min << endl;
    cout << "The maximum array element is " << max << endl;
 
    return 0;
}
