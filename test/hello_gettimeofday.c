#include <stdio.h>
#include <sys/time.h>

struct handler_time {
    double zikan;
};

static struct handler_time handler_time;

static double time_cal(double time_sec, double time_usec) {
    double cal_time;

    if(time_usec > 100000) {
        cal_time = time_sec + (time_usec/1000000);
    } else if (time_usec > 10000) {
        cal_time = time_sec + (time_usec/10000000);
    } else if (time_usec > 1000) {
        cal_time = time_sec + (time_usec/100000000);
    } else if (time_usec > 100) {
        cal_time = time_sec + (time_usec/1000000000);
    } else if (time_usec > 10) {
        cal_time = time_sec + (time_usec/10000000000);
    } else {
        cal_time = time_sec + (time_usec/100000000000);
    }

    return cal_time;
}

int main(int argc, char **argv) {
    handler_time.zikan = 0;
//    handler_time = {0, 0};

    struct timeval tv;
    gettimeofday(&tv, NULL);

    double time_before_sec = (double) tv.tv_sec;
    double time_before_usec = (double) tv.tv_usec;
    double before_time = time_cal(time_before_sec, time_before_usec);

    printf("%f.%f\n", time_before_sec, time_before_usec);
    printf("%f\n", before_time);

    // ここの処理時間を測って構造体にぶちこむ
    for (int i=0; i<1000000000; i++) {
        int a = 100;
    }

    gettimeofday(&tv, NULL);

    double time_after_sec = (double) tv.tv_sec;
    double time_after_usec = (double) tv.tv_usec;
    double after_time = time_cal(time_after_sec, time_after_usec);

    printf("%f.%f\n", time_after_sec, time_after_usec);
    printf("%f\n", after_time);

    handler_time.zikan += (after_time - before_time);

    printf("%f", handler_time.zikan);

    return 0;
}
