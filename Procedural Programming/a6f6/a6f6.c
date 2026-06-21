#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define N 5

void readData(int r, int c, int table[N][4]);
void FindMean(int col, int table[N][4], double *mensAverage, double *womensAverage);

int main(){
    int i, j, Table[N][4];
    double MensAverage, WomensAverage;

    for (i = 0; i < N; i++){
        for (j = 0; j < 4; j++){
            readData(i, j, Table);
        }
        printf("-----\n");
    }

    for (j = 1; j < 4; j++){
        FindMean(j, Table, &MensAverage, &WomensAverage);
        if (j == 1){
            printf("Mesos oros barous andrwn: %.1f\n", MensAverage);
            printf("Mesos oros barous gynaikwn: %.1f\n", WomensAverage);
        }
        else if (j == 2){
            printf("Mesos oros ypsous andrwn: %.1f\n", MensAverage);
            printf("Mesos oros ypsous gynaikwn: %.1f\n", WomensAverage);
        }
        else {
            printf("Mesos oros hlikias andrwn: %.1f\n", MensAverage);
            printf("Mesos oros hlikias gynaikwn: %.1f\n", WomensAverage);
        }
        printf("\n");
    }


return 0;
}

void readData(int r, int c, int table[N][4]){
    if (c == 0){
        printf("Dwse fylo: ");
    }
    else if (c == 1){
        printf("Dwse baros: ");
    }
    else if (c == 2){
        printf("Dwse ypsos: ");
    }
    else if (c == 3){
        printf("Dwse ilikia: ");
    }

    table[r][c] = GetInteger();
}

void FindMean(int col, int table[N][4], double *mensAverage, double *womensAverage){
    int i, mc, wc;

    *mensAverage = 0;
    mc = 0;
    *womensAverage = 0;
    wc = 0;
    for (i = 0; i < N; i++){
        if (table[i][0] == 0){
            *mensAverage += table[i][col];
            mc++;
        }
        else if (table[i][0] == 1){
            *womensAverage += table[i][col];
            wc++;
        }
    }

    if (mc != 0){
        *mensAverage = ((double) *mensAverage)/ mc;
    }
    else {
        *mensAverage = 0;
    }

    if (wc != 0){
        *womensAverage = ((double) *womensAverage)/ wc;
    }
    else {
        *womensAverage = 0;
    }
}
