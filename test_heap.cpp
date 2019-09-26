#include "heap.h"

int main(){
    //setting up
    int intArr[3] = {1,2,3};
    double doubleArr[3] = {1.0,2.2,3.3};
    char charArr[3] = {'A','B','C'};
    string strArr[3] = {"hallo","meinen","freunden"};
    int size = 3;
    //testing empty heap with each data type.
    MinHeap<int> intHeap;
    MinHeap<double> doubleHeap;
    MinHeap<char> charHeap;
    MinHeap<string> stringHeap;
    LOG1("-===============================================-");
    //testing heap with given size of 3;
    MinHeap<int> intHeap1(3);
    MinHeap<double> doubleHeap1(3);
    MinHeap<char> charHeap1(3);
    MinHeap<string> stringHeap1(3);
    LOG1("-===============================================-");
    //testing heap with arr given
    MinHeap<int> copyIntHeap(intArr, size);
    MinHeap<double> copyDoubleHeap(doubleArr, size);
    MinHeap<char> copyCharHeap(charArr, size);
    MinHeap<string> copystrHeap(strArr, size);
    LOG1("-===============================================-");
    //testing heap with copy costructor
    MinHeap<int> copyIntHeap1(copyIntHeap);
    MinHeap<double> copyDoubleHeap1(copyDoubleHeap);
    MinHeap<char> copyCharHeap1(copyCharHeap);
    MinHeap<string> copystrHeap1(copystrHeap);
    LOG1("-===============================================-");
    //testing toString()
    LOG1(intHeap.toString());
    LOG1(doubleHeap.toString());
    LOG1(charHeap.toString());
    LOG1(stringHeap.toString());
    LOG1(intHeap1.toString());
    LOG1(doubleHeap1.toString());
    LOG1(charHeap1.toString());
    LOG1(stringHeap1.toString());
    LOG1(copyIntHeap.toString());
    LOG1(copyDoubleHeap.toString());
    LOG1(copyCharHeap.toString());
    LOG1(copystrHeap.toString());
    LOG1(copyIntHeap1.toString());
    LOG1(copyDoubleHeap1.toString());
    LOG1(copyCharHeap1.toString());
    LOG1(copystrHeap1.toString());
    LOG1("-===============================================-");
    //testing assign operator
    intHeap = copyIntHeap;
    doubleHeap = copyDoubleHeap;
    charHeap = copyCharHeap;
    stringHeap = copystrHeap;
    LOG1(intHeap.toString());
    LOG1(doubleHeap.toString());
    LOG1(charHeap.toString());
    LOG1(stringHeap.toString());
    LOG1("-===============================================-");
    //testing heap sort and build heap and heapify
    // intHeap.heapSort(new int[3]);
    // doubleHeap.heapSort(new double[3]);
    // charHeap.heapSort(new char[3]);
    // stringHeap.heapSort(new string[3]);
    // LOG1(intHeap.toString());
    // LOG1(doubleHeap.toString());
    // LOG1(charHeap.toString());
    // LOG1(stringHeap.toString());
    LOG1("-===============================================-");
    //testing destructor and destroy which is embedded there
}