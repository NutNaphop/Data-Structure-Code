#include <stdio.h> 
#include <stdlib.h> 

struct node {
    int data ; 
    struct node *next ; 
} ; 

*top = NULL ; 

void push(int) ; 
void pop() ;
void display() ; 


int main(){
    int val , choice ; 
    while (1)
    {
        printf("\n\n***** Menu *****\n") ; 
        printf("1.Push\n2.Pop\n3.Display\n4.Exit") ; 
        printf("\nEnter Your Choice: ") ;
        scanf("%d",&choice) ; 
        switch (choice)
        {
        case 1:
            printf("Enter the value to be insert : ") ; 
            scanf("%d",&val) ; 
            push(val) ; 
            display() ; 
            break;
        case 2 : 
            pop() ; 
            display() ; 
            break ; 

        case 3 : 
            display() ; 
            break ; 
        
        case 4 : 
            exit(0) ; 

        default:
            printf("\nWrong selection!!! Try again!!!") ; 
            break;
        }
    }  
}

void push(int value){
    struct node *newnode ; 
    newnode = malloc(sizeof(struct node)) ; 
    newnode -> data = value ; 
    
    if(top == NULL){
        newnode -> next = NULL ; 
    }
    else{
        newnode -> next = top ; 
    }
    
    top = newnode ; 
    printf("\nInsertion is Success!!!\n") ; 
      
}

void pop(){
    if (top == NULL){
        printf("\nStack is Empty!!!\n") ; 
    }
    else{
        struct node *temp = top ; 
        printf("\nDeleted element: %d\n",temp->data) ; 
        top = temp -> next ; 
        free(temp) ; 
    }
}

void display(){
    if (top == NULL){
        printf("\nStack is Empty!!!\n") ;
    }
    else{
        struct node *temp = top ; 
        while (temp -> next != NULL)
        {
            printf("%d--->",temp->data) ;
            temp = temp -> next ; 
        }
        printf("%d--->NULL\n\n",temp->data) ;  
    }
}

