#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define usd 0.89
#define gbp 0.618
#define sfranc 1.5465
#define cad 1.3565
#define yen 109.22

int menu();
double conversion(int C, int AM);

int main(){
    int choice;
    double amount, money;

    while(choice != 6){
        choice = menu();
        if (choice != 6){
            printf("Dwse to xrhmatiko poso se euro: ");
            money = GetReal();
            amount = conversion(choice, money);
            printf("Axia: %.2f\n", amount);
        }
    }
    return 0;
}

int menu(){
    int Choice;

    printf("1. Metetroph se dollaria\n");
    printf("2. Metatroph se lires\n");
    printf("3. Metatroph se fraga Elbetias\n");
    printf("4. Metatroph se dollaria Canada\n");
    printf("5. Metatroph se gien\n");
    printf("6. Exodos\n");

    printf("Dwse epilogh: ");
    Choice = GetInteger();
    return Choice;
}

double conversion(int C, int AM){
    double value;

    if (C == 1){
        value = AM / usd;
    }
    else if (C == 2){
        value = AM / gbp;
    }
    else if (C == 3){
        value = AM / sfranc;
    }
    else if (C == 4){
        value = AM / cad;
    }
    else if (C == 5){
        value = AM / yen;
    }

    return value;
}

