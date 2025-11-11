#include <stdio.h> #include <stdlib.h> struct Node {
int data;
struct Node* next;
};
struct Node* front = NULL; struct Node* rear = NULL; void enqueue(int value); void dequeue();
void display(); void peek(); int main() {
int choice, value; while (1) {
printf("\n====== QUEUE USING LINKED LIST ======\n");
printf("1. Enqueue (Insert)\n"); printf("2. Dequeue (Delete)\n"); printf("3. Display\n");
printf("4. Peek (Front Element)\n"); printf("5. Exit\n");
printf("Enter your choice: "); scanf("%d", &choice); switch (choice) {
 
case 1:
printf("Enter value to enqueue: "); scanf("%d", &value); enqueue(value);
break; case 2:
dequeue(); break;
case 3:
display(); break;
case 4:
peek(); break;
case 5:
printf("\nExiting program...\n"); exit(0);
default:
printf("\nInvalid choice! Please try again.\n");
}
}
return 0;
}
void enqueue(int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); if (newNode == NULL) {
printf("\nMemory allocation failed!\n");
 
return;
}
newNode->data = value; newNode->next = NULL; if (rear == NULL) {
front = rear = newNode;
} else {
rear->next = newNode; rear = newNode;
}
printf("\n%d enqueued successfully.\n", value);
}
void dequeue() {
if (front == NULL) {
printf("\nQueue is empty! Cannot dequeue.\n"); return;
}
struct Node* temp = front;
printf("\nDequeued element: %d\n", front->data); front = front->next;
if (front == NULL) rear = NULL;
free(temp);
}
void display() {
if (front == NULL) { printf("\nQueue is empty!\n");
 
return;
}
struct Node* temp = front; printf("\nQueue elements: "); while (temp != NULL) {
printf("%d ", temp->data); temp = temp->next;
}
printf("\n");
}
void peek() {
if (front == NULL) { printf("\nQueue is empty!\n"); return;
}
printf("\nFront element: %d\n", front->data);
}
