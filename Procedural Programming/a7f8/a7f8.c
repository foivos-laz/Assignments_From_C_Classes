
#include <stdio.h>
#include <string.h>
#include "genlib.h"
#include "simpio.h"

#define RENTALS 20

typedef struct {
    int NumberOfRental;
    char Brand[20];
    int CC;
    char NameOfPersonRenting[20];
    int DaysOfRent;
    float PricePerDay;
    float Total_Charge;
} Car_Rental;

typedef struct {
    char brandOfCar[20];
    int cc;
    float totalCharge;
}Best_CarT;

int Get_Data(Car_Rental Table[]);
float Calculate_Total(int AmRentals, Car_Rental Table[]);
Best_CarT Find_Best(int AmRentals, Car_Rental Table[]);
void PrintAll(Best_CarT Best, int AmRentals, Car_Rental Table[], float total);

int main(){
    int i, amountOfRentals;
    float Total;

    Car_Rental Rentals[RENTALS];

    amountOfRentals = Get_Data(Rentals);

    Best_CarT bestCar;

    Total = Calculate_Total(amountOfRentals, Rentals);

    bestCar = Find_Best(amountOfRentals, Rentals);

    PrintAll(bestCar, amountOfRentals, Rentals, Total);

return 0;
}

int Get_Data(Car_Rental Table[]){
    int AmountOfRentals, i;

    printf("Dose ton arithmo ton enoikiaseon: ");
    AmountOfRentals = GetInteger();
    printf("\n");

    for (i = 0; i < AmountOfRentals; i++){
        printf("Dose ta stoixeia tis enoikiasis %d\n", i);

        Table[i].NumberOfRental = i;

        printf("Dose marka: ");
        gets(Table[i].Brand);

        printf("Dose kyvika: ");
        Table[i].CC = GetInteger();

        printf("Dose onoma pelati: ");
        gets(Table[i].NameOfPersonRenting);

        printf("Dose imeres enoikiasis: ");
        Table[i].DaysOfRent = GetInteger();

        printf("Dose timi ana imera: ");
        Table[i].PricePerDay = GetReal();

        printf("\n");
    }

return AmountOfRentals;
}

float Calculate_Total(int AmRentals, Car_Rental Table[]){
    int i;
    float total = 0;

    for (i = 0; i < AmRentals; i++){
        Table[i].Total_Charge = Table[i].DaysOfRent * Table[i].PricePerDay;
        total += Table[i].Total_Charge;
    }
return total;
}

Best_CarT Find_Best(int AmRentals, Car_Rental Table[]){
    Best_CarT Best;
    int i;

    Best.totalCharge = Table[0].Total_Charge;
    strcpy(Best.brandOfCar, Table[0].Brand);
    Best.cc = Table[0].CC;

    for (i = 1; i < AmRentals; i++){
        if (Best.totalCharge < Table[i].Total_Charge){
            Best.totalCharge = Table[i].Total_Charge;
            strcpy(Best.brandOfCar, Table[i].Brand);
            Best.cc = Table[i].CC;
        }
    }

return Best;
}

void PrintAll(Best_CarT Best, int AmRentals, Car_Rental Table[], float total){
    int i;

    printf("\n\n");
    printf("%-7s %-20s %-10s %-5s %-5s %-6s %-8s\n", "Number", "Name", "Type", "CC", "Days", "Price", "Total");

    for (i = 0; i < 73; i++) printf("-");
    printf("\n");

    for (i = 0; i < AmRentals; i++){
        printf("%-7d %-20s %-10s %-5d %-5d %-6.2f %-8.2f\n",
               Table[i].NumberOfRental,
               Table[i].NameOfPersonRenting,
               Table[i].Brand,
               Table[i].CC,
               Table[i].DaysOfRent,
               Table[i].PricePerDay,
               Table[i].Total_Charge);
    }
    for (i = 0; i < 73; i++) printf("-");
    printf("\n");
    printf("%58s %-8.2f\n", "Total", total);
    printf("Best Car: %s %d rented for %.2f Euros.\n", Best.brandOfCar, Best.cc, Best.totalCharge);
}
