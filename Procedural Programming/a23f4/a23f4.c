#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

bool Valid_Time(int H, int M, int S);

int main(){
    int hours, minutes, seconds;
    bool valid;

    printf("Dwse tis ores: ");
    hours = GetInteger();
    printf("Dwse ta lepta: ");
    minutes = GetInteger();
    printf("Dwse ta defterolepta: ");
    seconds = GetInteger();

    valid = Valid_Time(hours, minutes, seconds);
    if (valid == TRUE){
        printf("Valid: yes\n");
    }
    else if (valid == FALSE){
        printf("Valid: no\n");
    }

    return 0;
}

bool Valid_Time(int H, int M, int S){
    if ((H >= 0 && H <= 23) && (M >= 0 && M <= 59) && (S >= 0 && S <= 59)){
        return TRUE;
    }
    else {
        return FALSE;
    }
}
