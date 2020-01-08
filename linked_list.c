#include <stdio.h>
#include <stdlib.h>

typedef struct t_node{
    int value;
    struct t_node* next;
}Node;

typedef struct t_list
{
    int size;
    Node* firstItem;
    Node* lastItem;
}LinkedList;

Node* getNode(int value){
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

LinkedList* getNewLinkedList(){
    LinkedList* ll = (LinkedList*) malloc(sizeof(LinkedList));
    ll->size = 0;
    ll->firstItem = NULL;
    ll->lastItem = NULL;
    return ll;
}

// Implementación de las operaciones CRUD
void add(LinkedList* ll, Node* node){
    if(ll->firstItem == NULL) ll->firstItem = node;
    else ll->lastItem->next = node;
    ll->lastItem = node;
    ll->size++;
}

Node* read(LinkedList* ll, unsigned int index){
    if(ll->size){
        Node* listExplorer = ll->firstItem;
        int i = 0;
        while(i++ < index)
            listExplorer = listExplorer->next;
        return listExplorer;
    }
}

void update(LinkedList* ll, unsigned int index, int newValue){
    if(ll->size){
        Node* listExplorer = ll->firstItem;
        int i = 0;
        while(i++ < index)
            listExplorer = listExplorer->next;
        listExplorer->value = newValue;
    }
}

void remove_node(LinkedList* ll, unsigned int index){
    if(ll->size && index < ll->size - 1){
        Node* aux;
        Node* listExplorer = ll->firstItem;
        if(index == 0){
            aux = ll->firstItem;
            ll->firstItem = ll->firstItem->next;
            free(aux);
        } else {
            int i = 0;
            while (i++ < index - 1)
                listExplorer = listExplorer->next;
            aux = listExplorer->next;
            listExplorer->next = listExplorer->next->next;
            free(aux);
        }
    }
}

int main(){
    LinkedList* LIST = getNewLinkedList();
    Node* a = getNode(1);
    Node* b = getNode(2);
    Node* c = getNode(3);
    add(LIST, a);
    add(LIST, b);
    add(LIST, c);
    printf("%d", read(LIST, 1)->value);
    update(LIST, 1, 10);
    printf("\n%d", read(LIST, 1)->value);
    remove_node(LIST, 0);
    printf("\n%d", read(LIST, 0)->value);
    return 0;
}

