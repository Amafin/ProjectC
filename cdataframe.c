#include "cdataframe.h"
#include <stdio.h>
#include "malloc.h"
#include "column.h"

///////////////////////////////// Filling of the data frame /////////////////////////////////


// Creation of an empty CDataframe
COLUMN** createdataframe(){
    COLUMN* CDATAFRAME[5];
    return CDATAFRAME;
}

// Fill in the CDataframe with user input
void fillingdataframe(COLUMN ** dataframe, COLUMN* col){
    int i = 0;
    while(dataframe[i+1] != NULL){
        i++;
    }
    dataframe[i+1] = col;
}

///////////////////// Hard filling of the dataframe


///////////////////////////////// Displaying of the data frame /////////////////////////////////


// Display the whole dataframe
void displaydataframe(COLUMN** dataframe){
    int i;
    char* string[10];
    for(i = 0; i < display_nbrow(dataframe); i++){
        {
            for(int j = 0; j < display_nbcol(dataframe); j++){
                convert_value(dataframe[j], j, string, sizeof(string));
                printf("%s     ", string[j]);
            }
            printf("\n");
        }
    }
}

// Display some row of the dataframe
void displayrow(COLUMN** dataframe, int start, int end){
    int i;
    char* string[10];
    for(i = start; i < end + 1; i++){
        for(int j = 0; j < display_nbcol(dataframe); j++){
            convert_value(dataframe[j], i, string, sizeof(string));
            printf("%s      ", *string);
        }
        printf("\n");
    }
}

// Display some column of the dataframe
void displaycol(COLUMN** dataframe, int start, int end){
    char* string[10];
    for(int i = 0; i < display_nbrow(dataframe); i++){
        if(i == 0){
            for(int k = start; k < end + 1; k++){
                printf("%s  ", dataframe[k]->title);
            }
        }
        for(int j = start; j < end + 1; j++){
            convert_value(dataframe[j], i, string, sizeof(string));
            printf("%s     ", *string);
        }
        printf("\n");
    }
}


///////////////////////////////// Usual operations on the data frame /////////////////////////////////


void addrow(COLUMN** dataframe){
    int i = 0;
    void* value;

    while(dataframe[i] != NULL){
        // Add your values to your new column
        switch(dataframe[i]->column_type){
            case NULLVAL:
                value = NULL;
                insert_value(dataframe[i], (void*)&value);
                break;
            case UINT:
                // Use the function insert_value to add the value
                printf("Enter a value:\n");
                scanf("%ud", (unsigned int *) &value);
                insert_value(dataframe[i], (void *) value);
                break;
            case INT:
                printf("Enter a value:\n");
                scanf("%d", (int *) &value);
                insert_value(dataframe[i], (void *) value);
                break;
            case CHAR:
                printf("Enter a value:\n");
                scanf("%c", (char *) &value);
                insert_value(dataframe[i], (void *) value);
                break;
            case FLOAT:
                printf("Enter a value:\n");
                scanf("%f", (float *) &value);
                insert_value(dataframe[i], (void *) value);
                break;
            case DOUBLE:
                printf("Enter a value:\n");
                scanf("%lf", (double *) &value);
                insert_value(dataframe[i], (void *) value);
                break;
            case STRING:
                printf("Enter a value:\n");
                scanf("%s", (char *) &value);
                insert_value(dataframe[i], (void *) value);
                break;
            case STRUCTURE:
                printf("Enter a value:\n");
                scanf("%d", (int *) &value);
                insert_value(dataframe[i], (void *) value);
                break;
        }
        i ++;
    }
}

// Free space used by a row
void delrow(COLUMN** dataframe, int RowToDel){
    int i = 0;
    while(dataframe[i] != NULL){
        free((dataframe[i])->data[RowToDel]);
        i++;
    }
}

// Add a column in the dataframe
void addcol(COLUMN** dataframe){
    COLUMN* col;
    int tmp;
    ENUM_TYPE type;
    char title[20];
    void* value;

    // Select the type of the data in the new column
    printf("You have: NULLVAL = 1, UINT = 2, INT = 3, CHAR = 4, FLOAT = 5, DOUBLE = 6, STRING = 7, STRUCTURE = 8\n");
    printf("Enter the type of value for the column:\n");
    scanf("%d", &tmp);

    // Depending on the number given, give the right type to the variable type
    switch(tmp){
        case 2:
            type = UINT;
            break;
        case 3:
            type = INT;
            break;
        case 4:
            type = CHAR;
            break;
        case 5:
            type = FLOAT;
            break;
        case 6:
            type = DOUBLE;
            break;
        case 7:
            type = STRING;
            break;
        case 8:
            type = STRUCTURE;
            break;
        default:
            type = NULLVAL;
    }

    // Enter the title of the new column
    printf("Enter the title of your new column:\n");
    scanf("%s", title);

    col = create_column(type, title);
    int entervalue = 1;

    switch(col->column_type){
        case NULLVAL:
            for(int i = 0; i < col->phys_size; i++) {
                value = NULL;
                insert_value(col, (void*)&value);
            }
            break;
        case UINT:
            while(entervalue == 1) {
                printf("Enter a value:\n");
                scanf("%ud", (unsigned int *) &value);
                insert_value(col, (void *) value);
                printf("Do you want to enter another value (1=Yes, 0=No)\n");
                scanf("%d", &entervalue);
            }
            break;
        case INT:
            while(entervalue == 1) {
                printf("Enter a value:\n");
                scanf("%d", (int *) &value);
                insert_value(col, (void *) value);
                printf("Do you want to enter another value (1=Yes, 0=No)\n");
                scanf("%d", &entervalue);
            }
            break;
        case CHAR:
            while(entervalue == 1) {
                printf("Enter a value:\n");
                scanf("%c", (char *) &value);
                insert_value(col, (void *) value);
                printf("Do you want to enter another value (1=Yes, 0=No)\n");
                scanf("%d", &entervalue);
            }
            break;
        case FLOAT:
            while(entervalue == 1) {
                printf("Enter a value:\n");
                scanf("%f", (float *) &value);
                insert_value(col, (void *) value);
                printf("Do you want to enter another value (1=Yes, 0=No)\n");
                scanf("%d", &entervalue);
            }
            break;
        case DOUBLE:
            while(entervalue == 1) {
                printf("Enter a value:\n");
                scanf("%lf", (double *) &value);
                insert_value(col, (void *) value);
                printf("Do you want to enter another value (1=Yes, 0=No)\n");
                scanf("%d", &entervalue);
            }
            break;
        case STRING:
            while(entervalue == 1) {
                printf("Enter a value:\n");
                scanf("%s", (char *) &value);
                insert_value(col, (void *) value);
                printf("Do you want to enter another value (1=Yes, 0=No)\n");
                scanf("%d", &entervalue);
            }
            break;
        case STRUCTURE:
            while(entervalue == 1) {
                printf("Enter a value:\n");
                scanf("%d", (int *) &value);
                insert_value(col, (void *) value);
                printf("Do you want to enter another value (1=Yes, 0=No)\n");
                scanf("%d", &entervalue);
            }
            break;
    }
    fillingdataframe(dataframe, col);
}

// Free space used by the column and the column
void delcol(COLUMN** dataframe, int ColToDel){
    delete_column(&(dataframe[ColToDel]));
}

// Rename a column
void renamecol(COLUMN** dataframe, int ColToRename){
    char NewName[20];
    printf("Enter a new name for your column");
    scanf("%s", NewName);
    dataframe[ColToRename]->title = NewName;
}

// Check if a value is in the dataframe
void checkvalue(COLUMN** dataframe, void* value){
    int i, j, truth;
    i = 0;
    truth = 0;
    while(dataframe[i] != NULL && truth != 1){
        for(j = 0; j < dataframe[i]->log_size && truth != 1; j++){
            if(dataframe[i]->data[j] == value){
                truth = 1;
            }
        }
    }
    if(truth == 1){
        printf("The value is in the dataframe");
    }
    else{
        printf("The value is not in the dataframe");
    }
}

// Access a value and replace it with a new value given by the user
void accessvalue(COLUMN* dataframe, int rownb, int colnb, void* ReplaceValue){
    dataframe[colnb].data[rownb] = ReplaceValue;
}

// Gives the title of all the columns
void display_name(COLUMN** dataframe){
    int i = 0;
    while(dataframe[i] != NULL){
        printf("The title of the column %d is %s\n", i, dataframe[i]->title);
        i++;
    }
}


///////////////////////////////// Analysis and statistics of the data frame /////////////////////////////////


// Print the number of row in the dataframe
unsigned int display_nbrow(COLUMN** dataframe){
    unsigned int max_row = 0;
    int i = 0;
    while(dataframe[i] != NULL){
        if(dataframe[i]->log_size > max_row){
            max_row = dataframe[i]->log_size;
        }
    }
    printf("There are %ud rows at the maximum", max_row);
    return max_row;
}

// Print the number of columns in the dataframe
int display_nbcol(COLUMN** dataframe){
    int i = 0;
    while (dataframe[i] != NULL){
        i++;
    }
    printf("The dataframe contains %d columns", i);
    return i;
}

// Print the occurrences of a value given in the whole dataframe
void nb_occurences(COLUMN ** dataframe, void* value){
    int compteur = 0, i = 0;
    while(dataframe[i] != NULL) {
        compteur += value_occ(value, dataframe[i]);
        i++;
    }
}

// Return the number of value greater than the one given
int nb_sup(COLUMN ** dataframe, void* value){
    int compteur = 0, i = 0;
    while(dataframe[i]!=NULL) {
        compteur += value_greater(dataframe[i], value);
        i++;
    }
    return compteur;
}

// Return the number of value less than the one given
int nb_less(COLUMN ** dataframe, void* value){
    int compteur = 0,i = 0;
    while(dataframe[i]!=NULL) {
        compteur += value_less(dataframe[i], value);
        i++;
    }
    return compteur;
}
