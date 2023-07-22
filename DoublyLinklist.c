#include <stdio.h>
#include <stdlib.h> 
 
struct node
{
    int data ; 
    struct node *next ; 
    struct node *previous ;  
};

*head = NULL ; 
void gen() ; 
void insert_between(int val , int pos ) ; 
void insert_front(int val ) ;
void insert_back(int val ) ; 
void delete_first() ; 
void delete_last() ; 
void search(int val ) ; 

int main(){
    int val1 ; 
    int val2 ; 
    int choice ; 
    gen() ;
    display() ; 
    while(1){
        printf("\n\nMenu :\n1.Insert_Between\n2.Search\nI3.Insert Front\n4.Insert Back\n5.Delete First\n6.Delete Last\n7.Display\nWhat do you want : ") ;
        scanf("%d",&choice) ; 
        switch (choice){
            case 1 :
                printf("What number do you want to insert : ");
                scanf("%d",&val1) ; 
                printf("And what position do you like to insert : ");
                scanf("%d",val2) ; 
                insert_between(val1,val2) ;
                break ; 
            case 2 : 
                printf("What number do you want to search : ") ; 
                scanf("%d",&val1) ; 
                search(val1) ; 
                break ; 
            case 3 : 
                printf("Enter you number to insert front : ") ; 
                scanf("%d",&val1) ; 
                insert_front(val1) ;
                break ; 
            case 4 : 
                printf("Enter your number to insert at the back : ") ;
                scanf("%d",val1) ; 
                insert_back(val1) ; 
                break ; 
            case 5 : 
                printf("Delete first completely") ;
                delete_first();
                break ; 
            case 6 : 
                printf("Delete last completely") ;
                delete_last() ; 
                break ; 
            case 7 : 
                printf("DisplayMode\n") ; 
                display() ; 
                break; 
            default : 
                printf("Not found") ;
                break ; 
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

void insert_between(int val , int pos){
    struct node *newnode ; 
    struct node *temp = head ; 


    newnode = malloc(sizeof(struct node)) ; 
    newnode -> data = val ; 

    for (int i = 0 ; i < pos-2 ; i ++){
        temp = temp -> next ; 
    }
    // Connect
    newnode -> next = temp -> next ; 
    newnode -> previous = temp ; 
    temp -> next = newnode ; 
   
}

void insert_front(int val){
    struct node *newnode ; 
    struct node *temp ; 
    temp = head ; 
    newnode = malloc(sizeof(struct node)) ; 
    newnode -> data = val ; 
    newnode -> next = temp ; 
    newnode -> previous = NULL ; 
    head = newnode ; 
}

void insert_back(int val){
    struct node *newnode ; 
    struct node *temp ; 
    temp = head ; 
    newnode = malloc(sizeof(struct node)) ; 
    newnode -> data = val ; 
    newnode -> next = NULL ; 
    while (temp -> next != NULL)
    {
        temp = temp -> next ; 
    }
    temp -> next = newnode ; 
    newnode -> previous = temp ;
}

void delete_first(){
    struct node *temp ;
    temp = head ; 
    temp = temp -> next ; 
    temp -> previous = NULL ; 
    head = temp ; 
}

void delete_last(){
    struct node *temp ; 
    struct node *prev ; 

    temp = head ; 
    prev = head ; 

    temp = temp -> next ; 
    while (temp -> next != NULL){
        temp = temp -> next ; 
        prev = prev -> next ;
    }
    prev -> previous = temp -> previous ; 
    prev -> next = NULL ; 
    
}

void search(int val) {
    struct node *temp = head ;
 
    if (temp -> data == val) {
        printf("Found it ! ! !") ; 
    }
    
    else if (temp != NULL){
        while (temp != NULL){
            if (temp -> data == val){
                printf("Found it ! ! !\n") ; 
                break ; 
            }
            else{
                temp = temp -> next ; 
            }
        }
    }
}

void display(){
    struct node *temp = head ; 
    while (temp != NULL)
    {
        printf("%d->",temp -> data) ; 
        temp = temp -> next ; 
    }
}