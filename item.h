#ifndef ITEM_H
#define ITEM_H
#include <stdio.h>


int currentItem;
void saveNewItemToCSV();

typedef struct
{
    char itemName[100];
    int skuNumber;
    int tripNumber;
    char itemCategory[100];
    //listdate
    //sell date
    //float orderEarnings;
    //char itemSize[10];
    //LISTING LOCATIONS
} Item;

//load items from csv
//save new items to csv
typedef struct {
    int tripNumber;
    float tripCost;
    float tripEarnings;
    //trip date

} Trips;

int totalInventory;
int command;

Item newListing();
char input[50];




#endif 