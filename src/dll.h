/** @file dll.h
 * @brief Definições e funções necessárias para uma Double Link List(DLL) 
 *
 * Este ficheiro contém estruturas de dados e declarações das funções necessárias
 * para a implementação de uma DLL, que permitem fazer
 * inserção, remoção e busca de nós.
 * 
 * 
 * @authors Luís Araújo, Bernardo Modesto
 * @date 12 Mar 2024
 */


#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdint.h>
#include <stdbool.h>


#define MAX_ELEMENTS 100
#define ELEMENT_SIZE 256
#define OK 0
#define DLL_FULL -1
#define NO_EMPTY_NODE -2
#define KEY_NOT_FOUND -3


/**
 * @struct DLLNode
 * @brief Estrutura de um nó na DLL
 *
 * A estrutura representa um nó individual na lista.
 * Os parâmetros da estrutura que definem o nó são a chave(key), 
 * os dados e ponteiros para o nó anterior e seguinte na lista.
 */
typedef struct DLLNode {
    uint16_t key; /**< Chave do nó. */
    unsigned char data[ELEMENT_SIZE]; /**< Dados armazenados no nó. */
    struct DLLNode* next; /**< Ponteiro para o proximo nó. */
    struct DLLNode* prev; /**< Ponteiro para o nó anterior. */
    bool usingIt;
} DLLNode;

/**
 * @struct DoublyLinkedList
 * @brief Estrutura para DLL
 *
 * A estrutura seguint representa a DLL.
 * Os parâmetros são um array estático de nós,
 * o tamanho atual da lista e ponteiros para o primeiro e último nó.
 */
typedef struct {
    DLLNode nodes[MAX_ELEMENTS]; /***< Array estatico de nos */
    int size; /***<  Numero atual de nós na DLL */
    DLLNode* head; /***<  Ponteiro para o primeiro nó da lista */
    DLLNode* tail; /***<  Ponteiro para o ultimo nó da lista */
} DoublyLinkedList;

// Funções da DLL

/**
 * @brief Inicializa a DLL.
 *
 * Configuração para o estado inicial da DLL, com tamanho 0
 * e sem elementos.
 *
 * @param dll Ponteiro para a DLL a ser inicializada.
 */
void MyDLLInit(DoublyLinkedList* dll, int maxElements, int elementSize);

/**
 * @brief Insere um novo elemento na lista.
 *
 * Insere um elemento com a respetiva chave e os dados especificados na lista, mantendo
 * a ordem dos elementos.
 *
 * @param dll Ponteiro para a lista.
 * @param id Chave do novo elemento.
 * @param data Ponteiro para os dados do novo elemento.
 * @param dataSize Tamanho dos dados.
 * @return int Retorna 0 se a inserção for bem-sucedida, caso contrário retorna um código de erro.
 */
int MyDLLInsert(DoublyLinkedList* dll, uint16_t id, unsigned char* data, int dataSize);

/**
 * @brief Remove um elemento da lista.
 *
 * Remove o elemento com a respetiva chave da lista, se presente.
 *
 * @param dll Ponteiro para a lista.
 * @param id Chave do elemento a ser removido.
 * @return int Retorna 0 se a remoção for bem-sucedida, caso contrário retorna um código de erro.
 */
int MyDLLRemove(DoublyLinkedList* dll, uint16_t id);

/**
 * @brief Encontra um elemento na lista.
 *
 * Encontra na lista o elemento com a chave especifica e retorna um ponteiro
 * para os seus dados.
 *
 * @param dll Ponteiro para a lista.
 * @param id Chave do elemento a ser encontrado.
 * @return unsigned char* Retorna um ponteiro para os dados do elemento encontrado, ou NULL se não encontrado.
 */
unsigned char* MyDLLFind(DoublyLinkedList* dll, uint16_t id);

/**
 * @brief Encontra o próximo elemento na DLL a partir de um dado ID.
 * 
 *  A função inicia a procura pelo elemento atual utilizando o ID fornecido. Se o elemento atual
 * for encontrado, a função verifica se existe um próximo elemento na lista. Caso exista,
 * a função retorna os dados associados a esse próximo elemento. No caso do elemento atual
 * ser o último da lista ou o ID fornecido não corresponder a nenhum elemento na lista, a função
 * retorna NULL.
 *
 * @param dll Ponteiro para a DLL.
 * @param currentId O ID do elemento atual a partir do qual o próximo elemento será encontrado.
 * @return Ponteiro para os dados do próximo elemento, se encontrado; NULL caso contrário.
 * 
 */
unsigned char* MyDLLFindNext(DoublyLinkedList* dll, uint16_t currentId);

/**
 * @brief Encontra o elemento anterior na DLL a partir de um dado ID.
 * 
 * A função procura pelo elemento atual utilizando o ID fornecido. Se o elemento atual 
 * for encontrado, a função verifica se existe um elemento anterior na lista. Caso exista,
 * a função retorna os dados associados a esse elemento anterior. No caso do elemento atual
 * ser o primeiro da lista ou o ID fornecido não corresponder a nenhum elemento na lista, a função 
 * retorna NULL.
 * 
 * @param dll Ponteiro para a DLL.
 * @param currentId O ID do elemento atual a partir do qual o elemento anterior será encontrado.
 * @return Ponteiro para os dados do elemento anterior, se encontrado; NULL caso contrário.
 * 
 */
unsigned char* MyDLLFindPrevious(DoublyLinkedList* dll, uint16_t currentId);

#endif 
