// name - Sumit Kumar
// roll no. - CED19I028
//  Questions - Write a program to create five threads using pthread library. Find the sum of first 1000
//              numbers using five threads, where each thread can calculate sum of 200 numbers in each
//              (parallel counting using threads).


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// global var sum
int sum[5];

// Thread function..
void *addition(void *arg){
    char *str = malloc(sizeof(char) * 60);
    int ID = (int)arg;
    int a = ID*200 + 1;
    int l = ID*200 + 200;

    sum[ID] = 100 * (a+l);

    sprintf(str, "Value returned from thread %d is %d", ID+1, sum[ID]);

    pthread_exit(str);
}

int main() {

    pthread_t T1, T2, T3, T4, T5;
    char *result;

    // creating threads...
    pthread_create(&T1, NULL, addition, (void*)0);
    pthread_create(&T2, NULL, addition, (void*)1);
    pthread_create(&T3, NULL, addition, (void*)2);
    pthread_create(&T4, NULL, addition, (void*)3);
    pthread_create(&T5, NULL, addition, (void*)4);

    // waiting for thread to execute complete... 
    // result variable stores the returned string from thread function..
    pthread_join(T1, (void **)&result);
    printf("\n %s\n", result);
    free(result);

    pthread_join(T2, (void **)&result);
    printf("\n %s\n", result);
    free(result);

    pthread_join(T3, (void **)&result);
    printf("\n %s\n", result);
    free(result);

    pthread_join(T4, (void **)&result);
    printf("\n %s\n", result);
    free(result);

    pthread_join(T5, (void **)&result);
    printf("\n %s\n", result);
    free(result);

    printf("\n\n  ==> Total Sum of first 1000 numbers are %d \n", sum[0]+sum[1]+sum[2]+sum[3]+sum[4]);

    return 0;
}

