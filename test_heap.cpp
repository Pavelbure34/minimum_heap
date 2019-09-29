#include "heap.h"

int main(){
    //setting up the initial arrays
    int intArr[6] = {6,5,4,1,2,3};
    double doubleArr[6] = {2.2,1.0,5.3,4.3,3.3,6.3};
    float floatArr[6] = {2.3,1.6,4.8,3.4,5.9,6.8};
    char charArr[6] = {'A','B','C','a','b','c'};
    string strArr[6] = {"hallo","meinen","freunden","Guten Tag","Guten Abend","Gute Nacht"};
    int size = 6;

    //testing empty heap with each data type.
    MinHeap<int> intHeap;
    MinHeap<double> doubleHeap;
    MinHeap<float> floatHeap;
    MinHeap<char> charHeap;
    MinHeap<string> stringHeap;

    /*
        This tests emmpty heap is really empty
        using isEmpty() functions.
    */
    assert(intHeap.isEmpty() == 1);
    assert(doubleHeap.isEmpty() == 1);
    assert(floatHeap.isEmpty() == 1);
    assert(charHeap.isEmpty() == 1);
    assert(stringHeap.isEmpty() == 1);

    //testing heap with capacity and heapSize
    MinHeap<int> intHeap1(3);
    MinHeap<double> doubleHeap1(5);
    MinHeap<float> floatHeap1(10);
    MinHeap<char> charHeap1(6);
    MinHeap<string> stringHeap1(9);

    /*
        This tests whehter heapSize and capacity
        are identical when heap is generated
    */
    assert(intHeap1.cap() == intHeap1.heapsize());
    assert(doubleHeap1.cap() == doubleHeap1.heapsize());
    assert(floatHeap1.cap() == floatHeap1.heapsize());
    assert(charHeap1.cap() == charHeap1.heapsize());
    assert(stringHeap1.cap() == stringHeap1.heapsize());

    //testing heap with arr given array and heap with copy costructor
    MinHeap<int> copyIntHeap(intArr, size);
    MinHeap<double> copyDoubleHeap(doubleArr, size);
    MinHeap<float> copyFloatHeap(floatArr, size);
    MinHeap<char> copyCharHeap(charArr, size);
    MinHeap<string> copystrHeap(strArr, size);

    MinHeap<int> copyIntHeap1(copyIntHeap);
    MinHeap<double> copyDoubleHeap1(copyDoubleHeap);
    MinHeap<float> copyFloatHeap1(copyFloatHeap);
    MinHeap<char> copyCharHeap1(copyCharHeap);
    MinHeap<string> copystrHeap1(copystrHeap);

    MinHeap<int> copyIntHeap2 = copyIntHeap;
    MinHeap<double> copyDoubleHeap2 = copyDoubleHeap;
    MinHeap<float> copyFloatHeap2 = copyFloatHeap;
    MinHeap<char> copyCharHeap2 = copyCharHeap;
    MinHeap<string> copystrHeap2 = copystrHeap;

    /*
        This tests whether copied heap using either 
        assingment operator or copy constructor shares
        the identical A within themselves.
    */
    assert(copyIntHeap.getMin() == copyIntHeap1.getMin());
    assert(copyIntHeap.getMin() == copyIntHeap2.getMin());
    assert(copyDoubleHeap.getMin() == copyDoubleHeap1.getMin());
    assert(copyDoubleHeap.getMin() == copyDoubleHeap2.getMin());
    assert(copyFloatHeap.getMin() == copyFloatHeap1.getMin());
    assert(copyFloatHeap.getMin() == copyFloatHeap2.getMin());
    assert(copyCharHeap.getMin() == copyCharHeap1.getMin());
    assert(copyCharHeap.getMin() == copyCharHeap2.getMin());
    assert(copystrHeap.getMin() == copystrHeap1.getMin());
    assert(copyCharHeap.getMin() == copyCharHeap2.getMin());

    //testing toString(),embedded in << stream opretor, and << stream operator
    LOG2("intHeap = ", intHeap);
    LOG2("doubleHeap = ", doubleHeap);
    LOG2("floatHeap = ", floatHeap);
    LOG2("charHeap = ", charHeap);
    LOG2("stringHeap = ", stringHeap);
    LOG2("intHeap1 = ", intHeap1);
    LOG2("doubleHeap1 = ", doubleHeap1);
    LOG2("floatHeap1 = ", floatHeap1);
    LOG2("charHeap1 = ", charHeap1);
    LOG2("stringHeap1 = ", stringHeap1);
    LOG2("copyIntHeap = ", copyIntHeap);
    LOG2("copyDoubleHeap = ", copyDoubleHeap);
    LOG2("copyFloatHeap = ", copyFloatHeap);
    LOG2("copyCharHeap = ", copyCharHeap);
    LOG2("copystrHeap = ", copystrHeap);
    LOG2("copyIntHeap1 = ", copyIntHeap1);
    LOG2("copyDoubleHeap1 = ", copyDoubleHeap1);
    LOG2("copyFloatHeap1 = ", copyFloatHeap1);
    LOG2("copyCharHeap1 = ", copyCharHeap1);
    LOG2("copystrHeap1 = ", copystrHeap1);
    LOG2("copyIntHeap2 = ", copyIntHeap2);
    LOG2("copyDoubleHeap2 = ", copyDoubleHeap2);
    LOG2("copyFloatHeap2 = ", copyFloatHeap2);
    LOG2("copyCharHeap2 = ", copyCharHeap2);
    LOG2("copystrHeap2 = ", copystrHeap2);
    LOG1(BR_);

    //setting up for testing heapsort
    int *intSorted = new int[5];
    double *doubleSorted = new double[5];
    float *floatSorted = new float[10];
    char *charSorted = new char[6];
    string *strSorted = new string[3];
    int *intSorted2 = new int[50];
    for (int i = 0; i < 50; i++)
        intSorted2[i] = 50 - i;
    
    intSorted[0] = 1;
    intSorted[1] = 5;
    intSorted[2] = 2;
    intSorted[3] = 3;
    intSorted[4] = 4;
    
    doubleSorted[0] = 1.1;
    doubleSorted[1] = 3.1;
    doubleSorted[2] = 2.2;
    doubleSorted[3] = 5.6;
    doubleSorted[4] = 4.5;

    floatSorted[0] = 12.99;
    floatSorted[1] = 4.8;
    floatSorted[2] = 14.99;
    floatSorted[3] = 2.5;
    floatSorted[4] = 5.56;
    floatSorted[5] = 8.99;
    floatSorted[6] = 20.99;
    floatSorted[7] = 10.99;
    floatSorted[8] = 3.6;
    floatSorted[9] = 1.9;
    
    charSorted[0] = 'a';
    charSorted[1] = 'b';
    charSorted[2] = 'c';
    charSorted[3] = 'A';
    charSorted[4] = 'B';
    charSorted[5] = 'C';
    
    strSorted[0] = "Hola";
    strSorted[1] = "amigo";
    strSorted[2] = "Bonjour";

    MinHeap<int> intHeap2(intSorted, 5);
    MinHeap<int> intHeap3(intSorted2, 50);
    MinHeap<double> doubleHeap2(doubleSorted, 5);
    MinHeap<float> floatHeap2(floatSorted, 10);
    MinHeap<char> charHeap2(charSorted, 6);
    MinHeap<string> strHeap2(strSorted, 3);

    //testing heap sort and build heap and heapify
    intHeap2.heapSort(intSorted);
    intHeap3.heapSort(intSorted2);
    doubleHeap2.heapSort(doubleSorted);
    floatHeap2.heapSort(floatSorted);
    charHeap2.heapSort(charSorted);
    strHeap2.heapSort(strSorted);

    /*
        This tests whether the sorted list is 
        in ascending order.
    */
    assert(intSorted[0] == 1);
    assert(intSorted[3] == 4);
    assert(intSorted2[0] == 1);
    assert(intSorted2[49] == 50);
    assert(doubleSorted[0] == 1.100000);
    assert(floatSorted[0] == 1.9f);
    assert(floatSorted[9] == 20.99f);
    assert(charSorted[0] == 65);
    assert(charSorted[5] == 99);
    assert(strSorted[0] == "Hola");
    assert(strSorted[2] == "amigo");

    //deleting test arrays
    delete[] intSorted;
    delete[] intSorted2;
    delete[] doubleSorted;
    delete[] floatSorted;
    delete[] charSorted;
    delete[] strSorted;
    
    //testing destructor and destroy which is embedded there
}