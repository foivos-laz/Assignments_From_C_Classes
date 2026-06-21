#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main(){
    int amountOfStudents, amountOfExercises, i, j, z;

    printf("Dwse ton arithmo twn mathitwn: ");
    amountOfStudents = GetInteger();
    printf("Dwse ton arithmo twn thematwn: ");
    amountOfExercises = GetInteger();

    double GradeIn100[amountOfStudents][amountOfExercises], AverageGradeIn100[amountOfStudents], GradeIn20[amountOfStudents][amountOfExercises], AverageGradeIn20[amountOfStudents];

    for (i = 0; i < amountOfStudents; i++){
        for(j = 0; j < amountOfExercises; j++){
            printf("Dwse th bathmologia tou %dou thematos tou %dou mathiti: ", (j + 1), (i + 1));
            GradeIn100[i][j] = GetReal();
        }
    }

    for (i = 0; i < amountOfStudents; i++){
        for (j = 0; j < amountOfExercises; j++){
            GradeIn20[i][j] = GradeIn100[i][j] / 5;
        }
    }

    for (i = 0; i < amountOfStudents; i++){
        AverageGradeIn100[i] = 0;
        AverageGradeIn20[i] = 0;
    }

    for (i = 0; i < amountOfStudents; i++){
        for (j = 0; j < amountOfExercises; j++){
            AverageGradeIn100[i] += GradeIn100[i][j];
        }
        AverageGradeIn100[i] = AverageGradeIn100[i] / amountOfExercises;
    }

    for (i = 0; i < amountOfStudents; i++){
        for (j = 0; j < amountOfExercises; j++){
            AverageGradeIn20[i] += GradeIn20[i][j];
        }
        AverageGradeIn20[i] = AverageGradeIn20[i] / amountOfExercises;
    }

    for (i = 0; i < amountOfStudents; i++){
        for (j = 0; j < amountOfExercises; j++){
            printf("%6.1lf", GradeIn100[i][j]);
        }
        printf("%6.1lf\n", AverageGradeIn100[i]);
        for (z = 0; z < amountOfExercises; z++){
            printf("%6.1lf", GradeIn20[i][z]);
        }
        printf("%6.1lf\n", AverageGradeIn20[i]);
    }

    return 0;
}
