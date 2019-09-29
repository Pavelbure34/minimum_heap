#include "analysis.h"

template<class T>
void loop(T *data, int rep){
    for (int i = 0; i < rep; i++){
      data[i] = rep - i;
    }
}

template<class T>
void dataFill(T *arr, int rep){
    arr = new T[rep];
    loop(arr, rep);
}

template<class T>
long merge_runtime(timeval timeBefore,timeval timeAfter, long diffSeconds, long diffUSeconds, T *arr, int i, int j){
  gettimeofday(&timeBefore, NULL);

  //call sorting method here.
  mergeSort(arr, i, j);

  gettimeofday(&timeAfter, NULL);
  diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
  diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

  return diffSeconds + diffUSeconds/1000000.0;
}

template<class T>
void eachMergeTest(timeval timeBefore,timeval timeAfter, long diffSeconds, long diffUSeconds,T *arr, int n){
    dataFill(arr, n);
    LOG3("Run time when data size is ", n, merge_runtime(timeBefore, timeAfter, diffSeconds, diffUSeconds, arr, 0, n));
    delete[] arr;
}

template<class T>
void testMergeSort(T *arr){
    timeval timeBefore, timeAfter;
    long diffSeconds, diffUSeconds;
    for (int i = 1000; i <= 100000; i += 500){
      eachMergeTest(timeBefore, timeAfter, diffSeconds, diffUSeconds, arr, i);
    }
}

template<class T>
long insert_runtime(timeval timeBefore,timeval timeAfter, long diffSeconds, long diffUSeconds, T *arr, int n){
  gettimeofday(&timeBefore, NULL);

  //call sorting method here.
  insert_Sort(arr,n);

  gettimeofday(&timeAfter, NULL);
  diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
  diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

  return diffSeconds + diffUSeconds/1000000.0;
}

template<class T>
void eachInsertTest(timeval timeBefore,timeval timeAfter, long diffSeconds, long diffUSeconds,T *arr, int n){
    dataFill(arr, n);
    LOG3("Run time when data size is ", n, insert_runtime(timeBefore, timeAfter, diffSeconds, diffUSeconds, arr, n));
    delete[] arr;
}

template<class T>
void testInsert_Sort(T *arr){
    timeval timeBefore, timeAfter;
    long diffSeconds, diffUSeconds;
    for (int i = 1000; i <= 100000; i += 500){
      eachMergeTest(timeBefore, timeAfter, diffSeconds, diffUSeconds, arr, i);
    }
}

template<class T>
long heap_runtime(timeval timeBefore,timeval timeAfter, long diffSeconds, long diffUSeconds, T *arr, int n){
  gettimeofday(&timeBefore, NULL);

  //call sorting method here.
  MinHeap<int> test(arr, n);
  test.heapSort(arr);

  gettimeofday(&timeAfter, NULL);
  diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
  diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

  return diffSeconds + diffUSeconds/1000000.0;
}

template<class T>
void eachHeapTest(timeval timeBefore,timeval timeAfter, long diffSeconds, long diffUSeconds,T *arr, int n){
    dataFill(arr, n);
    LOG3("Run time when data size is ", n, heap_runtime(timeBefore, timeAfter, diffSeconds, diffUSeconds, arr, n));
    delete[] arr;
}

template<class T>
void testHeapSort(T *arr){
    timeval timeBefore, timeAfter;
    long diffSeconds, diffUSeconds;
    for (int i = 1000; i <= 100000; i += 500){
      eachHeapTest(timeBefore, timeAfter, diffSeconds, diffUSeconds, arr, i);
    }
}