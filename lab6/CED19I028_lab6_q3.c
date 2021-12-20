// Name: Sumit Kumar
// Roll No: CED19I028
// Question: Write a program where the parent process reads an array of integers and writes
//           it into pipe, the child process reads the array of numbers, checks whether 
//           the numbers are Armstrong or not and creates an array of 
//           binary values (0 - not Armstrong, 1 - Armstrong) and writes this array into the pipe.
//           Finally, the parent process reads this binary array and prints whether each element 
//           of the array is Armstrong or not.


#include <stdio.h>
#include <math.h>
#include <unistd.h>

int check(int n){
    // count digit.
    int count = 0, temp=n, value = n;
    while(temp != 0){
        temp = temp/10;
        count++;
    }
    // if 1 digit not armstrong..
    if(count == 1)
        return 0;

    int sum=0, rem;
    while(n != 0){
        rem = n % 10;
        sum += pow(rem, count);
        n = n/10;
    }
    if(value == sum)
        return 1;
    else
        return 0;
}

void armstrong(int arr[], int res_arr[], int n){ 
    for(int i=0; i<n; i++){
        res_arr[i] = check(arr[i]);
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

    int pipeFDS_1[2], pipeFDS_2[2];
    pid_t pid;

    int size;
    printf("\n Enter the size of array: ");
    scanf("%d", &size);

    int parent_send[size], parent_received[size];
    int child_send[size], child_receive[size];;

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

        armstrong(child_receive, child_send, size);

        printf("\n Child Sent:\n\n");
        display(child_send, size);

        write(pipeFDS_2[1], child_send, sizeof(child_send));

    } else {
        // closing unwanted ends of pipe for parent.
        close(pipeFDS_1[0]);  // read
        close(pipeFDS_2[1]);  // write

        printf("\n Enter the array: ");
        for(int i=0; i<size; i++)
            scanf("%d", &parent_send[i]);

        printf("\n Parent Send");
        display(parent_send, size);

        write(pipeFDS_1[1], parent_send, sizeof(parent_send));

        read(pipeFDS_2[0], parent_received, sizeof(parent_received));
        
        printf("\n Parent ..");
        for(int i=0; i<size; i++){
            if(parent_received[i] == 0)
                printf("\n %d is NOT Armstrong. ", parent_send[i]);
            else
                printf("\n %d is Armstrong. ", parent_send[i]);
        }
    }

    return 0;
}