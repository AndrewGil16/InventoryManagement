#ifndef ITEM_H
#define ITEM_H
#include <stdio.h>

extern void saveNewItemToCSV();
extern void initializeCSV();
void createItem();
typedef struct

{
    char commandSection[9][20];
    char itemName[100];
    char itemCategory[100];
    char itemSize[10];
    char placesListed[10];
    char skuNumber[40];
    char tripNumber[40];
    char listDate[40];
    char sellDate[40];
    char orderEarnings[40];
    
} Item_t;


typedef struct{
    char itemName[100];
    char itemCategory[100];
    char itemSize[10];
    char placesListed[10];
    char listDate[40];
    char sellDate[40];
    char orderEarnings[40];
    char skuNumber[40];
    char tripNumber[40];
} Inventory_t;


//extern struct Inventory_t currentInventory[100];
extern int itemCount;


//load items from csv
//save new items to csv
typedef struct {
    int tripNumber;
    float tripCost;
    float tripEarnings;
    //trip date

} Trips;


#endif 