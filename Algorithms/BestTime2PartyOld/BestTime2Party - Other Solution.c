#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main1(){
    int i,j, numberOfCelebrities;
    double bestTime;

    /* Input for the table for the availability of the celebrities*/
    printf("Give the number of celebrities who will attend the charity Xmas bazaar: ");
    numberOfCelebrities = GetInteger();

    int Celebrities[numberOfCelebrities][2], TimeAtTheEvent[numberOfCelebrities], foundArrival[6][1], foundDeparture[6][1], SubtractionOfDepartureAndArrival[6][1], max;

    for (i = 0; i <= (numberOfCelebrities - 1 ); i++){
        for (j = 0; j <= 1; j++){
            if (j == 0){
                printf("Please give me the arrival time of the %dst celebrity: ", (i+1));
                Celebrities[i][j] = GetInteger();
            }
            else {
                printf("Please give me the departure time of the %dst celebrity: ", (i+1));
                Celebrities[i][j] = GetInteger();
            }
        }

    }

    /*Calculation of the time that the celebrities will remain at the bazaar*/
    for (i = 0; i <= (numberOfCelebrities - 1); i++){
        for (j = 1; j < 2; j++){
            TimeAtTheEvent[i] = Celebrities[i][j] - Celebrities[i][j - 1];
        }
    }

    /*printing the first tables*/
    for (i = 0; i <= (numberOfCelebrities - 1); i++){
            printf(" %d", Celebrities[i][0]);
            printf(" %d\n", Celebrities[i][1]);
    }
    printf("\n");
    for (i = 0; i < numberOfCelebrities; i++){
            printf(" %d\n", TimeAtTheEvent[i]);
    }
    printf("\n");

    /*Searching the tables to find the best time to be at the bazaar*/
    /*Searching the arrivals*/
    for (i = 0; i <= 5; i++){
        foundArrival[i][0] = 0;
    }


        for (i = 0; i <= (numberOfCelebrities - 1); i++){
                if (Celebrities[i][0] == 18){
                    foundArrival[0][0] = foundArrival[0][0] + 1;
                }
                if (Celebrities[i][0] == 19){
                    foundArrival[1][0] = foundArrival[1][0] + 1;
                }
                if (Celebrities[i][0] == 20){
                    foundArrival[2][0] = foundArrival[2][0] + 1;
                }
                if (Celebrities[i][0] == 21){
                    foundArrival[3][0] = foundArrival[3][0] + 1;
                }
                if (Celebrities[i][0] == 22){
                    foundArrival[4][0] = foundArrival[4][0] + 1;
                }
                if (Celebrities[i][0] == 23){
                    foundArrival[5][0] = foundArrival[5][0] + 1;
                }
            }

    for(i = 0; i <= 5; i++){
        printf ("%d ", foundArrival[i][0]);
    }
    printf("\n");
    /*End of arrival search*/
    /*Searching the departures*/

    for (i = 0; i <= 5; i++){
        foundDeparture[i][0] = 0;
    }


        for (i = 0; i <= (numberOfCelebrities - 1); i++){
                if (Celebrities[i][1] == 18){
                    foundDeparture[0][0] = foundDeparture[0][0] + 1;
                }
                if (Celebrities[i][1] == 19){
                    foundDeparture[1][0] = foundDeparture[1][0] + 1;
                }
                if (Celebrities[i][1] == 20){
                    foundDeparture[2][0] = foundDeparture[2][0] + 1;
                }
                if (Celebrities[i][1] == 21){
                    foundDeparture[3][0] = foundDeparture[3][0] + 1;
                }
                if (Celebrities[i][1] == 22){
                    foundDeparture[4][0] = foundDeparture[4][0] + 1;
                }
                if (Celebrities[i][1] == 23){
                    foundDeparture[5][0] = foundDeparture[5][0] + 1;
                }
            }

    for(i = 0; i <= 5; i++){
        printf ("%d ", foundDeparture[i][0]);
    }
    printf("\n");
    /*End of departure search*/

    /*I will subtract the arrival from the departure (foundDeparture - foundArrival) to see where are the most celebrities*/
    for (i = 0; i <= (numberOfCelebrities - 1); i++){
        SubtractionOfDepartureAndArrival[i][0] = foundDeparture[i][0] - foundArrival[i][0];
    }

    for(i = 0; i <= 5; i++){
        printf ("%d ", SubtractionOfDepartureAndArrival[i][0]);
    }
    printf("\n");
    /*End of Subtraction*/

    /*I will find the maximum subtraction and that will be the amount of celebrities at the event at that time*/
    max = SubtractionOfDepartureAndArrival[0][0];
    bestTime = 18.00;
    for (i = 1; i <= 5; i++){
        if (SubtractionOfDepartureAndArrival[i][0] > max){
            max = SubtractionOfDepartureAndArrival[i][0];
            if (i == 1){
                bestTime = 19.00;
            }
            if (i == 2){
                bestTime = 20.00;
            }
            if (i == 3){
                bestTime = 21.00;
            }
            if (i == 4){
                bestTime = 22.00;
            }
            if (i == 5){
                bestTime = 23.00;
            }
        }
    }

    /*Print the final result*/
    printf("The optimal time where there will be the most celebrities is from %f to %f\n", (bestTime - 1.00), bestTime);

return 0;
}
