#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "string.h"

typedef struct {
    int PlayerNumber;
    char Name[28];
    int PointsScored;
} PlayerInfo_T;

#define N 100

void readFromFile(FILE* in, PlayerInfo_T tab[], int *playercount);
void writeToFile(FILE* out, PlayerInfo_T tab[], int playercount);


int main(){
    FILE *input, *output;
    int PlayerCount;
    PlayerInfo_T PlayerInfo[N];

    input = fopen("i11f9.dat", "r");

    if (input == NULL){
        printf("'i11f9.dat' cannot be opened");
        exit(1);
    }

    readFromFile(input, PlayerInfo, &PlayerCount);

    output = fopen("baso11f9.dat", "w");

    writeToFile(output, PlayerInfo, PlayerCount);

    fclose(input);
    fclose(output);

return 0;
}

void readFromFile(FILE* in, PlayerInfo_T tab[], int *playercount){
    int i, playersnumber, playersscore;
    char termch, name[28], n;

    i = 0;
    *playercount = 0;

    while(TRUE){
        n = fscanf(in, "%d, %28[^,], %d%c", &playersnumber, name, &playersscore, &termch);
        i++;

        if (n == EOF){
            break;
        }

        if (n != 4 || termch != '\n'){
            printf("Error in the line %d. Program termination\n", i);
            exit(1);
        }

        strcpy(tab[i].Name, name);
        tab[i].PlayerNumber = playersnumber;
        tab[i].PointsScored = playersscore;

        (*playercount) = i;
    }
}

void writeToFile(FILE* out, PlayerInfo_T tab[], int playercount){
    int i, totalpoints, totalamountofmorethan10;

    totalamountofmorethan10 = 0;
    totalpoints = 0;

    fprintf(out ,"%s  %20s", "ONOMATEPWNYMO", "PONTOI");

    fprintf(out,"\n");

    for (i = 1; i <= 35; i++){
        fprintf(out,"-");
    }
    fprintf(out,"\n");

    for (i = 1; i < (playercount + 1); i++){
        fprintf(out ,"%-30s %4d\n", tab[i].Name, tab[i].PointsScored);
    }


    for (i = 1; i <= 35; i++){
        fprintf(out,"-");
    }
    fprintf(out,"\n");

    for (i = 1; i < (playercount + 1); i++){
        totalpoints += tab[i].PointsScored;
        if (tab[i].PointsScored >= 10){
            totalamountofmorethan10++;
        }
    }

    fprintf(out,"%-30s %4d\n","SYNOLO PONTWN" , totalpoints);
    fprintf(out,"%-30s %4d\n", "SYLOLO PAIKTVN >= 10", totalamountofmorethan10);

}
