//
//  appendList.c
//  c
//
//  Created by Prakhar Jain on 30/07/13.
//  Copyright (c) 2013 Prakhar Jain. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node *NODEPTR;

void append (NODEPTR *head, NODEPTR *tail, int data) {
    NODEPTR temp = (NODEPTR) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if (*head == NULL) {
        *head = *tail = temp;
        return;
    }
    (*tail)->next = temp;
    *tail = temp;
}

void printList(NODEPTR list) {
    while (list != NULL) {
        printf("%d ", list->data);
        list = list->next;
    }
    putchar('\n');
}

int main() {
    NODEPTR listHead = NULL;
    NODEPTR listTail = NULL;
    int n;
    scanf("%d", &n);
    int num;
    while (n--) {
        scanf("%d", &num);
        append(&listHead, &listTail, num);
    }
    printList(listHead);
    return 0;
}