#include "heap.h"
#include "otherSort.h"
#include <sys/time.h>
#include <fstream>

#define LOG(x, y, z) std::cout <<  x << " " << y << " = " << z << std::endl;

template<class T>
void heapSortTest(T *arr){
    /*
        This function runs the heapSort
        of data size from 500 to 10500 with
        the interval of 100.

        precondition: arr has to be array of type T.
        postcondition: output has to be csv file with run time under different data size. 
    */
    ofstream file;                          //setting up for csv writing
    file.open("heapSort.csv");              //writing csv files
    file << "dataSize, runTime\n";          //writing column

    MinHeap<int> *testHeap;                 //setting up for heapSort tesing
    timeval timeBefore, timeAfter;          //time variables
    long diffSeconds, diffUSeconds;           
    for (int i = 500; i <= 10500; i += 100){//testing with different size of data
        arr = new int[i];
        for (int j = 0; j < i; j++){        //writing on arr
            arr[j] = i - j;
        }
        testHeap = new MinHeap<int>(arr, i);
        gettimeofday(&timeBefore, NULL);     //time count init
        testHeap->heapSort(arr);              //actual sorting happens here.
        gettimeofday(&timeAfter, NULL);       //time count done
        diffSeconds = timeAfter.tv_sec - timeBefore.tv_sec;
        diffUSeconds = timeAfter.tv_usec - timeBefore.tv_usec;
        file << i << "," << diffSeconds + (diffUSeconds/1000000.0) << "\n";//writing on csv
        
        //freeing up memory for next iteration
        delete testHeap;
        arr = NULL;
    }
    file.close(); //closing the file when writing is done.
}

template<class T>
void mergeSortTest(T *arr){
    /*
        This function runs the mergeSort
        of data size from 500 to 10500 with
        the interval of 100.

        precondition: arr has to be array of type T.
        postcondition: output has to be csv file with run time under different data size. 
    */
    ofstream file;                          //setting up for csv writing
    file.open("mergeSort.csv");             //writing csv files
    file << "dataSize, runTime\n";          //writing column

    timeval timeBefore, timeAfter;          //time variables
    long diffSeconds, diffUSeconds;
    for (int i = 500; i <= 10500; i += 100){//testing with different size of data
        arr = new int[i];
        for (int j = 0; j < i; j++){        //writing on arr
            arr[j] = i - j;
        }
        gettimeofday(&timeBefore, NULL);    //time count init
        mergeSort(arr, 0, i-1);             //actual sorting happens here.
        gettimeofday(&timeAfter, NULL);     //time count done
        diffSeconds = timeAfter.tv_sec - timeBefore.tv_sec;
        diffUSeconds = timeAfter.tv_usec - timeBefore.tv_usec;
        file << i << "," << diffSeconds + (diffUSeconds/1000000.0) << "\n";//writing on csv

        //freeing up memory for next iteration
        arr = NULL;
    }
    file.close();//closing the file when writing is done.
}

template<class T>
void insertSortTest(T *arr){
      /*
        This function runs the insertSort
        of data size from 500 to 10500 with
        the interval of 100.

        precondition: arr has to be array of type T.
        postcondition: output has to be csv file with run time under different data size. 
    */
    ofstream file;                                //setting up for csv writing
    file.open("insertSort.csv");                  //writing csv files
    file << "dataSize, InserSort\n";              //writing column

    timeval timeBefore, timeAfter;                //time variables
    long diffSeconds, diffUSeconds;
    for (int i = 500; i <= 10500; i += 100){      //testing with different size of data
        arr = new int[i];
        for (int j = 0; j < i; j++){
            arr[j] = i - j;
        }
        gettimeofday(&timeBefore, NULL);         //time count init
        insert_Sort(arr, i);                     //actual sorting happens here.
        gettimeofday(&timeAfter, NULL);          //time count done
        diffSeconds = timeAfter.tv_sec - timeBefore.tv_sec;
        diffUSeconds = timeAfter.tv_usec - timeBefore.tv_usec;
        file << i << "," << diffSeconds + (diffUSeconds/1000000.0) << "\n";
        
        //freeing up memory for next iteration
        arr = NULL;
    }
    file.close();//closing the file when writing is done.
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
