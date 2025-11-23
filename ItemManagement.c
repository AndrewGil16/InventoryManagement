/************************************************
* ItemManagement.c
* Author: Andrew Gilpatrick
* Date: 11/22/2025
* Handles logic for individual items and inventory management
***************************************************/

#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STORAGE

int itemCount = 0;

void createItem(){
    Item_t item1;
    strcpy(item1.itemName, "boots");
    strcpy(item1.itemCategory, "Shoes");
    strcpy(item1.itemSize, "12M");
    strcpy(item1.placesListed,"DEMP");
    item1.skuNumber = 35;
    item1.tripNumber = 2;
    stockCount[itemCount] = item1;
    Item_t item2;
    itemCount++;
    strcpy(item2.itemName, "Venom");
    strcpy(item2.itemCategory, "Shirts");
    strcpy(item2.itemSize, "XL");
    strcpy(item2.placesListed,"DEMP");
    item2.skuNumber = 36;
    item2.tripNumber = 2;
    stockCount[itemCount] = item2;
}

// markAs sold
//edit item
//calculate days listed
// 



