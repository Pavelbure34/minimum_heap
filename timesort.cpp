#include <sys/time.h>
#include "heap.h"

int main(){
    int *testArr1 = new int[100];
    int *testArr2 = new int[250];
    int *testArr3 = new int[500];
    int *testArr4 = new int[750];
    int *testArr5 = new int[1000];
    int *testArr6 = new int[1250];
    int *testArr7 = new int[1500];

    for (int i = 0; i <  100; i++){
      testArr1[i] = 100 - i;
    }
    for (int i = 0; i <  250; i++){
      testArr2[i] = 250 - i;
    }
    for (int i = 0; i < 500; i++){
      testArr3[i] = 500 - i;
    }
    for (int i = 0; i < 750; i++){
      testArr4[i] = 750 - i;
    }
    for (int i = 0; i < 1000; i++){
      testArr5[i] = 1000 - i;
    }
    for (int i = 0; i < 1250; i++){
      testArr6[i] = 1250 - i;
    }
    for (int i = 0; i < 1500; i++){
      testArr7[i] = 1500 - i;
    }

    //set up here
    timeval timeBefore, timeAfter;
    long diffSeconds, diffUSeconds;

    //1st testing
    gettimeofday(&timeBefore, NULL);

    //call sorting method here.
    MinHeap<int> test1(testArr1, 100);
    test1.heapSort(testArr1);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;

    //2st testing
    gettimeofday(&timeBefore, NULL);

    //call sorting method here.
    MinHeap<int> test2(testArr2, 250);
    test1.heapSort(testArr2);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;

    //3rd testing
    gettimeofday(&timeBefore, NULL);

    //call sorting method here.
    MinHeap<int> test3(testArr3, 500);
    test1.heapSort(testArr3);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;

    //4th testing
    gettimeofday(&timeBefore, NULL);

    //call sorting method here.
    MinHeap<int> test4(testArr4, 750);
    test1.heapSort(testArr4);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;

    //5th testing
    gettimeofday(&timeBefore, NULL);

    //call sorting method here.
    MinHeap<int> test5(testArr5, 1000);
    test1.heapSort(testArr5);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;

    //6st testing
    gettimeofday(&timeBefore, NULL);

    //call sorting method here.
    MinHeap<int> test6(testArr6, 1250);
    test1.heapSort(testArr6);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;

    //7st testing
    gettimeofday(&timeBefore, NULL);

    //call sorting method here.
    MinHeap<int> test7(testArr7, 1500);
    test1.heapSort(testArr7);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;
}
