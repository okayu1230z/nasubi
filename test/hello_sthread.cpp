#include <stdio.h>
#include <pthread.h>

// 新しいスレッドで実行されるタスク
void *doSomething(void* pArg) {
    int *pVal = (int*) pArg;
    printf("worker thread [%d]\n", *pVal);
    *pVal = 200;
}

int main() {
    pthread_t handle;  // Thread handle.
    int data = 100;

    pthread_create(&handle, NULL, doSomething, &data);
    pthread_join(handle, NULL);

    printf("main thread [%d]\n", data);
}