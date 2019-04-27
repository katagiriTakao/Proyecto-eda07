#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

typedef char Item;
typedef Item* ItemPtr;

typedef struct Node
{
    Item data;
    struct Node* next;
} Node;

typedef Node* NodePtr;

typedef struct SLL
{
 NodePtr first;
 NodePtr last;
 NodePtr cursor;
 size_t len;
} SLL;

SLL* SLL_New();
void SLL_Delete( SLL* this );
bool SLL_InsertBack( SLL* this, Item _data );
bool SLL_InsertFront( SLL* this, Item _data );
bool SLL_InsertAfter( SLL* this, Item _data );
bool SLL_RemoveFront( SLL* this, ItemPtr _data_back );
bool SLL_Peek( SLL* this, ItemPtr _data_back );
size_t SLL_Len( SLL* this );
bool SLL_IsEmpty( SLL* this );
void SLL_MakeEmpty( SLL* this );
void SLL_CursorFirst( SLL* this );
void SLL_CursorLast( SLL* this );
void SLL_CursorNext( SLL* this );
bool SLL_FindIf( SLL* this, Item _data );
bool SLL_Search( SLL* this, Item _data );