#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

void decompose(long num, int *AmountOfDigits, double *avg, int *Max);

int main(){
    long number;
    double average;
    int amountOfDigits, max;

    printf("Please insert non-negative number:");
    number = GetLong();

    decompose(number, &amountOfDigits, &average, &max);

    printf("Digits: %d\n", amountOfDigits);
    printf("Average: %.3f\n", average);
    printf("Max: %d\n", max);

return 0;
}

void decompose(long num, int *AmountOfDigits, double *avg, int *Max){
    int digits, i;
    long Number;
    bool flag = FALSE;

    digits = 0;
    Number = num;
    *AmountOfDigits = 0;

    while (Number != 0){
        Number = (Number / 10);
        digits++;
        flag = TRUE;
    }
    if (Number == 0 && flag == FALSE){
            digits++;
        }

    *AmountOfDigits = digits;

    int Digit[digits];

    Number = num;

    i = 0;
    *Max = 0;
    *avg = 0;
    while (Number != 0 && i < digits){
        Digit[i] = (Number % 10);
        Number = (Number / 10);
        i++;
    }

    for (i = 0; i < digits; i++){
        if (Digit[i] > *Max){
            *Max = Digit[i];
        }
        *avg += Digit[i];
    }

    *avg = *avg / digits;
}
