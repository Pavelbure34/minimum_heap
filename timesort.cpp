#include "heap.h"
#include "otherSort.h"
#include "analysis.h"

int *testArr;

int main(){
    //choosing either one.

    LOG1("HeapSort testing");
    testHeapSort(testArr);
    
    // LOG1("MergSort testing");
    // testMergeSort();
    
    // LOG1("Insertion Sort testing");
    // testInsert_Sort();
}
