// Name: Sumit Kumar
// Roll No: CED19I028
// Question: Write a program where the parent reads an array of integers, sorts it in ascending 
//           order and writes on the pipe. Child process will read from the pipe and output the ascending 
//           order onto the console. Then, converts the ascending order array into descending order 
//           and writes back the output to the pipe. Finally, the parent prints the descending 
//           order written by the child process into the pipe.


#include <stdio.h>
#include <unistd.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
    int L[n1], R[n2];
  
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
  
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // adding the remainings..
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
  
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
  
        merge(arr, l, m, r);
    }
}

void reverse(int arr[], int n){ 
    int i, temp;  

    for (i = 0; i < n/2; i++){  
        temp = arr[i];  
        arr[i] = arr[n - i - 1];  
        arr[n - i - 1] = temp;  
    }
}

void display(int arr[], int n){
    printf(" - Array: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() {

    // int arr[7] = {2,1,10,8,7,4,3};
    int pipeFDS_1[2], pipeFDS_2[2];
    pid_t pid;

    int size;
    printf("\n Enter the size of array: ");
    scanf("%d", &size);

    int parent_send[size];
    int parent_received[size];
    int child_receive[size];

    if(pipe(pipeFDS_1) == -1){
        printf("\n Error in Pipe 1 creation..");
        return 0;
    }
    if(pipe(pipeFDS_2) == -1){
        printf("\n Error in Pipe 2 creation..");
        return 0;
    }

    pid = fork();   // child fork

    if(pid == 0){
        // closing unwanted ends of pipe for child.
        close(pipeFDS_2[0]);  // read
        close(pipeFDS_1[1]);  // write
        read(pipeFDS_1[0], child_receive, sizeof(child_receive));

        printf(" Child Received from parent");
        display(child_receive, size);

        reverse(child_receive, size);

        printf("\n Child Sent:\n\n");
        display(child_receive, size);

        write(pipeFDS_2[1], child_receive, sizeof(child_receive));

    } else {
        // closing unwanted ends of pipe for parent.
        close(pipeFDS_1[0]);  // read
        close(pipeFDS_2[1]);  // write

        printf("\n Enter the array: ");
        for(int i=0; i<size; i++)
            scanf("%d", &parent_send[i]);

        // sorting 
        mergeSort(parent_send, 0, size-1);

        printf("\n Parent Send");
        display(parent_send, size);

        write(pipeFDS_1[1], parent_send, sizeof(parent_send));

        read(pipeFDS_2[0], parent_received, sizeof(parent_received));
        
        printf("\n Received from child:");
        display(parent_received, size);
    }

    return 0;
}