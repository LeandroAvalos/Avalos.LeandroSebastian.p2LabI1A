#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED

/** \brief Carga los datos de las peliculas desde el archivo .csv (modo texto).
 *
 * \param pArrayListaPeliculas LinkedList* Puntero a la lista de paises.
 * \return int Retorna 1 si esta todoOK y 0 si algo fallo.
 */
int controller_CargarDeTexto(LinkedList* pArrayListaPeliculas);

/** \brief Funcion para listar todos las peliculas.
 *
 * \param pArrayListaPeliculas LinkedList* Puntero a la lista de peliculas.
 * \return int Retorna 1 si esta todoOK y 0 si algo fallo.
 *
 */
int controller_MostrarPeliculas(LinkedList* pArrayListaPeliculas);

/** \brief Funcion que asigna duraciones de forma aleatoria
 *
 * \param pArrayListaPeliculas LinkedList* Puntero a la lista de peliculas.
 * \return int Retorna 1 si esta todoOK y 0 si algo fallo.
 *
 */
int controller_asignarDuracion(LinkedList* pArrayListaPeliculas);

/** \brief Funcion que guarda como un archivo como texto.
 *
 * \param path char* nombre del archivo
 * \param pArrayListaPeliculas LinkedList* Puntero a la lista de peliculas.
 * \return int Retorna 1 si esta todoOK y 0 si algo fallo.
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListaPeliculas);

int controller_FiltroAdventure(LinkedList* pArrayListaPeliculas);

/** \brief Funcion que ordena las peliculas
 *
 * \param pArrayListaPeliculas LinkedList* Puntero a la lista de peliculas.
 * \return int Retorna 1 si esta todoOK y 0 si algo fallo.
 *
 */
int controller_sortPeliculas(LinkedList* pArrayListaPeliculas);

int controller_FiltroRomance(LinkedList* pArrayListaPeliculas);

int controller_FiltroDrama(LinkedList* pArrayListaPeliculas);

int controller_FiltroComedy(LinkedList* pArrayListaPeliculas);

int controller_FiltroDocumentary(LinkedList* pArrayListaPeliculas);

int controller_FiltroHorror(LinkedList* pArrayListaPeliculas);

int controller_FiltroMusical(LinkedList* pArrayListaPeliculas);

int controller_FiltroAccion(LinkedList* pArrayListaPeliculas);
