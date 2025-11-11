#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "item.h"

const char filename[100] = "items.csv";


void saveNewItemToCSV(){
    FILE *file = fopen(filename, "w");
    if (!file){
        perror("error opening file");
    }
    for (int i = 0; i <= totalInventory; i++){

        fprintf(file, "%s,%d,%d,%s,\n", itemStorage[0].itemName, print.tripNumber, print.skuNumber, print.itemCategory);
    }
    fclose(file);
    printf("check csv");
    return 0;

}