#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main(){
    int m1, n1, m2, n2, i, j, z;

    printf("Dwse to plhthos twn grammwn m1: ");
    m1 = GetInteger();
    printf("Dwse to plhthos twn sthlwn n1: ");
    n1 = GetInteger();
    printf("Dwse to plhthos twn grammwn m2: ");
    m2 = GetInteger();
    printf("Dwse to plhthos twn sthlwn n2: ");
    n2 = GetInteger();

    long A[m1][n1], B[m2][n2], ADD[m1][n1], SUB[m1][n1], MUL[m1][n2];

    for(i = 0; i < m1; i++){
        for(j = 0; j < n1; j++){
                A[i][j] = GetLong();
        }
    }

    for(i = 0; i < m2; i++){
        for(j = 0; j < n2; j++){
                B[i][j] = GetLong();
        }
    }

    if (m1 ==  m2 && n1 == n2){
        for (i = 0; i < m1; i++){
            for(j = 0; j < n1; j++){
                ADD[i][j] = A[i][j] + B[i][j];
            }
        }
        for (i = 0; i < m1; i++){
                if (m1 > 1){
                  printf("%ld", ADD[i][0]);
                for (j = 1; j < n2; j++){
                    if (j < (n2 - 1)){
                        printf(" %ld", ADD[i][j]);
                    }
                    else if (j == (n2 - 1)) {
                        printf(" %ld\n", ADD[i][j]);
                        }
                    }
                }
                else {
                    printf("%ld\n", ADD[i][0]);
                }
        }
    }
    else {
        printf("ERROR +\n");
    }

    if (m1 ==  m2 && n1 == n2){
        for (i = 0; i < m1; i++){
            for(j = 0; j < n1; j++){
                SUB[i][j] = A[i][j] - B[i][j];
            }
        }
        for (i = 0; i < m1; i++){
                if (m1 > 1){
                    printf("%ld", SUB[i][0]);
                for (j = 1; j < n2; j++){
                    if (j < (n2 -1)) {
                        printf(" %ld", SUB[i][j]);
                    }
                    else if (j == (n2 - 1)){
                        printf(" %ld\n", SUB[i][j]);
                        }
                    }
                }
                else {
                    printf("%ld\n", SUB[i][0]);
                }
        }

    }
    else {
        printf("ERROR -\n");
    }

    if (n1 == m2){
        for (i = 0; i < m1; i++){
            for (j = 0; j < n2; j++){
                MUL[i][j] = 0;
                z = 0;
                    while (z < n1){
                           MUL[i][j] += A[i][z] * B[z][j];
                        z++;
                    }
                }
            }
            for (i = 0; i < m1; i++){
                if (m1 > 1){
                    printf("%ld", MUL[i][0]);
                for (j = 1; j < n2; j++){
                    if (j < (n2 - 1)){
                        printf(" %ld", MUL[i][j]);
                    }
                    else if (j == (n2 - 1)) {
                        printf(" %ld\n", MUL[i][j]);
                        }
                    }
                }
                else {
                    printf("%ld\n", MUL[i][0]);
                }
            }
    }
    else {
        printf("ERROR *\n");
    }

    return 0;
}
