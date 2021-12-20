// Name:    Sumit Kumar
// Roll No: CED19I028
// Lab3 Question:5 - Sorting in ascending and decending order in child and parent process respectively of the same array..  

#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include<stdlib.h>

void merge(int arr[], int p, int q, int r, int pid) {

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) {
        // if its child then sort in decending order...
        if(pid == 0){
            if (L[i] >= M[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = M[j];
                j++;
            }
            k++;
            
        // if its parent then sort in ascending order... 
        } else {
            wait(0);
            if (L[i] <= M[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = M[j];
                j++;
            }
            k++;
        }
        
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r, int pid) {
  if (l < r) {

    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m, pid);
    mergeSort(arr, m + 1, r, pid);

    // Merge the sorted subarrays
    merge(arr, l, m, r, pid);
  }
}


int main(){
    pid_t pid;
    pid = fork();

    if(pid < 0){
        printf("Error in fork\n");
        exit(0);
    }

    int arr[] = {2,3,4,5,6,11,12,1,10};
    int n = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0, n-1, pid);
    if(pid == 0)
        printf("\n Child : ");
    else
        printf("\n Parent : ");

    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

