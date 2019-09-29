#include "otherSort.h"

template<class T>
void insert_Sort(T *arr, int n){  
    int k;  //key int for comparison
    int j, i; //indeces for loop
    for (i = 1; i < n; i++){  
        k = arr[i];  
        j = i - 1;  
        while (j >= 0 && arr[j] > k) {  
            arr[j + 1] = arr[j];  //Move item to one position ahead of their current if bigger.
            j = j - 1;  
        }  
        arr[j + 1] = k;  
    }  
}  

template<class T>
void merge(T *arr, int left, int middle, int right){ 
    int n1 = middle - left + 1; 
    int n2 =  right - middle; 
    int L[n1], R[n2];            //create temp arrays 
    for (int i = 0; i < n1; i++) //Copy data to L[]
        L[i] = arr[left + i]; 
    for (int j = 0; j < n2; j++) //Copy data to R[]
        R[j] = arr[middle + 1+ j]; 
  
    //Merging temporary arrays into arr
    int x = 0; // Init index of first subarray 
    int y = 0; // Init index of second subarray 
    int z = left; // Init index of merged subarray 
    while (x < n1 && y < n2) { 
        if (L[x] <= R[y]) { 
            arr[z] = L[x]; 
            x++; 
        } 
        else{ 
            arr[z] = R[y]; 
            y++; 
        } 
        z++; 
    } 
  
    while (x < n1) {//Copy the remaining items in L[] 
        arr[z] = L[x]; 
        x++; 
        z++; 
    } 
  
    while (y < n2) {//Copy the remaining items in R[] 
        arr[z] = R[y]; 
        y++; 
        z++; 
    } 
} 
  
template<class T>
void mergeSort(T *arr, int left, int right) { 
    /*
        left = left index for sub-array to be sorted
        right = right index for sub-array to be sorted
    */
    if (left < right) { 
        int middle = left+(right-left)/2; 
   
        mergeSort(arr, left, middle);     //first half 
        mergeSort(arr, middle+1, right);  //second half
  
        merge(arr, left, middle, right); 
    } 
} 