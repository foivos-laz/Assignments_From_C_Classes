#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define QueueLimit 10  //το όριο μεγέθους της ουράς

typedef int QueueElementType;   /* ο τύπος δεδομένων των στοιχείων της ουράς
                                  ενδεικτικά τύπος int */

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
	int Count;
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);

int main()
{
   QueueType AQueue;
   QueueElementType num;
   int i;

   CreateQ(&AQueue);

   for(i=3; i <= 30; i= i + 3){
        AddQ(&AQueue, i);
   }

   printf("(a)\n");
   TraverseQ(AQueue);

   printf("(b)\n");
   do{
    printf("Give a number:");
    scanf("%d", &num);
    getchar();
    if (num % 3 != 0) printf("Give a multiple of 3\n");
    else AddQ(&AQueue, num);
   }while(num % 3 != 0);
   TraverseQ(AQueue);

   printf("(c)\n");
   RemoveQ(&AQueue, &num);
   TraverseQ(AQueue);
   printf("Removed item=%d\n", num);

   printf("(d)\n");
    for(i=1; i<=2; i++){
        do{
            printf("Give a number:");
            scanf("%d", &num);
            getchar();
            if (num % 3 != 0) printf("Give a multiple of 3\n");
            else AddQ(&AQueue, num);
        }while(num % 3 != 0);
        TraverseQ(AQueue);
    }

    printf("(e)\n");
    /*while(AQueue.Count != 0){*/
    while(!EmptyQ(AQueue)){
        RemoveQ(&AQueue, &num);
        TraverseQ(AQueue);
        printf("Removed item=%d\n", num);
    }

	return 0;
}

void TraverseQ(QueueType Queue) {
	int current;
	if (!EmptyQ(Queue)) {
        current = Queue.Front;
        printf("Queue: ");
	    while (current != Queue.Rear || current != Queue.Count) {
            printf("%d ", Queue.Element[current]);
            current = (current + 1) % QueueLimit;
		  if (current == QueueLimit){
            break;
		  }
		 /*else if(current == Queue.Count){
            break;
		  }*/
		  else if(current == Queue.Rear){
            break;
		  }
	   }
	   printf("\n");
	   printf("Front=%d Rear=%d Count=%d\n", Queue.Front, Queue.Rear, Queue.Count);
    }
    else{
       printf("Queue: Empty Queue\n");
       printf("Front=%d Rear=%d Count=%d\n", Queue.Front, Queue.Rear, Queue.Count);
    }
}

void CreateQ(QueueType *Queue)
/*  Λειτουργία:  Δημιουργεί μια κενή ουρά.
    Επιστρέφει:  Κενή ουρά
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
	Queue->Count=0;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, False διαφορετικά
*/
{
	return (Queue.Count == 0);
}

boolean FullQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη.
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά
*/
{
	return (Queue.Count == QueueLimit);
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την εμπρός άκρη της ουράς
                αν η ουρά δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα κενής ουρά αν η ουρά είναι κενή
*/
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
		Queue->Count--;
	}
	else
		printf("Empty Queue\n");
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια ουρά Queue και ένα στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στην ουρά Queue
                αν η ουρά δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα γεμάτης ουράς αν η ουρά είναι γεμάτη
*/
{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
		Queue->Count++;
	}
	else
		printf("Full Queue\n");
}
