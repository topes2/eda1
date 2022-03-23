#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"
#include "fatal.h"


#define MinQueueSize ( 5 )

struct QueueRecord{
    int Capacity;
    int Front;
    int Rear;
    ElementType *Array;
};


/* FUNCOES AUXILIARES */
/* numero de elementos na fila */
int size( Queue Q ){
    return (Q->Capacity - Q->Front + Q->Rear) % Q->Capacity;
}


/* indice do proximo elemento  */
int successor( int i, Queue Q ){
    return (i + 1) % Q->Capacity;
}



/* FUNCOES DE MANIPULACAO DE QUEUES */
Queue CreateQueue( int MaxElements ){
    Queue Q;

    if( MaxElements < MinQueueSize )
        Error( "Queue size is too small" );

    Q = malloc( sizeof( struct QueueRecord ) );
    if( Q == NULL )
        FatalError( "Out of space!!!" );

    Q->Array = malloc( sizeof( ElementType ) * MaxElements );
    if( Q->Array == NULL )
        FatalError( "Out of space!!!" );

    Q->Capacity = MaxElements+1;
    MakeEmptyQueue( Q );

    return Q;
}


void DisposeQueue( Queue Q ){
    if( Q != NULL ){
        free( Q->Array );
        free( Q );
    }
}


bool IsEmptyQueue( Queue Q ){
    return (Q->Front == Q->Rear);
}


bool IsFullQueue( Queue Q ){
    return (Q->Rear == Q->Capacity);
}


void MakeEmptyQueue( Queue Q ){
    Q->Rear = Q->Front = 0;

}


void Enqueue( ElementType X, Queue Q ){
    Q->Array[Q->Front+1] = X;
}


ElementType Front( Queue Q ){
    Q->Array[Q->Front];
}


ElementType Dequeue( Queue Q ){
}

int main(){
    Queue Q = CreateQueue(69);
    DisposeQueue(Q);
}