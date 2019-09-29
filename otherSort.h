#ifndef OTHER_SORT_H
#define OTHER_SORT_H

template<class T>
void insert_Sort(T *arr, int n);

template<class T>
void merge(T *arr, int left, int middle, int right);
  
template<class T>
void mergeSort(T *arr, int left, int right);

#include "otherSort.cpp"
#endif