#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

typedef struct{
    int width;
    int height;
    int depth;
    int area;
    int volume;
}box;

void get_box_information(box *a_box);
void calc_box_area(box *a_box);
void calc_box_volume(box *a_box);

int main(){
    box theBox;

    get_box_information(&theBox);

    calc_box_area(&theBox);

    calc_box_volume(&theBox);

    printf("To emvadon tou koutiou einai %d cm2\n", theBox.area);
    printf("O ogos tou koutiou einai %d cm3\n", theBox.volume);

return 0;
}

void get_box_information(box *a_box){
    printf("Dose to mikos tou koutiou se cm: ");
    a_box->width = GetInteger();

    printf("Dose to ypsos tou koutiou se cm: ");
    a_box->height = GetInteger();

    printf("Dose to vathos tou koutiou se cm: ");
    a_box->depth = GetInteger();
}

void calc_box_area(box *a_box){
    a_box->area = 2*a_box->width*a_box->depth + 2*a_box->height*a_box->depth + 2*a_box->height*a_box->width;
}

void calc_box_volume(box *a_box){
    a_box->volume = a_box->height * a_box->depth * a_box->width;
}
