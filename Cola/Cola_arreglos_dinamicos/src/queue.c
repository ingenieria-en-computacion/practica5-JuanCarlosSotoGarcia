#include "queue.h"
#include <stdlib.h>

Queue queue_create(int len) {
    Queue q;
    q.data = (Data*)malloc(len * sizeof(Data));
    if (q.data == NULL) {
        q.len = 0;  
        return q;
    }
    q.head = -1; 
    q.tail = -1;
    q.len = len;
    return q;
}

void queue_enqueue(Queue* q, Data d) {
    if (q->tail == q->len - 1) {
        return;
    }
    if (q->head == -1) {
        q->head = 0; 
    }
    q->tail++;
    q->data[q->tail] = d;
}

Data queue_dequeue(Queue* q) {
    if (q->head == -1) {
        return -1;
    }
    Data front = q->data[q->head];
    q->head++;
    if (q->head > q->tail) {
        q->head = -1;
        q->tail = -1;
    }
    return front;
}

bool queue_is_empty(Queue* q) {
    return q->head == -1; 

Data queue_front(Queue* q) {
    if (q->head == -1) {
        return -1;
    }
    return q->data[q->head]; 
}

void queue_empty(Queue* q) {
    q->head = -1; 
    q->tail = -1;
}

void queue_delete(Queue* q) {
    free(q->data);
    q->data = NULL;
    q->head = -1;
    q->tail = -1;
    q->len = 0;
}
