#include "column.h"
#include <stdio.h>
#include "malloc.h"

// Create a column
COLUMN* create_column(ENUM_TYPE type, char* title){
    COLUMN col;
    COLUMN* pcol = &col;

    col.title = title;
    col.log_size = 0;
    col.phys_size = 5;
    printf("%d\n",col.log_size);
    printf("%d",col.phys_size);
    col.column_type = type;
    col.data = NULL;
    col.index = 0;

    return pcol;
};

// Add a value in a column
int insert_value(COLUMN *col, void *value){
    printf("Purée");
    // check memory space
    if(col->log_size  < col->phys_size){
        switch(col->column_type){
            case NULLVAL:
            // TO CHANGE //
                // Allocate the memory for the value
                col->data[col->phys_size] = (char*) malloc (sizeof(char));
                // Add the value
                *((char*)col->data[col->phys_size])= *((char*)value);
                break;
            case UINT:
                col->data[col->phys_size] = (unsigned int*) malloc (sizeof(unsigned int));
                *((unsigned int*)col->data[col->phys_size])= *((unsigned int*)value);
                break;
            case INT:
                printf("Hello");
                col->data[col->phys_size] = (int*) malloc (sizeof(int));
                *((int*)col->data[col->phys_size])= *((int*)value);
                break;
            case CHAR:
                col->data[col->phys_size] = (char*) malloc (sizeof(char));
                *((char*)col->data[col->phys_size])= *((char*)value);
                break;
            case FLOAT:
                col->data[col->phys_size] = (float*) malloc (sizeof(float));
                *((float*)col->data[col->phys_size])= *((float*)value);
                break;
            case DOUBLE:
                col->data[col->phys_size] = (double*) malloc (sizeof(double));
                *((double*)col->data[col->phys_size])= *((double*)value);
                break;
            case STRING:
                col->data[col->phys_size] = (char*) malloc (sizeof(char));
                *((char*)col->data[col->phys_size])= *((char*)value);
                break;
            case STRUCTURE:
            // TO CHANGE //
                col->data[col->phys_size] = (int*) malloc (sizeof(int));
                *((int*)col->data[col->phys_size])= *((int*)value);
                break;
            }
        col->log_size +=1;
        return 1;
    }
    else{
        return 0;
    }
}


//  Delete the allocated space of each value, then the whole column
void delete_column(COLUMN **col){
    int i;
    for(i = 1; i<(*col)->log_size; i++ )
    {
        free((*col)->data[i]);
    }
    free((*col));

}


// Convert the values in a column to string
void convert_value(COLUMN *col, unsigned long long int i, char* str[], int size)
{
    printf("Arghhh");
    switch((*col).column_type){
        case 2:
            snprintf(*str, size, "%u", *((unsigned int*)col->data[i]));
            break;
        case 3:
            snprintf(*str, size, "%d", *((int*)col->data[i]));
            break;
        case 4:
            snprintf(*str, size, "%c", *((char*)col->data[i]));
            break;
        case 5:
            snprintf(*str, size, "%f", *((float*)col->data[i]));
            break;
        case 6:
            snprintf(*str, size, "%lf", *((double*)col->data[i]));
            break;
        case 7:
            snprintf(*str, size, "%s", (char*)col->data[i]);
            break;
        case 8:
            // TO CHANGE //
            snprintf(*str, size, "%d", *((int*)col->data[i]));
            break;
        default:
            // TO CHANGE //
            snprintf(*str, size, "%d", *((int*)col->data[i]));
    }
}


// Print the values in a column
void print_col(COLUMN* col){
    int i=0;
    char* string[50];
    printf("Pipapou");
    // Conversion of the values
    while(i<col->log_size) {
        printf("Rebelotte\n");
        // Call of the function convert_value
        convert_value(col, col->index[i], &(string[50]), sizeof(string));
        col->index ++;
    }
    printf("Pizza");
    for(i=0; i<col->log_size; i++) {
        printf("[%d] %s\n", i, col->data[i]);
    }
    printf("Peperonni");
}


///////////////////////////////// Additional functions /////////////////////////////////

// Return the number of occurrences of a value x (x given as a parameter)
int value_occ(void* value, COLUMN* col){
    int i, occurences = 0;
    for(i= 0; i<col->log_size; i++){
        if(col->data[i] == value){
            occurences += 1;
        }
    }
    return occurences;
}


// Return the value present at position x (x given as a parameter)
void* value_position(COLUMN* col, unsigned long long int i){
    return col->data[i];
}

// Return the number of values that are greater than x (x given as a parameter)
int value_greater(COLUMN* col, void* value){
    int counter = 0;
    for(int i = 0; i<col->log_size; i++){
        if(col->data[i] > value){
            counter ++;
        }
    }
    return counter;
}


// Return the number of values that are less than x (x given as a parameter)
int value_less(COLUMN* col, void* value){
    int counter = 0;
    for(int i = 0; i<col->log_size; i++){
        if(col->data[i] < value){
            counter ++;
        }
    }
    return counter;
}