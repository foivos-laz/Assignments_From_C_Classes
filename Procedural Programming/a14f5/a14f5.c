#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int TableLength();
void TableContents(int tabLength, long table[tabLength]);
void PrintTable(int tabLength, long table[tabLength]);
int FindMaxPosition(int tabLength, long table[tabLength], int index[tabLength]);

int main(){
    int tableLength, i;

    tableLength = TableLength();

    long Table[tableLength], maxCount;
    int Index[tableLength];

    TableContents(tableLength, Table);

    PrintTable(tableLength, Table);

    maxCount = FindMaxPosition(tableLength, Table, Index);

    printf("Plithos maximum %d\n", maxCount);
    printf("Positions of maximum");
    for (i = 0; i < maxCount; i++){
        printf(" %d", Index[i]);
    }

return 0;
}

int TableLength(){
    int size;

    printf("Dwse to plhthos twn stoixeiwn: ");
    size = GetInteger();

    return size;
}

void TableContents(int tabLength, long table[tabLength]){
    int i;

    for (i = 0; i < tabLength; i++){
        table[i] = GetLong();
    }
}

void PrintTable(int tabLength, long table[tabLength]){
    int i;

    for (i = 0; i < tabLength; i++){
        if (i != tabLength - 1){
            printf("%ld ", table[i]);
        }
        else if (i == tabLength - 1){
            printf("%ld\n", table[i]);
        }
    }
}

int FindMaxPosition(int tabLength, long table[tabLength], int index[tabLength]){
    int i, j, maxcount;
    long max = table[0];

    index[0] = 0;
    j = 0;
    maxcount = 1;

    for (i = 1; i < tabLength; i++){
        if (max == table[i]){
            index[j + 1] = i;
            j++;
            maxcount += 1;
        }
        else if (max < table[i]){
            j = 0;
            index[j] = i;
            max = table[i];
            maxcount = 1;
        }
    }

    printf("maximum %ld \n", max);

    return maxcount;
}
