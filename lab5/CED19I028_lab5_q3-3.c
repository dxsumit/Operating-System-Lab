// Name: Sumit Kumar
// Roll No: CED19I028
// Question: read() and write()

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
 
int main (void) {

    int fd[2];
    char msg1[20] = "Problem Solving";
    char msg2[20];
 
    fd[0] = open("newFile.txt", O_RDWR);        
    fd[1] = open("newFile.txt", O_RDWR);
     
    write(fd[0], msg1, strlen(msg1));        
    write(1, msg2, read(fd[1], msg2, sizeof(msg1)));
 
    close(fd[0]);
    close(fd[1]);
 
    return 0;
}