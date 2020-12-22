#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Represents the node of list.
struct node {
    int data;
    struct node *next;
};

//Declaring head and tail pointer as null.
struct node *head = NULL;
struct node *tail = NULL;

//This function will add the new node at the end of the list.
void add(int data) {
    //Create new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    //Checks if the list is empty.
    if (head == NULL) {
        //If list is empty, both head and tail would point to new node.
        head = newNode;
        tail = newNode;
        newNode->next = head;
    } else {
        //tail will point to new node.
        tail->next = newNode;
        //New node will become new tail.
        tail = newNode;
        //Since, it is circular linked list tail will point to head.
        tail->next = head;
    }
}

//Removes duplicate from the list
void removeDuplicate() {
    //Current will point to head
    struct node *current = head, *index = NULL, *temp = NULL;
    if (head == NULL) {
        printf("List is empty");
    } else {
        do {
            //Temp will point to previous node of index.
            temp = current;
            //Index will point to node next to current
            index = current->next;
            while (index != head) {
                //If current node is equal to index data
                if (current->data == index->data) {
                    //Here, index node is pointing to the node which is duplicate of current node
                    //Skips the duplicate node by pointing to next node
                    temp->next = index->next;
                } else {
                    //Temp will point to previous node of index.
                    temp = index;
                }
                index = index->next;
            }
            current = current->next;
        } while (current->next != head);
    }
}
//This function will display the nodes of circular linked list
void display() {
    struct node *current = head;
    if (head == NULL) {
        printf("List is empty");
    } else {
        do {
            //Prints each node by incrementing pointer.
            printf("%d ", current->data);
            current = current->next;
        } while (current != head);
        printf("\n");
    }
}

int main() {
    //Adds data to the list
    add(1);
    add(2);
    add(3);
    add(4);
    add(5);
    add(4);
    add(3);
    printf("Originals list: \n");
    display();
    //Removes duplicate nodes
    removeDuplicate();
    printf("List after removing duplicates: \n");
    display();

    return 0;
}