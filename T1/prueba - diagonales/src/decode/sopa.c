#include <stdlib.h>
#include "sopa.h"
#include "../imagelib/imagelib.h"

/** Inicializala la sopa a partir del archivo */
Sopa* sopa_init(int height, int width)
{
  // Creo la sopa
  Sopa* sopa = malloc(sizeof(Sopa));

  // Abro la imagen

  // Le doy las dimensiones a la matriz
  sopa -> height = height;
  sopa -> width = width;

  // Creo la matriz
  sopa -> matrix = malloc(sizeof(uint8_t*) * sopa -> height);
  for (int row = 0; row < sopa -> height; row++)
  {
    sopa -> matrix[row] = malloc(sizeof(uint8_t) * sopa -> width);
  }

  // Asigno los valores de la matriz a partir de la imagen
  for (int row = 0; row < sopa -> height; row++)
  {
    for (int col = 0; col < sopa -> width; col++)
    {
      sopa -> matrix[row][col] = row % 2;
    }
  }


  // Retorno la sopa
  return sopa;
}

/** Libera la sopa */
void sopa_destroy(Sopa* sopa)
{
  // Libero la matriz de 1s y 0s
  for (int row = 0; row < sopa -> height; row++)
  {
    free(sopa -> matrix[row]);
  }
  free(sopa -> matrix);

  // Libero la sopa
  free(sopa);
}
