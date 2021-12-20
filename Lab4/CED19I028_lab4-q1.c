// Name:    Sumit Kumar
// Roll No: CED19I028
// Lab3 Question: 1 multiple process using fork()


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>


int main() {

    fork();
    fork();
    fork();
    printf(" parent PID = %d  Child PID = %d\n", getppid(), getpid());

    return 0;
}