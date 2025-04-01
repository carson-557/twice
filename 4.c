#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;    
    struct Node* next;
} Node;

Node* createList() {
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    return head;
}

void insertNode(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = newNode;
}

void printList(Node* head) {
    Node* current = head->next;
    printf("\n当前链表内容：\n");
    int count = 1;
    while (current != NULL) {
        printf("第%d个节点：%d\n", count++, current->data);
        current = current->next;
    }
    printf("\n");
}

void insertAtFront(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head->next;
    head->next = newNode;
}

void insertBeforePosition(Node* head, int value, int position) {
    Node* current = head;
    int count = 0;
    
    while (current->next != NULL && count < position - 1) {
        current = current->next;
        count++;
    }
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = current->next;
    current->next = newNode;
}

void insertAtEnd(Node* head, int value) {
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    current->next = newNode;
}

void deleteNode(Node* head, int position) {
    Node* current = head;
    int count = 0;
    
    while (current->next != NULL && count < position - 1) {
        current = current->next;
        count++;
    }
    
    if (current->next != NULL) {
        Node* temp = current->next;
        current->next = temp->next;
        free(temp);
    }
}

void createOrderedList(Node* head, int length, int start) {
    for (int i = 0; i < length; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = start + i * 2;  // 创建有序数据
        newNode->next = NULL;
        
        Node* current = head;
        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void mergeLists(Node* LA, Node* LB) {
    Node *pa = LA->next, *pb = LB->next;
    LA->next = NULL;
    Node* pc = LA;
    
    while (pa && pb) {
        if (pa->data <= pb->data) {
            Node* temp = pa->next;
            pc->next = pa;
            pa->next = NULL;
            pc = pa;
            pa = temp;
        } else {
            Node* temp = pb->next;
            pc->next = pb;
            pb->next = NULL;
            pc = pb;
            pb = temp;
        }
    }
    
    if (pa) pc->next = pa;
    if (pb) pc->next = pb;
}

int main() {
    Node* LA = createList();
    Node* LB = createList();
    
    printf("创建第一个有序链表LA(15个节点)：\n");
    createOrderedList(LA, 15, 1);
    printf("LA链表内容：");
    printList(LA);
    
    printf("\n创建第二个有序链表LB(9个节点)：\n");
    createOrderedList(LB, 9, 2);
    printf("LB链表内容：");
    printList(LB);
    
    printf("\n合并后的链表LC(与LA共用)：\n");
    mergeLists(LA, LB);
    printf("LC链表内容：");
    printList(LA);
    
    // 释放内存
    Node* current = LA;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    
    free(LB);
    
    return 0;
}