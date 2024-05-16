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
void fillingdataframe(COLUMN ** dataframe,COLUMN* col,int place){
    if(dataframe[place] == NULL) {
        dataframe[place] = col;
    }
    else{
        printf("This place is not empty !");
    }
}


///////////////////// Hard filling of the dataframe


///////////////////////////////// Displaying of the data frame /////////////////////////////////


// Display the whole dataframe
void displaydataframe(COLUMN** dataframe){
    int i;
    char* string[10];
    for(i = 0; i<(*dataframe[i]).log_size; i++){
        {
            convert_value(dataframe[i],i, string, sizeof(string));
            printf("%s",string[i]);
        }
    }
}

// Display some row of the dataframe
void displayrow(COLUMN** dataframe, int start, int end){
    int i = 0;
    char* string[10];
    while(dataframe[i] != NULL){
        for(int j = start; j<end; j++) {
            convert_value(dataframe[i], i, string, sizeof(string));
            printf("%s\n",string[i]);
        }
        i++;
    }
}

// Display some column of the dataframe
void displaycol(COLUMN** dataframe, int start, int end){
    char* string[10];
    for(int i = start; i<end+1; i++){
        printf("Title : %s\n",dataframe[i]->title);
        convert_value(dataframe[i], i, string, sizeof(string));
        printf("%s\n",string[i]);
    }
}


///////////////////////////////// Usual operations on the data frame /////////////////////////////////


void addrow(COLUMN** dataframe){
    int i = 0;
    void* value;

    while(dataframe[i] != NULL){
        dataframe[i]->phys_size += 1;
        // Add your values to your new column
        switch(dataframe[i]->column_type){
            case NULLVAL:
                value = NULL;
                insert_value(dataframe[i], (void*)&value);
                break;
            case UINT:
                // TO CHANGE //
                // Use the function insert_value to add the value
                printf("Enter a value:\n");
                scanf("%u", (unsigned int *)&value);
                insert_value(dataframe[i], value);
                break;
            case INT:
                printf("hello world");
                printf("Enter a value:\n");
                scanf("%d", (int *)&value);
                printf("hello");
                insert_value(dataframe[i], (void *)value);
                printf("bye");
                break;
            case CHAR:
                printf("Enter a value:\n");
                scanf("%c", (char *)&value);
                insert_value(dataframe[i], value);
                break;
            case FLOAT:
                printf("Enter a value:\n");
                scanf("%f", (float *)&value);
                insert_value(dataframe[i], value);
                break;
            case DOUBLE:
                for(int i=0; dataframe[i]->log_size<dataframe[i]->phys_size; i++){
                    printf("Enter a value:\n");
                    scanf("%lf", (double *)&value);
                    insert_value(dataframe[i], value);
                }
                break;
            case STRING:
                printf("Enter a value:\n");
                scanf("%c", (char *)&value);
                insert_value(dataframe[i], value);
                break;
            case STRUCTURE:
                // TO CHANGE //

                // type = STRUCTURE;
                break;
        }
    }
}

// Free space used by the column and the column
void delrow(COLUMN** dataframe, int ColToDel){
    int i = 0;
    while(dataframe[i] != NULL){
        free((dataframe[i])->data[ColToDel]);
        i++;
    }
}

// Add a column in the dataframe
void addcol(COLUMN** dataframe){
    COLUMN* col;
    int tmp, place;
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

    switch(col->column_type){
        case NULLVAL:
            for(int i=0; col->log_size<col->phys_size; i++){
                col = NULL;
                insert_value(col, (void*)&value);
            }
            break;
        case UINT:
            // TO CHANGE //
            // Use the function insert_value to add the value
            for(int i=0; col->log_size<col->phys_size; i++){
                printf("Enter a value:\n");
                scanf("%u", (unsigned int *)&value);
                insert_value(col, value);
            }
            break;
        case INT:
            for(int i=0; col->log_size<col->phys_size; i++){
                printf("hello world");
                printf("Enter a value:\n");
                scanf("%d", (int *)&value);
                printf("hello");
                insert_value(col, (void *)value);
                printf("bye");
            }
            break;
        case CHAR:
            for(int i=0; col->log_size<col->phys_size; i++){
                printf("Enter a value:\n");
                scanf("%c", (char *)&value);
                insert_value(col, value);
            }
            break;
        case FLOAT:
            for(int i=0; col->log_size<col->phys_size; i++){
                printf("Enter a value:\n");
                scanf("%f", (float *)&value);
                insert_value(col, value);
            }
            break;
        case DOUBLE:
            for(int i=0; col->log_size<col->phys_size; i++){
                printf("Enter a value:\n");
                scanf("%lf", (double *)&value);
                insert_value(col, value);
            }
            break;
        case STRING:
            for(int i=0; col->log_size<col->phys_size; i++){
                printf("Enter a value:\n");
                scanf("%c", (char *)&value);
                insert_value(col, value);
            }
            break;
        case STRUCTURE:
            // TO CHANGE //

            // type = STRUCTURE;
            break;
    }

    printf("At which place do you want to add your column ?");
    scanf("%d",&place);
    fillingdataframe(dataframe, col, place);
}

// Free space used by the column and the column
void delcol(COLUMN** dataframe, int ColToDel){
    delete_column(&(dataframe[ColToDel]));
}

// Rename a column
void renamecol(COLUMN** dataframe, int ColToRename){
    char NewName[20];
    printf("Enter a new name for your column");
    scanf("%s",NewName);
    dataframe[ColToRename]->title = NewName;
}

// Check if a value is in the dataframe
void checkvalue(COLUMN** dataframe, void* value){
    int i,j,truth;
    i = 0;
    truth = 0;
    while(dataframe[i] != NULL && truth!=1){
        for(j=0; j<dataframe[i]->log_size && truth!=1; j++){
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


///////////////////////////////////////// Access value
void* accessvalue(int dataframe, int rownb, int colnb, void* ReplaceValue){
    return 0;
}

void display_name(COLUMN** dataframe){
    int i = 0;
    while(dataframe[i] != NULL){
        printf("The title of the column %d is %s",i,dataframe[i]->title);
        i++;
    }
}


///////////////////////////////// Analysis and statistics of the data frame /////////////////////////////////


/////////////////////////////////////// display_nbrow(COLUMN** dataframe)

// Print the number of columns in the dataframe
void display_nbcol(COLUMN** dataframe){
    int i = 0;
    while (dataframe[i] != NULL){
        i++;
    }
    printf("The dataframe contains %d columns",i);
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
