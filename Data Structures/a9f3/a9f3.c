#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QueueLimit 3  //το όριο μεγέθους της ουράς
#define QueueLimitW 100

typedef char QueueElementType[25];

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;

typedef struct {
    QueueElementType Name;
    int Code;
    char PhoneNumber[10];
}QueueElementTypeW;

typedef struct {
	int Front, Rear;
	QueueElementTypeW Element[QueueLimitW];
} QueueTypeW;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue[], int code);
boolean FullQ(QueueType Queue[], int code);
void RemoveQ(QueueType Queue[], QueueElementType *Item, int code);
void AddQ(QueueType Queue[], QueueElementType Item, int code);
void CreateQW(QueueTypeW *Queue);
boolean EmptyQW(QueueTypeW Queue);
boolean FullQW(QueueTypeW Queue);
void RemoveQW(QueueTypeW *Queue, QueueElementTypeW *Item);
void AddQW(QueueTypeW *Queue, QueueElementType Item);
void newAppointment(int code, QueueType clinicq[], QueueTypeW *waitingq);
void showWaitingQ(QueueTypeW Queue);
void showQ(QueueType Queue[], int code);

int main()
{
   QueueType ClinicQ[6];
   QueueTypeW WaitingQ;
   int i;
   int ClinicCode;
   char Choice;

   for (i = 1; i < 6; i++){
    CreateQ(&ClinicQ[i]);
   }
    CreateQW(&WaitingQ);

    srand(54);

    do{
        ClinicCode = rand() % 5 + 1;
        newAppointment(ClinicCode, ClinicQ, &WaitingQ);
        printf("Continue Y/N (Y=yes, N=No): ");
        gets(&Choice);
    } while(Choice != 'n' && Choice != 'N');

    showQ(ClinicQ, ClinicCode);

    showWaitingQ(WaitingQ);

	return 0;
}

void newAppointment(int code, QueueType clinicq[], QueueTypeW *waitingq){
    QueueElementType name;
    char phonenum[10];
    boolean Flag = FALSE;

    printf("Give your name: ");
    gets(name);

    if (!FullQ(clinicq, code)){
        AddQ(clinicq, name, code);
        printf("Successful appointment for clinic %d\n", code);
    }
    else {
        Flag = TRUE;
    }

    if(Flag){
        printf("You are in a waiting list\n");
        printf("Give your phone number: ");
        gets(phonenum);
        waitingq->Element[waitingq->Rear].Code = code;
        strcpy(waitingq->Element[waitingq->Rear].PhoneNumber,phonenum);
        AddQW(waitingq, name);
    }
}

void showWaitingQ(QueueTypeW Queue){
    int current;

    printf("\nWaiting list:\n");
	if (!EmptyQW(Queue)) {
        current = Queue.Front;
	    while (current != Queue.Rear) {
            printf("%s, ", Queue.Element[current].Name);
            printf("%d, ", Queue.Element[current].Code);
            printf("%s\n", Queue.Element[current].PhoneNumber);
		  current = (current + 1) % QueueLimitW;
	   }
    }
}

void showQ(QueueType Queue[], int code){
    int i, current;

    code = 1;
    for (i = 1; i < 6; i++){
    printf("\nAppointments of clinic %d\n", i);
    if (!EmptyQ(Queue, code)) {
        current = Queue[code].Front;
	    while (current != Queue[code].Rear) {
            printf("%s\n", Queue[code].Element[current]);
		  current = (current + 1) % QueueLimit;
            }
        }
    code++;
    }
}

void CreateQ(QueueType *Queue)
/*  Λειτουργία:  Δημιουργεί μια κενή ουρά.
    Επιστρέφει:  Κενή ουρά
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue[],int code)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, False διαφορετικά
*/
{
	return (Queue[code].Front == Queue[code].Rear);
}

boolean FullQ(QueueType Queue[], int code)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη.
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά
*/
{
	return ((Queue[code].Front) == ((Queue[code].Rear +1) % QueueLimit));
}
void RemoveQ(QueueType Queue[], QueueElementType *Item, int code)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την εμπρός άκρη της ουράς
                αν η ουρά δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα κενής ουρά αν η ουρά είναι κενή
*/
{
	if(!EmptyQ(Queue, code))
	{
	    strcpy(*Item,Queue[code].Element[Queue[code].Front]);
		Queue[code].Front  = (Queue[code].Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue\n");
}

void AddQ(QueueType Queue[], QueueElementType Item, int code)
/* Δέχεται:    Μια ουρά Queue και ένα στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στην ουρά Queue
                αν η ουρά δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα γεμάτης ουράς αν η ουρά είναι γεμάτη
*/
{
	if(!FullQ(Queue, code))
	{
	    strcpy(Queue[code].Element[Queue[code].Rear], Item);
		Queue[code].Rear = (Queue[code].Rear + 1) % QueueLimit;
	}
	else
		printf("Full Queue\n");
}

void CreateQW(QueueTypeW *Queue)
/*  Λειτουργία:  Δημιουργεί μια κενή ουρά.
    Επιστρέφει:  Κενή ουρά
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQW(QueueTypeW Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, False διαφορετικά
*/
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQW(QueueTypeW Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη.
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά
*/
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimitW));
}

void RemoveQW(QueueTypeW *Queue, QueueElementTypeW *Item)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την εμπρός άκρη της ουράς
                αν η ουρά δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα κενής ουρά αν η ουρά είναι κενή
*/
{
	if(!EmptyQW(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue\n");
}

void AddQW(QueueTypeW *Queue, QueueElementType Item)
/* Δέχεται:    Μια ουρά Queue και ένα στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στην ουρά Queue
                αν η ουρά δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα γεμάτης ουράς αν η ουρά είναι γεμάτη
*/
{
	if(!FullQW(*Queue))
	{
	    strcpy(Queue->Element[Queue->Rear].Name, Item);
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimitW;
	}
	else
		printf("Full Queue\n");
}
