// Name:    Sumit Kumar
// Roll No: CED19I028
// Lab3 Question: 3 wait() and exec()


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
 
int main(void) {
    // with execv we can pass all the args usin null terminated array..
    char *args[] = {"/home/sumit/C/Documents/OS/Lab4", NULL};
    execv("/bin/ls", args);
    
    return 0;
}