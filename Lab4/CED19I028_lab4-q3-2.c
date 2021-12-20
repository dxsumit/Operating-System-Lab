// Name:    Sumit Kumar
// Roll No: CED19I028
// Lab3 Question: 3 wait() and exec()

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main() {

    pid_t pid;
    pid = fork();

        // wait for perticular process to execute first
    if(pid == 0){
        printf(" This is child %d his parent %d\n", getpid(), getppid());
        pid = fork();
        if(pid == 0){
            printf(" new child = %d parent = %d\n", getpid(), getppid());
        } else {
            printf(" new parent = %d\n", getpid());
        }
    } else {
        printf(" just completed %d i'm %d\n", waitpid(pid), getpid());
    }
    return 0;
}