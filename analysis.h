#ifndef ANALYSIS_H
#define ANALYSIS_H
#include <sys/time.h>

template<class T>
void loop(T *data, int rep);

template<class T>
void dataFill(T *arr, int rep);

template<class T>
long merge_runtime(timeval timeBefore,timeval timeAfter, long diffSeconds, long diffUSeconds, T *arr, int i, int j);

template<class T>
void eachMergeTest(timeval timeBefore,timeval timeAfter, long diffSeconds, long diffUSeconds,T *arr, int n);

void testMergeSort();

template<class T>
long insert_runtime(timeval timeBefore,timeval timeAfter, long diffSeconds, long diffUSeconds, T *arr, int n);

template<class T>
void eachInsertTest(timeval timeBefore,timeval timeAfter, long diffSeconds, long diffUSeconds,T *arr, int n);

void testInsert_Sort();

template<class T>
long heap_runtime(timeval timeBefore,timeval timeAfter, long diffSeconds, long diffUSeconds, T *arr, int n);

template<class T>
void eachHeapTest(timeval timeBefore,timeval timeAfter, long diffSeconds, long diffUSeconds,T *arr, int n);

void testHeapSort();

#include "analysis.cpp"
#endif 