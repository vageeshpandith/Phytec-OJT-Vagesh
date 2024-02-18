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
    int shmid;
    struct shared*mem;

  
    if((shmid=shmget(SHM_KEY,SHM_SIZE,IPC_CREAT | 0666))==-1) 
    {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

   
    if ((mem=shmat(shmid,NULL,0))==(void *)-1) 
    {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

   
    printf("Server: msg from client: %s\n", mem->msg);


    strncpy(mem->msg,"Hello back from the server!", sizeof(mem->msg) - 1);
    mem->msg[sizeof(mem->msg)-1]='\0';


    if(shmdt(mem)==-1) 
    {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    // Wait for the client to read the response
    sleep(2);

   
    if ((mem=shmat(shmid,NULL,0))==(void *)-1) 
    {
        perror("shmat");
        exit(EXIT_FAILURE);
    }


    printf("Server: Client's response: %s\n", mem->msg);


    if (shmdt(mem)==-1) 
    {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    // shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

