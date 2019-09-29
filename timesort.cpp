#include "heap.h"
#include "sys_time.h"

int main{
    int *testArr1 = new int[50];
    int *testArr2 = new int[75];
    int *testArr3 = new int[100];
    int *testArr4 = new int[125];
    int *testArr5 = new int[150];
    int *testArr6 = new int[175];
    int *testArr7 = new int[200];

    for (int i = 0; i <  50; i++){
      testArr1[i] = 50 - i;
    }
    for (int i = 0; i <  75; i++){
      testArr2[i] = 75 - i;
    }
    for (int i = 0; i <  100; i++){
      testArr3[i] = 100 - i;
    }
    for (int i = 0; i <  125; i++){
      testArr4[i] = 125 - i;
    }
    for (int i = 0; i <  150; i++){
      testArr5[i] = 150 - i;
    }
    for (int i = 0; i <  175; i++){
      testArr6[i] = 175 - i;
    }
    for (int i = 0; i <  200; i++){
      testArr7[i] = 200 - i;
    }

    //set up here
    timeval timeBefore, timeAfter;
    long diffSeconds, diffUSeconds;

    //1st testing
    gettimeofday(&timebefore, NULL);

    //call sorting method here.
    MinHeap<int> test1(testArr1, 50);
    test1.heapSort(testArr1);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;

    //2st testing
    gettimeofday(&timebefore, NULL);

    //call sorting method here.
    MinHeap<int> test2(testArr2, 75);
    test1.heapSort(testArr2);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;

    //3rd testing
    gettimeofday(&timebefore, NULL);

    //call sorting method here.
    MinHeap<int> test3(testArr3, 100);
    test1.heapSort(testArr3);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;

    //4th testing
    gettimeofday(&timebefore, NULL);

    //call sorting method here.
    MinHeap<int> test4(testArr4, 125);
    test1.heapSort(testArr4);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;

    //5th testing
    gettimeofday(&timebefore, NULL);

    //call sorting method here.
    MinHeap<int> test5(testArr5, 150);
    test1.heapSort(testArr5);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;

    //6st testing
    gettimeofday(&timebefore, NULL);

    //call sorting method here.
    MinHeap<int> test6(testArr6, 175);
    test1.heapSort(testArr6);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;

    //7st testing
    gettimeofday(&timebefore, NULL);

    //call sorting method here.
    MinHeap<int> test7(testArr7, 200);
    test1.heapSort(testArr7);

    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;
    return 0;
}
