// Name:    Sumit Kumar
// Roll No: CED19I028
// Lab3 Question: 4 sum of even and odds using parent child method..

#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>

int main(){

    int arr[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int first_num;
    int sum;
    int n;    // number of terms
    pid_t pid;
    pid = fork();

    // error in fork 
    if(pid < 0){
        printf("\n Some error in fork\n");

    } else if(pid == 0){        // child..
        first_num = 1;
        if(size % 2 == 0)
            size -= 1;

        n = size/2 + size % 2;
        sum = (first_num + size) * n/2;
        printf("\n  Sum of Odd terms = %d \n", sum);
    
    } else {
        first_num = 2;
        if(size % 2 != 0)
            size -= 1;

        n = size/2;
        sum = (first_num + size) * n/2;
        printf("\n  Sum of Even terms = %d \n", sum);
    }

    return 0;
}
