#include <stdio.h> 
#include <stdlib.h> 

struct node
{
    int data ; 
    struct node *next ; 
};

*head = NULL ; 
void gen() ; 
void insert_first(int val) ; 
void insert_last(int val) ; 
void delete_first() ; 
void delete_choose(int *head ,int val) ; 
void display() ;
int main(){  
    int val ;
    int choice ; 
    gen() ; 
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
        case 4: 
            delete_first(); 
            display();
            break ;
        case 5:
            printf("What number do you want to delete : ") ; 
            scanf("%d",&val) ; 
            delete_choose(head,val) ; 
            break ; 
        default:
            printf("Not Found") ; 
            break;
        } 
    }
}
void gen(){
    struct node *one ;
    struct node *two ;
    struct node *three ;
 
    one = malloc(sizeof(struct node)) ;
    two = malloc(sizeof(struct node)) ;
    three = malloc(sizeof(struct node)) ;
    one -> data = 4 ; 
    two -> data = 8 ;
    three -> data = 1 ; 
    one -> next = two ; 
    two -> next = three ; 
    three ->  next = NULL ; 
    head = one ; 

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

void delete_first(){
    struct node *temp ; 
    temp = head ; 
    temp = temp -> next ; 
    head = temp ; 
}

void delete_choose(int *head ,int val){
    struct node *temp ; 
    while(temp != NULL){
        if (temp -> data == val){
            temp = temp -> next ;
        }
        else {
            delete_choose(temp->next , val) ; 
        }
    }
    
}

void display(){
    struct node *temp = head ; 
    while(temp != NULL){
        printf("%d-->",temp->data) ; 
        temp = temp -> next ; 
    }
}