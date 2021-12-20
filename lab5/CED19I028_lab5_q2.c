// Name: Sumit Kumar
// Roll No: CED19I028
// Question: Write a program using pipe() and fork() in which parent process takes string1 as input.
//           The same is provided to the child process using pipe1. Now, child process will take
//           string2 as input and read string1 from pipe1. Then, child will concatenate string1 with
//           string2. After the concatenation is complete, the child process will send it to the parent
//           process using pipe2. Subsequently, parent will read the concatenated string and
//           displays it.

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {

    int pipeFDS_1[2], pipeFDS_2[2];
    pid_t pid;
    char parent_send[20], parent_receive[20];
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

        printf("\n Enter string for Child: ");
        scanf("%s", child_send);

        strcat(child_send, child_receive);      // concatinating strings
        printf("\n Child Sent: %s \n", child_send);
        write(pipeFDS_2[1], child_send, sizeof(child_send));

    } else {
        // closing unwanted ends of pipe for parent.
        close(pipeFDS_1[0]);  // read
        close(pipeFDS_2[1]);  // write

        printf("\n Enter string for parent: ");
        scanf("%s",parent_send);
        write(pipeFDS_1[1], parent_send, sizeof(parent_send));

        read(pipeFDS_2[0], parent_receive, sizeof(parent_receive));
        
        printf("\n Message received from child: %s \n", parent_receive);
    }

    return 0;
}