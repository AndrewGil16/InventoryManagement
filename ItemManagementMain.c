/************************************************
* ItemManagementMain.c
* Author: Andrew Gilpatrick
* Date: 11/22/2025
* main
***************************************************/




#include <stdio.h>
#include <string.h>
#include "item.h"
#include <unistd.h>
// to do:
// total item counter
/*
    char itemName[100];
    char itemCategory[100];
    char itemSize[10];
    char placesListed[10];
    int skuNumber;
    int tripNumber;
    */


    // FILE IO FOR READING CSV
    // ON STARTUP LOOP THROUGH EACH LINE
    // INCREMENT ITEM COUNT EACH NUMBER AND VERIFY WITH SKU
    // all new items go at the location



Item_t stockCount[100];

int main (int argc, char *argv[]){
    printf("welcome to inventory managemnt\n");
    createItem();
    printf("Creating ITEM...\n");
    sleep(5);
    for(int i = 0; i < 3; i++){
        printf("Item: %s \nCategory: %s \nSize: %s \nPlaces Listed: %s \nSKU: %d \nTrip Number %d \n", 
            stockCount[i].itemName, stockCount[i].itemCategory, stockCount[i].itemSize, stockCount[i].placesListed, stockCount[i].skuNumber, stockCount[i].tripNumber);
    }
    saveNewItemToCSV();



}