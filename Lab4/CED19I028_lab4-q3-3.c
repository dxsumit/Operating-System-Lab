// Name:    Sumit Kumar
// Roll No: CED19I028
// Lab3 Question: 3 wait() and exec()

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
 
int main(void) {
    char *binaryPath = "/bin/ls";
    char *arg1 = "-lh";             // type of ls 
    char *arg2 = "/home/sumit/C/Documents/OS/Lab4";     // path of directory
    
    // first 2 args is binary operation need to perform 3rd is path end will null
    execl(binaryPath, binaryPath, arg2, NULL);
    
    return 0;
}