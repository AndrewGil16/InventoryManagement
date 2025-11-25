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

Item_t stockCount[100];



//file currently used for individual function testing

int main (void){
    printf("Testing Function...\n");
    initializeCSV();
    sleep(2);
    printf("Done");
}