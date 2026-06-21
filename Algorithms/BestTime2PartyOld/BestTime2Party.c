
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main(){
    int i,j, numberOfCelebrities, max, maxTime;
    double bestTimeStart, bestTimeEnd, lowerLimit, UpperLimit;

    /* Input for the table for the availability of the celebrities*/
    printf("Give the number of celebrities who will attend the charity Xmas bazaar: ");
      scanf(" %d", &numberOfCelebrities);

    int Celebrities[numberOfCelebrities][6], additionPerCol[6];

    for (i = 0; i <= (numberOfCelebrities - 1); i++){
        for (j = 0; j <= 5; j++){
            Celebrities[i][j] = 0;
        }
    }

    for (i = 0; i <= (numberOfCelebrities - 1 ); i++){
                printf("Please give me the arrival time of the %dst celebrity: ", (i+1));
                scanf(" %lf", &lowerLimit);

                printf("Please give me the departure time of the %dst celebrity: ", (i+1));
                scanf(" %lf", &UpperLimit);

                if (lowerLimit == 18.00 && UpperLimit == 19.00){
                    for (j = 0; j < 1; j++){
                        Celebrities[i][j] = 1;
                    }
                }
                else if (lowerLimit == 18.00 && UpperLimit == 20.00){
                    for (j = 0; j < 2; j++){
                        Celebrities[i][j] = 1;
                    }
                }
                else if (lowerLimit == 18.00 && UpperLimit == 21.00){
                    for (j = 0; j < 3; j++){
                        Celebrities[i][j] = 1;
                    }
                }
                else if (lowerLimit == 18.00 && UpperLimit == 22.00){
                    for (j = 0; j < 4; j++){
                        Celebrities[i][j] = 1;
                    }
                }
                else if (lowerLimit == 18.00 && UpperLimit == 23.00){
                    for (j = 0; j < 5; j++){
                        Celebrities[i][j] = 1;
                    }
                }
                else if (lowerLimit == 18.00 && UpperLimit == 24.00){
                    for (j = 0; j < 6; j++){
                        Celebrities[i][j] = 1;
                    }
                }
                else if (lowerLimit == 19.00 && UpperLimit == 20.00){
                    for (j = 1; j < 2; j++){
                        Celebrities[i][j] = 1;
                    }
                }
                else if (lowerLimit == 19.00 && UpperLimit == 21.00){
                    for (j = 1; j < 3; j++){
                        Celebrities[i][j] = 1;
                    }
                }
                else if (lowerLimit == 19.00 && UpperLimit == 22.00){
                    for (j = 1; j < 4; j++){
                        Celebrities[i][j] = 1;
                    }
                }
                else if (lowerLimit == 19.00 && UpperLimit == 23.00){
                    for (j = 1; j < 5; j++){
                        Celebrities[i][j] = 1;
                    }
                }
                else if (lowerLimit == 19.00 && UpperLimit == 24.00){
                    for (j = 1; j < 6; j++){
                        Celebrities[i][j] = 1;
                    }
                }
                else if (lowerLimit == 20.00 && UpperLimit == 21.00){
                    for (j = 2; j < 3; j++){
                        Celebrities[i][j] = 1;
                    }
                }
                else if (lowerLimit == 20.00 && UpperLimit == 22.00){
                    for (j = 2; j < 4; j++){
                        Celebrities[i][j] = 1;
                    }
                }
                else if (lowerLimit == 20.00 && UpperLimit == 23.00){
                    for (j = 2; j < 5; j++){
                        Celebrities[i][j] = 1;
                    }
                }
                else if (lowerLimit == 20.00 && UpperLimit == 24.00){
                    for (j = 2; j < 6; j++){
                        Celebrities[i][j] = 1;
                    }
                }
                else if (lowerLimit == 21.00 && UpperLimit == 22.00){
                    for (j = 3; j < 4; j++){
                        Celebrities[i][j] = 1;
                    }
                }
                else if (lowerLimit == 21.00 && UpperLimit == 23.00){
                    for (j = 3; j < 5; j++){
                        Celebrities[i][j] = 1;
                    }
                }
                else if (lowerLimit == 21.00 && UpperLimit == 24.00){
                    for (j = 3; j < 6; j++){
                        Celebrities[i][j] = 1;
                    }
                }
                else if (lowerLimit == 22.00 && UpperLimit == 23.00){
                    for (j = 4; j < 5; j++){
                        Celebrities[i][j] = 1;
                    }
                }
                else if (lowerLimit == 22.00 && UpperLimit == 24.00){
                    for (j = 4; j < 6; j++){
                        Celebrities[i][j] = 1;
                    }
                }
                else if (lowerLimit == 23.00 && UpperLimit == 24.00){
                    for (j = 5; j < 6; j++){
                        Celebrities[i][j] = 1;
                    }
                }
    }

    printf("\n");
    /*I am calculating the total amount of time that each celebrity was there by adding each column*/
    for (i = 0; i < 6; i++){
        additionPerCol[i] = 0;
    }

    for (i = 0; i < numberOfCelebrities; i++){
        for (j = 0; j < 6; j++){
            additionPerCol[j] = additionPerCol[j] + Celebrities[i][j];
        }
    }

    /*I will find the maximum addition and that will be the amount of celebrities at the event at that time*/
    max = additionPerCol[0];
    maxTime = 0;
    bestTimeEnd = 19.00;
    for (i = 1; i < 6; i++){
        if (additionPerCol[i] > max){
            max = additionPerCol[i];
            maxTime = i;
            }
        }

    if (maxTime == 1){
        bestTimeEnd = 20.00;
    }
    else if (maxTime == 2){
        bestTimeEnd = 21.00;
    }
    else if (maxTime == 3){
        bestTimeEnd = 22.00;
    }
    else if (maxTime == 4){
        bestTimeEnd = 23.00;
    }
    else if (maxTime == 5){
        bestTimeEnd = 24.00;
    }

    bestTimeStart = bestTimeEnd - 1.00;

    /*Print the final result*/
    printf("The optimal time where there will be the most celebrities is from %.2f to %.2f\n", bestTimeStart, bestTimeEnd);
    printf("Therefore the best time for the guest to arrive at the bazaar is at: %.2f\n", bestTimeStart);

    system("pause");
return 0;
}
