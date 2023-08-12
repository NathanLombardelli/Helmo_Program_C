int sem_transf(int key);

int semcall(int sid, int op);

void p(int sem);

void v(int sem);

union semun { int val; /* utilisé par SETVAL, GETVAL */
struct semid_ds *buf; /* utilisé par IPC_STAT, IPC_SET*/
unsigned short* array;
struct seminfo * __buf;
}
