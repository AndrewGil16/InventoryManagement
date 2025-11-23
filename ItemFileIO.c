/************************************************
* ItemFileIO.c
* Author: Andrew Gilpatrick
* Date: 11/22/2025
* Manages all exporting/importing from CSV
***************************************************/








#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "item.h"
const char filename[100] = "items.csv";

void initializeCSV(){
    FILE *file = fopen(filename, "r");
    if (!file){
        perror("error opening file");
    }
    char line[1000];
    
    while(fgets(line, sizeof(line), file)){
        line[strcspn(line, "\n")] = 0;

        char *token = strtok(line, ",'");
        while (token != NULL){
            printf("%s | ",token);
            token = strtok(NULL, ",");
        }
        printf("\n");
    }
   fclose(file); 
}
//save new item with append
//FILE *fp = fopen("inventory.csv", "a");
//The OS always moves the file pointer to the end before each write.
// so i can just do: fprintf(fp, "%d,%s,%.2f,%d\n", id, name, price, quantity);




void readCSV(){





}



void saveNewItemToCSV(){
    FILE *file = fopen(filename, "w");
    if (!file){
        perror("error opening file");
    }
    for(int i = 0; i < 3; i++){
        fprintf(file,"%s %s \n",stockCount[i].itemName,stockCount[i].itemCategory);
    }


}

