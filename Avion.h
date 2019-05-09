#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>

typedef struct
{
	char _nombre[10];
	char pasajeros[10];
	char capacidad[10];
	char estado[10];
	char hora_llegada[10];
	char hora_salida[10];
	
} Avion;

//typedef Avion* AvionPtr;

/*AvionPtr Avion_New(ItemC* _nombre,ItemC* _pasajeros, ItemC* capacidad, ItemC* estado,ItemC* h_ll, ItemC* h_s);
void 	 Avion_eliminar(   AvionPtr this );
void 	 Aviones_Imprimir();*/
/*void     Avion_llenar(     AvionPtr this, Item _data );
char     Avion_extraer(      AvionPtr this );
char     Avion_Peek(     AvionPtr this );//Devuelve todo los datos del avion
bool     Avion_IsEmpty(  AvionPtr this );
void     Avion_vaciar( AvionPtr this);
size_t   Avion_Len(      AvionPtr this );
size_t   Avion_Capacity( AvionPtr this );
bool     Avion_IsFull(   AvionPtr this );
bool     Avion_chocar ( AvionPtr this);*/