#include "heap.h"

int main(){
    //setting up
    int intArr[6] = {1,2,3,4,5,6};
    double doubleArr[6] = {1.0,2.2,3.3,4.3,5.3,6.3};
    char charArr[6] = {'A','B','C','a','b','c'};
    string strArr[6] = {"hallo","meinen","freunden","Guten Tag","Guten Abend","Gute Nacht"};
    int size = 6;

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
    LOG1(intHeap);
    LOG1(doubleHeap);
    LOG1(charHeap);
    LOG1(stringHeap);
    LOG1(intHeap1);
    LOG1(doubleHeap1);
    LOG1(charHeap1);
    LOG1(stringHeap1);
    LOG1(copyIntHeap);
    LOG1(copyDoubleHeap);
    LOG1(copyCharHeap);
    LOG1(copystrHeap);
    LOG1(copyIntHeap1);
    LOG1(copyDoubleHeap1);
    LOG1(copyCharHeap1);
    LOG1(copystrHeap1);
    LOG1("-===============================================-");

    //testing assign operator
    intHeap = copyIntHeap;
    doubleHeap = copyDoubleHeap;
    charHeap = copyCharHeap;
    stringHeap = copystrHeap;
    LOG1(intHeap);
    LOG1(doubleHeap);
    LOG1(charHeap);
    LOG1(stringHeap);
    LOG1("-===============================================-");

    //setting up 
    int *intSorted = new int[6];
    double *doubleSorted = new double[6];
    char *charSorted = new char[6];
    string *strSorted = new string[6];
    
    intSorted[0]=1;
    intSorted[1]=2;
    intSorted[2]=3;
    intSorted[3]=4;
    intSorted[4]=5;
    intSorted[5]=6;
    
    doubleSorted[0]=1.0;
    doubleSorted[1]=2.2;
    doubleSorted[2]=3.1;
    doubleSorted[3]=4.5;
    doubleSorted[4]=5.6;
    doubleSorted[5]=6.9;
    
    charSorted[0]='a';
    charSorted[1]='b';
    charSorted[2]='c';
    charSorted[3]='A';
    charSorted[4]='B';
    charSorted[5]='C';
    
    strSorted[0]="Hola";
    strSorted[1]="amigo";
    strSorted[2]="Hallo";
    strSorted[3]="Keine Anung";
    strSorted[4]="Die Uhr";
    strSorted[5]="Ubahn";

    //testing heap sort and build heap and heapify
    intHeap.heapSort(intSorted,6);
    doubleHeap.heapSort(doubleSorted,6);
    charHeap.heapSort(charSorted,6);
    stringHeap.heapSort(strSorted,6);

    //showing heap sorted arrays;
    showArr(intSorted,6);
    showArr(doubleSorted,6);
    showArr(charSorted,6);
    showArr(strSorted,6);

    //deleting test arrays
    delete intSorted;
    delete doubleSorted;
    delete charSorted;
    delete strSorted;
    LOG1("-===============================================-");

    //testing destructor and destroy which is embedded there
}