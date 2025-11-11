#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STORAGE
Item print;

static Item itemStorage[MAX_STORAGE];
Item newListing(void){
    
    Item newTest;
    char testName[100];
    char testCategory[100];
    int testSku;
    int testTrip;
    printf("Enter the name of item:\n");
    scanf("%49s", &testName);
    printf("\nEnter the trip number:\n");
    scanf("%d", &testTrip);
    printf("\nenter SKU\n");
    scanf("%d", &testSku);
    printf("\n Enter Item Category:\n");
    scanf("%49s", &testCategory);
    strcpy(newTest.itemName, testName);
    strcpy(newTest.itemCategory, testCategory);
    newTest.skuNumber = testSku;
    newTest.tripNumber = testTrip;
    itemStorage[0] = newTest;
}


