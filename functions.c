#include "functions.h"
#include <stdio.h>
#include "malloc.h"

// Create a column
COLUMN* create_column(ENUM_TYPE type, char* title){
    COLUMN col;
    COLUMN* pcol=&col;

    col.title = title;
    col.log_size = 0;
    col.phys_size = 10;
    col.column_type = type;
    col.data = NULL;
    col.index = 0;
    return pcol;
};

// Add a value in a column
int insert_value(COLUMN *col, void *value){
    // check memory space
    if(col->log_size  < col->phys_size){
        //...
        switch(col->column_type){
            case 1: // NULLVAL
            // TO CHANGE //
                // Allocate the memory for the value
                col->data[col->phys_size] = (char*) malloc (sizeof(char));
                // Add the value
                *((char*)col->data[col->phys_size])= *((char*)value);
                break;
            case 2: // UnInt
                col->data[col->phys_size] = (unsigned int*) malloc (sizeof(unsigned int));
                *((unsigned int*)col->data[col->phys_size])= *((unsigned int*)value);
                break;
            case 3: // Int
                col->data[col->phys_size] = (int*) malloc (sizeof(int));
                *((int*)col->data[col->phys_size])= *((int*)value);
                break;
            case 4: // Char
                col->data[col->phys_size] = (char*) malloc (sizeof(char));
                *((char*)col->data[col->phys_size])= *((char*)value);
                break;
            case 5: // Float
                col->data[col->phys_size] = (float*) malloc (sizeof(float));
                *((float*)col->data[col->phys_size])= *((float*)value);
                break;
            case 6: // Double
                col->data[col->phys_size] = (double*) malloc (sizeof(double));
                *((double*)col->data[col->phys_size])= *((double*)value);
                break;
            case 7: // String
                col->data[col->phys_size] = (char*) malloc (sizeof(char));
                *((char*)col->data[col->phys_size])= *((char*)value);
                break;
            case 8: // Structure
            // TO CHANGE //
                col->data[col->phys_size] = (int*) malloc (sizeof(int));
                *((int*)col->data[col->phys_size])= *((int*)value);
                break;
            }
            //...
        col->log_size++;
        //...
    };
};


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
void convert_value(COLUMN *col, unsigned long long int i, char *str, int size)
{

    switch((*col).column_type){
        case 2:
            snprintf(str, size, "%d", *((unsigned int*)col->data[i]));
            break;
        case 3:
            snprintf(str, size, "%d", *((int*)col->data[i]));
            break;
        case 4:
            snprintf(str, size, "%c", *((char*)col->data[i]));
            break;
        case 5:
            snprintf(str, size, "%f", *((float*)col->data[i]));
            break;
        case 6:
            snprintf(str, size, "%lf", *((double*)col->data[i]));
            break;
        case 7:
            snprintf(str, size, "%s", (char*)col->data[i]);
            break;
        case 8:
            // TO CHANGE //
            snprintf(str, size, "%d", *((int*)col->data[i]));
            break;
        default:
            // TO CHANGE //
            snprintf(str, size, "%d", *((int*)col->data[i]));
    }
    col->data[i]=str;
}


// Print the values in a column
void print_col(COLUMN* col){
    int i;
    for(i=0; i<(*col).log_size; i++)
    {
        printf("[%d] %s\n",i,(*col).data[i]);
    }
}