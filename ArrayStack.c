#include <stdio.h> 
#include <stdlib.h> 
#define SIZE 5 

void push(int) ; 
void pop() ;
void display() ; 

int stack[SIZE] , top = -1 ; 

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
    if (top == SIZE-1){
        printf("\nStack is FUll\n\n") ; 
    }
    else{
        top ++ ; 
        stack[top] = value ; 
        printf("\nInsertion success!!!\n\n") ; 
    }
}

void pop(){
    if (top == -1){
        printf("\nStack is Empty!!!\n\n") ;
    }
    else{
        printf("\nDeleted : %d",stack[top]) ; 
        top -- ; 
    }
}

void display(){
    if (top == -1){
        printf("\nStack is Empty!!!\n\n") ; 
    }
    else{
        int i ; 
        printf("\nStack elements are:\n\n"); 
        for(i = top ; i >= 0 ; i --){
            printf("%d\n",stack[i]) ; 
        }
    }
}