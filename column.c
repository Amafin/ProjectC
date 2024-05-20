#include "column.h"
#include <stdio.h>
#include "malloc.h"
#include <string.h>
#include "cdataframe.h"

int REALLOC_SIZE = 100;


// Create a column
COLUMN* create_column(ENUM_TYPE type, char* title1){
    COLUMN* col;
    col = (COLUMN*) malloc(sizeof (COLUMN));
    strcpy(col->title,title1);
    col->log_size = 0;
    col->phys_size = 0;
    col->column_type = type;
    col->data = NULL;
    col->index = NULL;
    return col;
};

// Add a value in a column
int insert_value(COLUMN* col,  void* value) {
    // check memory space
    if (col != NULL) {
        if (col->phys_size == 0) {
            col->phys_size = REALLOC_SIZE;
            col->data = (COL_TYPE **) malloc(col->phys_size * sizeof(COL_TYPE *));
            col->index = (unsigned long long int *) malloc(col->phys_size * sizeof(int));
        }
        if (col->log_size == col->phys_size) {
            col->phys_size = col->phys_size + REALLOC_SIZE;
            col->data = (COL_TYPE **) realloc(col->data, col->phys_size * sizeof(COL_TYPE *));
        }
        if (col->data != NULL) {
            if (value != NULL) {
                switch (col->column_type) {
                    case NULLVAL:
                        printf("Null");
                        // TO CHANGE //
                        // Allocate the memory for the value
                        col->data[col->phys_size] = (char *) malloc(sizeof(char));
                        // Add the value
                        *((char *) col->data[col->phys_size]) = *((char *) value);
                        break;
                    case UINT:
                        printf("UnInt");
                        col->data[col->log_size] = (COL_TYPE *) malloc(sizeof(unsigned int));
                        unsigned int* valaf1 = ((unsigned int *)value);
                        *(unsigned int *) col->data[col->log_size] = valaf1;
                        break;
                    case INT:
                        printf("Int\n");
                        col->data[col->log_size] = (COL_TYPE *) malloc(sizeof(int));
                        int* valaf2 = ((int *)value);
                        *(int *) col->data[col->log_size] = valaf2;
                        break;
                    case CHAR:
                        printf("Char");
                        col->data[col->log_size] = (COL_TYPE *) malloc(sizeof(char));
                        char* valaf3 = ((char *)value);
                        *(char *) col->data[col->log_size] = valaf3;
                        break;
                    case FLOAT:
                        printf("Float");
                        col->data[col->log_size] = (COL_TYPE *) malloc(sizeof(float));
                        float* valaf4 = ((float *)value);
                        *(float *) col->data[col->log_size] = *valaf4;
                        break;
                    case DOUBLE:
                        printf("Double");
                        col->data[col->log_size] = (COL_TYPE *) malloc(sizeof(double));
                        double* valaf5 = ((double *)value);
                        *(double *) col->data[col->log_size] = *valaf5;
                        break;
//////////////////// Change for string
                    case STRING:
                        printf("String");
                        col->data[col->log_size] = (COL_TYPE *) malloc(sizeof(char)*strlen(value));
                        char* valaf6 = ((char *)value);
                        *(char *) col->data[col->log_size] = valaf6;
                        break;
                    case STRUCTURE:
                        printf("Structure");
                        // TO CHANGE //
                        col->data[col->log_size] = (COL_TYPE *) malloc(sizeof(int));
                        int* valaf7 = ((int *)value);
                        *(int *) col->data[col->log_size] = *valaf7;
                        break;
                    default:
                        printf("Nothing");
                }
                col->index[col->log_size] = col->log_size;
                col->log_size += 1;
                return 1;
            }
            else {
                // We still store NULl value
                col->data[col->log_size] == NULL;
                col->log_size++;
                return 1;
            }
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}



//  Delete the allocated space of each value, then the whole column
void delete_column(COLUMN **col){
    int i;
    for(i = 0; i < (*col)->log_size; i++ )
    {
        free((*col)->data[i]);
        (*col)->log_size --;
        printf("Data deleted\n");
    }
    free((*col));
    printf("Column deleted\n");
}


// Convert a value in a column to string
void convert_value(COLUMN *col, unsigned long long int i, char* str[], int size)
{
    char buffer[50];
    switch((*col).column_type){
        case NULLVAL:
            break;
        case UINT:
            snprintf(buffer, size, "%d", *((unsigned int*)col->data[i]));
            *str = malloc(strlen(buffer) + 1);
            strcpy(*str, buffer);
            free(col->data[i]);
            col->data[i] = *str;
            break;
        case INT:
            snprintf(buffer, size, "%d", *((int*)col->data[i]));
            *str = malloc(strlen(buffer) + 1);
            strcpy(*str, buffer);
            free(col->data[i]);
            col->data[i] = *str;
            break;
        case CHAR:
            snprintf(buffer, size, "%d", *((char*)col->data[i]));
            *str = malloc(strlen(buffer) + 1);
            strcpy(*str, buffer);
            free(col->data[i]);
            col->data[i] = *str;
            break;
        case FLOAT:
            snprintf(buffer, size, "%d", *((float*)col->data[i]));
            *str = malloc(strlen(buffer) + 1);
            strcpy(*str, buffer);
            free(col->data[i]);
            col->data[i] = *str;
            break;
        case DOUBLE:
            snprintf(buffer, size, "%d", *((double*)col->data[i]));
            *str = malloc(strlen(buffer) + 1);
            strcpy(*str, buffer);
            free(col->data[i]);
            col->data[i] = *str;
            break;
        case STRING:
            snprintf(buffer, size, "%d", *((char*)col->data[i]));
            *str = malloc(strlen(buffer) + 1);
            strcpy(*str, buffer);
            free(col->data[i]);
            col->data[i] = *str;
            break;
        case STRUCTURE:
            // TO CHANGE //
            break;
    }
}


// Print the values in a column
void print_col(COLUMN* col){
    int i=0;

    // Conversion of the values
    if(col->data != NULL) {
        printf("%s\n", col->title);
        while (i < col->log_size) {
            char *string[20];
            // Call of the function convert_value
            convert_value(col, col->index[i], &(string[20]), sizeof(string));
            i++;
            col->index[i] = i;
        }
    }
    i=0;
    while(i<col->log_size) {
        printf("%s\n", col->data[col->index[i]]);
        i++;
    }
}


///////////////////////////////// Additional functions /////////////////////////////////


// Return the number of occurrences of a value x (x given as a parameter)
int value_occ(void* value, COLUMN* col){
    int i, occurences = 0;

    for(i= 0; i < col->log_size; i++){
        if(col->data[i] == value){
            occurences += 1;
        }
    }
    return occurences;
}

// Return the value present at position x (x given as a parameter)
void* value_position(COLUMN* col, unsigned long long int i){
    char* string[20];
    convert_value(col, i, &(string[20]), sizeof(string));
    return col->data[i];
}


// Return the number of values that are greater than x (x given as a parameter)
int value_greater(COLUMN* col, void* value){
    int counter = 0;
    for(int i = 0; i<col->log_size; i++){
        switch((*col).column_type) {
            case UINT:
                if (*(unsigned int *) value < *(unsigned int *) col->data[i]) {
                    counter++;
                }
                break;
            case INT:
                if (*(int *) value < *(int *) col->data[i]) {
                    counter++;
                }
                break;
            case DOUBLE:
                if (*(double *) value < *(double *) col->data[i]) {
                    counter++;
                }
                break;
        }
    }
    return counter;
}


// Return the number of values that are less than x (x given as a parameter)
int value_less(COLUMN* col, void* value) {
    int counter = 0;
    for (int i = 0; i < col->log_size; i++) {
        switch ((*col).column_type) {
            case UINT:
                if (*(unsigned int *) value > *(unsigned int *) col->data[i]) {
                    counter++;
                }
                break;
            case INT:
                if (*(int *)value > *(int *) col->data[i]) {
                    counter++;
                }
                break;
            case DOUBLE:
                if (*(double *) value > *(double *) col->data[i]) {
                    counter++;
                }
                break;
        }
    }
    return counter;
}