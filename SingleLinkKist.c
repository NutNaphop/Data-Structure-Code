#include <stdio.h> 
#include <stdlib.h> 

struct node
{
    int data ; 
    struct node *next ; 
};

*head = NULL ; 

void insert_first(int val) ; 
void insert_last(int val) ; 
void display() ;
int main(){  
    int val ;
    int choice ; 
    while(1){
        printf("\nChoice : ") ; 
        scanf("%d",&choice) ; 
        switch (choice){
        case 1:
            printf("Number : ") ; 
            scanf("%d",&val) ; 
            insert_first(val) ; 
            display() ;  
            break;
        case 2: 
            printf("Number : ") ; 
            scanf("%d",&val) ; 
            insert_last(val) ; 
            display() ; 
            break ; 
        case 3: 
            exit(0) ; 
        default:
            printf("Not Found") ; 
            break;
        } 
    }
}

void insert_first(int val){
    struct node *newnode ; 
    newnode = malloc(sizeof(struct node)) ; 
    newnode -> data = val ; 
    newnode -> next = head ; 
    head = newnode ; 

}

void insert_last(int val){
    struct node *newnode ;
    struct node *temp = head ; 
    if (temp == NULL){
        insert_first(val) ; 
    } 
    else{
        newnode = malloc(sizeof(struct node)) ; 
        newnode -> data = val ; 
        newnode -> next = NULL ; 
        while(temp -> next != NULL){
        temp = temp->next ; 
    }
    temp -> next = newnode ; 
    
    }


}
void display(){
    struct node *temp = head ; 
    while(temp != NULL){
        printf("%d-->",temp->data) ; 
        temp = temp -> next ; 
    }
}