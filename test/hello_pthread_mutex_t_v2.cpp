#include <stdio.h>
#include <iostream>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define USE_LOCK 1
#if USE_LOCK
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
#endif

using namespace std;
void test_mutex();
void *config_thread(void *ptr);
void *ncache_thread(void *ptr);

static int ncache_lifetime = 9;

void test_mutex() {
#if USE_LOCK
    cout << "USE_LOCK = 1" << endl;
    pthread_mutex_lock(&mutex);
    cout << "lock" << endl;
#endif
    cout << "USE_LOCK = 0" << endl;
}

void *config_thread(void *ptr)
{
    cout << "config_thread start" << endl;

    pthread_detach(pthread_self());
    int config_thread_count = 0;
    
    while(1) {
        sleep(1);
        config_thread_count++;
        cout << "config_thread: " << to_string(config_thread_count) << endl;
    }
}

void *ncache_thread(void *ptr)
{
    cout << "ncache_thread start" << endl;

    pthread_detach(pthread_self());
    int ncache_thread_count = 0;

    int *interval = (int*) ptr;
    int memory_span = (*interval) * 1000;
    
    while(1) {
        sleep(*interval);
        //organize_ump(memory_span);
        ncache_thread_count++;
        cout << "ncache_thread: " << to_string(ncache_thread_count) << endl;
    }
}

int main() {
    pthread_t th_config;
    pthread_t th_ncache;
    int ncache_interval = ncache_lifetime;

    int ret1 = pthread_create(&th_config, NULL, &config_thread, NULL);
    if(ret1 != 0) {
        cout << "pthread_create of config_thread error!" << endl;
        return 0;
    }
    int ret2 = pthread_create(&th_ncache, NULL, &ncache_thread, &ncache_interval);
    if(ret2 != 0) {
        cout << "pthread_create of ncache_thread error!" << endl;
        return 0;
    }

    sleep(22);
    //test_mutex();
}