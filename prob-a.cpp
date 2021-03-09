#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int angka;
    Node *next;
} * head, *tail, *curr;

// Create NULL
// Node *createNode(int angka) {
//     Node *newNode = (Node *)malloc(sizeof(Node));
//     newNode->angka = angka;
//     newNode->next = NULL;
//     return newNode;
// }

// Insert
void pushTail(int angka) {
    Node *temp = createNode(angka);
    if (!head) {
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

// Print
void printLinkedList() {
    Node *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->angka);
        curr = curr->next;
    }
}

// Sort
void sortLinkedList() {
    int temp;
    Node *curr;
    Node *ptr = head;
    while (ptr != NULL) {
        curr = ptr->next;
        while (curr != NULL) {
            if (ptr->angka > curr->angka) {
                temp = ptr->angka;
                ptr->angka = curr->angka;
                curr->angka = temp;
            }
            curr = curr->next;
        }
        ptr = ptr->next;
    }
}

// Driver code
int main() {
    int n, m, a, b;

    printf("Banyaknya List ke-1: ");
    scanf("%d", &m);
    printf("Masukan list ke 1: ");
    for (int i = 0; i < m; i++) {
        scanf(" %d", &a);
        pushTail(a);
    }
    printf("\n");

    printf("Banyaknya List ke-2: ");
    scanf("%d", &n);
    printf("Masukan list ke 2: ");
    for (int i = 0; i < n; i++) {
        scanf(" %d", &b);
        pushTail(b);
    }
    printf("\n");

    sortLinkedList();
    printf("List Akhir: ");
    printLinkedList();
    printf("\n");

    return 0;
}