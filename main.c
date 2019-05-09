#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include "DLL.h"

void imprime( Item item )
{
  printf( "Nombre: %s\n", item._nombre);
  printf( "Pasajeros: %s\n",item.pasajeros);
  printf( "Capacidad: %s\n", item.capacidad);
  printf( "Estado: %s\n", item.estado);
  printf( "Hora salida: %s\n", item.hora_salida);
  printf( "Hora llegada: %s\n", item.hora_llegada);
  printf("\n\n");

}

//Funcion menu
int menu()
{
    while( 1 )
    {
        printf( "\n"

                "1) Aviones para aterrizaje\n"
                "2) Aviones para despegue\n"
                "3) Ver lista de aviones disponibles\n"
                "4) Ver lista de aviones danados\n"
                "5) Solicitar aterrizaje\n"
                "6) Autorizar aterrizaje\n"
                "7) Solcitar despegue\n"
                "8) Autorizar despeque\n"
                "0) Salir\n"
         	 );

        int opcion;
        printf("Selecciona una opcion: ");
        scanf( "%d", &opcion );

        if( 0 <= opcion && opcion <= 8) { 
            return opcion; 
        }else{ printf( "Opcion no reconocida.\n" ); }
    }
}

int main(void){
    
    DLL* danados=DLL_New();
    DLL* disponible=DLL_New();
    DLL* entrada=DLL_New();
    DLL* salida=DLL_New();

    Item avi1=(Avion){"BoingMX2","0","250","Danado","",""};
    Item avi2=(Avion){"Airbus280","0","350","Danado","",""};
    Item avi3=(Avion){"Latam100","0","300","Danado","",""};
    DLL_InsertFront( danados, avi1);
    DLL_InsertFront( danados, avi2);
    DLL_InsertFront( danados, avi3);

    Item avi4=(Avion){"BoingMZY","0","250","Disponible","",""};
    Item avi5=(Avion){"Airbus760","0","400","Disponible","",""};
    Item avi6=(Avion){"LatamSUR7","0","300","Disponible","",""};
    DLL_InsertFront( disponible, avi4);
    DLL_InsertFront( disponible, avi5);
    DLL_InsertFront( disponible, avi6);

    Item avi7=(Avion){"Aero1","150","300","Ocupado","10:20","12:10"};
    Item avi8=(Avion){"Aero2","250","300","Ocupado","10:40","11:30"};
    DLL_InsertFront( entrada, avi7);
    DLL_InsertFront( entrada, avi8);

    Item avi9=(Avion){"Aero3","100","300","Ocupado","13:30","17:40"};
    Item avi10=(Avion){"Aero4","100","200","Ocupado","13:50","18:30"};
    DLL_InsertFront(salida, avi9);
    DLL_InsertFront(salida, avi10);

    while (1)
   {
           
        switch( menu() ){

            case 1:
                {
                    printf("Proximos arrivos: \n");
                    DLL_Traverse( entrada, imprime);
                   
                    break;
                }
                
            case 2:
                {
                    printf("Proximos despegues: \n");
                    DLL_Traverse( salida, imprime);
                   

                    break;
                }

            case 3:
                {
                    printf("Aviones disponibles: \n");
                    DLL_Traverse( disponible, imprime);    
                    break;
                }
                
            case 4:
                {
                    printf("Aviones danados: \n");
                    DLL_Traverse( danados, imprime);
                    break;
                }   
            case 5:
                { 
                    printf("");
                   
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
           
            case 0:
                {
                    //liberando memoria
                    DLL_Delete(danados);
                    DLL_Delete(disponible);
                    DLL_Delete(entrada);
                    DLL_Delete(salida);

                    return 0;
                 
                }

            default:
                printf( "Opcion no reconocida\n" );
                break;
        }
    
    }


    return 0;
}