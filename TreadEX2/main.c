#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_BOUCLE 5

void* my_thread(void* param)
{
    int i;
    for(i=0; i< MAX_BOUCLE; ++i)
    {
        printf("Thread %s: %d\n", (char*)param, i);
        sleep(1);
    }
    return NULL;
}
int main (int argc, char* argv[])
{
    pthread_t tid1, tid2;
    if(pthread_create(&tid1, NULL, my_thread, "Hunger Games") < 0)
    {
        fprintf(stderr, "pthread_create error for thread 1\n");
        exit(1);
    }
    if(pthread_create(&tid2, NULL, my_thread, "Zulu") < 0)
    {
        fprintf(stderr, "pthread_create error for thread 2\n");
        exit(1);
    }
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    return EXIT_SUCCESS;
}
