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
void insert_between(int val , int pos) ; 
void insert_front(int val ) ;
void insert_back(int val ) ; 
void delete_first() ; 
int main(){
    int val ; 
    int choice ; 
    gen() ; 
    insert_between(9,3) ;
    insert_front(0) ;  
    insert_back(20) ; 
    delete_first();
    display() ; 

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
void display(){
     struct node *temp = head ; 
    while (temp != NULL)
    {
        printf("%d->",temp -> data) ; 
        temp = temp -> next ; 
    }
}