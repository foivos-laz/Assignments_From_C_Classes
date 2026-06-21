#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int Fibonacci(int N);

int main(){
    int Number, X, i, x;

    printf("Dwse to n: ");
    Number = GetInteger();

    if (Number == 0){
        X = 0;
        printf("%5d\n", X);
    }

    else if (Number == 1){
        X = 1;
        printf("%5d\n", 1);
    }
    else{
        X = Fibonacci(Number);
        i = 0;
        while(i <= (Number - 1)) {
            x = Fibonacci(i);
            printf("%5d\n", x);
            i = i + 1;
        }
    }

    return 0;
}



int Fibonacci(int N){
    int last, i, result, previous_result;

    result = 0;
    last = 1;
    i = 1;
    for(i; i <= N; i = i + 1){
        previous_result = result;
        result += last;
        last = previous_result;
    }
    return result;
}
