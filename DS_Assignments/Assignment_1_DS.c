#include <stdio.h>
#include <stdlib.h>

//Define a structure for the linked list node
typedef struct node {
    int data; //data in the node
    struct node* next; //pointer to the next node
} NODEPTR;

// Define a structure for the queue
typedef struct queue {
    NODEPTR* front; //pointer to the front of the queue
    NODEPTR* rear; //pointer to the rear of the queue
} QUEUE;

// Function to initialize an empty queue
void initializeQueue(QUEUE* q) { //initialize front and rear of queue to NULL
    q->front = NULL; 
    q->rear = NULL;
}

// Function to insert an element into the queue
void insert(QUEUE* q, int elm) { //allocate memory for new node
    NODEPTR* newNode = (NODEPTR*)malloc(sizeof(NODEPTR));
    if (newNode == NULL) { //if memory allocation fails newNode is NULL and there isn't enough memory to create a new node
        printf("Memory allocation error.\n");
        exit(1);
    }

    newNode->data = elm; //new node's data is set to elm
    newNode->next = NULL; //new node's next is set to NULL

    if (q->rear == NULL) { //if queue is emtpy, front and rear is the newNode as there is only 1 element
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode; //queue's rear element's next becomes the new node (linking)
        q->rear = newNode; //queue's rear element now becomes the new node
    }

    printf("%d is inserted into the queue.\n", elm);
}

// Function to delete an element from the queue
void delete(QUEUE* q) {
    if (q->front == NULL) { //if queue is empty
        printf("Queue is empty. Deletion failed.\n");
        return;
    }

    int deleted = q->front->data; //store the first element in delted variable
    NODEPTR* temp = q->front; //temporary variable temp stores the first node of the queue

    q->front = q->front->next; //first node of queue becomes the previous first node's next node
    free(temp); //temp node is freed from the queue

    if (q->front == NULL) { //if the queue is now empty, i.e., front of queue is NULL
        q->rear = NULL; //make the rear of queue NULL
    }

printf("%d is deleted from the queue.\n", deleted);
}

// Function to print the elements in the queue
void printQueue(QUEUE* q) {
    if (q->front == NULL) { //if queue is empty
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    NODEPTR* current = q->front;
    while (current != NULL) { //if current is NULL it means queue ended 
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    QUEUE q;

    printf("Queue 1:\n");

    initializeQueue(&q);

    insert(&q,11);
    insert(&q,22);
    printQueue(&q);
    delete(&q);
    printQueue(&q);

    printf("\nQueue 2:\n");

    initializeQueue(&q);
    delete(&q);
    insert(&q,5);
    insert(&q,100000);
    insert(&q, 7);
    printQueue(&q);
    delete(&q);
    delete(&q);
    insert(&q, 37);
    printQueue(&q);

    return 0;
}