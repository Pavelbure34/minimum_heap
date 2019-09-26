#include "heap.h"

int main(){
    int intArr[3] = {1,2,3};
    int size = sizeof(intArr)/sizeof(intArr[0]);
    MinHeap<int> intHeap1;
    MinHeap<int> intHeap2(intArr, size);
    MinHeap<int> intHeap3(4);
    MinHeap<int> copyHeap2(intHeap2);
    MinHeap<int> copyHeap3 = intHeap2;
    // intHeap2.swap(0,1);
    // copyHeap3.swap(0,2);
    // copyHeap2.swap(1,2);
    //intHeap2.doubleUp();
    // copyHeap3.doubleUp();
    // copyHeap2.doubleUp()
    LOG1(intHeap1.toString());
    LOG1(intHeap2.toString());
    LOG1(intHeap3.toString());
    LOG1(copyHeap2.toString());
    LOG1(copyHeap3.toString());
    // LOG1(intHeap1.getCapacity());
    // LOG1(intHeap2.getCapacity());
    // LOG1(copyHeap2.getCapacity());
    // LOG1(copyHeap3.getCapacity());
}