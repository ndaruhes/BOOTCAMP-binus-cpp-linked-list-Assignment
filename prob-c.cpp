#include <stdio.h>
#include <stdlib.h>

struct Node {
    int number;
    Node *next;
} * head, *tail, *curr, *mid;

Node *createNode(int number) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->number = number;
    newNode->next = NULL;
    return newNode;
}

void pushHead(int number) {
    Node *temp = createNode(number);
    if (!head) {
        head = tail = temp;
    } else {
        temp->next = head;
        head = temp;
    }
}

void popHead(int number) {
    if (!head) {
        return;
    } else if (head == tail) {
        head = tail = NULL;
        free(head);
    } else {
        Node *temp = head;
        head = temp->next;
        temp->next = NULL;
        free(temp);
    }
}
void popTail(int number) {
    if (!head) {
        return;
    } else if (head == tail) {
        head = tail = NULL;
        free(head);
    } else {
        Node *temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = NULL;
        free(tail);
        tail = temp;
    }
}

void printLinkedList() {
    int count = 0;
    struct Node *mid = head;

    while (head != NULL) {
        count++;
        if (count % 2 == 0)
            mid = mid->next;

        head = head->next;
    }
    if (mid != NULL)
        printf("The Middle Element is %d\n", mid->number);
}

int main() {
    int data, a, b;
    printf("How many datas? ");
    scanf("%d", &data);
    printf("Input number: ");
    for (int i = 0; i < data; i++) {
        scanf(" %d", &a);
        pushHead(a);
    }
    printLinkedList();

    printf("\n");
    return 0;
}
