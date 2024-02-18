#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_KEY 1234
#define SHM_SIZE 1024

struct shared
{
    char msg[256];
};

int main() 
{
    int sid;
    struct shared*mem;

    
    if ((sid = shmget(SHM_KEY, SHM_SIZE, 0666)) == -1) 
    {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    
    if ((mem = shmat(sid, NULL, 0)) == (void *)-1) 
    {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    
    strncpy(mem->msg, "Hello from the client!", sizeof(mem->msg) - 1);
    mem->msg[sizeof(mem->msg) - 1] = '\0';

    
    if (shmdt(mem) == -1) 
    {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    
    sleep(2);

   
    if ((mem = shmat(sid, NULL, 0)) == (void *)-1) 
    {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

   
    printf("Client: Response from server: %s\n", mem->msg);

  
    if (shmdt(mem) == -1) 
    {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    return 0;
}

