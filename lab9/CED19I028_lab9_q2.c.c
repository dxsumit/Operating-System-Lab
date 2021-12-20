// name - Sumit Kumar
// roll no. - CED19I028
// Question - Write a program to create a thread. The thread prints numbers from 0 to n, where value of
//            n is passed from the main process to the thread.


#include <stdio.h>
#include <pthread.h>

void *fun(void *arg){
    int n = *(int*)arg;
    
    for(int i=0; i<=n; i++)
        printf(" %d", i);
        
    printf("\n");
    pthread_exit(NULL);
}

int main() {
    int val;
    pthread_t T;

    printf("\n Enter the value of n : ");
    scanf("%d", &val);

    pthread_create(&T, NULL, fun, &val);
    pthread_join(T, NULL);

    return 0;
}