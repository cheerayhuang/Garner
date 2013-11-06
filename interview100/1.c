#include <stdio.h> 
#include <stdlib.h>

typedef struct tree {

    int data;

    union {
        struct tree *left; 
        struct tree *p; 

    }prev;

    union {
        struct tree *right;
        struct tree *n;
    }next;

}tree;

inline tree * new_node(int data)
{
    tree *t = (tree*)malloc(sizeof(tree));
    if (t == NULL) {
        return NULL;
    }
    
    t->data = data; 
    t->prev.left = NULL;
    t->next.right = NULL;

    return t;
    
}

tree* init_tree(int *data)
{
    tree *tmp_tree = NULL;
    tree *res_tree = NULL;
    tree *parent = NULL;
    int i = 1; 

    tmp_tree = (tree*)malloc(sizeof(tree)); 
    if (tmp_tree == NULL) {
        return NULL;
    }

    tmp_tree->data = data[0];
    tmp_tree->prev.left = NULL;
    tmp_tree->next.right = NULL;

    res_tree = tmp_tree;

    while (data[i] != -1) {
        
        while(tmp_tree) {

            if (data[i] >= tmp_tree->data) {
                 if (tmp_tree->next.right == NULL) {

                    tree *t = new_node(data[i]);
                    if (t == NULL) {
                        return NULL;
                    }
                              
                    tmp_tree->next.right = t;
                    break;
                }        
                tmp_tree = tmp_tree->next.right;
            }
            else {
                if (tmp_tree->prev.left == NULL) {
                    
                    tree* t = new_node(data[i]);
                    if (t == NULL) {
                        return NULL;
                    }

                    tmp_tree->prev.left = t;
                    break;
                }
                tmp_tree = tmp_tree->prev.left;
            }

        }

        tmp_tree = (tree *)malloc(sizeof(tree));
        tmp_tree->data = data[i]; 
        tmp_tree->next.right = NULL;
        tmp_tree->prev.left = NULL;

        tmp_tree = res_tree;

        ++i; 
    }

    return res_tree;
}

int transform_tree_to_linklist(tree *t, tree** beg_node, tree** end_node) 
{
    tree *left_beg = NULL;
    tree *left_end = NULL;
    tree *right_beg = NULL;
    tree *right_end = NULL;
        
    if (t->prev.left != NULL) {
        transform_tree_to_linklist(t->prev.left, &left_beg, &left_end);
    }

    if (t->next.right != NULL) {
        transform_tree_to_linklist(t->next.right, &right_beg, &right_end);
    }

    *beg_node = t; 
    *end_node = t; 

    if (left_beg != NULL) {
        *beg_node = left_beg;
    }
    if (right_end != NULL) {
        *end_node = right_end;
    }

    if (left_end != NULL) {
        left_end->next.n = t; 
    }
    t->prev.p = left_end; 
    
    if (right_beg != NULL) {
       right_beg->prev.p = t; 
    }
    t->next.n = right_beg;

    return 0;
}

int print_linklist(tree* beg_node, tree* end_node)
{
    tree *tmp = beg_node; 

    while (tmp != NULL) {

        printf("%d ", tmp->data);
        tmp = tmp->next.n;
    }

    printf("\n");

    return 0;
}

int release_tree(tree *beg_node, tree* end_node) 
{
    tree *tmp = beg_node; 
    
    while (tmp != NULL) {
        tree *t = tmp;
        tmp = tmp->next.n;
        free(t); 
    }

    return 0;
}

int main()
{
    tree *t = NULL;
    tree *beg_node = NULL;
    tree *end_node = NULL;

    int input_data[] = {10, 6, 14, 4, 8, 12, 16, -1};
    int input_data2[] = {3, 2, 1, 5, 4, 6, 7, 8, 9, 10, 11, -1};

    t = init_tree(input_data2); 
    if (t == NULL) {
        perror("malloc failed.\n");
        return -1;
    }

    if (transform_tree_to_linklist(t, &beg_node, &end_node) == 0) {
        print_linklist(beg_node, end_node);
    }
    else {
        perror("transform tree to linklist failed.\n");
        return -1;
    }

    if (release_tree(beg_node, end_node) != 0) {
        perror("free memory failed.\n");
        return -1;
    }

    return 0;
}

