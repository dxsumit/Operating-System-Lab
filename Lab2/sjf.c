// Name:    Sumit Kumar
// Roll No: CED19I028
// Lab2 Question: 2 shortest Job first Scheduling algo using c language..


#include<stdio.h>
#include<stdlib.h>

int currentTime = 0, TAT = 0, waitTime = 0;      // global variables

//  linkedist node...
struct node {
    int id;
    int arrivalTime;
    int brustTime;
    struct node* next;
    struct node* prev;

}*head, *nextNode, *previousNode;


// printing one perticular process... 
void printNode(int pid){
    struct node *ptr = head;
    while(ptr != NULL){
        if(ptr->id == pid){
            currentTime += ptr->brustTime + ptr->arrivalTime;
            TAT = currentTime - ptr->arrivalTime;
            waitTime = TAT - ptr->brustTime;
            printf("    %d \t\t %d \t\t %d \t\t %d \t\t\t %d \t\t %d \n" , ptr->id, ptr->arrivalTime, ptr->brustTime, currentTime, waitTime, TAT);
        }
        ptr = ptr->next;
    }
}


// delete a perticular node..
void deleteNode(int pid){
    struct node *ptr = head;
    while(ptr != NULL){
        if(ptr->id == pid){
            // if its head
            if(ptr == head){
                // if it is only
                if(ptr->next != NULL){
                    ptr->next->prev = NULL;
                    head = ptr->next;
                }
                free(ptr);
            
            // if it is a tail..
            }else if(ptr->next == NULL){
                ptr->prev->next = NULL;
                free(ptr);
            
            }else{
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
                free(ptr);
            }
        }
        ptr = ptr->next;
    }
}


// inserting node in sorted order according to burst time..
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
        // pushing in the right position (insertion method)...
        while(ptr != NULL){
            
            if(ptr->brustTime > brust){
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


void SJF_algo(){
    struct node *ptr = head;
    while(ptr != NULL){
        if(ptr->arrivalTime <= currentTime){
            currentTime += ptr->brustTime;
            TAT = currentTime - ptr->arrivalTime;
            waitTime = TAT - ptr->brustTime;
            printf("    %d \t\t %d \t\t %d \t\t %d \t\t\t %d \t\t %d \n" , ptr->id, ptr->arrivalTime, ptr->brustTime, currentTime, waitTime, TAT);

            deleteNode(ptr->id);
            ptr = head;
            continue;
        } 
        ptr = ptr->next;
    }
}


int main(){

    int n, pid, AT, BT, prevAT = -1, firstProcessID;
    printf(" \n Enter number of process : ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        printf(" \n Enter process id, Arrival Time, Brust Time respectively [ ex- 1 0 20 ] : ");
        scanf("%d %d %d" , &pid, &AT, &BT);
        insertNode(pid, AT, BT);

        if(prevAT > AT){
            firstProcessID = pid;
        }
        prevAT = AT;
    }

    printf("\n  | PID |  | Arrival Time |  | Burst Time |  | Completion Time |  | Wait Time |  | Turn-around Time | \n\n");
    //  if all process arrive at same time then go for shortest brust time...
    printNode(firstProcessID);
    deleteNode(firstProcessID);
    SJF_algo();

    return 0;
}

