#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node* next;
};

void addNode();
void display(struct Node*);

void freeList(struct Node*);

int main(){
    // allocate memory first because the pointer needs to point to valid memory
    struct Node* first_node = malloc(sizeof(struct Node*));
    first_node->value = 1;
    first_node->next = NULL;
    
    struct Node* second_node = malloc(sizeof(struct Node*));
    second_node->value = 2;
    second_node->next = first_node;
    
    struct Node* third_node = malloc(sizeof(struct Node*));
    third_node->value = 3;
    third_node->next = second_node;
    
    struct Node* fourth_node = malloc(sizeof(struct Node*));
    fourth_node->value = 4;
    fourth_node->next = third_node;
    
    struct Node* head = fourth_node;
    
    display(head);
    return 0;
}

void display(struct Node* head){
    struct Node* iter = head;
    
    while(iter != NULL){
        printf("Node value: %d\n", iter->value);
        // No iter++ because these nodes are not consecutive memory locations
        iter = iter->next;
    }
}

void freeList(struct Node* head){
    struct Node* iter = head;
    struct Node* temp = iter->next;
    
    while(temp != NULL){
        free(iter);
        iter = temp;
        temp = iter->next;
        
    }
}
