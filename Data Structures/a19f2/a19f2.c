#include <stdio.h>
#include <stdlib.h>

#define StackLimit 8   // το όριο μεγέθους της στοίβας, ενδεικτικά ίσο με 50


typedef int StackElementType;   // ο τύπος των στοιχείων  της στοίβας
                                //ενδεικτικά τύπος int
typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void TraverseStack(StackType Stack);
void minElement(StackType *Stack, StackElementType *min);
void maxElement(StackType *Stack, StackElementType *max);

int main()
{
    StackElementType AnItem, Min, Max;
    StackType AStack;
    int i;

    CreateStack(&AStack);
    for(i = 0; i < StackLimit; i++){
        printf("Dwse to epomeno stoixeio:");
        scanf("%d", &AnItem);
        Push(&AStack, AnItem);
    }
    TraverseStack(AStack);

    minElement(&AStack, &Min);
    printf("Min: %d\n", Min);

    maxElement(&AStack, &Max);
    printf("Max: %d\n", Max);

    TraverseStack(AStack);


    return 0;
}

void minElement(StackType *Stack, StackElementType *min){
    StackType Temp;
    StackElementType Item;

    CreateStack(&Temp);

    Pop(&(*Stack), &Item);
    *min = Item;
    Push(&Temp, *min);

    while(!EmptyStack(*Stack)){
        Pop(&(*Stack), &Item);
        Push(&Temp, Item);
        if(*min > Item){
            *min = Item;
        }
    }

    while(!EmptyStack(Temp)){
        Pop(&Temp, &Item);
        if (Item != *min){
            Push(&(*Stack), Item);
        }
    }
}

void maxElement(StackType *Stack, StackElementType *max){
    StackType Temp;
    StackElementType Item;

    CreateStack(&Temp);

    Pop(&(*Stack), &Item);
    *max = Item;
    Push(&Temp, *max);

    while(!EmptyStack(*Stack)){
        Pop(&(*Stack), &Item);
        Push(&Temp, Item);
        if(*max < Item){
            *max = Item;
        }
    }

    while(!EmptyStack(Temp)){
        Pop(&Temp, &Item);
        if (Item != *max){
            Push(&(*Stack), Item);
        }
    }
}

void TraverseStack(StackType Stack)
{
    int i;
    printf("plithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}

void CreateStack(StackType *Stack)
/* Λειτουργία: Δημιουργεί μια κενή στοίβα.
   Επιστρέφει: Κενή Στοίβα.*
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι κενή.
   Επιστρέφει: True αν η Stack είναι κενή, False διαφορετικά
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι γεμάτη.
   Επιστρέφει: True αν η Stack είναι γεμάτη, False διαφορετικά
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* Δέχεται: Μια στοίβα Stack και ένα στοιχείο Item.
   Λειτουργία: Εισάγει το στοιχείο Item στην στοίβα Stack αν η Stack δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη Stack.
   Έξοδος: Μήνυμα γεμάτης στοίβας, αν η στοίβα Stack είναι γεμάτη
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Διαγράφει το στοιχείο Item από την κορυφή της Στοίβας αν η Στοίβα δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη Stack.
   Έξοδος:  Μήνυμα κενής στοίβας αν η Stack είναι κενή
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}
