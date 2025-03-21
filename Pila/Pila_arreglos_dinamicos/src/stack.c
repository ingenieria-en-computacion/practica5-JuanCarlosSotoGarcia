#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack stack_create(int len) {
    Stack s;
    s.data = (Data*)malloc(len * sizeof(Data));
    if (s.data == NULL) {
        s.top = -1;
        return s;
    }
    s.top = -1; 
    return s;
}

void stack_push(Stack* s, Data d) {
    s->top++;
    s->data[s->top] = d;
}

Data stack_pop(Stack* s) {
    if (s->top < 0) {
        return -1;
    }
    Data top_element = s->data[s->top];
    s->top--;
    return top_element;
}

int stack_is_empty(Stack* s) {
    if (s == NULL) {
        return -1; 
    }
    return s->top < 0; 
}

void stack_empty(Stack* s) {
    s->top = -1; 
}

void stack_delete(Stack *s) {
    free(s->data); 
    s->data = NULL; 
    s->top = -1; 
}

void stack_print(Stack *s) {
    if (s == NULL || s->top < 0) {
        printf("La pila está vacía o es inválida.\n");
        return;
    }
    printf("Elementos de la pila (de arriba hacia abajo):\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->data[i]);
    }
}
