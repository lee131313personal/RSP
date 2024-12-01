#include<iostream>
#include<stddef.h>
#include<assert.h>

using namespace std;

void partition(int array[], int *pivot, int *first_eq, int *first_gt, int n);
void quicksort(int array[], int n);
void printArray(int array[], int n);

int main(){
    int array1[10] = {12,56,34,11,223,8,5,43,2,-100};
    quicksort(array1, 10);
    printArray(array1, 10);
    return 0;
}

/* Basic idea about partition:
 * next = 0, fe = 0, fg = 0;
 * while (next < fg) do:
 *     if A[next] < p, then swap A[fe] and A[next], then fe++, next ++;
 *     else if A[next] > p, then swap A[next] and A[fg-1], then fg--;
 *     else next++;
 * */

void partition(int array[], int *pivot, int *first_eq, int *first_gt, int n){
    /*We maintain three loop control variables: fe, fg and next. And the distance between next and fg is going to tell us how many unprocessed elements there are.*/

    int next = 0;
    int fe = 0;
    int fg = n;
    
    while (next < fg) {
        if (array[next] < *pivot){
            swap(array[fe], array[next]);
            fe++;
            next++;
        }

        else if (array[next] > *pivot){
            swap(array[fg-1], array[next]);
            fg--;
        }

        else next++;
    }
    assert (fe >= 0  &&  fe<fg  &&  fg<=n);
    *first_eq = fe;
    *first_gt = fg;
    return;
}

void quicksort(int array[], int n){
    int pivot = array[n/2];
    int first_eq, first_gt;

    if(n<=1) return;
    partition(array, &pivot, &first_eq, &first_gt, n);
    quicksort(array, first_eq);
    quicksort(array+first_gt, n-first_gt);
}





void printArray(int array[], int n){
    cout <<"Array sorted:\n";
    for (int i=0; i<n; i++){
        cout << array[i] << " ";
    }
    cout << "\n";
}


