// Name:    Sumit Kumar
// Roll No: CED19I028
// Lab2 Question: 1 First come first server Scheduling algo using c language..

#include<stdio.h>
#include<stdlib.h>

// linkedlist node. 
struct node {
    int id;
    int arrivalTime;
    int brustTime;
    struct node* next;
    struct node* prev;

}*head, *nextNode, *previousNode;


void printData(struct node *head){
    int waitTime = 0, totalTime = 0, TAT = 0;

    if(head == NULL)
        printf("Empty");
    else{
        struct node *ptr = NULL;
        ptr = head;
        totalTime = ptr->arrivalTime;

        while(ptr != NULL){
            totalTime += ptr->brustTime;
            TAT = totalTime - ptr->arrivalTime;
            waitTime = TAT - ptr->brustTime;

            printf("    %d \t\t %d \t\t %d \t\t %d \t\t\t %d \t\t %d \n" , ptr->id, ptr->arrivalTime, ptr->brustTime, totalTime, waitTime, TAT);
            ptr = ptr->next;
        }
    }
    printf("\n");
}

// inserting node in sorted order according to arrival time..
void insertNode(int id, int arrive, int brust){
    // pushing the first node....
    if(head==NULL){
        head = (struct node *)malloc(sizeof(struct node));
        head->id = id;
        head->arrivalTime = arrive;
        head->brustTime = brust;
        head->next = NULL;
        head->prev = NULL;
    
    }else{

        nextNode = (struct node *)malloc(sizeof(struct node));
        nextNode->id = id;
        nextNode->arrivalTime = arrive;
        nextNode->brustTime = brust;

        struct node *ptr = head;
        previousNode = NULL;
        while(ptr != NULL){
            
            if(ptr->arrivalTime > arrive){
                // if it is head
                if(previousNode == NULL){
                    nextNode->next  = head;
                    nextNode->prev  = NULL;
                    head->prev      = nextNode;
                    
                    head = nextNode;
                
                } else{
                    nextNode->next  = ptr;
                    nextNode->prev  = previousNode;

                    previousNode->next  = nextNode;
                    ptr->prev           = nextNode;
                }
                return;
            }
            previousNode = ptr;
            ptr = ptr->next;
        }
        // inserting at the end
        nextNode->next = NULL;
        nextNode->prev = previousNode;
        previousNode->next = nextNode;
        
    }
}

int main(){

    //  provide input in any order...
    // insertNode(pid, arrivalTime, brustTime);
    insertNode(1,0,4);
    insertNode(2,1,3);
    insertNode(3,2,1);
    insertNode(4,3,2);
    insertNode(5,4,5);
    
    
    printf("\n  | PID |  | Arrival Time |  | Burst Time |  | Completion Time |  | Wait Time |  | Turn-around Time | \n\n");
    printData(head);

    return 0;
}


