#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main(){
    long AnnualWage, TotalAmountOfTax, FirstPartAmountOfTax, LastPartAmountOfTax;

    printf("Dwse ton katharo ethsio mistho: ");
    AnnualWage = GetLong();

    if (AnnualWage >= 1 && AnnualWage <= 10000){
        FirstPartAmountOfTax = 0;
        LastPartAmountOfTax = 0;
    }
    else if (AnnualWage >= 10001 && AnnualWage <= 39000){
        FirstPartAmountOfTax = 0;
        LastPartAmountOfTax = (AnnualWage - 10000) * 0.18;
    }
    else if (AnnualWage >= 39001 && AnnualWage <= 49000){
        FirstPartAmountOfTax = 5220;
        LastPartAmountOfTax = (AnnualWage - 39000) * 0.21;
    }
    else if (AnnualWage >= 49001 && AnnualWage <= 59000){
        FirstPartAmountOfTax = 7320;
        LastPartAmountOfTax = (AnnualWage - 49000) * 0.24;
    }
    else if (AnnualWage >= 59001 && AnnualWage <= 85000){
        FirstPartAmountOfTax = 9720;
        LastPartAmountOfTax =  (AnnualWage - 59000) * 0.28;
    }
    else if (AnnualWage >= 85001 && AnnualWage <= 100000){
        FirstPartAmountOfTax = 17000;
        LastPartAmountOfTax = (AnnualWage - 85000) * 0.33;
    }
    else if (AnnualWage >= 100001 && AnnualWage <= 120000){
        FirstPartAmountOfTax = 21950;
        LastPartAmountOfTax = (AnnualWage - 100000) * 0.38;
    }
    else if (AnnualWage >= 120001 && AnnualWage <= 150000){
        FirstPartAmountOfTax = 29550;
        LastPartAmountOfTax = (AnnualWage - 120000) * 0.43;
    }
    else if (AnnualWage >= 150001 && AnnualWage <= 170000){
        FirstPartAmountOfTax = 42450;
        LastPartAmountOfTax = (AnnualWage - 150000) * 0.49;
    }
    else if (AnnualWage >= 170001){
        FirstPartAmountOfTax = 52250;
        LastPartAmountOfTax = (AnnualWage - 170000) * 0.5;
    }
    else {
        FirstPartAmountOfTax = 0;
        LastPartAmountOfTax = 0;
    }

    TotalAmountOfTax = FirstPartAmountOfTax + LastPartAmountOfTax;

    printf("%ld Euro\n", AnnualWage);
    printf("%ld Euro\n", FirstPartAmountOfTax);
    printf("%ld Euro\n", LastPartAmountOfTax);
    printf("%ld Euro\n", TotalAmountOfTax);

    return 0;
}
