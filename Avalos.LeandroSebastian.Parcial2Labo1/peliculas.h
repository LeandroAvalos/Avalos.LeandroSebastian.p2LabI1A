#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

typedef struct
{
    int idPeli;
    char titulo[30];
    char genero[20];
    int duracion;
}eMovie;

#endif // PELICULAS_H_INCLUDED

/** \brief Funcion constructura para crear una nueva pelicula con valores inicializados en 0.
 *
 * \return ePais* Retorna la pelicula creada si tuvo exito.
 *
 */
eMovie* nuevaPelicula();

/** \brief Funcion constructora para crear una nueva pelicula a partir de parametros establecidos.
 *
 * \param idStr char* Puntero a char que contiene el ID que se le quiere asignar a la pelicula.
 * \param tituloStr char* Puntero a char que contiene el titulo que se le quiere asignar a la pelicula.
 * \param genero char*  Puntero a char que contiene el genero que se le quiere asignar a la pelicula.
 * \param duracion char* Puntero a char que contiene la duracion que se le quiere asignar a la pelicula.
 * \return eMovie* Retorna la pelicula creado si tuvo exito.
 *
 */
eMovie* peliculas_nuevosParametros(char* idStr ,char* tituloStr, char* genero, char* duracion);

/** \brief elimina de memoria la pelicula
 *
 * \param unaPelicula eMovie* Libera la memoria ocupada por la pelicula.
 * \return void
 *
 */
void eliminarPelicula(eMovie* unaPelicula);

/** \brief carga el id de una pelicula
 *
 * \param unaPelicula eMovie* puntero a la pelicula
 * \param id int id a cargar.
 * \return int Retorna 1 si esta todo OK y 0 si no.
 *
 */
int pelicula_setId(eMovie* unaPelicula, int id);

/** \brief busca el id de una pelicula
 *
 * \param unaPelicula eMovie* puntero a la pelicula
 * \param id int* id a buscar
 * \return int Retorna 1 si esta todo OK y 0 si no.
 *
 */
int pelicula_getId(eMovie* unaPelicula,int* id);

/** \brief carga el titulo de una pelicula
 *
 * \param unaPelicula eMovie* puntero a la pelicula
 * \param titulo char* titulo a cargar
 * \return int Retorna 1 si esta todo OK y 0 si no.
 *
 */
int pelicula_setTitulo(eMovie* unaPelicula, char* titulo);

/** \brief busca el titulo de una pelicula
 *
 * \param unaPelicula eMovie* puntero a la pelicula.
 * \param titulo char* titulo a buscar
 * \return int Retorna 1 si esta todo OK y 0 si no.
 *
 */
int pelicula_getTitulo(eMovie* unaPelicula, char* titulo);

/** \brief carga el genero de una pelicula.
 *
 * \param unaPelicula eMovie* puntero a la pelicula
 * \param genero char* genero a cargar.
 * \return int Retorna 1 si esta todo OK y 0 si no.
 *
 */
int pelicula_setGenero(eMovie* unaPelicula, char* genero);

/** \brief busca el genero de una pelicula
 *
 * \param unaPelicula eMovie* puntero a la pelicula
 * \param genero char* genero a buscar
 * \return int Retorna 1 si esta todo OK y 0 si no.
 *
 */
int pelicula_getGenero(eMovie* unaPelicula, char* genero);

/** \brief carga la duracion de una pelicula
 *
 * \param unaPelicula eMovie* puntero a la pelicula
 * \param duracion int duracion a cargar.
 * \return int Retorna 1 si esta todo OK y 0 si no.
 *
 */
int pelicula_setDuracion(eMovie* unaPelicula, int duracion);

/** \brief busca la duracion de una pelicula
 *
 * \param unaPelicula eMovie* puntero a la pelicula
 * \param duracion int* duracion a buscar.
 * \return int Retorna 1 si esta todo OK y 0 si no.
 *
 */
int pelicula_getDuracion(eMovie* unaPelicula, int* duracion);

/** \brief funcion que muestra una pelicula
 *
 * \param unaPelicula eMovie* puntero a la pelicula
 * \return void
 *
 */
void pelicula_mostrarPelicula(eMovie* unaPelicula);

/** \brief funcion que asigna de manera aleatoria duraciones
 *
 * \param elemento void* elemento a asignar la duracion
 * \return void*
 *
 */
void* asignarDuraciones(void* elemento);

int peliculas_filtrarPeliculaAdventure(void* elemento);

/** \brief funcion que decide un criterio para luego ser ordenado
 *
 * \param item1 void* primer item a comparar
 * \param item2 void* segundo item a comparar
 * \return int Retorna 1 si esta todo OK y 0 si no.
 *
 */
int pelicula_CriterioGenero(void* item1, void* item2);

int peliculas_filtrarPeliculaRomance(void* elemento);

int peliculas_filtrarPeliculaDrama(void* elemento);

int peliculas_filtrarPeliculaComedy(void* elemento);

int peliculas_filtrarPeliculaDocumentary(void* elemento);

int peliculas_filtrarPeliculaHorror(void* elemento);

int peliculas_filtrarPeliculaMusical(void* elemento);

int peliculas_filtrarPeliculaAccion(void* elemento);
