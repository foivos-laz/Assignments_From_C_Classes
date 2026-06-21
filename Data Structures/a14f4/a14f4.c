#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define ExpressionLimit 40

typedef char StackElementType;           /*ο τύπος των στοιχείων της στοίβας
                                        ενδεικτικά τύπου int */
typedef struct StackNode *StackPointer;
typedef struct StackNode
{
	StackElementType Data;
    StackPointer Next;
} StackNode;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackPointer *Stack);
boolean EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);
void TraverseStack(StackPointer Stack);

int main()
{
   StackPointer AStack;
   int count, length;
   StackElementType AnItem;
   char Expression[ExpressionLimit], c;
   boolean Found;

    CreateStack(&AStack);

    printf("EISAGETE MIA PARASTASI:");
    scanf("%s", Expression);
    getchar();

    length = strlen(Expression);
    count = 0;
    Found = TRUE;

    while(count != length){
        c = Expression[count];
        if(Expression[count] == '(' || Expression[count] == '{' || Expression[count] == '['){
                Push(&AStack, Expression[count]);
        }
        else if(Expression[count] == '}' ||Expression[count] == ')' || Expression[count] == ']'){
            if(EmptyStack(AStack)){
                Found = FALSE;
                break;
            }
            else{
                Pop(&AStack, &AnItem);
                if(AnItem == '(' && Expression[count] != ')'){
                    Found = FALSE;
                    break;
                }
                else if(AnItem == '{' && Expression[count] != '}'){
                    Found = FALSE;
                    break;
                }
                else if(AnItem == '[' && Expression[count] != ']'){
                    Found = FALSE;
                    break;
                }
            }
        }
        count++;
    }

    if (Found == FALSE || !EmptyStack(AStack)){
        printf("WRONG\n");
    }
    else{
        printf("CORRECT\n");
    }

	return 0;
}

void TraverseStack(StackPointer Stack)
{
	StackPointer CurrPtr;

   if (EmptyStack(Stack))
   {
   	    printf("EMPTY Stack\n");
    }
   else
   {
   	    CurrPtr = Stack;
         while ( CurrPtr!=NULL )
        {
      	     printf("%c ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}

void CreateStack(StackPointer *Stack)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη στοίβα.
   Επιστρέφει: Μια κενή συνδεδεμένη στοίβα, Stack
*/
{
	*Stack = NULL;
}

boolean EmptyStack(StackPointer Stack)
/* Δέχεται:     Μια συνδεδεμένη στοίβα, Stack.
   Λειτουργία:  Ελέγχει αν η Stack είναι κενή.
   Επιστρέφει:  TRUE αν η στοίβα είναι κενή, FALSE διαφορετικά
*/
{
	return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item)
/* Δέχεται:    Μια συνδεδεμένη στοίβα που η κορυφή της δεικτοδοτείται από τον
                δείκτη Stack και ένα στοιχείο Item.
   Λειτουργία: Εισάγει στην κορυφή της συνδεδεμένης στοίβας, το στοιχείο Item.
   Επιστρέφει: Την τροποποιημένη συνδεδεμένη στοίβα
*/
{
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item)
/* Δέχεται:    Μια συνδεδεμένη στοίβα που η κορυφή της δεικτοδοτείται από τον δείκτη Stack.
   Λειτουργία: Αφαιρεί από την κορυφή της συνδεδεμένης στοίβας,
                αν η στοίβα δεν είναι κενή, το στοιχείο Item.
   Επιστρέφει: Την τροποποιημένη συνδεδεμένη στοίβα και το στοιχείο Item.
   Έξοδος:     Μήνυμα κενής στοίβας, αν η συνδεδεμένη στοίβα είναι κενή
*/
{
    StackPointer TempPtr;

    if (EmptyStack(*Stack)) {
   	    printf("EMPTY Stack\n");
    }
   else
   {
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;
        free(TempPtr);
    }
}
