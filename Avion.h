#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "SLL.h"
// una SLL se utilizará como estructura de datos subyacente

typedef char ItemC;
typedef int ItemI;

typedef struct
{
	SLL* stack;
} Stack;

typedef Avion* AvionPtr;

AvionPtr Avion_New(      size_t _capacidad);
void     Avion_eliminar(   AvionPtr this );
void     Avion_llenar(     AvionPtr this, Item _data );
char     Avion_extraer(      AvionPtr this );
char     Avion_Peek(     AvionPtr this );//Devuelve todo los datos del avion
bool     Avion_IsEmpty(  AvionPtr this );
void     Avion_vaciar( AvionPtr this);
size_t   Avion_Len(      AvionPtr this );
size_t   Avion_Capacity( AvionPtr this );
bool     Avion_IsFull(   AvionPtr this );
bool     Avion_chocar ( AvionPtr this);