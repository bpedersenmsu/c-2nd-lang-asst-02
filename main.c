#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

struct Node {
    char name[20];
    struct Node* previous;
    struct Node* next;
};

struct Node* headNode;
struct Node* tailNode;

static void insertFirst(char val[20]){
    struct Node* first = (struct Node*) malloc(sizeof(struct Node));
    strcpy(first->name, val);

    // printf("Node Name: %s\n", first->name);
    first->next = tailNode;
    if(tailNode != NULL) {
        tailNode->previous = first;
    }
    else{
        headNode = first;
    }
    tailNode = first;
}

void insertLast(char val[20]){
    struct Node* head = (struct Node*) malloc(sizeof(struct Node));
    strcpy(head->name, val);

    head->previous = headNode;
    if(headNode != NULL) {
        headNode->next = head;
    }
    else{
        headNode = head;
    }
    headNode = head;
}

void insertNode(int index, char val[20]){
    struct Node* currentNode = tailNode;

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    strcpy(newNode->name, val);

    for (int i = 0; i < index; i++){
        if(i != (index - 1)){
            if(currentNode->next != NULL){
                currentNode = currentNode->next;
            }
            else{
                printf("Index is out of range\n");
                i = index;
            }
        }
        else{
            struct Node* previousNode = currentNode->previous;
            previousNode->next = newNode;
            newNode->previous = previousNode;
            newNode->next = currentNode;
            currentNode->previous = newNode;
        }
    }
}
void printList(){
    struct Node* currentVal = tailNode;
    while (currentVal->next != NULL){
        printf("Node Name: %s\n", currentVal->name);
        currentVal = currentVal->next;
    }
    printf("Node Name: %s\n", currentVal->name);

}

void freeList(){
    struct Node* currentNode = tailNode;
    free(currentNode->previous);
    if(currentNode->next != NULL){
        while (currentNode->next != NULL){
            free(currentNode->previous);
            currentNode = currentNode->next;
        }
    }
    free(currentNode);
}

int main() {
    printf("Hello, World!\n");

    insertFirst("Third Val");
    insertFirst("Second Val");
    insertFirst("First Val");
    insertLast("Fifth Val");
    insertNode(4, "Fourth Val");
    printList();
    freeList();
    return 0;
}
