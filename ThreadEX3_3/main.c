#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int Global = 0;

struct info_thread
{
    char thread_name[15];
    int initial_value;
};

void* my_thread(void* param)
{
    struct info_thread* info = (struct info_thread*) param; /*caster le void* */
    int i;
    for(i=0 ; i < 5 ; ++i)
    {
        Global ++;
        info->initial_value ++;
        printf("%s : variable globale : %d variable local : %d \n",info->thread_name,Global,info->initial_value);
    }

    return NULL;
}

int main (void)
{
    pthread_t tid1, tid2,tid3;
    struct info_thread info1 = {"Thread 1",10};
    struct info_thread info2 = {"Thread 2",20};
    struct info_thread info3 = {"Thread 3",30};

    if(pthread_create(&tid1, NULL, my_thread, &info1) < 0)
    {
        fprintf(stderr, "pthread_create error for thread 1\n");
        exit(1);
    }


    if(pthread_create(&tid2, NULL, my_thread, &info2) < 0)
    {
        fprintf(stderr, "pthread_create error for thread 2\n");
        exit(1);
    }


    if(pthread_create(&tid3, NULL, my_thread, &info3) < 0)
    {
        fprintf(stderr, "pthread_create error for thread 3\n");
        exit(1);
    }

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);

    return EXIT_SUCCESS;
}



