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
    heapSize = capacity = n;  //setting up heapsize and capacity
    A = new T[capacity];      //setting up A
}

template<class T>
MinHeap<T>::MinHeap(T initA[], int n){  //constructor #2
    //This is constructor generating empty heap with given array and size.
    A = new T[n];             //settubg up A
    copy(initA, n);           //copy the list from argument into this.
    heapSize = capacity = n;  //setting up heapsize and capacity
    buildHeap();              //making it into a heap structure.
}

template<class T>
MinHeap<T>::MinHeap(const MinHeap<T>& heap){ //constructor #3
    //This is constructor generating heap with another MinHeap instance.
    copy(heap);               //copy the heap into this from argument.
}
//}

//destructor{
template<class T>
MinHeap<T>::~MinHeap(){ //destructor
    //this is triggered when object is deleted or program ends.
    destroy();               //freeing A and reset capacity and heapsize to default value
}
//}

//public member functions{
template<class T>
string MinHeap<T>::toString(){//original toString function
    //this function prints out items in the heap.
    string str = "[";                    //string setup
    for (int i = 0; i < heapSize; i++){
        str += to_string(*(A+i));        //append each item in the heap
        if (i != heapSize - 1){
            str += ", ";
        }
    }
    str += "]";                         //wrap the string with ]
    return str;                         //return the result string
}

template<>
string MinHeap<string>::toString(){
    //this is toString for string data type.
    string str = "[";
    for (int i = 0; i < heapSize; i++){
        str += *(A+i);
        if (i != heapSize - 1){
            str += ", ";
        }
    }
    str += "]";
    return str;
}

template<class T>
bool MinHeap<T>::isEmpty(){
    //this function checks if the heap is empty or not.
    return (heapSize == 0)?true:false;
}

template<class T>
int MinHeap<T>::heapsize(){
    //this function returns the heapsize.
    return heapSize;
}

template<class T>
int MinHeap<T>::cap(){
    //this function returns the capacity.
    return capacity;
}

template<class T>
T MinHeap<T>::getMin(){
    //this function returns the smallest value within the heap.
    return A[0];
}

template<class T>
void MinHeap<T>::operator=(MinHeap<T> &heap){
    //this allows heap class working with assigment operator
    copy(heap);
}

template<class T>
void MinHeap<T>::heapSort(T *sorted){
    //sort the array in the ascending order.
                                               //1. sort in descending order.
    int size = heapSize;                       //storing heapSize for restoring after the loop.
    A = sorted;                                //shallow copy of the target array
    buildHeap();                               //making it into heap structure first
    for (int i = capacity - 1; i >= 0; i--){
        swap(0,i);                             //swap A[0] and A[n]
        heapSize--;                            //in order to exclude A[n] for heapify
        heapify(0);                            //heapify under mutated heapsize
    }
    heapSize = size;                           //restoring the heapSize
    reverse();                                 //2. reverse the A to make it in the ascending oder
}

template<class T>
void MinHeap<T>::buildHeap(){
    //this function makes the given array A into heap structure.
    heapSize = capacity;
    for (int i = (capacity/2) - 1; i >= 0; i--)
        heapify(i);
}

//private member funcions
template<class T>
void MinHeap<T>::heapify(int index){
    //this function checks heap property in parent node and children nodes.
    int left = leftChild(index);                  //left child node position
    int right = rightChild(index);                //right child node position
    int min;                                      //value to compare with
    if ((heapSize > left) && (A[left] < A[index]))//checking left child
        min = left;                               //if left child is smaller,set it as min
    else
        min = index;                              //if not, A[i] is the min.

    if ((heapSize > right) && (A[right] < A[min]))//checking right child
        min = right;                              //if right child is smaller, set it as min.

    if (min != index){                            //if min is not A[i]
        swap(index,min);                          //swap it with min
        heapify(min);                             //do the same with min.
    }
}

template<class T>
int MinHeap<T>::leftChild(int index){
    //this funciton returns the left child node position.
    return 2 * index;
}

template<class T>
int MinHeap<T>::rightChild(int index){
    //this funciton returns the right child node position.
    return 2 * index + 1;
}

template<class T>
int MinHeap<T>::parent(int index){
    //this funciton returns the parent node position.
    return (index - 1)/ 2;
}


template<class T>
void MinHeap<T>::swap(int index1, int index2){
    //this function swaps two items in different positions.
    T temp = A[index2];
    A[index2] = A[index1];
    A[index1] = temp;
}

template<class T>
void MinHeap<T>::copy(const MinHeap<T> &heap){
    //this function deep copies heap into A based on heap input.
    heapSize = heap.heapSize;
    capacity = heap.capacity;
    A = new T[heap.capacity];
    for (int i = 0; i < heapSize; i++){
        A[i] = *(heap.A+i);
    }
}

template<class T>
void MinHeap<T>::copy(T *copyA, int size){
    //this function deep copies heap into A on array input.
    for (int i = 0; i < size; i++){
        A[i] = *(copyA+i);
    }
}

template<class T>
void MinHeap<T>::destroy(){
    //this function free up the memory allocated for A.
    delete[] A;
    heapSize = capacity = 0;
}

template<class T>
void MinHeap<T>::reverse(){
    //this function reverse the array
    for (int i = 0; i < capacity/2; i++){
        swap(i, capacity-i-1);
    }
}
//}

template<class T>
void showArr(T *item, int size){
    //this function is toString for just array.
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
    //this function is toString for just array for string data type.
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
