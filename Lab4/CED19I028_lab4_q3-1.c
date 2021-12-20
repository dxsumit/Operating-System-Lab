// Name:    Sumit Kumar
// Roll No: CED19I028
// Lab3 Question: 3 wait() and exec()


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main() {

    pid_t pid;
    pid = fork();

    // wait for his child to execute first..
    if(pid == 0){
        printf(" This is child %d his parent %d\n", getpid(), getppid());
    } else {
        wait(0);      // wait for its child to finish
        printf(" This is Parent %d\n", getpid());
    }
    
    return 0;
}