#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

long encode(long starting_code);
bool check(long finalcode);

int main(){
    long lowerLimit, upperLimit, code, encodedCode;
    int i;
    bool checkedCode;

    printf("Lower Limit: ");
    lowerLimit = GetLong();
    printf("Upper Limit: ");
    upperLimit = GetLong();

    for (i = 0; i <= (upperLimit - lowerLimit); i++){
        code = lowerLimit + i;
        encodedCode = encode(code);
        checkedCode = check(encodedCode);
        printf("Code: %ld ", code);
        printf("Encoding: %ld ", encodedCode);
        if (checkedCode == TRUE){
            printf("isValid:yes\n");
        }
        else if (checkedCode == FALSE){
            printf("isValid:no\n");
        }
    }
    return 0;
}

long encode(long starting_code){
    long final_code, checkDigits, spacing;

    checkDigits = ((98 - (starting_code * 100) % 97) % 97);

    spacing = (starting_code / 0.01);
    final_code = (spacing + checkDigits);

    return final_code;
}

bool check(long finalcode){
    if (finalcode % 97 == 1){
        return TRUE;
    }
    else if(finalcode % 97 != 1){
        return FALSE;
    }
}
