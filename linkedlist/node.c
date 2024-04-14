#include <stdio.h>
#include <stdlib.h>
#include "node.h"

typedef struct list {
    Node* head;
} List;

bool add(List* pList, int number);
bool del(List* pList, int number);
void print(List* pList);
bool clear(List* pList);


int main()
{
    List list;
    list.head = NULL;
    int number;
    do {
        scanf("%d", &number);
        if (number != -1) {
            add(&list, number);
        }
    } while (number != -1);

    

    return 0;
}

bool add(List* pList, int number)
{
    Node* p = (Node*)malloc(sizeof(Node));
    if (!p) return false;
    p->val = number;
    p->next = NULL;
    // find tail to insert
    Node* last = pList->head;
    if (last)
    {
        while (last->next)
        {
            last = last->next;
        }
        last->next = p;
    }
    else
    {
        pList->head = p;
    }
    return true;
}

bool del(List* pList, int number)
{
    Node* pre = NULL;
    for (Node* node = pList->head; node; pre = node, node = node->next)
    {
        if (node->val == number)
        {
            if (pre)
            {
                pre->next = node->next;
            }
            else
            {
                pList->head = node->next;
            }
            free(node);
            return true;
        }
    }
    return false;
}

bool clear(List* pList)
{
    Node* next = NULL;
    for (Node* pre = pList->head; pre; pre = next)
    {
        next = pre->next;
        free(pre);
    }
}


void print(List* pList)
{
    for (Node* p = pList->head; p; p = p->next)
    {
        printf("%d\t", p->val);
    }
    printf("\n");
}