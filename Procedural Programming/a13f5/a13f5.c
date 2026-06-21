#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "math.h"

void populate_data(int R, int C, int Table_A[R][C]);
void print_array(int R, int C, int Table_A[R][C],bool FRun);
void change_array(int R, int C, int Table_A[R][C]);

int main(){
    int Rows, Columns;
    bool firstRun = TRUE;

    printf("Dwse ton arithmo twn grammwn: ");
    Rows = GetInteger();
    printf("Dwse ton arithmo twn sthlwn: ");
    Columns = GetInteger();

    int Table_A[Rows][Columns];

    populate_data(Rows, Columns, Table_A);

    print_array(Rows, Columns, Table_A, firstRun);
    firstRun = FALSE;

    change_array(Rows, Columns, Table_A);

    print_array(Rows, Columns, Table_A, firstRun);

    return 0;
}

void populate_data(int R, int C, int Table_A[R][C]){
    int i, j;

    for (i = 0; i < R; i++){
        for (j = 0; j < C; j++){
            Table_A[i][j] = (rand() % 100);
        }
    }

}

void print_array(int R, int C, int Table_A[R][C], bool FRun){
    int i, j;

    if (FRun == TRUE){
        printf("ARXIKOS PINAKAS\n");
    }
    else if (FRun == FALSE){
        printf("ALLAGMENOS PINAKAS\n");
    }

    for (i = 0; i < R; i++){
        for (j = 0; j < C; j++){
            if (j < (C - 1)){
                printf("%d ", Table_A[i][j]);
                }
            else if (j == (C - 1)) {
                printf("%d\n", Table_A[i][j]);
                }
            else {
                printf("%d\n", Table_A[i][0]);
            }
        }
    }


}

void change_array(int R, int C, int Table_A[R][C]){
    int i, j, max[R], maxJ[R];

    for (i = 0; i < R; i++){
            max[i] = Table_A[i][0];
            maxJ[i] = 0;
    }

    for (i = 0; i < R; i++){
        for (j = 1; j < C; j++){
            if (max[i] < Table_A[i][j]){
                max[i] = Table_A[i][j];
                maxJ[i] = j;
            }
        }
    }

    for (i = 0; i < R; i++){
        for (j = 0; j < maxJ[i]; j++){
            Table_A[i][j] =  max[i];
        }
    }
}
