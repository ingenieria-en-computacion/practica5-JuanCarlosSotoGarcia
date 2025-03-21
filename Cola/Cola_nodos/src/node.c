#include "node.h"
#include <stdio.h>
#include <stdlib.h>

Node *new_node(Data d) {
    Node* n = (Node*)malloc(sizeof(Node));
    if (n == NULL) {
        return NULL;
    }
    n->data = d;
    n->next = NULL;
    return n;
}

void delete_node(Node* n) {
    if (n == NULL) {
        return;
    }
    free(n);
}

void print_node(Node* n) {
    if (n == NULL) {
        printf("Nodo inválido.\n");
        return;
    }
    printf("Dato: %d\n", n->data);
    if (n->next != NULL) {
        printf("Siguiente nodo: %p\n", (void*)n->next);
    } else {
        printf("Siguiente nodo: NULL\n");
    }
}
