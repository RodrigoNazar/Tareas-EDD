#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Trie.h"
#include "sopa.h"

/** Inicializa un nodo de Trie */
Trie* trie_init(int count)
{
	// Creo el nodo
	Trie* tree = malloc(sizeof(Trie));

	// Lo inicializo con contador 1
	tree -> count = count;
	tree -> left = NULL;
	tree -> right = NULL;

	// Retorno el nodo
	return tree;
}

/** Libera el arbol recursivamemte */
void trie_destroy(Trie* trie)
{
  if (trie) {
    trie_destroy(trie->left);
    trie_destroy(trie->right);
    free(trie);
  }
}

/** Inserta un nodo dependiendo si es 0 o 1
  - No busca la ubicación donde ponerlo -*/
void trie_append(Trie* tree, int val)
{

	if (val)
	{
		if (tree -> right == NULL)
		{
	    tree -> right = trie_init(1);
		}
		else if (tree -> right != NULL)
		{
	    tree -> right -> count ++;
	  }
  }
	else
	{
		if (tree -> left == NULL)
		{
	    tree -> left = trie_init(1);
		}
		else if (tree -> left != NULL)
		{
	    tree -> left -> count ++;
	  }
  }

}

/** Inserta los sufijos de una palabra en el trie */
void trie_insert(Trie* tree, uint8_t* palabra, int largo)
{
	Trie* aux = tree;
	tree -> count--;
	// Recorriendo los sufijos de la palabra
	for (int i = largo; 0 <= i; i--)
	{
		// Nuevo sufijo
		tree -> count++;
		aux = tree;
		for (int j = 0; j < largo; j++)
		{

			int indice = (i - j - 1);

			if (indice >= 0)
			{
				indice = largo - indice - 1;

				trie_append(aux, palabra[indice]);

				aux = palabra[indice] ? aux -> right : aux -> left;
			}
		}
	}
}

/** Busca una palabra en el trie y retorna el numero de veces que aparece */
int trie_search(Trie* tree, uint8_t* palabra, int largo)
{
	for (int i = 0; i < largo; i++)
	{
		if (palabra[i])
		{
			if (tree -> right) tree = tree -> right;
			else return 0;
		}

		else
		{
			if (tree -> left) tree = tree -> left;
			else return 0;
		}
	}
	return tree -> count;
}

/** Toma una sopa y pobla el trie con las palabras contenidas en ella */
void trie_poblate(Trie* tree, Sopa* sopa)
{

	int largo = sopa -> height;
	uint8_t* word = malloc(largo * sizeof(uint8_t));

	// Recorriendo por filas
	for (int row = 0; row < sopa -> height; row++)
	{
		for (int col = 0; col < sopa -> width; col++)
		{
			word[col] = sopa -> matrix[row][col];
		}
		trie_insert(tree, word, largo);
	}

	// Recorriendo por columnas
	for (int col = 0; col < sopa -> width; col++)
	{
		for (int row = 0; row < sopa -> height; row++)
		{
			word[row] = sopa -> matrix[row][col];
		}
		trie_insert(tree, word, largo);
	}

	// Diagonales inferiores
	largo = 0;
	int row = sopa -> height - 1;
	int col = 0;
	int aux = row;
	while (0 <= row)
	{
		while (row < sopa -> height  && col < sopa -> width) {
			word[largo] = sopa -> matrix[row][col];
			row++;
			col++;
			largo++;
		}

		trie_insert(tree, word, largo);

		row = aux - 1;
		aux--;
		col = 0;
		largo = 0;
	}

	// Diagonales superiores
	largo = 0;
	row = 0;
	col = sopa -> width - 1;
	aux = col;
	while (0 <= col)
	{
		while (row < sopa -> height  && col < sopa -> width) {
			word[largo] = sopa -> matrix[row][col];
			row++;
			col++;
			largo++;
		}

		trie_insert(tree, word, largo);

		col = aux - 1;
		aux--;
		row = 0;
		largo = 0;
		// Para no tomar la diagonal central 2 veces
		if (col == row) break;
	}

	free(word);
}

/* Imprime los hijos de la izquierda */
void trie_print_left(Trie* tree)
{
  if (tree)
  {
    printf("Left count: %d\n", tree -> count);
    trie_print_left(tree -> left);
  }
}

/* Imprime los hijos de la derecha */
void trie_print_right(Trie* tree)
{
  if (tree)
  {
    printf("Right count: %d\n", tree -> count);
    trie_print_right(tree -> right);
  }
}
