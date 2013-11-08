#include <stdio.h> 

typedef struct stack {

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

int main()
{
    int push_q[] = {1, 2, 3, 4, 5 };
    int pop_q[] = {4, 3, 5, 1, 2};

    int len_push = 5; 
    int len_pop = 5;

    stack s; 
    s.top = 0;
    
    int i = 0; 
    int cur_push = 0;
    for (; i < len_pop; ++i) {
        int pop_target = pop_q[i];    

        if (s.top == 0 || s.slot[s.top-1] != pop_target) {
           while(cur_push < len_push) {
               if (push(&s, push_q[cur_push]) != 0) {
                   fprintf(stderr, "push stack failed.\n");
                   return -1;
               }
               if (push_q[cur_push++] == pop_target) {
                   break;
               }
           }
        }
        
        int tmp = 0;
        if (pop(&s, &tmp) != 0) {
            fprintf(stderr, "pop stack failed.\n");
            return -1;
        }
        if (tmp != pop_target) {
            break;
        }
    }

    if (i < len_pop) {
        printf("false\n");
    }
    else {
        printf("true\n");
    }
    
    return 0;
}

