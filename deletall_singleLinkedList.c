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

// Function to recursively delete all occurrences of a target value in the linked list
struct Node* recursiveDelete(struct Node* current, int target) {
    if (current == NULL) {
        return NULL; // Base case: reached the end of the list
    }

    // Recur to the next node if the target is not found in the current node
    current->next = recursiveDelete(current->next, target); // Re check ทั้งหมดก่อน

    // Check if the current node contains the target value
    if (current->data == target) {
        struct Node* nextNode = current->next;
        free(current);
        return nextNode; // Return the next node to update the link in the previous node
    }

    return current; // Return the current node if the target is not found in the rest of the list
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
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 1);
    insert(&head, 3);

    printf("Original Linked List: ");
    printList(head);

    int target = 3;
    // Deleting all occurrences of the target value in the linked list recursively
    head = recursiveDelete(head, target);

    printf("Linked List after Recursive Deletion of %d: ", target);
    printList(head);

    return 0;
}
