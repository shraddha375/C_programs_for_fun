#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node* next;
};

void display(struct Node*);

void freeList(struct Node*);

struct Node* insertNode_front(struct Node*, int);

struct Node* insertNode_back(struct Node*, int);

struct Node* insertNode_position(struct Node*, int, int);

struct Node* deleteNode_front(struct Node*);

struct Node* deleteNode_back(struct Node*);

struct Node* deleteNode_position(struct Node*, int);

void findNode(struct Node*, int);


int main(){
    // allocate memory first because the pointer needs to point to valid memory
    struct Node* first_node = (struct Node*) malloc(sizeof(struct Node));
    first_node->value = 1;
    first_node->next = NULL;
    
    struct Node* second_node = (struct Node*) malloc(sizeof(struct Node));
    second_node->value = 2;
    second_node->next = first_node;
    
    struct Node* third_node = (struct Node*) malloc(sizeof(struct Node));
    third_node->value = 3;
    third_node->next = second_node;
    
    struct Node* fourth_node = (struct Node*) malloc(sizeof(struct Node));
    fourth_node->value = 4;
    fourth_node->next = third_node;
    
    struct Node* head = fourth_node;
    
    // display(head);

    head = insertNode_front(head, 10);

    // display(head);

    head = insertNode_back(head, 11);
    
    // display(head);

    head = insertNode_position(head, 12, 8);
    
    // display(head);
    
    head = deleteNode_front(head);
    
    // display(head);
    
    head = deleteNode_back(head);
    
    // display(head);
    
    head = deleteNode_position(head, 3);
    
    display(head);
    
    findNode(head, 2);
    
    return 0;
}

void display(struct Node* head){
    struct Node* iter = head;
    
    printf("Node value: \t");
    while(iter != NULL){
        printf("%d\t", iter->value);
        // No iter++ because these nodes are not consecutive memory locations
        iter = iter->next;
    }
    printf("\n");
}

void freeList(struct Node* head){
    // struct Node* iter = head;
    struct Node* temp;
    
    while(head != NULL){
        temp = head->next;
        free(head);
        head = temp;
    }
}

struct Node* insertNode_front(struct Node* head, int value){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = head;
    head = newNode;
    return head;
}

struct Node* insertNode_back(struct Node* head, int value){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;

    // If the node is empty then return the new node
    if (head == NULL){
        return newNode;
    }

    struct Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

struct Node* insertNode_position(struct Node* head, int value, int position){
    if(head == NULL || position == 1){
        head = insertNode_front(head, value);
        return head;
    }
    
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    struct Node* temp = head;
    int count = 0;

    while((temp->next != NULL) && (count != (position - 2))){
        temp = temp->next;
        count++;
    }

    newNode->value = value;
    newNode->next = temp->next;
    temp->next = newNode;
    
    return head;
}

// remembr to heandle epmty lists and other exceptions

struct Node* deleteNode_front(struct Node* head){
    struct Node* temp = head->next;
    free(head);
    head = temp;
    return head;
}

struct Node* deleteNode_back(struct Node* head){
    struct Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    
    free(temp->next);
    temp->next = NULL;
    return head;
}

struct Node* deleteNode_position(struct Node* head, int position){
    struct Node* temp1;
    struct Node* temp2;
    int count = 0;
    
    temp1 = head;
    
    while(count != (position - 2)){
         head = head->next;
         count++;
    }
    
    temp2 = head->next;
    head->next = head->next->next;
    free(temp2);
    return temp1;
}

void findNode(struct Node* head, int value){
    int b = 0;
    while(head != NULL){
        if(head->value == value){
            b = 1;
            break;
        }
        head = head->next;
    }
    
    if (b)
        printf("Value is present.\n");
    else
        printf("Value is not present.\n");
}
