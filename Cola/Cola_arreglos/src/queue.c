#include "queue.h"
#include <stdlib.h>

Queue queue_create() {
    Queue q;
    q.head = -1;
    q.tail = -1;
    q.len = 0; 
    return q;
}

void queue_enqueue(Queue* q, Data d) {
    if (q->len == TAM) {
        return;
    }
    if (q->head == -1) {
        q->head = 0; 
    }
    q->tail++;
    q->datos[q->tail] = d;
    q->len++;
}

Data queue_dequeue(Queue* q) {
    if (q->head == -1) {
        return -1;
    }
    Data front = q->datos[q->head];
    q->head++;
    q->len--;

    if (q->head > q->tail) {
        q->head = -1;
        q->tail = -1;
    }
    return front;
}

bool queue_is_empty(Queue* q) {
    return q->head == -1; 
}

Data queue_front(Queue* q) {
    if (q->head == -1) {
        return -1;
    }
    return q->datos[q->head];
}

void queue_empty(Queue* q) {
    q->head = -1; 
    q->tail = -1;
    q->len = 0; 
}

void queue_delete(Queue* q) {
  
}
