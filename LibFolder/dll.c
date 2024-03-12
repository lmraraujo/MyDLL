/*dll.c file:
            Autores: João Modesto, Luís Araújo  
            */

/////includes/////
#include<stdlib.h>
#include<stdio.h>
#include "dll.h"
/////////////////

///////////////////////////////////////////////////////////////////////////////
////////////////////////////MyDLLInit function begin///////////////////////////
///////////////////////////////////////////////////////////////////////////////
void MyDLLInit(DoublyLinkedList* dll, int maxElements, int elementSize) {
    
    dll->size = 0;                      // Inicializar o tamanho atual da lista como 0
    dll->head = NULL;                   // Inicializar a head da lista como NULL
    dll->tail = NULL;                   // Inicializar a tail da lista como NULL

    //////////////////////////////////////////////////////////////////////////                            
                                        // Ciclo para inicializar cada nó na lista
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        dll->nodes[i].next = NULL;
        dll->nodes[i].prev = NULL;
        dll->nodes[i].usingIt = false;   // Marcar o nó como não utilizado
    }
}
///////////////////////////////////////////////////////////////////////////////
////////////////////////////MyDLLInit function end/////////////////////////////
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
////////////////////////////MyDLLInsert function begin/////////////////////////
///////////////////////////////////////////////////////////////////////////////
int MyDLLInsert(DoublyLinkedList* dll, uint16_t id, unsigned char* data, int dataSize) {
    if (dll->size >= MAX_ELEMENTS) {
        printf("The list is full!\n");
        return DLL_FULL;                      // Código de erro, lista cheia
    }

    DLLNode* newNode = NULL;
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (!dll->nodes[i].usingIt) {   // Procurar um nó não utilizado
            newNode = &dll->nodes[i];
            break;                      // Salta do loop se o nó vazio é encontrado
        }
    }

    if (newNode == NULL) {
        printf("No empty node found!\n");
        return NO_EMPTY_NODE;                      // Código de erro, todos os nós estão a ser utilizados
    }

    newNode->key = id;
    int copySize = (dataSize > ELEMENT_SIZE) ? ELEMENT_SIZE : dataSize;
    for (int i = 0; i < copySize; i++) {
        newNode->data[i] = data[i];
    }
    newNode->usingIt = true;            // Marcar o nó como utilizado

    newNode->prev = dll->tail;
    newNode->next = NULL;
    if (dll->tail != NULL) {
        dll->tail->next = newNode;
    }
    dll->tail = newNode;
    if (dll->head == NULL) {
        dll->head = newNode;
    }

    dll->size++;
    return OK;                           // Insert com sucesso
}
///////////////////////////////////////////////////////////////////////////////
////////////////////////////MyDLLInsert function end///////////////////////////
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
////////////////////////////MyDLLRemove function begin/////////////////////////
///////////////////////////////////////////////////////////////////////////////
int MyDLLRemove(DoublyLinkedList* dll, uint16_t id) {
    DLLNode* current = dll->head;
    while (current != NULL && current->key != id) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Element with key %d not found\n", id);
        return KEY_NOT_FOUND;                      // Key não encontrada, retorna código de erro
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        dll->head = current->next;      // Atualiza a Head da lista 
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    } else {
        dll->tail = current->prev;      // Atualiza a Tail da lista 
    }

    
    current->usingIt = false;           // Marca o nó como não utilizado

    dll->size--;                        // Atualiza o tamanho atual da lista
    return OK;                           // Remove com sucesso
}
///////////////////////////////////////////////////////////////////////////////
////////////////////////////MyDLLRemove function end///////////////////////////
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
////////////////////////////MyDLLFind function begin///////////////////////////
///////////////////////////////////////////////////////////////////////////////
unsigned char* MyDLLFind(DoublyLinkedList* dll, uint16_t id) {

    DLLNode* current = dll->head;       // Inicializa current como sendo o nó atual

    while (current != NULL && current->key != id) {
        current = current->next;        // Corre o ciclo até encontrar um nó com uma key == id
    }

    if (current == NULL) {
        printf("Element with key %d not found\n", id);
        return NULL;                    // Key não encontrada após o ciclo, retorna NULL
    }

    return current->data;               // Retorna os dados do nó encontrado
}
///////////////////////////////////////////////////////////////////////////////
////////////////////////////MyDLLFind function end/////////////////////////////
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
////////////////////////////MyDLLFindNext function begin///////////////////////
///////////////////////////////////////////////////////////////////////////////
unsigned char* MyDLLFindNext(DoublyLinkedList* dll, uint16_t currentId) {
    
    if (dll->size == 0) {               // Verifica se a lista está vazia, se estiver retorna NULL
        return NULL;
    }

    DLLNode* currentNode = dll->head;
    while (currentNode != NULL) {
        if (currentNode->key == currentId) {
            break;                      // Procura o nó com o id atual
        }
        currentNode = currentNode->next;
    }

    if (currentNode == NULL) {
        return NULL;                    // Se o nó com o id atual não foi encontrado, retorna NULL
    }

    if (currentNode->next == NULL) {
        return NULL;                    // Se o nó atual é o último, retorna NULL
    }

    return currentNode->next->data;     // Retorna os dados do próximo nó
}
///////////////////////////////////////////////////////////////////////////////
////////////////////////////MyDLLFindNext function end/////////////////////////
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/////////////////////////MyDLLFindPrevious function begin//////////////////////
///////////////////////////////////////////////////////////////////////////////
unsigned char* MyDLLFindPrevious(DoublyLinkedList* dll, uint16_t currentId) {
    
    if (dll->size == 0) {
        return NULL;                    // Verifica se a lista está vazia, se estiver retorna NULL
    }

    DLLNode* currentNode = dll->head;
    while (currentNode != NULL) {
        if (currentNode->key == currentId) {
            break;                      // Procura o nó com o id atual, se encontrar  sai do ciclo
        }
        currentNode = currentNode->next;
    }

    
    if (currentNode == NULL) {
        return NULL;                    // Se o nó com o id atual não foi encontrado, retorna NULL
    }

    
    if (currentNode->prev == NULL) {
        return NULL;                    // Se o nó atual é o primeiro nó, retorna NULL
    }

    
    return currentNode->prev->data;     // Retorna os dados do nó anterior
}
///////////////////////////////////////////////////////////////////////////////
/////////////////////////MyDLLFindPrevious function end////////////////////////
///////////////////////////////////////////////////////////////////////////////
