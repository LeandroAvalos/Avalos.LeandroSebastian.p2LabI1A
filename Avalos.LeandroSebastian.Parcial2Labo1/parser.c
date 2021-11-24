#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "peliculas.h"
#include "controller.h"

int parser_PeliculasDesdeTexto(FILE* pFile , LinkedList* pArrayListaPeliculas)
{
	int todoOk = 0;
	eMovie* peliculaNueva;
	char buffer[4][30];
	int aux;

	if(pFile != NULL && pArrayListaPeliculas != NULL)
	{
		fscanf(pFile,"%[^,], %[^,], %[^,],%[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3]);

		while(!feof(pFile))
		{
			aux = fscanf(pFile,"%[^,], %[^,], %[^,],%[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3]);
			if(aux == 4)
			{
				peliculaNueva = peliculas_nuevosParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

				if(peliculaNueva != NULL)
				{
					aux = ll_add(pArrayListaPeliculas, peliculaNueva);
					if(aux != 0)
					{
						eliminarPelicula(peliculaNueva);
						break;
					}
					else
					{
						todoOk = 1;
					}
				}
			}
			else
			{
				break;
			}
		}
	}
    return todoOk;
}
