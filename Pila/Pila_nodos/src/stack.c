#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack *stack_create() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    if (s == NULL) {
        return NULL; 
    }
    s->top = NULL; 
    return s;
}

void stack_push(Stack* s, Data d) {
    if (s == NULL) {
        return; 
    }
    Node* new_node = new_node(d); 
    if (new_node == NULL) {
        return; 
    }
    new_node->next = s->top; 
    s->top = new_node; 
}

Data stack_pop(Stack* s) {
    if (s == NULL || s->top == NULL) {
        return -1; 
    }
    Node* temp = s->top; 
    Data top_data = temp->data; 
    s->top = s->top->next; 
    delete_node(temp); 
    return top_data; 
}

int stack_is_empty(Stack* s) {
    if (s == NULL) {
        return -1; 
    }
    return s->top == NULL; 
}

void stack_empty(Stack* s) {
    if (s == NULL) {
        return; 
    }
    while (s->top != NULL) {
        stack_pop(s); 
    }
}

void stack_delete(Stack *s) {
    if (s == NULL) {
        return;
    }
    stack_empty(s); 
    free(s); 
}

void stack_print(Stack *s) {
    if (s == NULL || s->top == NULL) {
        printf("La pila está vacía o es inválida.\n");
        return;
    }
    printf("Elementos de la pila (de arriba hacia abajo):\n");
    Node* current = s->top;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next; 
    }
}
