#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
   
    int data; 
    
    struct tree *left; 
    struct tree *right; 
}tree;

typedef struct tree_node_list {

    tree *tree_node; 
    struct tree_node_list *next;
}tree_node_list;


tree* init_tree() 
{
    tree *tmp = (tree*)malloc(sizeof(tree));
    if (tmp == NULL) {
        return NULL;
    }

    tmp->data = 0;
    tmp->left = NULL;
    tmp->right = NULL;

    return tmp;
}

tree_node_list* init_tree_node_list() 
{
    tree_node_list *tmp = (tree_node_list*)malloc(sizeof(tree_node_list));
    if (tmp == NULL) {
        return NULL;
    }

    tmp->tree_node = NULL;
    tmp->next = NULL;

    return tmp;
}

int insert_tree(int data, tree_node_list **head, tree_node_list **tail) 
{
    tree *t = (*head)->tree_node; 

    tree *new_node = (tree*)malloc(sizeof(tree));
    if (new_node == NULL) {
        return -1;
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    tree_node_list *new_tail = (tree_node_list*)malloc(sizeof(tree_node_list)); 
    if (new_tail == NULL) {
        return -1;
    }

    if (t->left == NULL) {
        t->left = new_node;  

        new_tail->tree_node = t->left;
        (*tail)->next = new_tail;
        *tail = (*tail)->next;
    }
    else if (t->right == NULL) {
        t->right = new_node; 

        tree_node_list *tmp = *head;
        *head = (*head)->next;
        free(tmp);

        new_tail->tree_node = t->right;
        (*tail)->next = new_tail;
        *tail = (*tail)->next;
    }
    else {
        // head should point to a note where a new data can be inserted.
        free(new_tail);
        return -1;
    }

    return 0; 
}

int print_res(int *res, int res_index)
{
    int i = 0;
    for(; i < res_index-1; ++i) {
        printf("%d-->", res[i]);
    }
    printf("%d\n", res[res_index-1]);
    
    return 0;
}

int find_path(tree *root, const int expect_sum) 
{
    static int res[100] = {0};
    static int sum = 0; 
    static int res_index = 0;
    
    sum += root->data; 
    res[res_index++] = root->data;

    if (sum == expect_sum) {
        print_res(res, res_index);
    }

    if (root->left != NULL) {
        find_path(root->left, expect_sum);
    }

    if (root->right != NULL) {
        find_path(root->right, expect_sum);
    }

    sum -= root->data;
    --res_index;

    return 0;
}

int main()
{
    int inpute_data[] = {10, 5, 12, 4, 7};
    int expect_sum = 22;

    tree_node_list *head = NULL;
    tree_node_list *tail = NULL;
    tree *root = NULL;

    root = init_tree();
    if (root == NULL) {
        perror("init tree failed.");
        return -1;
    }

    head = init_tree_node_list();
    if (head == NULL) {
        fprintf(stderr, "init tree node list failed.");
        return -1;
    }

    root->data = inpute_data[0]; 
    head->tree_node = root; 
    tail = head;
    
    int i = 0; 
    for(i = 1; i < 5; ++i) {
        if (insert_tree(inpute_data[i], &head, &tail) != 0) {
            fprintf(stderr, "insert operation failed.");
            return -1;
        }
    }

    int res[100] = {0};

    find_path(root, expect_sum);

    return 0;    
}

