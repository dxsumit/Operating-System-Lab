// Name: Sumit Kumar
// Roll No: CED19I028
// Question: Write a program using pipe() and fork() in which parent process takes one string as
//           input. The same is sent to the child using pipe1 and child will reverse it. After the
//           reversing is complete, the child process will send it (reversed string) to parent process
//           using pipe2. Subsequently, parent process will read the string and displays it.

#include <stdio.h>
#include <unistd.h>
#include <string.h>

void reverse(char *arr){ 
    int i, len, temp;  
    len = strlen(arr);
       
    for (i = 0; i < len/2; i++){  
        temp = arr[i];  
        arr[i] = arr[len - i - 1];  
        arr[len - i - 1] = temp;  
    }
}

int main() {

    int pipeFDS_1[2], pipeFDS_2[2];
    pid_t pid;
    char parent_send[20] = "Education", parent_receive[20];
    char child_send[20], child_receive[20];

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
        printf(" Child Received from parent: %s", child_receive);

        reverse(child_receive);
        strcpy(child_send, child_receive);
        printf("\n Child Sent: %s \n\n", child_send);
        write(pipeFDS_2[1], child_send, sizeof(child_send));

    } else {
        // closing unwanted ends of pipe for parent.
        close(pipeFDS_1[0]);  // read
        close(pipeFDS_2[1]);  // write
        printf("\n Parent Send message: %s", parent_send);
        write(pipeFDS_1[1], parent_send, sizeof(parent_send));
        read(pipeFDS_2[0], parent_receive, sizeof(parent_receive));
        
        printf("\n Message received from child: %s \n", parent_receive);
    }

    return 0;
}