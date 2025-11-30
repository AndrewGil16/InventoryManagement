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
const char writeCSV[150] = "itemsAfterRead.csv";
int count = 0;
Inventory_t currentInventory[100];
void initializeCSV(){
    FILE *file = fopen(filename, "r");
    if (!file){
        perror("error opening file");
    }
    char lineBuffer[500];                          //max character count for a line
    Item_t buffer;
    while(fgets(lineBuffer, sizeof(lineBuffer), file) != NULL){    
        //trim newline
        lineBuffer[strcspn(lineBuffer, "\n")] = '\0';
        static int lineNum = 0;
        printf("Reading Line: %d -> %s\n",++lineNum,lineBuffer);    
        char *token = strtok(lineBuffer,",");                           // char pointer cuz its a string so points to start of the string
        strcpy (buffer.commandSection[0], token);                       // first column going into new items "location of value"
       


        // assign following tokens to proper column #'s
        for (int i = 1; i < columnNumber; i++){                         //use i to pick from the column count array to decide where str tok value goes
            token = strtok(NULL,",");                                   // advance token for next
            strcpy(buffer.commandSection[i],token);                     //strcpy(dest, source)
            //printf("%s going into section %d \n", token, i);            // verified that token is going into proper command section location
        } 
        // debug status
        //printf("success after the for loop\n\n");
        sleep(2);
        // Assign to proper places
        printf("Assigning buffer -> inventory\n");
        strcpy(currentInventory[count].skuNumber, buffer.commandSection[0]);
        strcpy(currentInventory[count].itemName, buffer.commandSection[1]);
        strcpy(currentInventory[count].itemCategory, buffer.commandSection[2]);
        strcpy(currentInventory[count].itemSize, buffer.commandSection[3]);
        strcpy(currentInventory[count].tripNumber, buffer.commandSection[4]);
        strcpy(currentInventory[count].placesListed, buffer.commandSection[5]);
        strcpy(currentInventory[count].listDate, buffer.commandSection[6]);
        strcpy(currentInventory[count].sellDate, buffer.commandSection[7]);
        strcpy(currentInventory[count].orderEarnings, buffer.commandSection[8]);
        count++;
    }
    FILE *file2 = fopen(writeCSV, "w");                             // second csv file to verify it gets and outputs proper data upon initialization
        if (!file2){
            perror("error opening file");
        }
        for(int i = 0; i < 3; i++){
        printf("printing to after read csv file...\n\n");
        fprintf(file2, "%s,%s,%s,%s,%s,%s,%s,%s,%s",currentInventory[i].skuNumber,
            currentInventory[i].itemName,
            currentInventory[i].itemCategory,
            currentInventory[i].itemSize,
            currentInventory[i].tripNumber,
            currentInventory[i].placesListed,
            currentInventory[i].listDate,
            currentInventory[i].sellDate,
            currentInventory[i].orderEarnings);
            printf("printed line -> csv\n");

            // debug
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
