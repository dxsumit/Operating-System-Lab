// Name: Sumit Kumar
// Roll No: CED19I028
// Question: Write a program in which the parent process sets up the string and sends the same 
//           string to the child process using pipe. Subsequently, child process reads the data from 
//           the pipe and calculates the sum of ASCII equivalent of the string. Then, child process will 
//           write back the ASCII sum to another pipe and the parent prints the same.


#include <stdio.h>
#include <unistd.h>
#include <string.h>

int calculate_ascii(char *arr){ 
    int sum = 0, len;  
    len = strlen(arr);
       
    for (int i=0; i<len; i++){  
        sum += (int)arr[i];
    }
    return sum;
}

int main() {

    int pipeFDS_1[2], pipeFDS_2[2];
    pid_t pid;
    char parent_send[20];
    int parent_received;
    char child_receive[20];
    int child_send;

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

        child_send = calculate_ascii(child_receive);
        printf("\n Child Sent: %d \n\n", child_send);

        write(pipeFDS_2[1], &child_send, sizeof(child_send));

    } else {
        // closing unwanted ends of pipe for parent.
        close(pipeFDS_1[0]);  // read
        close(pipeFDS_2[1]);  // write

        printf("\n Enter string : ");
        scanf("%s", parent_send);

        printf("\n Parent Send message: %s", parent_send);
        write(pipeFDS_1[1], parent_send, sizeof(parent_send));

        read(pipeFDS_2[0], &parent_received, sizeof(parent_received));
        
        printf("\n Message received from child: %d \n", parent_received);
    }

    return 0;
}