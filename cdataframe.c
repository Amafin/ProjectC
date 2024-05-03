#include "cdataframe.h"
#include <stdio.h>
#include "malloc.h"
#include "column.h"

// Creation of an empty CDataframe
COLUMN** createdataframe(){
    COLUMN* CDATAFRAME[5];
    return CDATAFRAME;
}


// Filling in the CDataframe with user input
void fillingdataframe(COLUMN ** dataframe,COLUMN* col,int place){
    if(dataframe[place] == NULL) {
        dataframe[place] = col;
    }

    else{
        printf("This place is not empty !");
    }



}

void displaydataframe(COLUMN** dataframe){
    int i, j;
    char* string[10];
    for(i = 0; i<(*dataframe[i]).log_size; i++){
        {
            convert_value(dataframe[i],i, string, sizeof(string));
            printf("%s",string[i]);

        }
    }
}


void displaycol(COLUMN** dataframe, int start, int end){
    int i;
    char* string[10];
    for(i = start; i<end+1;i++){
        convert_value(dataframe[i],i, string, sizeof(string));
        printf("%s",string[i]);
    }
}

void addcol(COLUMN** dataframe,ENUM_TYPE type, char *title){
    COLUMN* col;
    int place;
    col = create_column(INT, title);
    printf("At which place do you want to add your column ?");
    scanf("%d",&place);
    fillingdataframe(dataframe,col,place);
}