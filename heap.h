#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/*
    This is header file for heap.h.
    Coded by Alistaire Suh
*/

#define LOG1(x) cout << x << endl;
#define DEFAULT_SIZE 0

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

        void heapSort(T sorted[]);
        string toString();//done
        void operator=(MinHeap<T>& heap);//done
        //int height();
        //int size();
        int getCapacity();//done

    private:
        void heapify(int index);
        void buildHeap();

        int leftChild(int index);
        int rightChild(int index);
        int parent(int index);
        void swap(int index1, int index2);//done
        void copy(const MinHeap<T> &heap);//done
        void copy(T *copyA, int size);//done
        void destroy();//done
        void doubleUp();//done
};

#include "heap.cpp"
#endif