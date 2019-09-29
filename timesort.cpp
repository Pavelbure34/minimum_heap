#include <sys/time.h>
#include "heap.h"
#include "otherSort.h"

int *testArr1 = new int[1000];
int *testArr2 = new int[1500];
int *testArr3 = new int[2000];
int *testArr4 = new int[2500];
int *testArr5 = new int[3000];
int *testArr6 = new int[3500];
int *testArr7 = new int[4000];

int dataFill(){
    for (int i = 0; i <  1000; i++){
      testArr1[i] = 1000 - i;
    }
    for (int i = 0; i <  1500; i++){
      testArr2[i] = 1500 - i;
    }
    for (int i = 0; i < 2000; i++){
      testArr3[i] = 2000 - i;
    }
    for (int i = 0; i < 2500; i++){
      testArr4[i] = 2500 - i;
    }
    for (int i = 0; i < 3000; i++){
      testArr5[i] = 3000 - i;
    }
    for (int i = 0; i < 3500; i++){
      testArr6[i] = 3500 - i;
    }
    for (int i = 0; i < 4000; i++){
      testArr7[i] = 4000 - i;
    }
}

void testMergeSort(){
  //set up here
    timeval timeBefore, timeAfter;
    long diffSeconds, diffUSeconds;

    //1st testing
    gettimeofday(&timeBefore, NULL);

    //call sorting method here.
    mergeSort(testArr1,0,999);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;

    //2st testing
    gettimeofday(&timeBefore, NULL);

    //call sorting method here.
    mergeSort(testArr2,0,1499);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;

    //3rd testing
    gettimeofday(&timeBefore, NULL);

    //call sorting method here.
    mergeSort(testArr3,0,1999);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;

    //4th testing
    gettimeofday(&timeBefore, NULL);

    //call sorting method here.
    mergeSort(testArr4,0,2499);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;

    //5th testing
    gettimeofday(&timeBefore, NULL);

    //call sorting method here.
    mergeSort(testArr5,0,2999);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;

    //6st testing
    gettimeofday(&timeBefore, NULL);

    //call sorting method here.
    mergeSort(testArr6,0,3499);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;

    //7st testing
    gettimeofday(&timeBefore, NULL);

    //call sorting method here.
    mergeSort(testArr7,0,3999);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;
}

void testInsert_Sort(){
  //set up here
    timeval timeBefore, timeAfter;
    long diffSeconds, diffUSeconds;

    //1st testing
    gettimeofday(&timeBefore, NULL);

    //call sorting method here.
    insert_Sort(testArr1,1000);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;

    //2st testing
    gettimeofday(&timeBefore, NULL);

    //call sorting method here.
    insert_Sort(testArr2,1500);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;

    //3rd testing
    gettimeofday(&timeBefore, NULL);

    //call sorting method here.
    insert_Sort(testArr3,2000);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;

    //4th testing
    gettimeofday(&timeBefore, NULL);

    //call sorting method here.
    insert_Sort(testArr4,2500);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;

    //5th testing
    gettimeofday(&timeBefore, NULL);

    //call sorting method here.
    insert_Sort(testArr5,3000);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;

    //6st testing
    gettimeofday(&timeBefore, NULL);

    //call sorting method here.
    insert_Sort(testArr6,3500);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;

    //7st testing
    gettimeofday(&timeBefore, NULL);

    //call sorting method here.
    insert_Sort(testArr7,4000);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;
}

void testHeapSort(){
    //set up here
    timeval timeBefore, timeAfter;
    long diffSeconds, diffUSeconds;

    //1st testing
    gettimeofday(&timeBefore, NULL);

    //call sorting method here.
    MinHeap<int> test1(testArr1, 1000);
    test1.heapSort(testArr1);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;

    //2st testing
    gettimeofday(&timeBefore, NULL);

    //call sorting method here.
    MinHeap<int> test2(testArr2, 1500);
    test1.heapSort(testArr2);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;

    //3rd testing
    gettimeofday(&timeBefore, NULL);

    //call sorting method here.
    MinHeap<int> test3(testArr3, 2000);
    test1.heapSort(testArr3);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;

    //4th testing
    gettimeofday(&timeBefore, NULL);

    //call sorting method here.
    MinHeap<int> test4(testArr4, 2500);
    test1.heapSort(testArr4);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;

    //5th testing
    gettimeofday(&timeBefore, NULL);

    //call sorting method here.
    MinHeap<int> test5(testArr5, 3000);
    test1.heapSort(testArr5);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;

    //6st testing
    gettimeofday(&timeBefore, NULL);

    //call sorting method here.
    MinHeap<int> test6(testArr6, 3500);
    test1.heapSort(testArr6);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;

    //7st testing
    gettimeofday(&timeBefore, NULL);

    //call sorting method here.
    MinHeap<int> test7(testArr7, 4000);
    test1.heapSort(testArr7);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;
}

int main(){
    dataFill();
    //choosing either one.

    LOG1("HeapSort testing");
    testHeapSort();
    
    // LOG1("MergSort testing");
    // testMergeSort();
    
    // LOG1("Insertion Sort testing");
    // testInsert_Sort();
}
