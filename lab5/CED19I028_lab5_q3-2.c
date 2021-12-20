// Name: Sumit Kumar
// Roll No: CED19I028
// Question: open() with its ACCESS MODES and close()

#include<stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {

    int fd = open("newFile.txt", O_RDONLY);
    if (fd < 0) {
        perror("c1");
        exit(1);
    }
    printf("Opened FD = % d\n", fd);
     
    // close system Call
    if (close(fd) < 0){
        perror("c1");
        exit(1);
    }
    printf("Closed FD.\n");
}