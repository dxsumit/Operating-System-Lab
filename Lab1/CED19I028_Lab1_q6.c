// Name:    Sumit Kumar
// Roll No: CED19I028
// Lab1 Question 1. Getting the address of variable using pointer and address of array int 

#include<stdio.h>

int main(){

    int x = 10;
    int *ptr = &x;
    int arr[] = {1,2,3,4,5};

    printf("Value of Int = %d, its address using pointer = %p \n\n", *ptr, ptr);
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        ptr = &arr[i];
        printf("Integer Value = %d, Address of this integer %p \n", arr[i], ptr);
    }

    return 0;
}

