/*
 
Question : 
given an array, sorted, given a target value 
Find the index or find where it should be inserted ? 

Test cases:

 arr1 = [1,3,5,6] target = 5, theb return index = 2;
 arr2 = [1,3,5,6] target = 2, theb return index = 1;
 arr3 = [3,7,9,10] target = 8, theb return index = 3;

 The idea is: 
 (1) Iteration 
 (2) BS  >>> 

Constraits: 
length of the array ? 
the time complexity ? O(log(n)) 
the nums[i]  ?
target ? 


Steps :

1. We start from the middle of the array 
2. We do BS {
    if the target value is larger    ====> go left 
    if the targt value is smaller    ====> go right 
    if not found we return the closest one
}

Idea : Recursion 
 *
 * */

#include<iostream>
using std::cout; 
using std::endl;


int helper(int arr[], int target, int start, int end){
    
    if (start > end) return start;

    // base case: the target == arr[i]
    int middle = (start + end) / 2 ; 
    if (arr[middle] > target) // go left 
        return helper(arr, target, start, middle -1);
    else if (arr[middle] < target) // go right 
        return helper(arr, target, middle + 1, end);
    else // arr[middle] = target 
        return middle;

}


int findTargetIndex(int arr[], int target, int size){
    int target_index = helper(arr, target, 0, size-1);  
    return target_index;
}

int main(){
    int arr[] = {3,7,9,10};
    cout << findTargetIndex(arr, 8, 4) << endl;  // expect 2
    cout << findTargetIndex(arr, 14, 4) << endl; // expect 4 



    return 0;
}

