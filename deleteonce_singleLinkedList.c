#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the linked list
void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to recursively delete all nodes in the linked list
void recursiveDelete(struct Node* current) {
    if (current == NULL) {
        return; // Base case: reached the end of the list
    }

    // Recur to the next node before deleting the current one
    recursiveDelete(current->next);

    // Delete the current node
    free(current);
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Inserting elements into the linked list
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);

    printf("Original Linked List: ");
    printList(head);

    // Deleting the linked list recursively
    recursiveDelete(head);
    head = NULL;

    printf("Linked List after Recursive Deletion: ");
    printList(head); // Should print an empty list

    return 0;
}
