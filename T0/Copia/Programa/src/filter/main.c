#include <stdio.h>
#include <stdlib.h>
#include "../imagelib/imagelib.h"
#include "../imagelib/funct.h"
#include <time.h>


int main(int argc, char *argv[])
{
	/* El programa recibe 2 parametros */
	if(argc != 5)
	{
		printf("Modo de uso: %s <input.png> <output.png>\n", argv[0]);
		printf("\t<input.png> es la imagen a filtrar\n");
		printf("\t<output.png> es donde se guardará la imagen resultante\n");
		return 1;
	}
	clock_t begin = clock();

	/* Leemos la imagen a partir del archivo */
	char* input_file = argv[1];
	Image* img = img_png_read_from_file(input_file);
	Image* output = img_png_read_from_file(input_file);

	int alto = atoi(argv[3]);
	int ancho = atoi(argv[4]);

	// printf("Ancho maximo: %i\nAlto maximo: %i\n\n", img -> width, img -> height);
	//
	// printf("Ancho: %i\nAlto: %i\n", ancho, alto);

	/* TODO: Filtro de mediana */

	/*

	La representación de la casilla de píxeles que usaré será de la forma

										vecinos[0]  vecinos[1]  vecinos[2]
										vecinos[3]  vecinos[4]  vecinos[5]
										vecinos[6]  vecinos[7]  vecinos[8]

	*/

	int vecinos_r[9];
	int vecinos_g[9];
	int vecinos_b[9];



	for (int row = 0; row < alto; row++)
	{
		for (int col = 0; col < ancho; col++)
		{
			if ((img -> pixels[row][col].R == 255) &&
					(img -> pixels[row][col].G == 255) &&
					(img -> pixels[row][col].B == 255))
				{

				//////////////////////////////////// Esquina superior izquierda /////////////////////////////////////
				if ((row == 0) && (col == 0))
				{
					// Canal Rojo
					vecinos_r[0] = img -> pixels[row][col].R;   vecinos_r[1] = img -> pixels[row][col].R;   vecinos_r[2] = img -> pixels[row][col+1].R;
					vecinos_r[3] = img -> pixels[row][col].R;   vecinos_r[4] = img -> pixels[row][col].R;   vecinos_r[5] = img -> pixels[row][col+1].R;
					vecinos_r[6] = img -> pixels[row+1][col].R; vecinos_r[7] = img -> pixels[row+1][col].R; vecinos_r[8] = img -> pixels[row+1][col+1].R;

					output -> pixels[row][col].R = median(vecinos_r, 9);

					// Canal Verde
					vecinos_g[0] = img -> pixels[row][col].G;   vecinos_g[1] = img -> pixels[row][col].G;   vecinos_g[2] = img -> pixels[row][col+1].G;
					vecinos_g[3] = img -> pixels[row][col].G;   vecinos_g[4] = img -> pixels[row][col].G;   vecinos_g[5] = img -> pixels[row][col+1].G;
					vecinos_g[6] = img -> pixels[row+1][col].G; vecinos_g[7] = img -> pixels[row+1][col].G; vecinos_g[8] = img -> pixels[row+1][col+1].G;

					output -> pixels[row][col].G = median(vecinos_g, 9);

					// Canal Azul
					vecinos_b[0] = img -> pixels[row][col].B;   vecinos_b[1] = img -> pixels[row][col].B;   vecinos_b[2] = img -> pixels[row][col+1].B;
					vecinos_b[3] = img -> pixels[row][col].B;   vecinos_b[4] = img -> pixels[row][col].B;   vecinos_b[5] = img -> pixels[row][col+1].B;
					vecinos_b[6] = img -> pixels[row+1][col].B; vecinos_b[7] = img -> pixels[row+1][col].B; vecinos_b[8] = img -> pixels[row+1][col+1].B;

					output -> pixels[row][col].B = median(vecinos_b, 9);

				}

				//////////////////////////////////// Techo /////////////////////////////////////
				else if ((row == 0) && (col != 0) && (col != img -> width - 1))
				{
					// Canal Rojo
					vecinos_r[0] = img -> pixels[row][col-1].R;   vecinos_r[1] = img -> pixels[row][col].R;   vecinos_r[2] = img -> pixels[row][col+1].R;
					vecinos_r[3] = img -> pixels[row][col-1].R;   vecinos_r[4] = img -> pixels[row][col].R;   vecinos_r[5] = img -> pixels[row][col+1].R;
					vecinos_r[6] = img -> pixels[row+1][col-1].R; vecinos_r[7] = img -> pixels[row+1][col].R; vecinos_r[8] = img -> pixels[row+1][col+1].R;

					output -> pixels[row][col].R = median(vecinos_r, 9);

					// Canal Verde
					vecinos_g[0] = img -> pixels[row][col-1].G;   vecinos_g[1] = img -> pixels[row][col].G;   vecinos_g[2] = img -> pixels[row][col+1].G;
					vecinos_g[3] = img -> pixels[row][col-1].G;   vecinos_g[4] = img -> pixels[row][col].G;   vecinos_g[5] = img -> pixels[row][col+1].G;
					vecinos_g[6] = img -> pixels[row+1][col-1].G; vecinos_g[7] = img -> pixels[row+1][col].G; vecinos_g[8] = img -> pixels[row+1][col+1].G;

					output -> pixels[row][col].G = median(vecinos_g, 9);

					// Canal Azul
					vecinos_b[0] = img -> pixels[row][col-1].B;   vecinos_b[1] = img -> pixels[row][col].B;   vecinos_b[2] = img -> pixels[row][col+1].B;
					vecinos_b[3] = img -> pixels[row][col-1].B;   vecinos_b[4] = img -> pixels[row][col].B;   vecinos_b[5] = img -> pixels[row][col+1].B;
					vecinos_b[6] = img -> pixels[row+1][col-1].B; vecinos_b[7] = img -> pixels[row+1][col].B; vecinos_b[8] = img -> pixels[row+1][col+1].B;

					output -> pixels[row][col].B = median(vecinos_b, 9);

				}

				//////////////////////////////////// Esquina superior derecha /////////////////////////////////////
				else if ((row == 0) && (col == img -> width - 1))
				{

					// Canal Rojo
					vecinos_r[0] = img -> pixels[row][col-1].R;   vecinos_r[1] = img -> pixels[row][col].R;   vecinos_r[2] = img -> pixels[row][col].R;
					vecinos_r[3] = img -> pixels[row][col-1].R;   vecinos_r[4] = img -> pixels[row][col].R;   vecinos_r[5] = img -> pixels[row][col].R;
					vecinos_r[6] = img -> pixels[row+1][col-1].R; vecinos_r[7] = img -> pixels[row+1][col].R; vecinos_r[8] = img -> pixels[row+1][col].R;

					output -> pixels[row][col].R = median(vecinos_r, 9);

					// Canal Verde
					vecinos_g[0] = img -> pixels[row][col-1].G;   vecinos_g[1] = img -> pixels[row][col].G;   vecinos_g[2] = img -> pixels[row][col].G;
					vecinos_g[3] = img -> pixels[row][col-1].G;   vecinos_g[4] = img -> pixels[row][col].G;   vecinos_g[5] = img -> pixels[row][col].G;
					vecinos_g[6] = img -> pixels[row+1][col-1].G; vecinos_g[7] = img -> pixels[row+1][col].G; vecinos_g[8] = img -> pixels[row+1][col].G;

					output -> pixels[row][col].G = median(vecinos_g, 9);

					// Canal Azul
					vecinos_b[0] = img -> pixels[row][col-1].B;   vecinos_b[1] = img -> pixels[row][col].B;   vecinos_b[2] = img -> pixels[row][col].B;
					vecinos_b[3] = img -> pixels[row][col-1].B;   vecinos_b[4] = img -> pixels[row][col].B;   vecinos_b[5] = img -> pixels[row][col].B;
					vecinos_b[6] = img -> pixels[row+1][col-1].B; vecinos_b[7] = img -> pixels[row+1][col].B; vecinos_b[8] = img -> pixels[row+1][col].B;

					output -> pixels[row][col].B = median(vecinos_b, 9);

				}

				//////////////////////////////////// Pared derecha /////////////////////////////////////
				else if ((row != 0) && (row != img -> height - 1) && (col == img -> width - 1))
				{

					// Canal Rojo
					vecinos_r[0] = img -> pixels[row-1][col-1].R; vecinos_r[1] = img -> pixels[row-1][col].R; vecinos_r[2] = img -> pixels[row-1][col].R;
					vecinos_r[3] = img -> pixels[row][col-1].R;   vecinos_r[4] = img -> pixels[row][col].R;   vecinos_r[5] = img -> pixels[row][col].R;
					vecinos_r[6] = img -> pixels[row+1][col-1].R; vecinos_r[7] = img -> pixels[row+1][col].R; vecinos_r[8] = img -> pixels[row+1][col].R;

					output -> pixels[row][col].R = median(vecinos_r, 9);

					// Canal Verde
					vecinos_g[0] = img -> pixels[row-1][col-1].G; vecinos_g[1] = img -> pixels[row-1][col].G; vecinos_g[2] = img -> pixels[row-1][col].G;
					vecinos_g[3] = img -> pixels[row][col-1].G;   vecinos_g[4] = img -> pixels[row][col].G;   vecinos_g[5] = img -> pixels[row][col].G;
					vecinos_g[6] = img -> pixels[row+1][col-1].G; vecinos_g[7] = img -> pixels[row+1][col].G; vecinos_g[8] = img -> pixels[row+1][col].G;

					output -> pixels[row][col].G = median(vecinos_g, 9);

					// Canal Azul
					vecinos_b[0] = img -> pixels[row-1][col-1].B; vecinos_b[1] = img -> pixels[row-1][col].B; vecinos_b[2] = img -> pixels[row-1][col].B;
					vecinos_b[3] = img -> pixels[row][col-1].B;   vecinos_b[4] = img -> pixels[row][col].B;   vecinos_b[5] = img -> pixels[row][col].B;
					vecinos_b[6] = img -> pixels[row+1][col-1].B; vecinos_b[7] = img -> pixels[row+1][col].B; vecinos_b[8] = img -> pixels[row+1][col].B;

					output -> pixels[row][col].B = median(vecinos_b, 9);

				}

				//////////////////////////////////// Esquina inferior derecha /////////////////////////////////////
				else if ((row == img -> height - 1) && (col == img -> width - 1))
				{

					// Canal Rojo
					vecinos_r[0] = img -> pixels[row-1][col-1].R; vecinos_r[1] = img -> pixels[row-1][col].R; vecinos_r[2] = img -> pixels[row-1][col].R;
					vecinos_r[3] = img -> pixels[row][col-1].R;   vecinos_r[4] = img -> pixels[row][col].R;   vecinos_r[5] = img -> pixels[row][col].R;
					vecinos_r[6] = img -> pixels[row][col-1].R;   vecinos_r[7] = img -> pixels[row][col].R;   vecinos_r[8] = img -> pixels[row][col].R;

					output -> pixels[row][col].R = median(vecinos_r, 9);

					// Canal Verde
					vecinos_g[0] = img -> pixels[row-1][col-1].G; vecinos_g[1] = img -> pixels[row-1][col].G; vecinos_g[2] = img -> pixels[row-1][col].G;
					vecinos_g[3] = img -> pixels[row][col-1].G;   vecinos_g[4] = img -> pixels[row][col].G;   vecinos_g[5] = img -> pixels[row][col].G;
					vecinos_g[6] = img -> pixels[row][col-1].G;   vecinos_g[7] = img -> pixels[row][col].G;   vecinos_g[8] = img -> pixels[row][col].G;

					output -> pixels[row][col].G = median(vecinos_g, 9);

					// Canal Azul
					vecinos_b[0] = img -> pixels[row-1][col-1].B; vecinos_b[1] = img -> pixels[row-1][col].B; vecinos_b[2] = img -> pixels[row-1][col].B;
					vecinos_b[3] = img -> pixels[row][col-1].B;   vecinos_b[4] = img -> pixels[row][col].B;   vecinos_b[5] = img -> pixels[row][col].B;
					vecinos_b[6] = img -> pixels[row][col-1].B;   vecinos_b[7] = img -> pixels[row][col].B;   vecinos_b[8] = img -> pixels[row][col].B;

					output -> pixels[row][col].B = median(vecinos_b, 9);

				}

				//////////////////////////////////// Piso /////////////////////////////////////
				else if ((row == img -> height - 1) && (col != img -> width - 1) && (col != 0))
				{

					// Canal Rojo
					vecinos_r[0] = img -> pixels[row-1][col-1].R; vecinos_r[1] = img -> pixels[row-1][col].R; vecinos_r[2] = img -> pixels[row-1][col+1].R;
					vecinos_r[3] = img -> pixels[row][col-1].R;   vecinos_r[4] = img -> pixels[row][col].R;   vecinos_r[5] = img -> pixels[row][col+1].R;
					vecinos_r[6] = img -> pixels[row][col-1].R;   vecinos_r[7] = img -> pixels[row][col].R;   vecinos_r[8] = img -> pixels[row][col+1].R;

					output -> pixels[row][col].R = median(vecinos_r, 9);

					// Canal Verde
					vecinos_g[0] = img -> pixels[row-1][col-1].G; vecinos_g[1] = img -> pixels[row-1][col].G; vecinos_g[2] = img -> pixels[row-1][col+1].G;
					vecinos_g[3] = img -> pixels[row][col-1].G;   vecinos_g[4] = img -> pixels[row][col].G;   vecinos_g[5] = img -> pixels[row][col+1].G;
					vecinos_g[6] = img -> pixels[row][col-1].G;   vecinos_g[7] = img -> pixels[row][col].G;   vecinos_g[8] = img -> pixels[row][col+1].G;

					output -> pixels[row][col].G = median(vecinos_g, 9);

					// Canal Azul
					vecinos_b[0] = img -> pixels[row-1][col-1].B; vecinos_b[1] = img -> pixels[row-1][col].B; vecinos_b[2] = img -> pixels[row-1][col+1].B;
					vecinos_b[3] = img -> pixels[row][col-1].B;   vecinos_b[4] = img -> pixels[row][col].B;   vecinos_b[5] = img -> pixels[row][col+1].B;
					vecinos_b[6] = img -> pixels[row][col-1].B;   vecinos_b[7] = img -> pixels[row][col].B;   vecinos_b[8] = img -> pixels[row][col+1].B;

					output -> pixels[row][col].B = median(vecinos_b, 9);

				}

				//////////////////////////////////// Esquina inferior izquierda /////////////////////////////////////
				else if ((row == img -> height - 1) && (col == 0))
				{

					// Canal Rojo
					vecinos_r[0] = img -> pixels[row-1][col].R; vecinos_r[1] = img -> pixels[row-1][col].R; vecinos_r[2] = img -> pixels[row-1][col+1].R;
					vecinos_r[3] = img -> pixels[row][col].R;   vecinos_r[4] = img -> pixels[row][col].R;   vecinos_r[5] = img -> pixels[row][col+1].R;
					vecinos_r[6] = img -> pixels[row][col].R;   vecinos_r[7] = img -> pixels[row][col].R;   vecinos_r[8] = img -> pixels[row][col+1].R;

					output -> pixels[row][col].R = median(vecinos_r, 9);

					// Canal Verde
					vecinos_g[0] = img -> pixels[row-1][col].G; vecinos_g[1] = img -> pixels[row-1][col].G; vecinos_g[2] = img -> pixels[row-1][col+1].G;
					vecinos_g[3] = img -> pixels[row][col].G;   vecinos_g[4] = img -> pixels[row][col].G;   vecinos_g[5] = img -> pixels[row][col+1].G;
					vecinos_g[6] = img -> pixels[row][col].G;   vecinos_g[7] = img -> pixels[row][col].G;   vecinos_g[8] = img -> pixels[row][col+1].G;

					output -> pixels[row][col].G = median(vecinos_g, 9);

					// Canal Azul
					vecinos_b[0] = img -> pixels[row-1][col].B; vecinos_b[1] = img -> pixels[row-1][col].B; vecinos_b[2] = img -> pixels[row-1][col+1].B;
					vecinos_b[3] = img -> pixels[row][col].B;   vecinos_b[4] = img -> pixels[row][col].B;   vecinos_b[5] = img -> pixels[row][col+1].B;
					vecinos_b[6] = img -> pixels[row][col].B;   vecinos_b[7] = img -> pixels[row][col].B;   vecinos_b[8] = img -> pixels[row][col+1].B;

					output -> pixels[row][col].B = median(vecinos_b, 9);

				}

				//////////////////////////////////// Pared izquierda /////////////////////////////////////
				else if ((row != img -> height - 1) && (row != 0) && (col == 0))
				{

					// Canal Rojo
					vecinos_r[0] = img -> pixels[row-1][col].R; vecinos_r[1] = img -> pixels[row-1][col].R; vecinos_r[2] = img -> pixels[row-1][col+1].R;
					vecinos_r[3] = img -> pixels[row][col].R;   vecinos_r[4] = img -> pixels[row][col].R;   vecinos_r[5] = img -> pixels[row][col+1].R;
					vecinos_r[6] = img -> pixels[row+1][col].R; vecinos_r[7] = img -> pixels[row+1][col].R; vecinos_r[8] = img -> pixels[row+1][col+1].R;

					output -> pixels[row][col].R = median(vecinos_r, 9);

					// Canal Verde
					vecinos_g[0] = img -> pixels[row-1][col].G; vecinos_g[1] = img -> pixels[row-1][col].G; vecinos_g[2] = img -> pixels[row-1][col+1].G;
					vecinos_g[3] = img -> pixels[row][col].G;   vecinos_g[4] = img -> pixels[row][col].G;   vecinos_g[5] = img -> pixels[row][col+1].G;
					vecinos_g[6] = img -> pixels[row+1][col].G; vecinos_g[7] = img -> pixels[row+1][col].G; vecinos_g[8] = img -> pixels[row+1][col+1].G;

					output -> pixels[row][col].G = median(vecinos_g, 9);

					// Canal Azul
					vecinos_b[0] = img -> pixels[row-1][col].B; vecinos_b[1] = img -> pixels[row-1][col].B; vecinos_b[2] = img -> pixels[row-1][col+1].B;
					vecinos_b[3] = img -> pixels[row][col].B;   vecinos_b[4] = img -> pixels[row][col].B;   vecinos_b[5] = img -> pixels[row][col+1].B;
					vecinos_b[6] = img -> pixels[row+1][col].B; vecinos_b[7] = img -> pixels[row+1][col].B; vecinos_b[8] = img -> pixels[row+1][col+1].B;

					output -> pixels[row][col].B = median(vecinos_b, 9);

				}

				//////////////////////////////////// Otro caso /////////////////////////////////////
				else
				{
					// Canal Rojo
					vecinos_r[0] = img -> pixels[row-1][col-1].R; vecinos_r[1] = img -> pixels[row-1][col].R; vecinos_r[2] = img -> pixels[row-1][col+1].R;
					vecinos_r[3] = img -> pixels[row][col-1].R;   vecinos_r[4] = img -> pixels[row][col].R;   vecinos_r[5] = img -> pixels[row][col+1].R;
					vecinos_r[6] = img -> pixels[row+1][col-1].R; vecinos_r[7] = img -> pixels[row+1][col].R; vecinos_r[8] = img -> pixels[row+1][col+1].R;

					output -> pixels[row][col].R = median(vecinos_r, 9);

					// Canal Verde
					vecinos_g[0] = img -> pixels[row-1][col-1].G; vecinos_g[1] = img -> pixels[row-1][col].G; vecinos_g[2] = img -> pixels[row-1][col+1].G;
					vecinos_g[3] = img -> pixels[row][col-1].G;   vecinos_g[4] = img -> pixels[row][col].G;   vecinos_g[5] = img -> pixels[row][col+1].G;
					vecinos_g[6] = img -> pixels[row+1][col-1].G; vecinos_g[7] = img -> pixels[row+1][col].G; vecinos_g[8] = img -> pixels[row+1][col+1].G;

					output -> pixels[row][col].G = median(vecinos_g, 9);

					// Canal Azul
					vecinos_b[0] = img -> pixels[row-1][col-1].B; vecinos_b[1] = img -> pixels[row-1][col].B; vecinos_b[2] = img -> pixels[row-1][col+1].B;
					vecinos_b[3] = img -> pixels[row][col-1].B;   vecinos_b[4] = img -> pixels[row][col].B;   vecinos_b[5] = img -> pixels[row][col+1].B;
					vecinos_b[6] = img -> pixels[row+1][col-1].B; vecinos_b[7] = img -> pixels[row+1][col].B; vecinos_b[8] = img -> pixels[row+1][col+1].B;

					output -> pixels[row][col].B = median(vecinos_b, 9);
				}
			}
		}
	}

	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	// printf("El tiempo que demoró el algoritmo fue:\n%lf,\n", time_spent);
	printf("%lf,\n", time_spent*1000);


	/* Guardamos la imagen como un archivo png */
	char* output_file = argv[2];
	img_png_write_to_file (output, output_file);


	/* Liberamos los recursos asociados de la imagen */
	img_png_destroy(img);
	img_png_destroy(output);

	return 0;
}
