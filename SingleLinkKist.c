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
void delete_last() ; 
void delete_choose(int *head ,int val) ; 
void search(int val) ; 

void display() ;
int main(){  
    int val ;
    int choice ; 
    gen() ; 
    while(1){
        printf("\n\nMenu :\n1.Insert_First\n2.Insert Last\n3.exit\n4.Delete First\n5.Delete Choose\n6.Delete Last\n7.Search\n8.Display\nWhat do you want : ") ;

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
        case 6 :
            delete_last() ; 
            display() ; 
            break; 
        case 7: 
            printf("What number do you want to find : ") ; 
            scanf("%d",&val) ; 
            search(val) ; 
            display() ; 
            break ; 
        case 8:
            display() ; 
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
    prev -> next = NULL ; 
    prev = head ; 
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
    while(temp != NULL){
        printf("%d-->",temp->data) ; 
        temp = temp -> next ; 
    }
}