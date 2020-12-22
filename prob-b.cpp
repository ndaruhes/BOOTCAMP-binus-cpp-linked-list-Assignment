#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} * head;

void initialize() {
    head = NULL;
}

void insert(int num) {
    struct node *createNode = (struct node *)malloc(sizeof(struct node));
    createNode->data = num;
    createNode->next = head;
    head = createNode;
    printf("%d -> ", num);
}

void findloop(struct node *head) {
    struct node *slow, *fast;
    slow = fast = head;

    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            printf("\nLinked List contains a Cycle\n");
            return;
        }
    }
    printf("\nNo Cycle in Linked List\n");
}

void printLinkedList(struct node *ptr) {
    while (ptr != NULL) {
        printf("%d", ptr->data);
        ptr = ptr->next;
        if (ptr != NULL)
            printf("-->");
    }
}

int main() {
    initialize();
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    printf("NULL");
    head->next->next->next->next->next = head->next;

    findloop(head);
    return 0;
}
