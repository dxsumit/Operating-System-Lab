// Name - Sumit Kumar
// Roll no. - CED19I028
// Question - Write a program to create a thread. The thread is created by passing an array which
//          contains more than two integers as input from the main process. The two or more array
//          elements will be added in the thread and will return the result to the main function. Finally,
//          the main function will print the final sum.


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int size = 5;

void *func(void *arg){
    int sum = 0;
    int *array = (int*)arg;

    for(int i=0; i<size; i++)
        sum += array[i];
    
    int *total = (int*)sum;    
    pthread_exit(total);
}


int main(){

    pthread_t T;
    int *arr, sum;

    printf("\n Enter Size of Array: ");
    scanf("%d", &size);
    
    arr =  (int*)malloc(size * sizeof(int));

    printf("\n Enter Array: ");
    for(int i=0; i<size; i++)
        scanf("%d", &arr[i]);

    pthread_create(&T, NULL, func, arr);
    pthread_join(T, (void **)&sum);

    printf("\n In MAIN(): Total Sum = %d \n", sum);
    free(arr);
    
    return 0;
}

