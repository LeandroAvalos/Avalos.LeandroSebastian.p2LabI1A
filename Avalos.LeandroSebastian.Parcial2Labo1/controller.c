#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "peliculas.h"
#include "parser.h"
#include "inputs.h"


int controller_CargarDeTexto(LinkedList* pArrayListaPeliculas)
{
	int todoOk = 0;
	FILE* f;
	char path[20];

	if(pArrayListaPeliculas != NULL)
	{
	    ll_clear(pArrayListaPeliculas);
	    printf("Ingrese el nombre del archivo a cargar. Sugerencia/s -movies.csv-\n");
        fflush(stdin);
        gets(path);

		f = fopen(path, "r");
        if(f != NULL)
        {
            parser_PeliculasDesdeTexto(f, pArrayListaPeliculas);
            printf("Lista cargada exitosamente!!\n");
            todoOk = 1;
        }
        else
        {
            printf("No existe una lista con ese nombre.\n");
        }
	}
	fclose(f);
    return todoOk;
}

int controller_MostrarPeliculas(LinkedList* pArrayListaPeliculas)
{
	int todoOk = 0;
	eMovie* peliculaNueva = NULL;
	if(pArrayListaPeliculas != NULL)
	{
		printf("                         *** Listado de peliculas ***\n");
		printf("----------------------------------------------------------------------------\n");
		printf("|Id           |Titulo                   |Genero                    |Duracion\n");
		printf("----------------------------------------------------------------------------\n");

		for(int i = 0; i < ll_len(pArrayListaPeliculas); i++)
		{
			peliculaNueva = ll_get(pArrayListaPeliculas, i);
			if(peliculaNueva != NULL)
			{
				pelicula_mostrarPelicula(peliculaNueva);
				todoOk = 1;
			}
		}
	}
    return todoOk;
}

int controller_asignarDuracion(LinkedList* pArrayListaPeliculas)
{
    int todoOk = 0;

    if(pArrayListaPeliculas != NULL)
    {
        ll_map(pArrayListaPeliculas, asignarDuraciones);
        printf("Se asigno correctamente las duraciones de las peliculas\n");
        todoOk = 1;
    }
    return todoOk;
}

int controller_saveAsText(char* path , LinkedList* pArrayListaPeliculas)
{
	int todoOk;
	FILE* f;
	int id;
	char titulo[30];
	char genero[20];
	int duracion;
	eMovie* peliculaNueva;

	if(path != NULL && pArrayListaPeliculas != NULL)
	{
		f = fopen(path, "w");

		peliculaNueva = nuevaPelicula();

		fprintf(f, "id,nombre,primeraDosis,segundaDosis,sinVacunar\n");

		for(int i = 0; i < ll_len(pArrayListaPeliculas); i++)
		{
			peliculaNueva = ll_get(pArrayListaPeliculas, i);
			if(peliculaNueva != NULL)
			{
				pelicula_getId(peliculaNueva, &id);
				pelicula_getTitulo(peliculaNueva, titulo);
				pelicula_getGenero(peliculaNueva, genero);
				pelicula_getDuracion(peliculaNueva, &duracion);

				fprintf(f, "%d,%s,%s,%d\n",id,titulo,genero,duracion);
				todoOk = 1;
			}
			else
			{
				todoOk = 0;
				break;
			}
		}
		fclose(f);
	}
    return todoOk;
}

int controller_FiltroAdventure(LinkedList* pArrayListaPeliculas)
{
    int todoOk = 0;
    LinkedList* listaFiltrada = NULL;

    if(pArrayListaPeliculas != NULL)
    {
        listaFiltrada = ll_filter(pArrayListaPeliculas, peliculas_filtrarPeliculaAdventure);
        controller_MostrarPeliculas(listaFiltrada);
        printf("\nFiltrado Exitoso!!\n");
        controller_saveAsText("peliculaGeneroAdventure.csv", listaFiltrada);
        todoOk = 1;
    }
    return todoOk;
}

int controller_FiltroRomance(LinkedList* pArrayListaPeliculas)
{
    int todoOk = 0;
    LinkedList* listaFiltrada = NULL;

    if(pArrayListaPeliculas != NULL)
    {
        listaFiltrada = ll_filter(pArrayListaPeliculas, peliculas_filtrarPeliculaRomance);
        controller_MostrarPeliculas(listaFiltrada);
        printf("\nFiltrado Exitoso!!\n");
        controller_saveAsText("peliculaGeneroRomance.csv", listaFiltrada);
        todoOk = 1;
    }
    return todoOk;
}

int controller_FiltroDrama(LinkedList* pArrayListaPeliculas)
{
    int todoOk = 0;
    LinkedList* listaFiltrada = NULL;

    if(pArrayListaPeliculas != NULL)
    {
        listaFiltrada = ll_filter(pArrayListaPeliculas, peliculas_filtrarPeliculaDrama);
        controller_MostrarPeliculas(listaFiltrada);
        printf("\nFiltrado Exitoso!!\n");
        controller_saveAsText("peliculaGeneroDrama.csv", listaFiltrada);
        todoOk = 1;
    }
    return todoOk;
}

int controller_FiltroComedy(LinkedList* pArrayListaPeliculas)
{
    int todoOk = 0;
    LinkedList* listaFiltrada = NULL;

    if(pArrayListaPeliculas != NULL)
    {
        listaFiltrada = ll_filter(pArrayListaPeliculas, peliculas_filtrarPeliculaComedy);
        controller_MostrarPeliculas(listaFiltrada);
        printf("\nFiltrado Exitoso!!\n");
        controller_saveAsText("peliculaGeneroComedy.csv", listaFiltrada);
        todoOk = 1;
    }
    return todoOk;
}

int controller_FiltroDocumentary(LinkedList* pArrayListaPeliculas)
{
    int todoOk = 0;
    LinkedList* listaFiltrada = NULL;

    if(pArrayListaPeliculas != NULL)
    {
        listaFiltrada = ll_filter(pArrayListaPeliculas, peliculas_filtrarPeliculaDocumentary);
        controller_MostrarPeliculas(listaFiltrada);
        printf("\nFiltrado Exitoso!!\n");
        controller_saveAsText("peliculaGeneroDocumentary.csv", listaFiltrada);
        todoOk = 1;
    }
    return todoOk;
}

int controller_FiltroHorror(LinkedList* pArrayListaPeliculas)
{
    int todoOk = 0;
    LinkedList* listaFiltrada = NULL;

    if(pArrayListaPeliculas != NULL)
    {
        listaFiltrada = ll_filter(pArrayListaPeliculas, peliculas_filtrarPeliculaHorror);
        controller_MostrarPeliculas(listaFiltrada);
        printf("\nFiltrado Exitoso!!\n");
        controller_saveAsText("peliculaGeneroHorror.csv", listaFiltrada);
        todoOk = 1;
    }
    return todoOk;
}

int controller_FiltroMusical(LinkedList* pArrayListaPeliculas)
{
    int todoOk = 0;
    LinkedList* listaFiltrada = NULL;

    if(pArrayListaPeliculas != NULL)
    {
        listaFiltrada = ll_filter(pArrayListaPeliculas, peliculas_filtrarPeliculaMusical);
        controller_MostrarPeliculas(listaFiltrada);
        printf("\nFiltrado Exitoso!!\n");
        controller_saveAsText("peliculaGeneroMusical.csv", listaFiltrada);
        todoOk = 1;
    }
    return todoOk;
}

int controller_FiltroAccion(LinkedList* pArrayListaPeliculas)
{
    int todoOk = 0;
    LinkedList* listaFiltrada = NULL;

    if(pArrayListaPeliculas != NULL)
    {
        listaFiltrada = ll_filter(pArrayListaPeliculas, peliculas_filtrarPeliculaAccion);
        controller_MostrarPeliculas(listaFiltrada);
        printf("\nFiltrado Exitoso!!\n");
        controller_saveAsText("peliculaGeneroAccion.csv", listaFiltrada);
        todoOk = 1;
    }
    return todoOk;
}

int controller_sortPeliculas(LinkedList* pArrayListaPeliculas)
{
	int todoOk = 0;
	int criterio;

	if(pArrayListaPeliculas != NULL)
	{
		criterio = menuDeCriterio();
		if(ll_isEmpty(pArrayListaPeliculas) == 0)
		{
			ll_sort(pArrayListaPeliculas, pelicula_CriterioGenero, criterio);
            controller_MostrarPeliculas(pArrayListaPeliculas);
            printf("Ordenamiento exitoso!!!\n");
		}
		else
		{
			printf("La lista esta vacia y no se puede ordenar\n");
		}
		todoOk = 1;
	}
    return todoOk;
}
