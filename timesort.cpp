#include "heap.h"
#include "otherSort.h"
#include <sys/time.h>
#include <fstream>

#define LOG(x, y, z) std::cout <<  x << " " << y << " = " << z << std::endl;

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
void heapSortTest(T *arr){
    ofstream file;
    file.open("heapSort.csv");
    file << "dataSize, runTime\n";

    MinHeap<int> *testHeap;
    timeval timeBefore, timeAfter;
    long diffSeconds, diffUSeconds;
    for (int i = 1000; i <= 100000; i += 500){
        arr = new int[i];
        for (int j = 0; j < i; j++){
            arr[j] = i - j;
        }
        gettimeofday(&timeBefore, NULL);
        testHeap = new MinHeap<int>(arr, i);
        testHeap->heapSort(arr);
        gettimeofday(&timeAfter, NULL);
        diffSeconds = timeAfter.tv_sec - timeBefore.tv_sec;
        diffUSeconds = timeAfter.tv_usec - timeBefore.tv_usec;
        file << i << "," << diffSeconds + (diffUSeconds/1000000.0) << "\n";
        //LOG("Run time when data size is", i, diffSeconds + diffUSeconds/1000000.0);
        delete testHeap;
        arr = NULL;
    }
    file.close();
}

template<class T>
void mergeSortTest(T *arr){
    ofstream file;
    file.open("mergeSort.csv");
    file << "dataSize, runTime\n";

    timeval timeBefore, timeAfter;
    long diffSeconds, diffUSeconds;
    for (int i = 1000; i <= 100000; i += 500){
        arr = new int[i];
        for (int j = 0; j < i; j++){
            arr[j] = i - j;
        }
        gettimeofday(&timeBefore, NULL);
        mergeSort(arr, 0, i-1);
        gettimeofday(&timeAfter, NULL);
        diffSeconds = timeAfter.tv_sec - timeBefore.tv_sec;
        diffUSeconds = timeAfter.tv_usec - timeBefore.tv_usec;
        file << i << "," << diffSeconds + (diffUSeconds/1000000.0) << "\n";
        //LOG("Run time when data size is", i, diffSeconds + diffUSeconds/1000000.0);
        arr = NULL;
    }
    file.close();
}

template<class T>
void insertSortTest(T *arr){
    ofstream file;
    file.open("insertSort.csv");
    file << "dataSize, runTime\n";

    timeval timeBefore, timeAfter;
    long diffSeconds, diffUSeconds;
    for (int i = 1000; i <= 100000; i += 500){
        arr = new int[i];
        for (int j = 0; j < i; j++){
            arr[j] = i - j;
        }
        gettimeofday(&timeBefore, NULL);
        insert_Sort(arr, i);
        gettimeofday(&timeAfter, NULL);
        diffSeconds = timeAfter.tv_sec - timeBefore.tv_sec;
        diffUSeconds = timeAfter.tv_usec - timeBefore.tv_usec;
        file << i << "," << diffSeconds + (diffUSeconds/1000000.0) << "\n";
        //LOG("Run time when data size is", i, diffSeconds + diffUSeconds/1000000.0);
        arr = NULL;
    }
    file.close();
}

int main(){
    int *testArr;
    LOG1("HeapSort Testing");
    heapSortTest(testArr);

    LOG1("MergeSort Testing");
    mergeSortTest(testArr);

    LOG1("insertSort Testing");
    insertSortTest(testArr);

    LOG1("Testing Complete");
}
