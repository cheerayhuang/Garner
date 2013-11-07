#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int data;

    struct tree *left; 
    struct tree *right;
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


int postorder_tree(tree *root, int *res, int *index) 
{
    //static int index = 0; 
    //static int res[100] = {0};

    if (root == NULL) {
        return -1;
    }

    if (root->left != NULL) {
        postorder_tree(root->left, res, index);
    }

    if (root->right != NULL) {
        postorder_tree(root->right, res, index);
    }

    res[(*index)++] = root->data;


    return 0;
}

int main()
{
    tree *root = NULL;
    int inpute_data[7] = {8, 6, 10, 9, 11, 5, 7};
    int i = 0; 

    for (i = 0; i < 7; ++i) {
        if (insert_tree(&root, inpute_data[i]) != 0) {
            fprintf(stdout, "insert tree failed.\n");
            return -1;
        }
    }
    
    int count = 0;
    int post_order[100] = {0};
    i = postorder_tree(root, post_order, &count); 
    if (i != 0) {
        fprintf(stderr, "postorder iterate failed.\n");
        return -1;
    }

    for(i = 0; i < count; ++i) {
        printf("%d ", post_order[i]);
    }
    printf("\n");

    int inpute_order[100] = {0};

    FILE *fin = fopen("6.in", "r");
    if (fin == NULL) {
        fprintf(stderr, "open 6.in file failed.\n");
        return -1;
    }

    int tmp = 0;
    i = 0;
    while(fscanf(fin, "%d", &tmp) != EOF) {

        if (tmp != post_order[i++]) {
            printf("false\n");
            fclose(fin);

            return 0;
        }
    }

    if (i == 7) {
        printf("true\n");
    }
    else {
        printf("false\n");
    }

    fclose(fin);
    return 0;
}
