#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct t_node
{
    const char* value;
    struct t_node* next;
}Node;

typedef struct t_queue
{
    int size;
    Node* front;
    Node* tail;
}Queue;

Node* getNewNode(const char* value)
{
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

Queue* getNewQueue()
{
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->size = 0;
    queue->front = NULL;
    queue->tail = NULL;
    return queue;
}

void enqueue(Queue* q, Node* n)
{
    if(q->front == NULL) q->front = n;
    else q->tail->next = n;
    q->tail = n;
    q->size++;
}

char* unconstchar(const char* s) {
    int i;
    char* res;
    for (i = 0; s[i] != '\0'; i++) {
        res[i] = s[i];
    }
    res[i] = '\0';
    return res;
}

char* dequeue(Queue* q) {
    if(q->size)
    {
        const char* returnValue;
        Node* aux = q->front;
        returnValue = aux->value;
        q->front = q->front->next;
        free(aux);
        q->size--;  

        char* res = strstr(returnValue, "");
        return res;
    }
}

int main()
{   
    Queue* QUEUE = getNewQueue();
    Node* a = getNewNode("hola");
    Node* b = getNewNode("bebe");
    Node* c = getNewNode("te extraño");
    enqueue(QUEUE, a);
    enqueue(QUEUE, b);
    enqueue(QUEUE, c);;
    printf("%s ", dequeue(QUEUE));
    printf("%s ", dequeue(QUEUE));
    printf("%s ", dequeue(QUEUE));
    free(QUEUE);
    return 0;
}
