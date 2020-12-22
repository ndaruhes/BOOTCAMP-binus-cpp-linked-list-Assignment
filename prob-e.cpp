#include <stdio.h>
#include <stdlib.h>

struct Node {
    int angka;
    Node *next;
} * head, *tail, *curr;

// Create NULL
Node *createNode(int angka) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->angka = angka;
    newNode->next = NULL;
    return newNode;
}

// Insert
void pushHead(int angka) {
    Node *temp = createNode(angka);

    if (!head) {
        head = tail = temp;
    } else {
        temp->next = head;
        head = temp;
    }
}

// Print
int count = 0;
void searchLinkedList(int b) {
    Node *curr = head;
    while (curr) {
        count++;
        if (count == b)
            printf("Node ke-%d: %d\n", b, curr->angka);
        curr = curr->next;
    }
}

int main() {
    int m, a, b;

    printf("Banyaknya List: ");
    scanf("%d", &m);
    printf("Masukan list: ");
    for (int i = 0; i < m; i++) {
        scanf(" %d", &a);
        pushHead(a);
    }
    printf("Cari node ke (dari belakang): ");
    scanf("%d", &b);
    searchLinkedList(b);

    printf("\n");
    return 0;
}