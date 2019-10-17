#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sopa.h"
#include "Trie.h"

void prueba_diagonal(int height, int width) {

	// Cargo la sopa desde la imagen
	Sopa* sopa = sopa_init(height, width);

	printf("\n\nNueva prueba con:\nAlto: %i\tAncho: %i\n", sopa -> height, sopa -> width);

	printf("\n");

	for (int row = 0; row < sopa -> height; row++)
  {
    for (int col = 0; col < sopa -> width; col++)
    {
			// printf("%i, ", sopa -> matrix[row][col]);
			printf("(%i, %i) ", row, col);
    }
		printf("\n");
  }

	printf("\n");


	printf("\nDiagonales inferiores\n");

	// Diagonales inferiores
	int largo = 0;
	int row = sopa -> height - 1;
	int col = 0;
	int aux = row;
	while (0 <= row)
	{
		while (row < sopa -> height  && col < sopa -> width) {
			printf("(%i, %i) ", row, col);
			// word[largo] = sopa -> matrix[row][col];
			row++;
			col++;
			largo++;
		}

		row = aux - 1;
		aux--;
		col = 0;
		largo = 0;
	}

	printf("\nDiagonales superiores\n");

	// Diagonales superiores
	largo = 0;
	row = 0;
	col = sopa -> width - 1;
	aux = col;
	while (0 <= col)
	{
		while (row < sopa -> height  && col < sopa -> width) {
			printf("(%i, %i) ", row, col);
			// word[largo] = sopa -> matrix[row][col];
			row++;
			col++;
			largo++;
		}

		col = aux - 1;
		aux--;
		row = 0;
		largo = 0;
		// Para no tomar la diagonal central 2 veces
		if (col == row) break;
	}

	// Libero la sopa
	sopa_destroy(sopa);
}

/** Metodo main del programa */
int main(int argc, char *argv[])
{

	prueba_diagonal(4, 8);

	prueba_diagonal(8, 4);

	// Retornar 0 significa que el programa termina sin errores
	return 0;
}
