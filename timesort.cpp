#include <sys/time.h>

int main{
    //set up here
    timeval timeBefore, timeAfter;
    long diffSeconds, diffUSeconds;

    gettimeofday(&timebefore, NULL);
    //call sorting method here.
    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec = timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec = timeBefore.tv_usec;

    cout << diffSeconds + diffUSeconds/1000000.0 << "seconds" << endl;

    return 0;
}