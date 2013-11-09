#include <stdio.h>
#include <stdlib.h>

typedef struct link_list{
    int data;
    struct link_list* next;
}link_list;

int insert_link_list(link_list *head, int data) {

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

int delete_link_list(link_list *head, link_list *p) {

    if (head == NULL || p == NULL) {
        return -1;
    }

    link_list *tmp = head->next; 
    int t = tmp->data;
    tmp->data = p->data;
    p->data = t;

    head->next = tmp->next; 
    free(tmp);

    return 0;
}

int main(void) {
    
    int input_data[] = {1,2,3,4,5,6};
    int i = 0; 
    link_list *head = NULL;
    head = (link_list*)malloc(sizeof(link_list));
    if (head == NULL) {
        fprintf(stderr, "init link list failed.\n");
        return -1;
    }
    head->next = NULL;

    for (; i < 6; ++i) {
        if (insert_link_list(head, input_data[i]) != 0) {
            fprintf(stderr, "insert data failed.\n");
            return -1;
        }
    }

    link_list *p = head->next->next->next->next;
    if (delete_link_list(head, p) != 0) {
        fprintf(stderr, "delete node failed.\n");
        return -1;
    }

    p = head->next;
    while(p != NULL) {
        link_list *tmp = p;
        printf("%d ", p->data);
        p = p->next;
        free(tmp);
    }
    free(head);

    return 0;
}
