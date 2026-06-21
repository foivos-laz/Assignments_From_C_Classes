#include <stdio.h>
#include "genlib.h"
#include "simpio.h"


int main(){
    int N , last, i, result;

    printf("N:");
    N = GetInteger();

    result = 1;
    last = 1;
    i = 2;
    for(i; i <= N; i = i + 1){
        result += last;
    }
    printf("%5d", result);

    return 0;
}
