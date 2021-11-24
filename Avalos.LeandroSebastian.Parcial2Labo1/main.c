#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "time.h"
#include "inputs.h"
#include "controller.h"
#include "peliculas.h"

int main()
{
    srand(time(NULL));
    char seguir = 'n';
    char path[20];
    LinkedList* listaPeliculas = ll_newLinkedList();

    do{
		switch(menu())
		{
			case 1:
			    controller_CargarDeTexto(listaPeliculas);
				break;
			case 2:
			    if(!ll_isEmpty(listaPeliculas))
                {
                    controller_MostrarPeliculas(listaPeliculas);
                }
                else
                {
                    printf("Debe cargar una lista para poder mostrar las peliculas\n");
                }
				break;
			case 3:
			    if(!ll_isEmpty(listaPeliculas))
                {
                    controller_asignarDuracion(listaPeliculas);
                }
                else
                {
                    printf("Debe cargar una lista para poder asignar duracion a las peliculas\n");
                }
				break;
			case 4:
			    if(!ll_isEmpty(listaPeliculas))
                {
                    switch(menuDeGeneros())
                    {
                        case 1:
                            controller_FiltroAdventure(listaPeliculas);
                            break;
                        case 2:
                            controller_FiltroRomance(listaPeliculas);
                            break;
                        case 3:
                            controller_FiltroDrama(listaPeliculas);
                            break;
                        case 4:
                            controller_FiltroComedy(listaPeliculas);
                            break;
                        case 5:
                            controller_FiltroDocumentary(listaPeliculas);
                            break;
                        case 6:
                            controller_FiltroHorror(listaPeliculas);
                            break;
                        case 7:
                            controller_FiltroMusical(listaPeliculas);
                            break;
                        case 8:
                            controller_FiltroAccion(listaPeliculas);
                            break;
                    }
                }
                else
                {
                    printf("Debe cargar una lista para poder filtrar\n");
                }
				break;
			case 5:
			    if(!ll_isEmpty(listaPeliculas))
                {
                    controller_sortPeliculas(listaPeliculas);
                }
                else
                {
                    printf("Debe cargar una lista antes de ordenar\n");
                }
				break;
			case 6:
			    if(!ll_isEmpty(listaPeliculas))
                {
                    printf("Con que nombre quiere guardar el archivo?(Recuerde poner .csv al final del nombre)\n");
                    fflush(stdin);
                    gets(path);
                    controller_saveAsText(path, listaPeliculas);
                    printf("Guardado exitoso\n");
                }
                else
                {
                    printf("Debe cargar una lista para poder guardarla\n");
                }
				break;
			case 7:
				pedirCaracter(&seguir, "Esta seguro que desea salir? s(si) y n(no).", "Error. letra invalida. Ingrese s si desea salir o n para continuar.", 's', 'n');
				fflush(stdin);
				if(seguir == 's')
				{
					ll_deleteLinkedList(listaPeliculas);
					printf("Gracias por todo. Hasta la proxima!!!\n");
				}
				break;
			default:
				printf("Opcion invalida!!!\n");
				break;
		}
		system("pause");
	}while(seguir == 'n');

    return 0;
}
