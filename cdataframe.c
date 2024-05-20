#include "cdataframe.h"
#include <stddef.h>
#include <stdio.h>
#include "malloc.h"
#include "column.h"

///////////////////////////////// Filling of the data frame /////////////////////////////////

/**
 * CDataFrame
 * Bastien COULON, Amandine FINAS
 * Cdataframe.c is where all the functions are written to handle the Cdataframe work
 */


// Creation of an empty CDataframe
COLUMN** createdataframe(){
    COLUMN** CDATAFRAME;
    CDATAFRAME = (COLUMN **) malloc(CAPACITY * sizeof(COLUMN *));
    return CDATAFRAME;
}

// Fill in the CDataframe with user input
void fillingdataframe(COLUMN ** dataframe, COLUMN* col, int* log_size_array){
    dataframe[*log_size_array] = (COLUMN *) malloc(sizeof(COLUMN));
    dataframe[*log_size_array] = col;
    *log_size_array = *log_size_array + 1;
}

void hardfillingdataframe(COLUMN** dataframe, int* log_size_array){
    COLUMN* newcol;

    // Initialize a new column
    newcol = (COLUMN*) malloc(sizeof (COLUMN));
    newcol->title = "User col";
    newcol->phys_size = 100;
    newcol->log_size = 0;
    newcol->column_type = INT;
    newcol->index = NULL;
    newcol->index = (unsigned long long int *) malloc(newcol->phys_size * sizeof(int));

    // Enter values in the column
    for(int i = 0; i < 5; i++){
        newcol->data[newcol->log_size] = (COL_TYPE *) malloc(sizeof(int));
        *(int *)newcol->data[i] = i + 1;
        newcol->index[newcol->log_size] = newcol->log_size;
        newcol->log_size += 1;
    }

    // Put the new column in the dataframe
    fillingdataframe(dataframe, newcol, log_size_array);
}


///////////////////////////////// Displaying of the data frame /////////////////////////////////


// Display the whole dataframe
void displaydataframe(COLUMN** dataframe, int* log_size_array){
    int i;
    char* string[20];
    printf("Entered\n");
    for(i = 0; i < display_nbrow(dataframe, log_size_array); i++){
        {
            for(int j = 0; j < display_nbcol(dataframe, log_size_array); j++){
                convert_value(dataframe[j], dataframe[j]->index[j], &string[20], sizeof(string));
                printf("%s     ", string[j]);
            }
            printf("\n");
        }
    }
}

// Display some row of the dataframe
void displayrow(COLUMN** dataframe, int start, int end, int* log_size_array){
    int i;
    char* string[10];
    for(i = start-1; i < end; i++){
        for(int j = 0; j < display_nbcol(dataframe, log_size_array); j++){
            convert_value(dataframe[j], i, string, sizeof(string));
            printf("%s      ", *string);
        }
        printf("\n");
    }
}

// Display some column of the dataframe
void displaycol(COLUMN** dataframe, int start, int end, int* log_size_array){
    char* string[10];
    printf("Entrée fonction");
    for(int i = 0; i < display_nbrow(dataframe, log_size_array); i++){
        if(i == 0){
            for(int k = start-1; k < end; k++){
                printf("%s  ", dataframe[k]->title);
            }
        }
        for(int j = start; j < end; j++){
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
void addcol(COLUMN** dataframe, int* log_size_array){
    COLUMN* col;
    int tmp;
    ENUM_TYPE type;
    char title[50];
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
                insert_value(col, (void  *) value);
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
    fillingdataframe(dataframe, col, log_size_array);
}

// Free space used by the column and the column
void delcol(COLUMN** dataframe, int ColToDel){
    delete_column(&(dataframe[ColToDel-1]));
}

// Rename a column
void renamecol(COLUMN** dataframe, int ColToRename){
    char NewName[20];
    printf("Enter a new name for your column:\n");
    scanf("%s", NewName);
    dataframe[ColToRename-1]->title = NewName;
}

// Check if a value is in the dataframe
void checkvalue(COLUMN** dataframe, void* value){
    int i, j, truth;
    i = 0;
    truth = 0;
    while(dataframe[i] != NULL && truth != 1){
        for(j = 0; j < dataframe[i]->log_size && truth != 1; j++){
            char* string[20];
            convert_value(dataframe[i], i, &string[20], sizeof(string));
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
    dataframe[colnb-1].data[rownb-1] = ReplaceValue;
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
unsigned int display_nbrow(COLUMN** dataframe, int* log_size_array){
    unsigned int max_row = 0;
    for(int i = 0; i < *log_size_array; i++){
        if(dataframe[i]->log_size > max_row){
            max_row = dataframe[i]->log_size;
        }
    }
    return max_row;
}

// Print the number of columns in the dataframe
int display_nbcol(COLUMN** dataframe, int* log_size_array){
    int counter = 0;
    for(int i = 0; i < *log_size_array; i++){
        counter++;
    }
    return counter;
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
