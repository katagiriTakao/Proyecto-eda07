#include "SLL.h"

static NodePtr newNode(Item _data){
   NodePtr n= (NodePtr)malloc(sizeof(Node));
   if(n){
       n->data=_data;
       n->next=NULL;
   }
   return n;
}


SLL* SLL_New(){

    SLL* list=(SLL*)malloc(sizeof(SLL));

    if (list){
        list->first=NULL;
        list->last=NULL;
        list->cursor=NULL;
        list->len=0;
    }
 return list;

};

void SLL_Delete( SLL* this )
{
    if( this ){

    //se devuelven todos los nodos primero
        while( !SLL_IsEmpty( this ) ){
                NodePtr next = this->first->next;
                free( this->first );
                this->first = next;
                --this->len;
        }
            assert(this->len==0);
            //¿borramos todos?
            this->first=this->last=this->cursor=NULL;
            this->len=0;
            
            //se devuelve la lista
            free( this );
    }
}

bool SLL_InsertBack( SLL* this, Item _data )
{
 assert( this );
 bool done = false;
 NodePtr n = newNode( _data );
 if( n ){

    //comprueba la memoria
    done = true;
    if( SLL_IsEmpty( this ) ){ this->first=this->last=this->cursor=n; }
       // la lista está vacía; éste es el primer nodo.
       else{
           //caso general
           //Dos pasos
           //apuntamos al siguiente nodo
           this->last->next = n;
           //el nuevo last apunta al nuevo nodo
           this->last=n;
        }
       // la lista ya tenía nodos. El último nodo apunta al nuevo.
       ++this->len;
 }
    return done;
}


bool SLL_InsertFront( SLL* this, Item _data ){

  assert( this );

  NodePtr n = newNode( _data );
  bool done = false;

    if( n ){
    done = true;
    //caso especial
    if( SLL_IsEmpty( this ) ){this->first=this->last=this->cursor= n;}
    else{
        //en un principio next a apunta a NULL
        n->next=this->first;
        this->first=n;
        }

        ++this->len;
    }
 return done;

}

bool SLL_InsertAfter( SLL* this, Item _data ){

 assert(this);
 bool done=false;
 Node* n =newNode(_data);
    if (n){
        done=true;
        if( SLL_IsEmpty( this ) ){this->first=this->last=this->cursor= n;}
        else{
            //derecha de donde apunta el cursor
            this->cursor->next=n;
            this->cursor=n;
        }
        ++this->len;
    }
    return done;
}

bool SLL_RemoveFront( SLL* this, ItemPtr _data_back )
{
 assert( this );
    if( SLL_IsEmpty( this ) ){ return false; }
        //tomamos el primer valor y lo guardamos en nuestro apuntador entero
        *_data_back = this->first->data;
        //apuntador temporal para no perder first del siguiente nodo
         NodePtr tmp = this->first->next;
        //liberamos el nodo first original
        free( this->first );
        //igualamos el nuevo first a tmp
        this->first = tmp;
        //se disminuye el tamaño
        --this->len;

 return true;
}


bool SLL_Peek( SLL* this, ItemPtr _data_back ){

   assert(this);
   bool done;
   if(!SLL_IsEmpty(this)){
       *_data_back=this->cursor->data;
       done=true;
   }
   return done;
}

size_t SLL_Len( SLL* this ){
    return this->len;
};

bool SLL_IsEmpty( SLL* this )
{
 return this->first == NULL;
}

/** 
 * SLL_MakeEmpty vacia la lista
*/
void SLL_MakeEmpty(SLL* this){

   assert(this);
   while(!SLL_IsEmpty(this)){
       NodePtr next=this->first->next;
       free(this->first);
       this->first=next;
       --this->len;
   }

   assert(this->len==0);
   //¿borramos todos?
   this->first=this->last=this->cursor=NULL;
   this->len=0;
}

void SLL_CursorFirst( SLL* this )
{
    this->cursor=this->first;
}

void SLL_CursorLast( SLL* this )
{
    this->cursor=this->last;
}

/** 
 *@brief Mueve al cursor un elemento a la derecha. 
 *@param this Referencia a un objeto SLL 
 *@post El cursor NO se mueve si vale NULL 
*/
void SLL_CursorNext( SLL* this ){

   assert(this);
   if(this->cursor!=NULL){
       this->cursor=this->cursor->next;
   }

}

bool SLL_FindIf( SLL* this, Item _key ){

   assert(this);
   bool found= false;
   if(!SLL_IsEmpty(this)){
       //RECORRIENDO LA LISTA CONN UN FOR
       for(NodePtr it=this->first;it->next!=NULL;it=it->next){
           if(_key==it->data){
               found=true;
               break;
           }
       }
       
    }
   return found;

}

bool SLL_Search( SLL* this, Item _key ){

   assert(this);
   bool found= false;
   if(!SLL_IsEmpty(this))
   {  
       NodePtr tmp=this->cursor;
       //guardamos al cursor en caso que no se encuentre ninguna coincidencia
       //RECORRIENDO LA LISTA CONN UN FOR
       for(this->cursor=this->first;this->cursor->next!=NULL;this->cursor=this->cursor->next )
        {
           if(_key==this->cursor->data){
               found= true;
               break;
           }
        }
       //NO ENCONTRADO
       if(!found){
           //se devuelve el valor original del cursor
           this->cursor=tmp;
       }  

    }    
    
    return found;
}