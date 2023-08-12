#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_BOUCLE 10

void* thread1(void* param)
{
    int i;
    for(i=0; i< MAX_BOUCLE; ++i)
    {
        printf("Hello!!\n");
    }
    return NULL;
}
void* thread2(void * param)
{
    int i;
    for(i=0; i< MAX_BOUCLE; ++i)
    {
        printf("How are you ?\n");
    }
    return NULL;
}
int main(void)
{

    pthread_t tid1, tid2;/*on déclare 2 threads*/
    pthread_create(&tid1, NULL, thread1, NULL);/*on crée et lance le threads "thread1" */
    pthread_create(&tid2, NULL, thread2, NULL);/*on crée etlance le threads "thread2" */
    pthread_join(tid1, NULL);/*on attend la mort de "thread1" */
    pthread_join(tid2, NULL);/*on attend la mort de "thread2" */
    printf("Les threads ont terminé\n");
    sleep(2);
    return EXIT_SUCCESS;
}
