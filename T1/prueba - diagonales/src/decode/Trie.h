#pragma once
#include <stdint.h>
#include "sopa.h"

/** Arbol Trie */
typedef struct trie
{
	/** Altura del arbol */
	int count;
	/** Hijo izquierdo
      Representa los 0's */
	struct trie* left;
	/** Hijo derecho
      Representa los 1's */
	struct trie* right;
} Trie;

/** Inicializa un nodo de AVL dado su key, value */
Trie* trie_init(int count);

/** Inserta un nodo dependiendo si es 0 o 1
  - No busca la ubicación donde ponerlo -*/
void trie_append(Trie* tree, int val);

/** Inserta los sufijos de una palabra en el trie */
void trie_insert(Trie* tree, uint8_t* palabra, int largo);

/** Busca una palabra en el trie y retorna el numero de veces que aparece */
int trie_search(Trie* tree, uint8_t* palabra, int largo);

/** Toma una sopa y pobla el trie con las palabras contenidas en ella */
void trie_poblate(Trie* tree, Sopa* sopa);

/* Imprime los hijos de la izquierda */
void trie_print_left(Trie* tree);

/* Imprime los hijos de la derecha */
void trie_print_right(Trie* tree);

/** Libera el arbol recursivamemte */
void trie_destroy(Trie* trie);
