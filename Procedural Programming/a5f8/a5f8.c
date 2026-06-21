#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <string.h>

#define TOTALNUMBER 20
#define TOWNS 4

typedef struct{
    int Code;
    char Name[16];
    long NumberOfSales;
    int Region;
}SalesmenInformation;

void Give_Info(int num, SalesmenInformation Table[]);
void Calc_Total_Sales(int num , SalesmenInformation Table[], long TotalAmountSales[]);
void PrintResults(long TotalAmountSales[]);



int main(){
    SalesmenInformation Salesmen[TOTALNUMBER];
    int count;

    printf("Dwse to plhthos twn pwlhtwn? ");
    count = GetInteger();

    Give_Info(count, Salesmen);

    long TotalSales[TOWNS];

    Calc_Total_Sales(count, Salesmen, TotalSales);

    PrintResults(TotalSales);

return 0;
}

void Give_Info(int num, SalesmenInformation Table[]){
    int i;

    for (i = 0; i < num; i++){
        printf("Kwdikos? ");
        Table[i].Code = GetInteger();

        printf("Onomatepwnymo? ");
        gets(Table[i].Name);

        printf("Poso pwlhsewn? ");
        Table[i].NumberOfSales = GetLong();

        printf("Kwdikos (1= Thes/niki, 2= Athens, 3= Volos, 4= Hrakleio)? ");
        Table[i].Region = GetInteger();
    }

}

void Calc_Total_Sales(int num , SalesmenInformation Table[], long TotalAmountSales[]){
    int i, j;

    for (i = 0; i < TOWNS; i++){
        TotalAmountSales[i] = 0;
    }

    for (i = 0; i < num; i++){
        for ( j = 1; j <= TOWNS; j++){
            if (Table[i].Region == j){
                TotalAmountSales[j - 1] += Table[i].NumberOfSales;
                break;
            }
        }
    }
}

void PrintResults(long TotalAmountSales[]){
    int i;
    long Total = 0;

    printf("    PERIOXH SYN.PWLHSEWN\n");

    for (i = 0; i < 24; i++) printf("-");

    printf("\n");
    printf("  Thes/niki %12ld\n", TotalAmountSales[0]);
    printf("     Athens %12ld\n", TotalAmountSales[1]);
    printf("      Volos %12ld\n", TotalAmountSales[2]);
    printf("   Hrakleio %12ld\n", TotalAmountSales[3]);

    for (i = 0; i < 24; i++) printf("-");

    printf("\n");

    for (i = 0; i < TOWNS; i++){
        Total += TotalAmountSales[i];
    }

    printf("    SYNOLO: %12ld\n", Total);
}
