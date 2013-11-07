#include <stdio.h> 
#include <stdlib.h>

typedef struct link_node {

    int data;
    struct link_node * next;
}link_node;


int push_back(link_node **head, int data)
{
    link_node *node = (link_node*)malloc(sizeof(link_node));
    if (node == NULL) {
        return -1;
    }
    
    node->data = data;  
    node->next = NULL; 

    if (*head != NULL) {
        node->next = *head;
    }

    *head = node;

    return 0;
}

int main()
{
    link_node *head = NULL;
    int i = 0; 

    for (i = 0; i < 10; ++i) {
        if (push_back(&head, i) != 0) {
            fprintf(stderr, "push back failed.\n");
            return -1;
        }
    }

    link_node *tail = head; 
    int k = 0; 

    scanf("%d", &k);
    
    ++k;
    while(k--) {
        tail = tail->next;
    }

    link_node *curr = head;
    while (tail != NULL) {
       curr = curr->next;
       tail = tail->next;
    }

    printf("%d\n", curr->data);

    return 0;
}

