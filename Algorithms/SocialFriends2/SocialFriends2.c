#include <stdio.h>

void FindDislikedPplPerPerson(int Relationships[15][15], int DislikeAmount[15], int flag, int Person);
void FindAllInvitees(int Relationships[15][15], int DislikeAmount[15]);
int FindNumberOfAttendees(int DislikeAmount[15]);
void PrintAll(int MaxAttendees, int DislikeAmount[15], char Names[15][12]);


int main(){
    /*Εισαγωγή των ονομάτων και του γράφου στο πρόγραμμα*/
    int FriendRelationshipsTable[15][15] = {{0,1,0,0,0,0,0,1,0,0,0,0,0,0,0},
                       {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
                       {0,0,1,0,0,0,1,1,0,0,0,0,0,0,0},
                       {0,0,0,1,0,1,0,0,1,1,0,0,0,0,0},
                       {1,0,0,0,1,1,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,1,0,0,0,0,1,0,0,0},
                       {0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
                       {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
                       {0,0,0,0,0,0,0,0,1,0,0,0,1,0,0},
                       {0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
                       {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,1,0,0,1,0,0}};

    char FriendNames[15][12] = {"Nikos", "Lydia", "Marilia", "Petros", "Giannis", "Manos",
    "Elenh", "Akhs", "Maria", "Dhmhths", "Zwh", "Alexandros", "Anna", "Artemis", "Alekos"};

    /*Τέλος εισαγωγής*/

    int AmountOfDislikedPeoplePerCol[15], MaxOfPeopleAttending;
    int Flag = 0;
    int Person = 0;

    FindDislikedPplPerPerson(FriendRelationshipsTable, AmountOfDislikedPeoplePerCol, Flag, Person);

    FindAllInvitees(FriendRelationshipsTable, AmountOfDislikedPeoplePerCol);

    MaxOfPeopleAttending = FindNumberOfAttendees(AmountOfDislikedPeoplePerCol);

    PrintAll(MaxOfPeopleAttending, AmountOfDislikedPeoplePerCol, FriendNames);

return 0;
}

void FindDislikedPplPerPerson(int Relationships[15][15], int DislikeAmount[15], int flag, int Person){
    int i, j;

    if (flag == 0){
        for (i = 0; i < 15; i++){
            DislikeAmount[i] = 0;
        }
    }
    else if (flag == 1){
         for (i = 0; i < 15; i++){
                if (DislikeAmount[i] != -1) DislikeAmount[i] = 0;
                }
    }

    if (flag == 0){
        for (i = 0; i < 15; i++){
            for (j = 0; j < 15; j++){
                DislikeAmount[i] += Relationships[i][j];
            }
        }
    }
    else if (flag == 1){
        for (i = 0; i < 15; i++){
            for (j = 0; j < 15; j++){
                if (Relationships[i][j] != -1) DislikeAmount[i] += Relationships[i][j];
                }
                DislikeAmount[Person] = -1;
        }
    }

}

void FindAllInvitees(int Relationships[15][15], int DislikeAmount[15]){
    int i, Max, Person, Flag;

    while (Max != -1){
        Max = 0;
        Person = -1;
        Flag = 1;
        for (i = 0; i < 15; i++){
            if (DislikeAmount[i] >= Max && DislikeAmount[i] != -1){
                Max = DislikeAmount[i];
                Person = i;
            }
        }

        if (Max != 0){
            for (i = 0; i < 15; i++){
                if (Relationships[Person][i] == 1){
                    Relationships[Person][i] = -1;
                }
                if (Relationships[i][Person] == 1){
                    Relationships[i][Person] = -1;
                }
            }

            FindDislikedPplPerPerson(Relationships, DislikeAmount, Flag, Person);

        }
        else if (Max == 0) break;
    }
}

int FindNumberOfAttendees(int DislikeAmount[15]){
    int i, MaxAttendees;

    MaxAttendees = 0;
    for (i = 0; i < 15; i++){
        if (DislikeAmount[i] == 0){
            MaxAttendees++;
        }
    }

return MaxAttendees;
}

void PrintAll(int MaxAttendees, int DislikeAmount[15], char Names[15][12]){
    int i,j;

    printf("The maximum amount of friends that Sta8hs can invite to the ball maske is: %d\n\n", MaxAttendees);

    printf("The invitees are: \n");
    j = 0;
    for (i = 0; i < 15; i++){
        if (DislikeAmount[i] == 0){
            j++;
            printf("%d. %s\n", j, Names[i]);
        }
    }
}
