#include <stdio.h>

int main(){
    int Relationships[15][15] = {{0,1,0,0,0,0,0,1,0,0,0,0,0,0,0},
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

    char Names[15][12] = {"Nikos", "Lydia", "Marilia", "Petros", "Giannis", "Manos",
    "Elenh", "Akhs", "Maria", "Dhmhths", "Zwh", "Alexandros", "Anna", "Artemis", "Alekos"};

    int i, j, DislikeAmount[15], Max, Person, MaxAttendees;


    for (i = 0; i < 15; i++){
        DislikeAmount[i] = 0;
    }

    for (i = 0; i < 15; i++){
        for (j = 0; j < 15; j++){
            DislikeAmount[i] += Relationships[i][j];
            }
        }

    while (Max != -1){
        Max = 0;
        Person = -1;
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
            for (i = 0; i < 15; i++){
                if (DislikeAmount[i] != -1) DislikeAmount[i] = 0;
                }

            for (i = 0; i < 15; i++){
                for (j = 0; j < 15; j++){
                    if (Relationships[i][j] != -1) DislikeAmount[i] += Relationships[i][j];
                }
                DislikeAmount[Person] = -1;
            }

        }
        else if (Max == 0) break;
    }

    MaxAttendees = 0;
    for (i = 0; i < 15; i++){
        if (DislikeAmount[i] == 0){
            MaxAttendees++;
        }
    }
    printf("The maximum amount of friends that Sta8hs can invite to the ball maske is: %d\n\n", MaxAttendees);

    printf("The invitees are: \n");
    j = 0;
    for (i = 0; i < 15; i++){
        if (DislikeAmount[i] == 0){
            j++;
            printf("%d. %s\n", j, Names[i]);
        }
    }


return 0;
}
