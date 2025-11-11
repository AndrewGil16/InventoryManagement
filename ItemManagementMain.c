#include <stdio.h>
#include <string.h>
#include "item.h"

int main (int argc, char *argv[]){
    printf("welcome to inventory managemnt");
    scanf("%49s", input);
    if (input == "1"){
        command = 1;
    }


    switch(command){
        case 1:
        newListing();
        saveNewItemToCSV();
        break;

        case 2:
        printf("in progress");

    }




}