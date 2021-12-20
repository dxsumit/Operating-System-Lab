// Name:    Sumit Kumar
// Roll No: CED19I028
// Lab3 Question: 1 priority Scheduling algo using linkedlist in c language..

#include<stdio.h>
#include<stdlib.h>

// gloabl variabls
int currentTime = 0;

struct node{
    int id;
    int arrivalTime;
    int brustTime;
    int priority;
    struct node* next;
    struct node* prev;

}*head, *nextNode, *previousNode;


// inserting node in sorted order according to priority..
void insertNode(int id, int arrive, int brust, int P){
    // pushing the first node....
    if(head==NULL){
        head = (struct node *)malloc(sizeof(struct node));
        head->id = id;
        head->arrivalTime = arrive;
        head->brustTime = brust;
        head->priority = P;
        head->next = NULL;
        head->prev = NULL;
    
    }else{
        nextNode = (struct node *)malloc(sizeof(struct node));
        nextNode->id = id;
        nextNode->arrivalTime = arrive;
        nextNode->brustTime = brust;
        nextNode->priority = P;

        struct node *ptr = head;
        previousNode = NULL;
        // pushing in the right position (insertion method)...
        while(ptr != NULL){
            
            if(ptr->priority > P){
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
            return;
        }
        ptr = ptr->next;
    }
}

// printing one perticular process... 
void printNode(int pid, int PT){
    struct node *ptr = head;
    int ramainingTime = 0;
    while(ptr != NULL){
        if(ptr->id == pid){
            // remaning time..
            ptr->brustTime = ptr->brustTime - PT;
            
            if(ptr->brustTime <= 0){
                printf("|P%d %d %d |", ptr->id, ptr->priority, 0);
                currentTime = currentTime + PT + ptr->brustTime;
                deleteNode(ptr->id);
            
            } else {
                printf("|P%d %d %d |", ptr->id, ptr->priority, ptr->brustTime);
                currentTime += PT;
            }
            return;
        }
        ptr = ptr->next;
    }
}


void priority_algo(int PT){
    struct node *ptr = head;
    while(ptr != NULL){
        if(ptr->arrivalTime <= currentTime){
            ptr->brustTime = ptr->brustTime - PT;

            if(ptr->brustTime <= 0){
                printf("|P%d %d %d |", ptr->id, ptr->priority, 0);
                currentTime = currentTime + PT + ptr->brustTime;
                deleteNode(ptr->id);
            
            } else {
                printf("|P%d %d %d |", ptr->id, ptr->priority, ptr->brustTime);
                currentTime += PT;
            }
            ptr = head;
            continue;
        } 
        ptr = ptr->next;
    }
}


int main(){

    int n, pid, AT, P, BT, minAT = -1, firstProcessID, QT;
    printf(" \n Enter quantum share Time : ");
    scanf("%d", &QT);

    printf(" \n Enter number of process : ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        printf(" \n Enter process id, Arrival Time, Brust Time, Priority respectively [ ex- 1 0 20 3] : ");
        scanf("%d %d %d %d" , &pid, &AT, &BT, &P);
        insertNode(pid, AT, BT, P);

        if(minAT > AT || i==0){
            minAT = AT;
            firstProcessID = pid;
        }
    }
    printf("\n ==> Smaller the priorty means execute first..\n");
    printf(" | processID, Priority, Remaning time to finish |\n\n");

    printNode(firstProcessID, QT);
    priority_algo(QT);
    printf("\n");

    return 0;
}
