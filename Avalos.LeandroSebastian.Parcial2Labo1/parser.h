/*
 * parser.h
 *
 *  Created on: 12 nov. 2021
 *      Author: Avalos Leandro Sebastian
 */

#ifndef PARSER_H_
#define PARSER_H_



#endif /* PARSER_H_ */

/**
 * @fn int parser_PeliculasDesdeTexto(FILE*, LinkedList*)
 * @brief Parsea los datos de las peliculas desde el archivo .csv (modo texto).
 *
 * @param pFile Direccion de memoria del archivo que sera parseado.
 * @param pArrayListaPeliculas puntero a la lista de peliculas.
 * @return Retorna 1 si esta todo OK y 0 si fallo.
 */
int parser_PeliculasDesdeTexto(FILE* pFile , LinkedList* pArrayListaPeliculas);
