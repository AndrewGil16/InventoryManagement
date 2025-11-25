/************************************************
* ItemFileIO.c
* Author: Andrew Gilpatrick
* Date: 11/22/2025
* Manages all exporting/importing from CSV
***************************************************/
//CSV Format: SKU, Item, Category, Size, Trip #, Places Listed, List Date, Sell Date, Order Earnings
//str tok uses internal pointer to track where it left off, after first iteration do "(NULL, ",")" for remaining parsing 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "item.h"


int columnNumber = 9;                                                   // amount of colums in csv, keeps track of where vars are going
const char filename[100] = "items.csv";
const char writeCSV[100] = "itemsAfterRead.csv";

void initializeCSV(){
    FILE *file = fopen(filename, "r");
    if (!file){
        perror("error opening file");
    }
    char lineBuffer[1000];                                              //max character count for a line
    while(fgets(lineBuffer, sizeof(lineBuffer), file) != NULL){

        // create placeholder structs for transfering from CSV to inventory
        Item_t buffer;
        Inventory_t toInventory;
        char *token = strtok(lineBuffer,",");                           // char pointer cuz its a string so points to start of the string
        strcpy (buffer.commandSection[0], token);                       // first column going into new items "location of value"


        // debug status
        printf("%s going into section 0 \n",token); 
        printf("success before the for loop\n\n");


        // assign following tokens to proper column #'s
        for (int i = 1; i < columnNumber; i++){                         //use i to pick from the column count array to decide where str tok value goes
            token = strtok(NULL,",");                                   // advance token for next
            strcpy(buffer.commandSection[i],token);                     //strcpy(dest, source)
            printf("%s going into section %d \n", token, i);            // verified that token is going into proper command section location
        } 


        // debug status
        printf("success after the for loop\n\n");
        sleep(2);
        printf("moving structures...\n");


        // move buffer to actual inventory space with proper type conversions **potentially add a real buffer array to keep system busy
        // Assign to proper places
        strcpy(toInventory.skuNumber, buffer.commandSection[0]);
        strcpy(toInventory.itemName, buffer.commandSection[1]);
        strcpy(toInventory.itemCategory, buffer.commandSection[2]);
        strcpy(toInventory.itemSize, buffer.commandSection[3]);
        strcpy(toInventory.tripNumber, buffer.commandSection[4]);
        strcpy(toInventory.placesListed, buffer.commandSection[5]);
        strcpy(toInventory.listDate, buffer.commandSection[6]);
        strcpy(toInventory.sellDate, buffer.commandSection[7]);
        strcpy(toInventory.orderEarnings, buffer.commandSection[8]);

        // debug status
        sleep(2);
        printf("success moving structures\n\n");
        sleep(2);
        printf("opening file 2\n");
        

        FILE *file2 = fopen(writeCSV, "w");                             // second csv file to verify it gets and outputs proper data upon initialization
        if (!file2){
            perror("error opening file");
        }
        printf("printing to after read csv file...\n\n");
        fprintf(file2, "%s,%s,%s,%s,%s,%s,%s,%s,%s",toInventory.skuNumber,
            toInventory.itemName,
            toInventory.itemCategory,
            toInventory.itemSize,
            toInventory.tripNumber,
            toInventory.placesListed,
            toInventory.listDate,
            toInventory.sellDate,
            toInventory.orderEarnings); 

            // debug
            sleep(1);
            printf("success writing to after read csv. closing both files...");
            fclose(file);
            fclose(file2);
            sleep(2);
            printf("success!");

    }  
}






//save new item with append
//FILE *fp = fopen("inventory.csv", "a");
//The OS always moves the file pointer to the end before each write.
// so i can just do: fprintf(fp, "%d,%s,%.2f,%d\n", id, name, price, quantity);
void readCSV();
void saveNewItemToCSV(){}
