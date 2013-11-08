#include <stdio.h> 
#include <stdlib.h>

typedef struct link_list {
    int data;
    struct link_list* next;
}link_list;

int push(link_list *head, int data) {

    if (head == NULL) {
        return -1;
    }

    link_list *new_node = (link_list*)malloc(sizeof(link_list));
    if (new_node == NULL) {
        return -1;
    }

    new_node->data = data;
    new_node->next = head->next;

    head->next = new_node;

    return 0;
}

int reverse_link_list(link_list *head) {

    if (head == NULL) {
        return -1;
    }

    link_list *p = head->next;
    if (p == NULL) {
        return -1;
    }

    link_list *n = p->next;
    while (n != NULL) {
        link_list *tmp = n->next; 
        n->next = p;
        p = n; 
        n = tmp;
    }

    n = head->next;
    head->next = p; 
    n->next = NULL;

    return 0;

}

int release_link_list(link_list *head) {

    while(head != NULL) {
        link_list *tmp = head;
        head = head->next;
        free(tmp);
    }

    return 0;
}

int main()
{

    link_list *head = NULL; 
    head = (link_list*)malloc(sizeof(link_list));
    if (head == NULL) {
        fprintf(stderr, "init head failed.\n");
        return -1;
    }

    head->next = NULL;

    int i = 0; 
    for (i = 0; i < 10; ++i) {
        if (push(head, i) != 0) {
            fprintf(stderr, "push back operation failed.\n");
            return -1;
        }
    }


    if (reverse_link_list(head) != 0) {
        fprintf(stderr, "reverse link list failed.\n");
        return -1;
    }

    link_list *tmp = head->next; 
    while (tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }

    release_link_list(head);

    return 0;
}

