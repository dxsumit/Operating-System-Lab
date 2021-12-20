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

int palindrome(char str[]){
    int len = strlen(str);
    for(int i=0; i<len/2; i++){
        if(str[i] != str[len-1-i]){
            return 0;
        }
    }
    return 1;
}

int main(){

    key_t key = ftok("shmfile", 65);
    int shmID;
    char *SM;
    // char str[50];
    int res;

    shmID = shmget(key, 1024, 0666|IPC_CREAT);

    SM = shmat(shmID, NULL, 0);

    printf("\n Data read from SM by P2: %s\n", SM);

    res = palindrome(SM);

    sprintf(SM, "%d", res);     // convert int to string..
    printf("\n Data written in SM by P2: %d\n", res);

    return 0;
}
