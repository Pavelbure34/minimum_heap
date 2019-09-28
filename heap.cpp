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
    heapSize = capacity = n;
    A = new T[capacity];
}

template<class T>
MinHeap<T>::MinHeap(T initA[], int n){  //constructor #2
    //This is constructor generating empty heap with given array and size.
    A = new T[n];
    copy(initA, n);
    heapSize = capacity =n;
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

template<class T>
bool MinHeap<T>::isEmpty(){
    return (heapSize == 0)?true:false;
}

template<class T>
int MinHeap<T>::heapsize(){
    return heapSize;
}

template<class T>
int MinHeap<T>::cap(){
    return capacity;
}

template<class T>
T MinHeap<T>::getMin(){
    return A[0];
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
void MinHeap<T>::heapSort(T *sorted){
    //sorted outside source
    int size = heapSize;
    copy(sorted, heapSize);
    buildHeap();
    for (int i = capacity; i > 1;i--){
        swap(1,i);
        heapSize--;
        heapify(1);
    }
    heapSize = size;
}

template<class T>
void MinHeap<T>::operator=(MinHeap<T> &heap){
    copy(heap);
}

template<class T>
void MinHeap<T>::buildHeap(){
    heapSize = capacity;
    for (int i = capacity/2 ; i > 0; i--)
        heapify(i-1);
}

//private member funcions
template<class T>
void MinHeap<T>::heapify(int index){
    int left = leftChild(index);
    int right = rightChild(index);
    int min;
    if ((heapSize >= left) && (A[left] < A[index]))//do you have left child?
        min = left;
    else
        min = index;

    if ((heapSize >= right) && (A[right] < A[min]))//do you have right child?
        min = right;

    if (min != index){
        swap(index,min);
        heapify(min);
    }
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
    delete[] A;
    heapSize = capacity = 0;
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