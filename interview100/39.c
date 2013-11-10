#include <stdio.h> 

typedef struct stack{

    int top; 
    int slot[100];
}stack;

int push(stack *s, int data) {

    if (s == NULL) {
        return -1;
    }

    if (s->top == 100) {
        return -1;
    }

    s->slot[s->top++] = data;

    return 0;
}

int pop(stack *s, int *data) {

    if (s == NULL) {
        return -1;
    }

    if (s->top == 0) {
        return -1;
    }

    --s->top; 
    if (data != NULL) {
        *data = s->slot[s->top];
    }

    return 0;
}

int top_to_bottom(stack *s, int bottom) {

    if (s == NULL) {
        return -1;
    }

    if (s->top == 0) {
        push(s, bottom);
        return 0;
    }

    int t = 0; 
    if (pop(s, &t) != 0) {
        return -1;
    }

    if (top_to_bottom(s, bottom) != 0) {
        return -1;
    }

    if (push(s, t) != 0) {
        return -1;
    }
    
    return 0;
}

int reverse(stack *s) {

    if (s->top == 0) {
        return 0;
    }

    int t = 0; 
    if (pop(s, &t) != 0) {
        return -1;
    }

    if (reverse(s) != 0) {
        return -1;
    }
    
    if (top_to_bottom(s, t) != 0) {
        return -1;
    }

    return 0;
}

int main(void) {

    stack s; 
    s.top = 0;

    int i = 0;
    for (i = 1; i <= 5; ++i) {
        if (push(&s, i) != 0) {
            fprintf(stderr, "push failed.\n"); 
            return -1;
        }
    }

    if (reverse(&s) != 0) {
        fprintf(stderr, "reverse failed.\n");
        return -1;
    }

    for (i = 0; i < 5; ++i) {
        int tmp = 0; 
        if (pop(&s, &tmp) != 0) {
            fprintf(stderr, "pop failed.\n");
            return -1;
        }
        printf("%d ", tmp);
    }
    
    return 0;
}

