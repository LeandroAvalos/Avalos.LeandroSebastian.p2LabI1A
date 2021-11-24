#include <stdio.h>
#include <stdlib.h>
#include "peliculas.h"
#include <string.h>
#include <ctype.h>

eMovie* nuevaPelicula()
{
	eMovie* peliculaNueva;

	peliculaNueva = (eMovie*) malloc(sizeof(eMovie));
	if(peliculaNueva != NULL)
	{
		peliculaNueva->idPeli = 0;
		strcpy(peliculaNueva->titulo, "-");
		strcpy(peliculaNueva->genero, "-");
		peliculaNueva->duracion = 0;
	}

	return peliculaNueva;
}

eMovie* peliculas_nuevosParametros(char* idStr ,char* tituloStr, char* genero, char* duracion)
{
	eMovie* peliculaNueva;

	peliculaNueva = nuevaPelicula();
	if(peliculaNueva != NULL)
	{
		if(!(pelicula_setId(peliculaNueva, atoi(idStr))
		   && pelicula_setTitulo(peliculaNueva, tituloStr)
		   && pelicula_setGenero(peliculaNueva, genero)
		   && pelicula_setDuracion(peliculaNueva, atoi(duracion))))
		   {
				eliminarPelicula(peliculaNueva);
				peliculaNueva = NULL;
		   }
	}
	return peliculaNueva;
}

void eliminarPelicula(eMovie* unaPelicula)
{
	free(unaPelicula);
}

int pelicula_setId(eMovie* unaPelicula, int id)
{
	int todoOk = 0;
	if(unaPelicula != NULL && id > 0)
	{
		unaPelicula->idPeli = id;
		todoOk = 1;
	}
	else
	{
		printf("Id Invalido\n");
	}
	return todoOk;
}

int pelicula_getId(eMovie* unaPelicula,int* id)
{
	int todoOk = 0;
	if(unaPelicula != NULL && id != NULL)
	{
		*id = unaPelicula->idPeli;
		todoOk = 1;
	}
	return todoOk;
}

int pelicula_setTitulo(eMovie* unaPelicula, char* titulo)
{
	int todoOk = 0;
	if(unaPelicula != NULL && titulo != NULL)
	{
		if(strlen(titulo) < 30 && strlen(titulo) > 3)
		{
			strcpy(unaPelicula->titulo, titulo);
			strlwr(unaPelicula->titulo);
			unaPelicula->titulo[0] = toupper(unaPelicula->titulo[0]);
			todoOk = 1;
		}
	}
	else
	{
		printf("titulo Invalido\n");
	}
	return todoOk;
}

int pelicula_getTitulo(eMovie* unaPelicula, char* titulo)
{
	int todoOk = 0;
	if(unaPelicula != NULL && titulo != NULL)
	{
		strcpy(titulo, unaPelicula->titulo);
		todoOk = 1;
	}
	return todoOk;
}

int pelicula_setGenero(eMovie* unaPelicula, char* genero)
{
	int todoOk = 0;
	if(unaPelicula != NULL && genero != NULL)
	{
		if(strlen(genero) < 30 && strlen(genero) > 3)
		{
			strcpy(unaPelicula->genero, genero);
			strlwr(unaPelicula->genero);
			unaPelicula->genero[0] = toupper(unaPelicula->genero[0]);
			todoOk = 1;
		}
	}
	else
	{
		printf("genero Invalido\n");
	}
	return todoOk;
}

int pelicula_getGenero(eMovie* unaPelicula, char* genero)
{
	int todoOk = 0;
	if(unaPelicula != NULL && genero != NULL)
	{
		strcpy(genero, unaPelicula->genero);
		todoOk = 1;
	}
	return todoOk;
}

int pelicula_setDuracion(eMovie* unaPelicula, int duracion)
{
	int todoOk = 0;
	if(unaPelicula != NULL && duracion >= 0)
	{
		unaPelicula->duracion = duracion;
		todoOk = 1;
	}
	else
	{
		printf("duracion invalida.\n");
	}
	return todoOk;
}

int pelicula_getDuracion(eMovie* unaPelicula, int* duracion)
{
	int todoOk = 0;
	if(unaPelicula != NULL && duracion != NULL)
	{
		*duracion = unaPelicula->duracion;
		todoOk = 1;
	}
	return todoOk;
}

void pelicula_mostrarPelicula(eMovie* unaPelicula)
{
	int id;
	char titulo[30];
	char genero[20];
	int duracion;

	if(unaPelicula != NULL)
	{
		pelicula_getId(unaPelicula, &id);
		pelicula_getTitulo(unaPelicula, titulo);
		pelicula_getGenero(unaPelicula, genero);
		pelicula_getDuracion(unaPelicula, &duracion);

		printf("%-15d%-26s%-27s%-8d\n",id, titulo, genero, duracion);
	}
}

void* asignarDuraciones(void* elemento)
{
    eMovie* pelicula = NULL;
    int duracion;
    int minDuracion = 100;
    int maxDuracion = 240;

    pelicula = (eMovie*) elemento;
    if(elemento != NULL)
    {
        duracion = rand() % (maxDuracion - minDuracion + 1) + minDuracion;
        pelicula_setDuracion(pelicula, duracion);
    }
    return pelicula;
}

int peliculas_filtrarPeliculaAdventure(void* elemento)
{
	eMovie* aux = NULL;
	int todoOk = 0;
	aux = (eMovie*)elemento;
	char genero[30] = {"Adventure"};
	if(aux != NULL)
	{
		if (strcmp(aux->genero, genero) == 0)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}

int peliculas_filtrarPeliculaRomance(void* elemento)
{
	eMovie* aux = NULL;
	int todoOk = 0;
	aux = (eMovie*)elemento;
	char genero[30] = {"Romance"};
	if(aux != NULL)
	{
		if (strcmp(aux->genero, genero) == 0)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}

int peliculas_filtrarPeliculaDrama(void* elemento)
{
	eMovie* aux = NULL;
	int todoOk = 0;
	aux = (eMovie*)elemento;
	char genero[30] = {"Drama"};
	if(aux != NULL)
	{
		if (strcmp(aux->genero, genero) == 0)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}

int peliculas_filtrarPeliculaComedy(void* elemento)
{
	eMovie* aux = NULL;
	int todoOk = 0;
	aux = (eMovie*)elemento;
	char genero[30] = {"Comedy"};
	if(aux != NULL)
	{
		if (strcmp(aux->genero, genero) == 0)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}

int peliculas_filtrarPeliculaDocumentary(void* elemento)
{
	eMovie* aux = NULL;
	int todoOk = 0;
	aux = (eMovie*)elemento;
	char genero[30] = {"Documentary"};
	if(aux != NULL)
	{
		if (strcmp(aux->genero, genero) == 0)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}

int peliculas_filtrarPeliculaHorror(void* elemento)
{
	eMovie* aux = NULL;
	int todoOk = 0;
	aux = (eMovie*)elemento;
	char genero[30] = {"Horror"};
	if(aux != NULL)
	{
		if (strcmp(aux->genero, genero) == 0)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}

int peliculas_filtrarPeliculaMusical(void* elemento)
{
	eMovie* aux = NULL;
	int todoOk = 0;
	aux = (eMovie*)elemento;
	char genero[30] = {"Musical"};
	if(aux != NULL)
	{
		if (strcmp(aux->genero, genero) == 0)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}

int peliculas_filtrarPeliculaAccion(void* elemento)
{
	eMovie* aux = NULL;
	int todoOk = 0;
	aux = (eMovie*)elemento;
	char genero[30] = {"Accion"};
	if(aux != NULL)
	{
		if (strcmp(aux->genero, genero) == 0)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}


int pelicula_CriterioGenero(void* item1, void* item2)
{
	int todoOk = 0;
	eMovie* peli1 = NULL;
	eMovie* peli2 = NULL;
	char generoUno[20];
	char generoDos[20];
	int duracionUno;
	int duracionDos;

	peli1 = (eMovie*) item1;
	peli2 = (eMovie*) item2;
	if(item1 != NULL && item2 != NULL)
	{
	    pelicula_getGenero(peli1, generoUno);
        pelicula_getGenero(peli2, generoDos);
        pelicula_getDuracion(peli1, &duracionUno);
        pelicula_getDuracion(peli2, &duracionDos);
		if(strcmp(generoUno, generoDos)> 0)
		{
            todoOk = 1;
		}
		else if(strcmp(generoUno, generoDos)< 0)
		{
			todoOk = -1;
		}
		else
        {
            if(strcmp(generoUno, generoDos) == 0)
            {
                if(duracionUno > duracionDos)
                {
                    todoOk = 1;
                }
                else if(duracionUno < duracionDos)
                {
                    todoOk = -1;
                }
            }
        }
	}
	return todoOk;
}
