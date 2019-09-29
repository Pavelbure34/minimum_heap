#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include <string>
#include "assert.h"
using namespace std;

/*
    This is header file for heap.h.
    Coded by Alistaire Suh
*/

#define LOG1(x) cout << x << endl;
#define LOG2(x, y) cout << x << y << endl;
#define LOG3(x, y, z) cout << x << " " << y << " = "<< z << endl;
#define DEFAULT_SIZE 0
#define BR_ "-===============================================-"

template<class T>
class MinHeap{
    private:
        T *A;
        int heapSize;
        int capacity;

    public:
        MinHeap(int n = DEFAULT_SIZE);//done
        MinHeap(T initA[], int n);//done
        MinHeap(const MinHeap<T>& heap);//done
        ~MinHeap();//done

        void heapSort(T *sorted);
        string toString();//done
        void operator=(MinHeap<T>& heap);//done
        bool isEmpty();
        int heapsize();
        int cap();
        T getMin();
        friend ostream& operator<<(ostream &o, MinHeap<T> &heap){
            //this friend function enables osteam operator.
            o << heap.toString();
            return o;
        }

    private:
        void heapify(int index);
        void buildHeap();

        int leftChild(int index);
        int rightChild(int index);
        int parent(int index);
        void swap(int index1, int index2);
        void copy(const MinHeap<T> &heap);
        void copy(T *copyA, int size);
        void destroy();
        void reverse();
};

template<class T>
void showArr(T *item, int size);

template<>
void showArr(string *item, int size);

#include "heap.cpp"
#endif