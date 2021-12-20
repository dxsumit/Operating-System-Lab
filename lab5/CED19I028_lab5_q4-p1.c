// Name: Sumit Kumar
// Roll No: CED19I028
// question: Write two different programs (P1 and P2) in C to demonstrate IPC using shared
//           memory. Process P1 will write 100 bytes of data to the shared memory and P2 will
//           read from the shared memory and displays it. Then, P2 will write 100 bytes of data to
//           the same shared memory and P1 will read and displays it.


#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

int main(){

    key_t key = ftok("shmfile", 65);
    int shmID;
    char *SM;
    char str[50] = "This message is from P1";

    shmID = shmget(key, 1024, 0666|IPC_CREAT);

    SM = shmat(shmID, NULL, 0);

    strcpy(SM, str);
    printf("\n Data written in SM by P1: %s\n", SM);
    sleep(5);

    printf("\n Data read from SM by P1: %s\n", SM);

    return 0;
}

