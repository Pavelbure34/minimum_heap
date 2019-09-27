#include "heap.h"

/*
    This is implementation file for heap.h.
    Coded by Alistaire Suh
*/

//constructors{
template<class T>
MinHeap<T>::MinHeap(int n){             //constructor #1
    /*
        This is constructor generating empty heap with given size.
        If size n is not given, it is set by default value of 0.
    */
    heapSize = n;
    capacity = heapSize * 2;
    A = new T[capacity];
}

template<class T>
MinHeap<T>::MinHeap(T initA[], int n){  //constructor #2
    //This is constructor generating empty heap with given array and size.
    A = new T[n];
    copy(initA, n);
    heapSize = n;
    capacity = 2 * n;
    buildHeap();
}

template<class T>
MinHeap<T>::MinHeap(const MinHeap<T>& heap){ //constructor #3
    //This is constructor generating heap with another MinHeap instance.
    copy(heap);
    buildHeap();
}
//}

//destructor{
template<class T>
MinHeap<T>::~MinHeap(){ //destructor
    //this is triggered when object is deleted or program ends.
    destroy();
    LOG1("heap deleted");
}
//}

//public member functions{
template<class T>
string MinHeap<T>::toString(){//original toString function
    //this function prints out items in the heap.
    string str = "[";
    for (int i = 0; i < heapSize; i++){
        str += to_string(*(A+i));
        if (i != heapSize - 1){
            str += ", ";
        }
    }
    str += "]";
    return str;
}

template<>
string MinHeap<string>::toString(){
    //this is toString for string data type.
    string str = "[";
    for (int i = 0; i < heapSize; i++){
        //assert(typeof(*(A+i))==string);
        str += *(A+i);
        if (i != heapSize - 1){
            str += ", ";
        }
    }
    str += "]";
    return str;
}

template<class T>
void MinHeap<T>::heapSort(T *sorted, int size){
    //storing original value
    MinHeap<T> *temp = new MinHeap<T>(A,heapSize);
    int tempSize = heapSize;
    int tempCap = capacity;

    //sorted outside source
    copy(sorted, size);
    heapSize = size;
    capacity = size * 2;
    buildHeap();
    for (int i = heapSize; i >= 2;i--){
        swap(1,i);
        heapSize--;
        heapify(1);
    }

    //returning to original value;
    copy(*temp);
    heapSize = tempSize;
    capacity = tempCap;
    delete temp;
}

template<class T>
void MinHeap<T>::operator=(MinHeap<T> &heap){
    copy(heap);
}

// template<class T>
// int MinHeap<T>::height(){
//     return (int)log2(heapSize);
// }   

// template<class T>
// int MinHeap<T>::size(){
//     return heapSize;
// }

//private member funcions
template<class T>
void MinHeap<T>::heapify(int index){
    int left = leftChild(index);
    int right = rightChild(index);
    int smallest;
    if ((heapSize >= left) && (A[left] < A[right]))//do you have left child?
        smallest = left;
    else
        smallest = index;

    if ((heapSize >= right) && (A[right] < A[smallest]))//do you have right child?
        smallest = right;

    if (smallest != index){
        swap(index,smallest);
        heapify(smallest);
    }
}

template<class T>
void MinHeap<T>::buildHeap(){
    for (int i = capacity/2 ; i > 0; i--)
        heapify(i);
}

template<class T>
int MinHeap<T>::getCapacity(){
    return capacity;
}


template<class T>
int MinHeap<T>::leftChild(int index){
    return 2 * index;
}

template<class T>
int MinHeap<T>::rightChild(int index){
    return 2 * index + 1;
}

template<class T>
int MinHeap<T>::parent(int index){
    return (index - 1)/ 2;
}


template<class T>
void MinHeap<T>::swap(int index1, int index2){
    T temp = A[index2];
    A[index2] = A[index1];
    A[index1] = temp;
}

template<class T>
void MinHeap<T>::copy(const MinHeap<T> &heap){
    heapSize = heap.heapSize;
    capacity = heap.capacity;  
    A = new T[heap.capacity];
    for (int i = 0; i < heapSize; i++){
        A[i] = *(heap.A+i);
    }
}

template<class T>
void MinHeap<T>::copy(T *copyA, int size){
    for (int i = 0; i < size; i++){
        A[i] = *(copyA+i);
    }
}

template<class T>
void MinHeap<T>::destroy(){
    delete A;
    heapSize = 0;
    capacity = 0;
}

template<class T>
void MinHeap<T>::doubleUp(){
    capacity = capacity * 2;
    T* newA = new T[capacity];  
    for (int i = 0; i < heapSize; i++){
        newA[i] = *(A+i);
    }
    A = newA;
    delete newA;
}     
//}

template<class T>
void showArr(T *item, int size){
    string str = "{";
    for (int i = 0; i < size; i++){
        str += to_string(item[i]);
        if (i != size-1){
            str += ", ";
        }
    }
    str += "}";
    LOG1(str);
}

template<>
void showArr(string *item, int size){
    string str = "{";
    for (int i = 0; i < size; i++){
        str += item[i];
        if (i != size-1){
            str += ", ";
        }
    }
    str += "}";
    LOG1(str);
}  