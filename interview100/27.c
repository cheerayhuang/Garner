#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int data;
    struct tree *left;
    struct tree *right;
}tree;

tree *init_tree() {

    tree* new_node = NULL;
    new_node = (tree*)malloc(sizeof(tree));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->data = 0; 
    new_node->left = new_node->right = NULL;

    return new_node;
}

int insert_tree(tree *root, int data) {

    if (root == NULL) {
        return -1;
    }

    if (data < root->data) {
        if (root->left == NULL) {
            tree *new_node = init_tree();
            if (new_node == NULL) {
                return -1;
            }
            new_node->data = data;
            root->left = new_node;
        }
        else {
            return insert_tree(root->left, data);
        }
    }
    else if (data >= root->data) {
        if (root->right == NULL) {
            tree *new_node = init_tree();
            if (new_node == NULL) {
                return -1;
            }
            new_node->data = data;
            root->right = new_node;
        }
        else {
            return insert_tree(root->right, data);
        }
    }

    return 0;
}

int compute_depth(tree *root, int depth, int* max) {

    if (root == NULL) {
        return -1;
    }

    if (depth > *max) {
        *max = depth;
    }

    if (root->left != NULL) {
        compute_depth(root->left, depth+1, max);
    }

    if (root->right != NULL) {
        compute_depth(root->right, depth+1, max);
    }

    return 0;
}

int main()
{
    int inpute_data[] = {10, 6, 14, 4, 12, 16};
    tree *root = NULL;
    root = init_tree();
    if (root == NULL) {
        fprintf(stderr, "init tree failed.\n");
        return -1;
    }
    root->data = inpute_data[0];

    int i = 1;
    for (; i < 6; ++i) {
        if (insert_tree(root, inpute_data[i]) != 0) {
            fprintf(stderr, "insert tree failed.\n");
            return -1;
        }
    }
    
    int depth = 1;
    compute_depth(root, 1, &depth);

    printf("depth = %d\n", depth);
    
    return 0;
}

