// Name: Sumit Kumar
// Roll No: CED19I028
// question: Write a program that creates two processes P1 and P2. P1 sets-up a 
//           string and writes it on to the shared memory. P2 reads the string 
//           from the shared memory, checks whether the string is palindrome or 
//           not and writes either 0 (not palindrome) or 1 (palindrome) to the 
//           shared memory. P1 reads this value and prints whether the string 
//           is palindrome or not on to the console.

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

int main(){

    key_t key = ftok("shmfile", 65);
    int shmID;
    char *SM;
    char str[50] = "ABA";           // case sensitive

    shmID = shmget(key, 1024, 0666|IPC_CREAT);

    SM = shmat(shmID, NULL, 0);

    strcpy(SM, str);
    printf("\n Data written in SM by P1: %s\n", SM);

    sleep(10);       // sleep for some duration so that P2 can write data in shared memory

    printf("\n Data read from SM by P1: %s ", SM);
    if(SM[0] == '0')
        printf("- NOT Palindrome Number..");
    else
        printf("- Palindrome Number..");

    return 0;
}
