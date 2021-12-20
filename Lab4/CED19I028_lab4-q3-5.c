// Name:    Sumit Kumar
// Roll No: CED19I028
// Lab3 Question: 3 wait() and exec()

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
 
int main(void) {
    // same as execv but executalbe file dont need full path
    char *args[] = {"/home/sumit/C/Documents/OS/Lab4", NULL};
    execvp("ls", args);
    
    return 0;
}