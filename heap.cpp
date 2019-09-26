#include "heap.h"

/*
    This is implementation file for heap.h.
    Coded by Alistaire Suh
*/

//constructors{
template<class T>
MinHeap<T>::MinHeap(int n){
    heapSize = n;
    capacity = heapSize * 2;
    A = new T[capacity];
    LOG1("Heap init");
}

template<class T>
MinHeap<T>::MinHeap(T initA[], int n){
    A = new T[n];
    copy(initA, n);
    heapSize = n;
    capacity = 2 * n;
    LOG1("Heap init");
}

template<class T>
MinHeap<T>::MinHeap(const MinHeap<T>& heap){
    copy(heap);
    LOG1("copyHeap init");
}
//}

//destructor{
template<class T>
MinHeap<T>::~MinHeap(){
    destroy();
    LOG1("heap deleted");
}
//}

//public member functions{
template<class T>
string MinHeap<T>::toString(){
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
void MinHeap<T>::heapSort(T sorted[]){
    //??
    int size = sizeof(sorted)/sizeof(sorted[0]);
    copy(sorted, size);
    buildHeap();
    for (int i = size; i >= 2;i--){
        swap(1,i);
        heapSize--;
        heapify(1);
    }
    heapSize = size;
    capacity = size;//????
}

template<class T>
MinHeap<T> MinHeap<T>::operator=(MinHeap<T> &heap){
    copy(heap);
}

// template<class T>
// int MinHeap<T>::getHeight(){
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
        swap(i,smallest);
        heapify(smallest);
    }
}

template<class T>
void MinHeap<T>::buildHeap(){
    for (int i = capacity/2 ; i >= 1; i--)
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