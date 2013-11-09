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

link_list *find_common_node(link_list *head, link_list *head2) {

    if (head == NULL || head2 == NULL) {
        return NULL;
    }

    int len_head = 0;
    int len_head2 = 0; 

    link_list *iter = head->next;

    while (iter != NULL) {
        len_head++;
        iter = iter->next;
    }

    iter = head2->next; 
    while (iter != NULL) {
        len_head2++;
        iter = iter->next;
    }

    int distance = abs(len_head - len_head2);
    iter = len_head > len_head2 ? head->next : head2->next;
    head2 = iter == head->next ? head2->next : head->next;
    while(distance--) {
        iter = iter->next;
    }
    while(1) {
        if (iter == head2) {
            return iter;
        }
        iter = iter->next;
        head2 = head2->next;
    }

    return NULL;
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

    link_list *head2 = NULL; 
    head2 = (link_list*)malloc(sizeof(link_list));
    if (head2 == NULL) {
        fprintf(stderr, "init link list failed.\n");
        return -1;
    } head2->next = NULL;

    for (i = 7; i <= 10; ++i) {
        if (insert_link_list(head2, i) != 0) {
            fprintf(stderr, "insert data failed.\n");
            return -1;
        }
    }

    link_list *tail2 = head2; 

    while (tail2->next != NULL) {
        tail2 = tail2->next;
    }

    tail2->next = head->next->next;

    tail2 = find_common_node(head, head2);
    if (tail2 == NULL) {
        fprintf(stderr, "can't find common node or find failed.\n");
        return -1;
    }
    else {
        printf("%d\n", tail2->data);
    }

    while (head != tail2) {
        link_list *tmp = head;
        head = head->next;
        free(tmp);
    }

    while (head2 != tail2) {
        link_list *tmp = head2;
        head2 = head2->next;
        free(tmp);
    }

    while (tail2 != NULL) {
        link_list *tmp = tail2; 
        tail2 = tail2->next; 
        free(tmp);
    }

    return 0;
}

