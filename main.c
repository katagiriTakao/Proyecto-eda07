#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>

#include "Avion.h"
#include "DLL.h"

void imprime( Item item )
{
  printf( "Nombre: %s\n", item._nombre);
  printf( "Pasajeros: %s\n",item.pasajeros);
  printf( "Capacidad: %s\n", item.capacidad);
  printf( "Estado: %s\n", item.estado);
  printf( "Hora llegado: %s\n", item.hora_llegada);
  printf( "Hora salida: %s\n", item.hora_salida);

}

//Funcion menu
int menu()
{
    while( 1 )
    {
        printf( "\n"

                "1) Ver aviones\n"
                "2) Eliminar un avion\n"
                "3) Ver lista de aviones disponibles\n"
                "4) Ver lista de aviones dañados\n"
                "5) Arreglar un avion\n"
                "6) Asignar horario\n"
                "7) Fenomeno meterologico\n"
                "8) Solicitar despegue \n"
                "9) Autorizar despegue\n"
                "10) Buscar un avion\n"
                "0) Salir\n"
         	 );

        int opcion;
        printf("Selecciona una opcion: ");
        scanf( "%d", &opcion );

        if( 0 <= opcion && opcion <= 10) { 
            return opcion; 
        }else{ printf( "Opcion no reconocida.\n" ); }
    }
}

int main(void){
    
    char nombre[10]="Boing123";
    char estado[10]="Ocupado";
    char h_ll[10]="10:20";
    char h_s[10]="12:25";
    char pasajeros[10]="150";
    char capacidad[10]="220";

    DLL* lista=DLL_New();

    DLL_InsertBack( lista, (struct Avion){nombre,pasajeros,capacidad,estado,h_ll,h_s} );

    DLL_Traverse( lista, imprime);


    /*while (1)
   {
           
        switch( menu() ){

            case 1:
                {
                    printf("\n1...\n");
                    Aviones_Imprimir(avion1);
                   
                    break;
                }
                
            case 2:
                {
                    printf("\n2...\n");
                    Avion_eliminar(avion1);

                    break;
                }

            case 3:
                {
                    printf("\n3...\n");    
                    break;
                }
                
            case 4:
                {
                    printf("\n4...\n");
                    break;
                }   
            case 5:
                { 
                    printf("\n5...\n");
                   
                    break;
                }   

            case 6:
                {
                    printf("\n6...\n");
                    break;
                }       
            case 7:
                { 
                    printf("\n7...\n");
                   
                    break;
                }
                    
            case 8:
                {

                    printf("\n8...\n");
                    break;
                }
            case 9:
                {
                    printf("\n9...\n");
                    break; 
                }
                     
            case 10:
                { 
                    printf("\n10...\n");
                    
                    break;
                }

            case 0:
                {
                   
                
                    return 0;
                    printf("Se libero memoria");
                }

            default:
                printf( "Opcion no reconocida\n" );
                break;
        }
    
    }

    */



    return 0;
}