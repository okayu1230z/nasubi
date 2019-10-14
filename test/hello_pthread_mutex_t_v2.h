#ifdef HELLO_PTHREAD_MUTEX_T_V2
#define HELLO_PTHREAD_MUTEX_T_V2

void test_mutex();
void *config_thread(void *ptr);
void *ncache_thread(void *ptr);

#endif