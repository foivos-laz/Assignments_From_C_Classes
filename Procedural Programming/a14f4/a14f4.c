#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int max(int A, int B);
int gr(int X, int Y, int Z);

int main(){
    double y;
    int a,b,c;

    printf("Dwse a: ");
    a = GetInteger();

    printf("Dwse b: ");
    b = GetInteger();

    printf("Dwse c: ");
    c = GetInteger();

    y = (((2 * max(a,b)) + (3 * gr(a,b,c))) / 4.0);
    printf("y = %.2f\n", y);

    return 0;
}


int max(int A, int B){
    if (A > B){
        return A;
    }
    else if (B > A){
        return B;
    }
}

int gr(int X, int Y, int Z){
        if (X > Y && X > Z ){
            return X;
        }
        else if (Y > X && Y > Z){
                return Y;
        }
        else if (Z > X && Z > Y){
                return Z;
        }
}
