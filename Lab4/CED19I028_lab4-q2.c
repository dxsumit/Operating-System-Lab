// Name:    Sumit Kumar
// Roll No: CED19I028
// Lab3 Question: 2 exec system call demonstration..

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    pid_t pid;
    pid=fork();
    
    if(pid < 0){
        printf(" Error in fork\n");
    
    } else if (pid==0) {
        char *args[] = {"/home/sumit/C/Documents/OS/Lab4", NULL};
        execvp("ls", args);
    
    } else{
        char *args[] = {"/home/sumit/C/Documents/OS/Lab4", NULL};
        execvp("pstree", args);
    }

    return 0;
}