#include <stdio.h> 
#include <stdlib.h>

typedef struct tree {
    int data; 
    
    struct tree* left; 
    struct tree* right;
}tree;

int insert_tree(tree **root, int data) 
{
    if (*root == NULL) {
        tree *new_node = (tree*)malloc(sizeof(tree));
        if (new_node == NULL) {
            return -1;
        }

        new_node->data = data; 
        new_node->left = NULL;
        new_node->right = NULL;

        *root = new_node; 
        return 0;
    }

    if (data < (*root)->data) {
        insert_tree(&((*root)->left), data);
    }
    else {
        insert_tree(&((*root)->right), data);
    }

    return 0;
}

int reflex_tree(tree *root) {

    tree *tmp = NULL; 

    if (root == NULL) {
        return -1;
    }

    tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    if (root->left != NULL) {
        reflex_tree(root->left);
    }

    if (root->right != NULL) {
        reflex_tree(root->right);
    }

    
    return 0;
}

int layerorder_tree(tree *root) {

    typedef struct tree_node_link {
        tree *node; 
        struct tree_node_link* next; 
    }tree_node_link;

    tree_node_link *head = (tree_node_link*)malloc(sizeof(tree_node_link));
    if (head == NULL) {
        return -1;
    }

    head->node = root; 
    head->next = NULL;
    
    tree_node_link *tail = head;

    while (head != NULL) {
        printf("%d ", head->node->data);

        if (head->node->left != NULL) {
            tree_node_link *new_node = (tree_node_link*)malloc(sizeof(tree_node_link));
            if (new_node == NULL) {
                return -1;
            }
            
            new_node->node = head->node->left;
            new_node->next = NULL;

            tail->next = new_node;
            tail = tail->next;
        }

        if (head->node->right != NULL) {
            tree_node_link *new_node = (tree_node_link*)malloc(sizeof(tree_node_link));
            if (new_node == NULL) {
                return -1;
            }
            
            new_node->node = head->node->right;
            new_node->next = NULL;

            tail->next = new_node;
            tail = tail->next;
        }
        tree_node_link *tmp_for_free =head; 
        head = head->next;
        free(tmp_for_free);
    }

    printf("\n");
    
    return 0;
}

int release_tree(tree *root)  {
    
    if (root == NULL) {
        return -1;
    }

    if (root->left != NULL) {
        release_tree(root->left);
    }

    if (root->right != NULL) {
        release_tree(root->right);
    }

    free(root);
    return 0;
}

int main()
{
    tree *root = NULL;
    int input_data[7] = {8, 6, 10, 5, 7, 9, 11};
    int i = 0; 

    for (i = 0; i < 7; ++i) {
        if (insert_tree(&root, input_data[i]) != 0) {
            fprintf(stdout, "insert tree failed.\n");
            return -1;
        }
    }

    if (reflex_tree(root) != 0) {
        fprintf(stderr, "reflex tree failed.\n");
        return -1;
    }

    if (layerorder_tree(root) != 0) {
        fprintf(stderr, "layerorder tree failed.\n");
        return -1;
    }

    release_tree(root);

    return 0;
}

