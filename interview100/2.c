#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct stack_node {

    int data; 
    struct stack_node *next;
}stack_node;

typedef struct stack {
    struct stack_node *top; 
    int count;
    int min; 
}stack;

static stack *accessory_stack = NULL; 

stack* init_stack() 
{
   stack *s = (stack*)malloc(sizeof(stack)); 
   if (s == NULL) {
       return NULL;
   }
    
   s->count = 0;
   s->top = NULL;
   s->min = INT_MAX;
}

int push_stack(stack *s, int d) 
{
    if (s == NULL) {
        return -1;
    }

    stack_node *node = (stack_node*)malloc(sizeof(stack_node));
    if (node == NULL) {
        return -1;
    }

    node->data = d;
    node->next = s->top; 
    s->top = node; 
    s->count++;
    
    if (d < s->min) {
        stack_node* tmp = (stack_node*)malloc(sizeof(stack_node));
        if (tmp == NULL) {
            return -1;
        }
        tmp->data = d; 
        tmp->next = accessory_stack->top; 
        accessory_stack->top = tmp; 
        accessory_stack->count++;
    
        s->min = d;
    }

    return 0;
}

stack_node* get_top(stack *s) 
{
    if (s == NULL) {
        return NULL;
    }

    return s->top;
}

int pop_stack(stack *s, int *d) 
{
    if (s == NULL || s->count == 0) {
        return -1;
    }

    stack_node *tmp = s->top;

    if (d == NULL) {
        return -1;
    }

    *d = s->top->data;
    s->top = s->top->next;
    s->count--; 

    free(tmp); 
    
    if (*d == s->min) {
        tmp = accessory_stack->top; 
        accessory_stack->top = accessory_stack->top->next;
        accessory_stack->count--; 
        free(tmp);

        if (accessory_stack->count != 0) {
            s->min = get_top(accessory_stack)->data;
        }
        else {
            s->min = INT_MAX;
        }
    }
    
    return 0;
}

int release_stack(stack *s) 
{
    if (s == NULL) {
        return -1;
    }

    stack_node* node = s->top; 

    while (node != NULL) {
        stack_node* tmp = node;
        node = node->next; 
        free(tmp);
    }

    free(s);

    return 0;
}

int main()
{
    stack *main_stack = NULL; 

    int input_data[] = {3, 1, 4, 7, 5, 6, 0,2, -1};

    main_stack = init_stack();
    if (main_stack == NULL) {
        perror("init stack failed.\n");
        return -1;
    }

    accessory_stack = init_stack(); 
    if (accessory_stack == NULL) {
        perror("init stack failed.\n");
        return -1;
    }

    int i;
    for (i = 0;  i < 9; ++i) {

        if (push_stack(main_stack, input_data[i]) != 0) {
            perror("push operation failed.\n");
            return -1;
        }
        printf("stack count = %d, min = %d\n", main_stack->count, main_stack->min);
    }

    for (i = 0; i < 9; ++i) {

        int data; 
        if (pop_stack(main_stack, &data) != 0) {
            perror("pop operation failed.\n");
            return -1;
        }

        printf("pop %d, stack count = %d, min = %d\n", 
                data, main_stack->count, main_stack->min);
    }

    if (release_stack(main_stack) != 0) {
        perror("release stack failed.\n");
        return -1;
    }

    if (release_stack(accessory_stack) != 0) {
        perror("release stack failed.\n");
        return -1;
    }

    return 0;
}

