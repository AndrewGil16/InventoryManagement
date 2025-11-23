#ifndef ITEM_H
#define ITEM_H
#include <stdio.h>

extern void saveNewItemToCSV();
void createItem();
typedef struct
{
    char itemName[100];
    char itemCategory[100];
    char itemSize[10];
    char placesListed[10];
    int skuNumber;
    int tripNumber;
    //listdate
    //sell date
    //float orderEarnings;
    
} Item_t;
extern int itemCount;
extern Item_t stockCount[100];

//load items from csv
//save new items to csv
typedef struct {
    int tripNumber;
    float tripCost;
    float tripEarnings;
    //trip date

} Trips;


Item_t newListing();




#endif 