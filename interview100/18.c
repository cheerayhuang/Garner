#include <stdio.h> 

typedef struct stack {
    int top; 
    int slot[100];
}stack;


typedef struct queue {
    stack in_queue; 
    stack out_queue;
}queue;

int push_stack(stack *s, int data) {

    if (s == NULL) {
        return -1;
    }

    if (s->top == 100) {
        return -1;
    }
    s->slot[s->top++] = data;

    return 0;
}

int push_queue(queue *q, int data)  {

    if (q == NULL) {
        return -1;
    }

    if (q->in_queue.top < 100) {
        if (push_stack(&(q->in_queue), data) != 0) {
            return -1;
        }
    }
    else if (q->out_queue.top == 0) {
       
        int tmp = 0; 

        while (q->in_queue.top) {
            if (pop_stack(&(q->in_queue), &tmp) != 0) {
                return -1;
            }

            if (push_stack(&(q->out_queue), tmp) != 0) {
            }
        }

        if (push_stack(&(q->in_queue), data) != 0) {
            return -1;
        }
    }
    else {
        return -1;
    }

    return 0;
}

int pop_stack(stack *s, int *data) {

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

int pop_queue(queue *q, int *data) {

    if (q == NULL) {
        return 0; 
    }

    if (q->out_queue.top > 0) {
       if (pop_stack(&(q->out_queue), data) != 0) {
           return -1;
       }
    }
    else if (q->in_queue.top > 0) {
        int tmp = 0;
        while (q->in_queue.top) {
           if (pop_stack(&(q->in_queue), &tmp) != 0) {
               return -1;
           }

           if (push_stack(&(q->out_queue), tmp) != 0) {
               return -1;
           }
        }

        if (pop_stack(&(q->out_queue), data) != 0) {
            return -1;
        }
    }
    else {
        return -1;
    }

    return 0;
}

int main() {

    queue q; 

    q.in_queue.top = 0;
    q.out_queue.top = 0;

    int i = 0; 

    for (i = 1; i < 100; ++i) {
       if (push_queue(&q, i) != 0) {
           fprintf(stderr, "push queue failed.\n");
           return -1;
       }
    }

    for (i = 0; i < 100; ++i) {
        int tmp = 0;
        if (pop_queue(&q, &tmp) != 0) {
            fprintf(stderr, "pop queue failed.\n");
            return -1;
        }
        printf ("%d ", tmp);
    }

    printf("\n");

    return 0;
}

