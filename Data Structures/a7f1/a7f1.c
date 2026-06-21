#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define megisto_plithos 5

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;

void Dimiourgia(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);
void displayset(typos_synolou set);
void createPowerSet(typos_synolou powerset[], int plhthos);

int main()
{
    stoixeio_synolou powerSetsize = megisto_plithos;
    int i, megPL;
    megPL = pow(2, powerSetsize);
    typos_synolou powerSet[megPL];

    createPowerSet(powerSet, megPL);
    printf("TO DYNAMOSYNOLO GIA N=5\n");

    for (i = 0; i < megPL; i++){
        displayset(powerSet[i]);
    }

    return 0;
    system("PAUSE");
}

void createPowerSet(typos_synolou powerset[], int plhthos){
    int counter, j;

    for (counter = 0; counter < plhthos; counter++){
        Dimiourgia(powerset[counter]);
        for (j = 0; j < megisto_plithos; j++){
            if ((counter >> j) & 1){
                Eisagogi(j, powerset[counter]);
            }
        }
    }
}

void displayset(typos_synolou set)
{
	stoixeio_synolou i;

	for (i=0;i < megisto_plithos;i++)
	{
		if(Melos(i,set))
			printf(" %d", i + 1);
	}
	printf("\n");
}

void Dimiourgia(typos_synolou synolo)
/* Λειτουργία: Δημιουργεί ένα σύνολο χωρίς στοιχεία, δηλαδή το κενό σύνολο.
   Επιστρέφει: Το κενό σύνολο
*/
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = FALSE;
}

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο.
   Λειτουργία: Εισάγει το στοιχείο στο σύνολο.
   Επιστρέφει: Το τροποποιημένο σύνολο
*/
{
    synolo[stoixeio] = TRUE;
}

boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο.
   Λειτουργία: Ελέγχει αν το στοιχείο είναι μέλος του συνόλου.
   Επιστρέφει: Επιστρέφει TRUE αν το στοιχείο είναι μέλος του και FALSE διαφορετικά
*/
{
    return synolo[stoixeio];
}
