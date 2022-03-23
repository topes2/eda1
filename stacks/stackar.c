#include "stackar.h"
#include "fatal.h"
#include <stdlib.h>


#define EmptyTOS ( -1 )
#define MinStackSize ( 5 )


struct StackRecord
{
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};

int main(){
    int i, x;
    //printf("Thanks Gonçalo!\n");
    Stack Pile = CreateStack(10);
    do
    {
        printf("Tem push (1) | Tem pop (2) | Top(3) | Empty (4)\n");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            printf("Numero: ");
            scanf("%d", &x);
            Push(x, Pile);
            break;

        case 2:
            Pop(Pile);
            break;
		
		case 3:
			printf("%d \n", Top(Pile)) ;
			break;

        case 4:
            MakeEmpty(Pile);
            break;
        default:
            printf("Done\n");
            break;
        }
    } while (i != 5);


    return 0;
}

Stack CreateStack( int MaxElements )
{
    Stack S;	

	if( MaxElements < MinStackSize )
		Error( "Stack size is too small" );

	S = malloc( sizeof( struct StackRecord ) );
	if( S == NULL )
		FatalError( "Out of space!!!" );

	S->Array = malloc( sizeof( ElementType ) * MaxElements );
	if( S->Array == NULL )
		FatalError( "Out of space!!!" );

	S->Capacity = MaxElements;
	MakeEmpty( S );

	return S;
}



void DisposeStack( Stack S )
{
    if( S != NULL )
    {
        free( S->Array );
        free( S );
    }
}


int IsEmpty( Stack S ){
	if ( S -> TopOfStack == EmptyTOS )
		return 1;
	else
		return 0;
}


int IsFull( Stack S ){
	if(S->Capacity == S->TopOfStack)
		return 1;
	else
		return 0;
}


void MakeEmpty( Stack S ){
	S->Capacity = EmptyTOS;
}


void Push( ElementType X, Stack S ){
	if (IsFull(S))
		printf("Stack is full!\n");
	else
		S->Array[++S->TopOfStack] = X;
}


ElementType Top( Stack S ){
	if(IsEmpty(S))
		Error("Stack está vazia!\n");
	else
		return S->Array[S->TopOfStack];
}


ElementType Pop( Stack S ){
	if( S->TopOfStack == 0)
		printf("A stack está vazia!\n");
	else
		S->Array[S->TopOfStack--];
}